def infile(filename, oper):
     file = open(filename, oper)
     str_ = ' '
     print("Write ur text ")
     while str_:
         str_ = input()
         if str_:
             file.write(str_ + ' ')
     file.close()
     
def new_file(file1, file2, n):
    file1 = open(file1, 'r')
    file2 = open(file2, 'w')
    text = file1.read()
    words = text.split()
    new_words = list()
    for word in words:
        counter = 0
        for i, w in enumerate(words):
            if word == w and w!='':
                counter += 1
                words[i] = ''
        if counter > n: 
            new_words.append(word + ' ') 
    new_words.sort(key=lambda l: len(l))
    for word in new_words:
        file2.write(word)
    file1.close()
    file2.close()

def outfile(name):
     file = open(name, 'r')
     for line in file:
          print(line)
          

def main():
     oper = input('To write file - w \nTo add text - a\n')
     infile('infile.txt', oper)
     n = int(input('Enter N '))
     new_file('infile.txt', 'outfile.txt', n)
     print('First File:')
     outfile('infile.txt')
     print('Second File:')
     outfile('outfile.txt')
main()
