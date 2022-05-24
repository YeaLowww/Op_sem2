#include "Header.h"

DATE::DATE(string day, string month, string year) {
    this->day = day;
    this->month = month;
    this->year = year;
}
DATE::DATE() {
    cout << "Input day: " << endl;
    cin >> day;
    cout << "Input month: " << endl;
    cin >> month;
    cout << "Input year: " << endl;
    cin >> year;
}
void DATE::setDay(string day) {
    this->day = day;
}
void DATE::setMonth(string month) {
    this->month = month;
}
void DATE::setYear(string year) {
    this->year = year;
}
string DATE::getDay() {
    return day;
}
string DATE::getMonth() {
    return month;
}
string DATE::getYear() {
    return year;
}
void DATE::print() {
    cout << "Date: " << day << "." << month << "." << year << endl;
}
int DATE::DIM(int month, int year) {
    int temp[] = { 4,6,9,11 };
    for (int i = 0; i < 4; i++)
    {
        if (month == temp[i]) return 30;
    }
    if (month == 2) {
        if (year % 4 == 0) return 29;
        else return 28;
    }
    else return 31;
}
int DATE::DIY(int year) {
    if (year % 4 == 0) return 366;
    else return 365;
}
string DATE::getSeason() {
    int monthInt = stoi(month);
    if (monthInt < 3 || monthInt == 12) return "winter";
    else if (monthInt < 6) return "spring";
    else if (monthInt < 9) return "summer";
    else return "autumn";
}
DATE& DATE::operator+=(int days) {
    int dayInt = stoi(this->day);
    int monthInt = stoi(this->month);
    int yearInt = stoi(this->year);
    if (dayInt + days > this->DIM(monthInt, yearInt)) {
        do {
            days -= this->DIM(monthInt, yearInt) - dayInt;
            dayInt = 0;
            monthInt++;
            if (monthInt == 13) {
                monthInt = 1;
                yearInt++;
            }
        } while (dayInt + days > this->DIM(monthInt, yearInt));
    }
    dayInt += days;
    string day2 = to_string(dayInt);
    string month2 = to_string(monthInt);
    string year2 = to_string(yearInt);
    if (dayInt < 10) day2 = "0" + to_string(dayInt);
    if (monthInt < 10) month2 = "0" + to_string(monthInt);
    this->setDay(day2);
    this->setMonth(month2);
    this->setYear(year2);
    return(*this);

}
int operator-(DATE date1, DATE date2) {
    int res = 0;
    int dayInt1 = stoi(date1.day);
    int monthInt1 = stoi(date1.month);
    int yearInt1 = stoi(date1.year);
    int dayInt2 = stoi(date2.day);
    int monthInt2 = stoi(date2.month);
    int yearInt2 = stoi(date2.year);

    if (yearInt2 > yearInt1 + 1) {
        int yearChecker = yearInt2 - 1;
        do {
            res += date2.DIY(yearChecker);
            yearChecker--;
        } while (yearChecker != yearInt1);
        int monthChecker1 = monthInt1;
        do {
            res += date1.DIM(monthChecker1, yearInt1);
            monthChecker1++;
        } while (monthChecker1 < 13);
        res -= dayInt1;
        int monthChecker2 = 1;
        while (monthChecker2 < monthInt2) {
            res += date2.DIM(monthChecker2, yearInt2);
            monthChecker2++;
        };
        res += dayInt2;
    }
    if (yearInt2 == yearInt1) {
        if (monthInt1 != monthInt2) {
            int monthChecker = monthInt1;
            do {
                res += date1.DIM(monthChecker, yearInt1);
                monthChecker++;
            } while (monthChecker < monthInt2);
            res -= dayInt1;
            res += dayInt2;
        }
        else res = dayInt2 - dayInt1;
    }
    if (yearInt1 + 1 == yearInt2) {
        int monthChecker1 = monthInt1;
        do {
            res += date1.DIM(monthChecker1, yearInt1);
            monthChecker1++;
        } while (monthChecker1 < 13);
        res -= dayInt1;
        int monthChecker2 = 1;
        while (monthChecker2 < monthInt2) {
            res += date2.DIM(monthChecker2, yearInt2);
            monthChecker2++;
        };
        res += dayInt2;
    }
    return res;
}