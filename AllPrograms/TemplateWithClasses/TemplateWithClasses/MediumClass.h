#ifndef MEDIUMCLASS_H
#define MEDIUMCLASS_H

#include <iostream>
#include <string>
#include "Types.h"

// ������ ������ � ������� ������ �����

class ClassTemplate {
  // ���� ������ - �� ��������� ������, ����� ���� ������� � ����� ������
  // (������ ���� ������, �������, ������ ��������� � ������)
  int field1;
  double field2;
  std::string field3;
  // ...
  int* fieldN;
  int fieldN_size;

public:
  // ����������� �� ���������
  ClassTemplate();
  // ����������� �������������
  ClassTemplate(int _field1, double _field2, std::string _field3, /*...*/ int* _fieldN, int _fieldN_size);
  // ����������� �����������
  ClassTemplate(const ClassTemplate& current);

  // ����������
  ~ClassTemplate();

  // ������
  void print();
};

#endif // MEDIUMCLASS_H
