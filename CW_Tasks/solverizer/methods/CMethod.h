#pragma once

enum sortType { bubble, counting, quick, merge };

struct Characteristics {
  int time;
  int comparisonCount;
  int permutationCount;
};

// It's a BASE
class IMethod {
protected:
  Characteristics analysis;
  IMethod() {
    analysis.time = 0;
    analysis.comparisonCount = 0;
    analysis.permutationCount = 0;
  }
public:
  virtual void sort(int* mass, int size) = 0;

  void swap(int* p1, int* p2) {
      int tmp = *p1;
      *p1 = *p2;
      *p2 = tmp;
  }
};

// Derived class
class BubbleSort : IMethod {
public:
  BubbleSort() {};
  void sort(int* mass, int size);
};

// Derived class
class CountingSort : IMethod {
public:
  CountingSort() {};
  void sort(int* mass, int size);
};

// Derived class
class QuickSort : IMethod {
public:
  QuickSort() {};
  void sort(int* mass, int size) {
    qsort(mass, 0, size - 1);
  };

  void qsort(int *mass, int left, int right);
};

// Derived class
class MergeSort : IMethod {
public:
    MergeSort() {};
    void sort(int* mass, int size) {
        Merge(mass, 0, size);
        mergeSort(mass, 0, size - 1);
    };
;
    void Merge(int* arr, int left, int right);
    int mergeSort(int* arr, int left, int right);
};
