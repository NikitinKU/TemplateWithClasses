// Copyright 2022 Nikitin Kirill
// Group: 3821B1PR2

/*ѕостановка задачи:
¬рем€.
–азработать класс Time дл€ работы с временем в формате, представленным в виде тройки hour, min, sec.
 ласс должен содержать :
 * все необходимые конструкторы(включа€ преобразовани€ типа из строки вида У12 : 24 : 35Ф и деструктор;
 * метод представлени€ времени в виде строки : У12 : 24 : 35Ф;
¬ классе должны быть перегружены операции :
 * 1) присваивани€;
 * 2) сложени€(и вычитани€) времени с количеством секунд(переполнение результата Ђвверхї
   или Ђвнизї должно выполн€ть переход на следующие или предыдущие сутки с Ђотбрасываемї количества суток);
 * 3) сравнени€;
 * 4) операци€ ввода / вывода в поток.*/

#include <iostream>
#include <string>
using namespace std;

class Time {

public:

    int hour, min, sec;

    // Default constructor
    Time() {
        hour = min = sec = 0;
    }

    // Destructor
    ~Time() {}

    // Copy constructor
    Time(const Time& time) {
        hour = time.hour;
        min = time.min;
        sec = time.sec;
    }

    // Method of the time output
    void TimePrint() {
        cout << "The time is : " << hour << ":" << min << ":" << sec << endl;
    }

    // Method of the interpreting time into the correct format 
    void TimeEdit() {
        hour = (hour + ((min + (sec / 60)) / 60)) % 24;
        min = (min + (sec / 60)) % 60;
        sec %= 60;
    }

    // Time addition method (+) 
    void TimeAction(const Time& time) {
        //finish
        TimeEdit();
    }

    // Time subtraction method (-)
    void TimeAction(const Time& time) {
        //finish
        TimeEdit();
    }

    void text(string userTime) {
        char strToInt[10] = { 0 };
        for (int i = 0, j = 0, tSection = 0; i <= userTime.length(); i++) {
            if (userTime[i] == ':' || userTime[i] == ' ' || i == userTime.length()) {
                if (tSection == 0) {
                    hour = atoi(strToInt);
                }
                else if (tSection == 1) {
                    min = atoi(strToInt);
                }
                else if (tSection == 2) {
                    sec = atoi(strToInt);
                }
                tSection++;
                j = 0;

                for (int a = 0; a < 10; a++) strToInt[a] = 0;
            }
            else {
                strToInt[j] = userTime[i];
                j++;
               
            }
        }
    }
    // Time comparison method (==)

};

int main() {
    srand((unsigned)time(NULL));
    string userTime;

    cout << "Enter the time (Format: hours:minutes:seconds) : ";

    Time firstTime;

    getline(cin, userTime);
    firstTime.text(userTime);

    return 0;
}