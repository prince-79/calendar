#include <iostream>
#include <iomanip>

using namespace std;


bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}


int getDaysInMonth(int month, int year) {
    if (month == 2) {
        return isLeapYear(year) ? 29 : 28;
    }
    return (month == 4 || month == 6 || month == 9 || month == 11) ? 30 : 31;
}


int getFirstDayOfMonth(int month, int year) {
    if (month < 3) {
        month += 12;
        year--;
    }
    return (1 + (13 * month + 1) * 13 / 5 + year + year / 4 - year / 100 + year / 400) % 7;
}


void printCalendar(int month, int year) {
    cout << "Calendar for " << month << "/" << year << endl;
    cout << "Sun Mon Tue Wed Thu Fri Sat" << endl;

    int daysInMonth = getDaysInMonth(month, year);
    int firstDay = getFirstDayOfMonth(month, year);


    for (int i = 0; i < firstDay; i++) {
        cout << "    ";
    }

    for (int day = 1; day <= daysInMonth; day++) {
        cout << setw(3) << day << " ";
        if ((firstDay + day) % 7 == 0) {
            cout << endl;
        }
    }
    cout << endl;
}

int main() {
    int month, year, type;
    cout << "For Full Year Calendar : Enter 1  \n";
    cout <<"For Monthly Calendar : Enter 2 : ";
    cin >> type;
    switch(type){
        case 2:
  
             
    cout << "Enter year (e.g., 2024): ";
    cin >> year;
    cout << "Enter month (1-12): ";
    cin >> month;

    if (month < 1 || month > 12) {
        cout << "Invalid month. Please enter a value between 1 and 12." << endl;
        return 1;
    }

    printCalendar(month, year);
    break;
    
    case 1:
            cout << "Enter year (e.g., 2024): ";
    cin >> year;
    for(int i = 1; i <= 12 ; i++){
        printCalendar(i,year);
    }
    break;
        
        
    }
    return 0;
}