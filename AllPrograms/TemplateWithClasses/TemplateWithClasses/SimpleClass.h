#ifndef SIMPLECLASS_H
#define SIMPLECLASS_H

#include <iostream>
#include <string>
#include "Types.h"

// ����� ����� ��������� �������� ������

class NameClass {
  // ����
  Type example;
public:
  // ������������ (�� ���������, �������������, �����������)
  NameClass() {};
  NameClass(Type _example /*<������ ����������, ��������������� ������ ����� ������>*/) {};
  NameClass(const NameClass&) {};

  // ���������� (���������, ���� � ������������� ����������� ������������ ��������� ������)
  ~NameClass() {};

  // ����� �� �����
  void show() { std::cout << example; };

  // ����������� �� ������ ������ (����� ������� ����� ������ private,
  // ����� ������ �� �� ������������ ������ ������, ��� ����� ����, ��������, ��������� ������)
};

#endif // SIMPLECLASS_H
