#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>

/*
�������� ������

������� �������: http://www.vsokovikov.narod.ru/New_MSDN_API/Console/con_fn.htm
���� � ��������� ����� - https://colorscheme.ru/color-converter.html

������� �� ��������������� ������ � ����������:
- ������������ ����-���� (��� ���� �� ����� �����������):
1) ������� ������������ ��������� ��� ���� (���� �������, ������)
2) ���������� ���� ���� � ����:
<< ������ >>
   �����
�
   ������
<< ����� >>
�� ���� �� ������� ���� ����� ���������� ��������� �����/����.
3) ���� ���� ����������� � ���������:
* ������� ����� �������� (�� ������ ���� ���� ��� ������������),
* ������������ �������� �����, ������� ����� ��������� �� ������� ������
(����� ����� ������������� - ������� ����� ������ ��� ������� �� �����
��� ����������� ������������� backspace),
* ������������ ������������ ������ �������� ����� �������� enter,
* ��� ������� esc - ���� ����������� � ��������� ����,
* ������, ���� ������������ ����� ��� ����� (���������� � ������ �����
���� ���� �� ������������ � ������� �������, ������������ �� �����).

- �������� ������� (����� ��� �� ����� � ����� main)
- ���������� �� ���������� ���������� �����.

�������������� �������: ��������� ���������� ���������� ����������� ������������� - ����� ����������.

*/

#define KEY_EXIT 27
#define ARROW_KEY 224
#define KEY_SPACE 0

#define KEY_ARROW_RIGHT 77
#define KEY_ARROW_LEFT 75


