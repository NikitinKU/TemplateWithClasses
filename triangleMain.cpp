#include <iostream>
#include <cmath>
using namespace std;

/* Задание: дописать пропущенные методы, выделить функции, классы,
заменить часть функций перегрузкой операторов.

ЦЕЛЬ: main() должен стать хорошо читаемой структрутой, чтобы было понятно, что происходит во всей программе (без комментариев),
но при этом помещался бы на одном экране.

! В main() вносить свои изменения структуры программы запрещено. Только заменять действия на аналоги, реализованные в
функциях или с использованием классов. СТРУКТУРА ДОЛЖНА ОСТАТЬСЯ ИСХОДНОЙ.

На гитхабе должно появиться 4 коммита:
0. дописал методы
1. выделил функции
2. выделил классы и применил принципы ООП
3. заменил часть функций операторами

То есть по окончании каждого этапа делайте коммит.

Подсказки:
0. Возможные классы, которые проглядываются в программе:
- класс МЕНЮ (объединяет функции, относящиеся к меню взаимодействия с пользователем),
- класс ТОЧКА (для хранения координат)
- класс ТРЕУГОЛЬНИК (в конструкторах должны отображаться все способы задания треугольника).

1. Функции:
- различные функции меню (показать меню 1 уровня, показать меню 2 уровня и т.д.),
- функции ввода и проверки корректности данных,
- функции различных действий над треугольником: проверка на существование, подсчёт площади и т.д.

Указание. На этапе создания классов предполагается, что объект класса создаётся не в данной функции, а после неё.
Не лепите ввод данных и конструктор в один метод. Функции ввода данных - функции МЕНЮ, а создание объекта (точки, например) -
функции соответствующего класса.

Пример допустимой реализации:
Через 3 метода:
1) метод ввода значений (метод класса меню) - inputSides
2) метод ввода треугольника (метод класса треугольник) -inputTriangle

Далее используется перечисление - enum Type {bySides, byBaseAndHeight, byPointsCoords};

Triange tr1;
tr1.inputTriangle(bySides);

void inputTriangle(Type _type) {
  switch (_type) {
   case bySides:
     int side1, side2, side3;
     inputSides(&side1, &side2, &side3);   // тут сидит ввод значений
     Triange temp(side1, side2, side3);    // тут создаётся треугольник с указанными полями
     this = temp;
     break;
   // ...
  }
}

или

void inputTriangle(Type _type) {
  switch (_type) {
   case bySides:
     int side1, side2, side3;
     inputSides(&side1, &side2, &side3);   // тут сидит ввод значений
     this->side1 = side1;                  // тут изменяется уже существующий треугольник, заполнение указанными полями
     this->side2 = side2;
     this->side3 = side3;
     break;
   // ...
  }
}

*/

class Menu {};
class Point {};
class Triangle {};

enum Type { bySides, byBaseAndHeight, byPointsCoords };

