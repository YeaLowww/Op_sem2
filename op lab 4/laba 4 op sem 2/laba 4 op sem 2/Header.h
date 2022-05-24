#include <iostream>
#include <string>
using namespace std;
class DATE {
    string day, month, year;
public:
    DATE(string day, string month, string year);
    DATE();
    void setDay(string day);
    void setMonth(string month);
    void setYear(string year);
    string getDay();
    string getMonth();
    string getYear();
    void print();
    int DIM(int month, int year);
    int DIY(int year);
    string getSeason();
    DATE& operator+=(int days);
    friend int operator-(DATE date1, DATE date2);
};