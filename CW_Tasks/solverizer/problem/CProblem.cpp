#include "CProblem.h"
using namespace std;

void CProblem::sort(sortType type) {
  if (type == bubble) {
      BubbleSort BS;
      BS.sort(massive, size);
  }
  else if (type == counting) {
      CountingSort CS;
      CS.sort(massive, size);
  }
  else if (type == quick) {
      QuickSort QS;
      QS.sort(massive, size);
  }
  else if (type == merge) {
      MergeSort MS;
      MS.sort(massive, size);
  }
}

void CProblem::print() {
  cout << "\t";
  for (int i = 0; i < size; i++) {
      cout << massive[i] << " ";
  }
}
