#include "Header.h"

int main() {
    DATE Date1("20", "05", "2022");
    DATE Date2;
    DATE Date3("03", "12", "2003");
    Date1.print();
    Date2.print();
    Date3.print();
    Date1 += 9;
    cout << "new date 1" << endl;
    Date1.print();
    Date2 += 14;
    cout << "new date 2" << endl;
    Date2.print();
    int res = Date1 - Date2;
    cout << "result: " << abs(res) << endl;
    string season = Date3.getSeason();
    cout << "date3 season: " << season << endl;
    return 0;
}