int main() {
  // ����� �������� ����������� ����
  system("title My Application");

  // �������� ���������� ���� ��� ��������� � �������
  HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

  // ������������� �������������� � �������� �������
  SetConsoleCP(1251);         // ��������� ������� �������� win-cp 1251 � ����� �����
  SetConsoleOutputCP(1251);   // ��������� ������� �������� win-cp 1251 � ����� ������

  /*

  ���� ���� ������� ���������� � ������ ������� � ��� �������� �� ������� Lucida Console. �� ��������� � ������� ����� ����� Consolas.
  ������� � ��������� ������ ���������� ��������� ������������ �����. ��� ����� ���������cmd, ������� � ��������, � �������� ����� �������� Lucida Console,
  �������� �� � �� ���� ��������� ���������.

  */

  // ����� ���� ���� � ������:
  //   ������ �������� - 16-������� ����������� �����,
  //   �������������� ����������� ����� � �������
  //   �������������1-R1-G1-B1-�������������2-R2-G2-B2
  SetConsoleTextAttribute(hStdOut, 2);
  std::cout << "������ ���� � ��� ������ ���.1" << std::endl;
  system("pause");

  //   ������ �������� ����� �������������� �� ������ ������ (������ 1)
  SetConsoleTextAttribute(hStdOut,
    FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);  std::cout << "������ ���� � ��� ������ ���.2" << std::endl;
  system("pause");

  //   ������ �������� ����� �������������� �� ������ ������ (������ 2)
  SetConsoleTextAttribute(hStdOut,
    BACKGROUND_BLUE | BACKGROUND_INTENSITY |
    FOREGROUND_RED | FOREGROUND_GREEN |
    FOREGROUND_BLUE | FOREGROUND_INTENSITY);  std::cout << "������ ���� � ��� ������ ���.3" << std::endl;
  system("pause");

  // ��� ������������ �� �++ ����� � 16 �������, ��������, 5D ������������ 0x5D
  SetConsoleTextAttribute(hStdOut, 0x70);
  std::cout << "������ ���� � ��� ������ ���.4" << std::endl;
  system("pause");


  // ����� ����� ��� ��� ���� ������� � �������
  SetConsoleTextAttribute(hStdOut, BACKGROUND_RED |
    BACKGROUND_GREEN | BACKGROUND_BLUE);
  std::cout << "������ ���� ������� �� �����, ����� �������, ��� ����� �����" << std::endl;
  system("pause");
  system("CLS");

  std::cout << "����� ���� �������" << std::endl;
  system("pause");

  // ������ ����� ���� (������)
  int rez = (2 << 6);   // == 2 * Math.pow(2, 6) == A0 � �����������������
  rez += (2 << 4);      // 10 -> 10000000 -> + 100000 = 10100000
                        // 1) HEX  #0A0, 2)RGB rgb(0, 170, 0)
  SetConsoleTextAttribute(hStdOut, rez);
  std::cout << "������ ���� ������� ����� ��� ������� ����� " << rez << " ��� 10100000 ��� A0" << std::endl << "������� �������...";
  system("pause");

  system("CLS");
  system("pause");

  // �������� ������
  system("CLS");
  std::cout << "� ������ ������� ����� ������ � ������ �������� ���� � ������ �������...";
  COORD cursorPos;
  cursorPos.X = 5;
  cursorPos.Y = 2;
  SetConsoleCursorPosition(hStdOut, cursorPos);
  std::cout << "����� ������ ����� ���" << std::endl << "�� �� ������� �������� �� ����� ������" << std::endl;
  system("pause");

  SetConsoleTextAttribute(hStdOut, 0x70);
  system("CLS");

  // �������� ������� ������
  std::cout << "\n\n";
  for (int IR = 0; IR <= 3; IR++) {
    for (int k = 0; k < 3; k++) {
      for (int GB = 0; GB <= 3; GB++) {
        rez = (IR << 6) + (GB << 4);
        SetConsoleTextAttribute(hStdOut, rez);
        if (k == 1)
          std::cout << "  " << IR << " " << GB << "   ";
        else
          std::cout << "        ";
      }
      std::cout << std::endl;
    }
  }
  std::cout << std::endl;

  // ���������� ����� ���� �������
  SetConsoleTextAttribute(hStdOut, 0x70);
  system("pause");

  // ������ ��������������
  cursorPos = { 5,1 };           // �-�� ������ �������� ����
  for (int i = 0; i < 6; i++) {
    SetConsoleCursorPosition(hStdOut, cursorPos);
    for (int j = 0; j < 6; j++) std::cout << '.';
    cursorPos.Y += 1;
  }
  std::cout << std::endl;
  system("pause");

  system("CLS");

  // �������� �������� ���� ��� ����� ������
  cursorPos = { 5,5 };
  int len = 30;  // ������ ���� �����
  SetConsoleCursorPosition(hStdOut, cursorPos);
  DWORD cWrittenChars;
  FillConsoleOutputCharacter(hStdOut, (TCHAR)'_', len, cursorPos, &cWrittenChars);  // ���������� ������ � �������� ������ ������� �������� ����� ���
  SetConsoleCursorPosition(hStdOut, cursorPos);

  // ���� ������ � �������������� �� ���� insert
  // ����� �� ������� ESC, �� ���� ����� ����� ��������� � ������� �������
  int iKey = 67;              // ������ ��������
  CONSOLE_SCREEN_BUFFER_INFO cbsi;

  while (iKey != KEY_EXIT && len > 0) {
    switch (iKey)
    {
    case KEY_ARROW_LEFT:
      GetConsoleScreenBufferInfo(hStdOut, &cbsi);       // ��������� ���������� � �������� �������� ������ �������
      cursorPos.X = cbsi.dwCursorPosition.X - 1;        // ������� ������� ��������� ������� �� ������ �����
      SetConsoleCursorPosition(hStdOut, cursorPos);
      len++;
      iKey = 67;
      break;
    case KEY_ARROW_RIGHT:
      GetConsoleScreenBufferInfo(hStdOut, &cbsi);
      cursorPos.X = cbsi.dwCursorPosition.X + 1;
      SetConsoleCursorPosition(hStdOut, cursorPos);
      len--;
      iKey = 67;
      break;
    default:
      iKey = _getch();
      if (iKey == KEY_EXIT || iKey == ARROW_KEY || iKey == KEY_SPACE
        || iKey == KEY_ARROW_LEFT || iKey == KEY_ARROW_RIGHT) break;
      std::cout << (char)iKey;    // ������ ���� ��� ������ ������ ���������� ��� � �������
      len--;
      break;
    }
  }

  // ��������� ���������� � ������� ����� � ������ (������ ��������)
  char Chars[31];
  DWORD dwRead;
  ReadConsoleOutputCharacter(hStdOut, Chars, 30, { 5, 5 }, &dwRead);
  Chars[30] = '\0';
  system("CLS");

  std::cout << "Your finale text: "<< Chars << std::endl;
  system("pause");

  return 0;
}
