import pickle

def FirstFile(file1, oper):
    count=int(input("Введіть кількість поїздів: "))
    print("Формат часу: xx:xx ")
    with open(file1,oper) as text:
        for i in range(count):
            direction=input("Введіть напрямок: ")
            number=input("Введіть номер поїзда: ")
            timeP=input("Введіть час відправлення: ")
            timeK=input("Введіть час прибуття: ")
            A=train(number,direction,timeP,timeK)
            pickle.dump(A, text)
            
def SecondFile(array, file2):
    with open(file2,'wb') as text:
        min_time=1000
        max_time=1800
        for i in range (len(array)):
            tp=int(array[i].timeP)
            tk=int(array[i].timeK)
            if ((tp <= min_time and tk <= min_time) or (tp >= max_time and tk >= max_time) or (tp >= max_time and tk <= min_time)):
                 pickle.dump(array[i], text)
            


class train:
    def __init__(TRAIN, number=0, direction=None, timeP="00:00", timeK="00:00"):
        TRAIN.number=number
        TRAIN.direction=direction
        TRAIN.timeP=timeP
        TRAIN.timeK=timeK

    def inf(TRAIN):
        print("Номер поїзда", TRAIN.number, "напрямок",TRAIN.direction, ", відправляється о",TRAIN.timeP, "приїжджає о", TRAIN.timeK)
     

def Output(file):
    array=[]
    with open(file,'rb') as text:
        while True:
            try:
                A=pickle.load(text)
            except:
                break
            else:
                array.append(A)
                A.inf()
    return array
print("print wb - new file!")
print("print ab - add to file!")
oper = input()
file1="Trains.bin"
file2="NewTrains.bin"
array=[]
FirstFile(file1,oper)
print("Літній розклад: ")
array=Output(file1)
SecondFile(array, file2)
print("Зімній розклад: ")
Output(file2)
