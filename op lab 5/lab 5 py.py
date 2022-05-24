from abc import ABC, abstractmethod
from math import sqrt
class TVector(ABC):
    def __init__(self):
        super().__init__()
    @abstractmethod
    def get_length():
        pass
    @abstractmethod
    def get_coord(coord):
        pass
    @abstractmethod
    def scalar(t):
        pass
    
class TVector2(TVector):
    def __init__(self, x, y):
        self.__x=x 
        self.__y=y
    def get_length(self):
        return sqrt(pow(self.__x,2)+pow(self.__y,2))
    def get_coord(self, coord):
            return self.__x if coord=='x' else self.__y
    def scalar(self, t):
        return self.__x*t.get_coord('x')+self.__y*t.get_coord('y')
    
class TVector3(TVector):
    def __init__(self, x, y, z):
        self.__x=x 
        self.__y=y
        self.__z=z
    def get_length(self):
        return sqrt(pow(self.__x,2)+pow(self.__y,2)+pow(self.__z,2))
    def get_coord(self, coord):
        if coord=='x':
            return self.__x
        elif coord=='y':
            return self.__y
        else:
            return self.__z
    def scalar(self, t):
        return self.__x*t.get_coord('x')+self.__y*t.get_coord('y')+self.__z*t.get_coord('z')
    
print("Введіть три координати вектора A: ")
x1, y1, z1 = map(int, input().split())
A = TVector3(x1, y1, z1)

print("Введіть три координати вектора B: ")
x2, y2, z2 = map(int, input().split())
B = TVector3(x2, y2, z2)

print("Введіть дві координати вектора C: ")
x3, y3 = map(int, input().split())
C = TVector2(x3, y3)

print("Введіть дві координати вектора D: ")
x4, y4 = map(int, input().split())
D = TVector2(x4, y4)

res = A.scalar(B) + C.scalar(D) + A.get_length();
print("S = (A,B) + (C,D) + |A| = ", res)
