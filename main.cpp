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
#include <math.h>
using namespace std;

class Time {

public:

    int days, hour, min, sec;

    // Default constructor
    Time() {
        days = hour = min = sec = 0;
    }

    // Destructor
    ~Time() {}

    // Copy constructor
    Time(const Time& time) {
        days = time.days;
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
        days += ((hour + (min + (sec / 60)) / 60) / 24);
        hour = (hour + ((min + (sec / 60)) / 60)) % 24;
        min = (min + (sec / 60)) % 60;
        sec %= 60;
    }

    void StringToInt(string userTime) {
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

    // Time assignment overload (=)
    Time& operator= (const Time& right) {
        if (this == &right)
            return *this;
        hour = right.hour;
        min = right.min;
        sec = right.sec;
        return *this;
    }

    // Time addition overload (+) 
    Time operator+ (const Time& right) {
        Time res;
        res.hour = this -> hour + right.hour;
        res.min = this-> min + right.min;
        res.sec = this-> sec + right.sec;
        return res;
    }

    // Time subtraction overload (-)
    Time operator- (const Time& right) {
        Time res;
        res.hour = this->hour - right.hour;
        res.min = this->min - right.min;
        res.sec = this->sec - right.sec;
        return res;
    }

    // Time comparison overload (==)
    bool operator== (const Time& right) {
       return ((this->hour == right.hour) && (this->min == right.min) && (this->sec == right.sec));
    }

    //friend ostream& operator<<(ostream& out, const Time& right);
};

//ostream& operator<<(ostream& out, const Time& right) {                // !!! help me here, please !!!
//    out << "\nThe total time is: " << totalTime.hour << ":"
//                                   << totalTime.min << ":"
//                                   << totalTime.sec;
//};

int main() {
    srand((unsigned)time(NULL));
    int menuChooser = 0;
    string userTime;
    Time firstTime, secondTime, totalTime;

    cout << "Enter the time" << "Format : hours ' ' / : minutes ' ' / : seconds : ";
    getline(cin, userTime);
    firstTime.StringToInt(userTime);

    cout << "\nEnter the time you want to: add (+), subtract (-), compare (==)" << "\nFormat : hours ' ' / : minutes ' ' / : seconds" << endl;
    cout << "Your input is : ";
    getline(cin, userTime);
    secondTime.StringToInt(userTime);

    int isWork = 1;

    while (isWork) {
        cout << "\nInput the number of the action" 
            << "\n\t1) input 1 to add (+)" 
            << "\n\t2) input 2 to subtract (-)" 
            << "\n\t3) input 3 to compare (==)" 
            << "\n\t4) input 0 to exit" << endl;
        cout << "Your input is : ";
        cin >> menuChooser;
        switch (menuChooser) {
        case 0:
            isWork = 0;
            break;

        case 1:
            totalTime.hour = firstTime.hour + secondTime.hour;
            totalTime.min = firstTime.min + secondTime.min;
            totalTime.sec = firstTime.sec + secondTime.sec;
            totalTime.TimeEdit();
            cout << "\nThe total time is: " << totalTime.days << ":"
                                            << totalTime.hour << ":"
                                            << totalTime.min << ":"
                                            << totalTime.sec << endl;
            break;

        case 2:
            totalTime.hour = abs(firstTime.hour - secondTime.hour);
            totalTime.min = abs(firstTime.min - secondTime.min);
            totalTime.sec = abs(firstTime.sec - secondTime.sec);
            totalTime.TimeEdit();
            cout << "\nThe total time is: " << totalTime.days << ":"
                                            << totalTime.hour << ":"
                                            << totalTime.min << ":" 
                                            << totalTime.sec << endl;
            break;

        case 3:
            bool result;
            if (bool result = (firstTime.hour == secondTime.hour) && 
                (firstTime.min == secondTime.min) && (firstTime.sec == secondTime.sec))
                cout << "\nThe times are equal to each other" << endl;
            else cout << "\nThe times aren't equal to each other" << endl;

            break;

        default:
            cout << "\nERROR! You've entered the wrong operation!" << endl;

            break;
        }
    }

    return 0;
}