int main() {
    int user_chosen;
    int AB, BC, AC, DE, EF, DF;
    int A[2], B[2], C[2];
    int D[2], E[2], F[2];
    int h1, h2;
    float p1, p2, S1 = 0, S2 = 0, P;
    bool exit_flag = false, back_flag;

    Type _inputType;
    while (!exit_flag) {
        back_flag = false;
        cout << "Ways to define a triangle:" << endl
            << "\t1) by three sides," << endl
            << "\t2) by base and height," << endl
            << "\t3) by three points" << endl
            << "Input: ";
        cin >> user_chosen;

        switch (user_chosen) {
        case 1:
            _inputType = bySides;
            while (1) {
            cout << "\nInput 3 side of the 1st triangle (using spacebar): ";
            cin >> AB >> BC >> AC;
            if (!(AB + BC > AC && AB + AC > BC && AC + BC > AB)) {
                cout << "Input error: triangle doesn't exist" << endl;
                cout << "Try again" << endl;
                continue;
            }

            cout << "Input 3 side of the 2nd triangle (using spacebar): ";
            cin >> DE >> EF >> DF;
            if (!(DE + EF > DF && DE + DF > EF && DF + EF > DE)) {
                cout << "Input error: triangle doesn't exist" << endl;
                cout << "Try again" << endl;
                continue; 
            }
            break;
            }
        break;

        case 2:
            _inputType = byBaseAndHeight;
            cout << "\n1st triangle";
            cout << "\nInput base of triangle: ";
            cin >> AB;
            cout << "Input height of triangle: ";
            cin >> h1;

            cout << "\n\n2nd triangle";
            cout << "\nInput base of triangle: ";
            cin >> DE;
            cout << "Input height of triangle: ";
            cin >> h2;
        break;

        case 3:
            _inputType = byPointsCoords;
            cout << "\n1st triangle";
            cout << "\nInput 1st point's coordinates (using spacebar): A = ";
            cin >> A[0] >> A[1];
            cout << "Input 2nd point's coordinates (using spacebar): B = ";
            cin >> B[0] >> B[1];
            cout << "Input 3rd point's coordinates (using spacebar): C = ";
            cin >> C[0] >> C[1];

            cout << "\n\n2nd triangle";
            cout << "\nInput 1st point's coordinates (using spacebar): D = ";
            cin >> D[0] >> D[1];
            cout << "Input 2nd point's coordinates (using spacebar): E = ";
            cin >> E[0] >> E[1];
            cout << "Input 3rd point's coordinates (using spacebar): F = ";
            cin >> F[0] >> F[1];

        break;

        default:
            cout << "Input error: error in input" << endl;
            break;
        }

        while (!back_flag) {
            bool check = true;
            cout << "\nMethods: 1) get square" << endl
            << "\t 2) get perimeter" << endl
            << "\t 3) get type of triangle," << endl
            << "\t 4) compare with another triangle by square" << endl
            << "\t 5) back to first menu" << endl
            << "\t 0) exit" << endl
            << "Input: ";
            cin >> user_chosen;

            switch (user_chosen) {
            case 0:
                check = false;
                exit_flag = true;
                break;

            case 1:
                if (_inputType == bySides) {
                    if ((AB + BC > AC && AB + AC > BC && AC + BC > AB) && (DE + EF > DF && DE + DF > EF && DF + EF > DE)) {
                        p1 = (AB + BC + AC) * 0.5;
                        p2 = (DE + EF + DF) * 0.5;
                        S1 = sqrt(p1 * (p1 - AB) * (p1 - BC) * (p1 - AC));
                        S2 = sqrt(p2 * (p2 - DE) * (p2 - EF) * (p2 - DF));
                        cout << "\n\tSquare of triangle: S1 = " << S1 << endl;
                        cout << "\tSquare of triangle: S2 = " << S2 << endl;
                    }
                    else {
                        cout << "\tInput error: triangles dont't exist" << endl;
                    }
                }
                else if (_inputType == byBaseAndHeight) {
                    S1 = 0.5 * AB * h1;
                    S1 = 0.5 * DE * h2;
                    cout << "\n\tSquare of triangle: S1 = " << S1 << endl;
                    cout << "\tSquare of triangle: S2 = " << S2 << endl;
                }
                else if (_inputType == byPointsCoords) {
                    S1 = 0.5 * abs((B[0] - A[0]) * (C[1] - A[1]) - (C[0] - A[0]) * (B[1] - A[1]));
                    S1 = 0.5 * abs((E[0] - D[0]) * (F[1] - D[1]) - (F[0] - D[0]) * (E[1] - D[1]));
                    cout << "\n\tSquare of triangle: S1 = " << S1 << endl;
                    cout << "\tSquare of triangle: S2 = " << S2 << endl;
                }
                //system("pause");
                //system("cls");
                break;

            case 2:
                if (_inputType == bySides) {
                    if (AB + BC > AC && AB + AC > BC && AC + BC > AB) {
                        P = AB + BC + AC;
                        cout << "\n\tPerimeter of triangle: P = " << P << endl;
                    }
                    else {
                        cout << "\n\tInput error: triangle doesn't exist" << endl;
                    }
                }
                else if (_inputType == byBaseAndHeight) {
                    cout << "\n\tInput error: we couldn't find perimeter by your parameters" << endl;
                }
                else if (_inputType == byPointsCoords) {
                    AB = sqrt(((pow(B[0] - A[0], 2)) + (pow(B[1] - A[1], 2))));
                    BC = sqrt(((pow(C[0] - B[0], 2)) + (pow(C[1] - B[1], 2))));
                    AC = sqrt(((pow(C[0] - A[0], 2)) + (pow(C[1] - A[1], 2))));
                    P = AB + BC + AC;
                    cout << "\n\tPerimeter of triangle: P = " << P << endl;
                }
                break;

            case 3:
                if ((AB == BC) && (BC == AC) && (AB == AC))
                    cout << "\n\tThe triangle is equilateral" << endl; //равносторонний

                if ((AB == BC) || (BC == AC) || (AB == AC))
                    if (!((AB == BC) && (BC == AC) && (AB == AC)))
                        cout << "\n\tThe triangle is isosceles" << endl; //равнобедренный

                if (((AB == 0.5 * BC) || (AC == 0.5 * BC)) ||
                    ((BC == 0.5 * AB) || (AC == 0.5 * AB)) ||
                    ((BC == 0.5 * AC) || (AB == 0.5 * AC)))
                    cout << "\n\tThe triangle is a right triangle" << endl; //прямоугольный

                if (!((AB == BC) && (BC == AC) && (AB == AC)))
                    if (!(((AB == BC) || (BC == AC) || (AB == AC))))
                        if (!((((AB == 0.5 * BC) || (AC == 0.5 * BC)) ||
                            ((BC == 0.5 * AB) || (AC == 0.5 * AB)) ||
                            ((BC == 0.5 * AC) || (AB == 0.5 * AC)))))
                            cout << "\n\tThe triangle is scalene" << endl; //произвольный
                break;

            case 4:
                if (S1 != 0 && S2 != 0) {
                    if (S1 == S2) cout << "\n\tTriangles are the same" << endl;
                    else cout << "\n\tTriangles are different" << endl;
                } 
                else { 
                    cout << "\n\tGet squares of the triangles first!\n"; 
                    break;
                }
            break;

            case 5:
                check = false;
                back_flag = true;
            break;

            default:
                cout << "Input error: error in input" << endl;
            break;
            }

            //if (back_flag || exit_flag) {
            if (back_flag || exit_flag) {
                system("cls");
                cout << "Last parameters: ";
                if (_inputType == bySides) {
                    cout << AB << "x" << BC << "x" << AC << endl;
                }
                else if (_inputType == byBaseAndHeight) {
                    cout << "a = " << AB << ", h = " << h1 << endl;
                }
                else if (_inputType == byPointsCoords) {
                    cout << "(" << A[0] << ", " << A[1] << ")" << ", ";
                    cout << "(" << B[0] << ", " << B[1] << ")" << ", ";
                    cout << "(" << C[0] << ", " << C[1] << ")" << endl;
                }
            }
            if (check == false) break;
        }
    }
    system("cls");
    cout << "\n\tGoodbye!" << endl;
}