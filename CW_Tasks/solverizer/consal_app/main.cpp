#include <iostream>
#include <string>
#include "CProblem.h"
using namespace std;

int main() {
  string massage;
  int* mass;
  int size;
  int SortVar;
 bool isWork = true;

  cout << "Here's the array we're gonna sort:" << endl << "\n\t";
  size = 10 + rand() % 11;
  mass = new int[size];
  for (int i = 0; i < size; i++) {
    mass[i] = rand() % 101;
    cout << mass[i] << " ";
  }
  cout << endl;

  CProblem problem(mass, size);

  cout << "\nInput the variant of the sort:" << endl
      << "\t1) Bubble sort" << endl
      << "\t2) Counting sort" << endl
      << "\t3) Quick sort" << endl
      << "\t4) Merge sort" << endl
      << "\t5) To show the menu" << endl
      << "\t0) To exit" << endl;

  while (isWork) {
      cout << "\nInput : ";
      cin >> SortVar;
      switch (SortVar) {
      case 0:
          isWork = false;
          break;
      case 1:
          cout << "\nBubble sort : ";
          problem.sort(bubble);
          problem.print();
          cout << endl;
          break;
      case 2:
          cout << "\nCounting sort :";
          problem.sort(counting);
          problem.print();
          cout << endl;
          break;
      case 3:
          cout << "\nQuick sort : ";
          problem.sort(quick);
          problem.print();
          cout << endl;
          break;
      case 4:
          cout << "\nMerge sort : ";
          problem.sort(merge);
          problem.print();
          cout << endl;
          break;
      case 5: 
          cout << "\nInput the variant of the sort:" << endl
              << "\t1) Bubble sort" << endl
              << "\t2) Counting sort" << endl
              << "\t3) Quick sort" << endl
              << "\t4) Merge sort" << endl
              << "\t5) To show the menu" << endl
              << "\t0) To exit" << endl;
          break;
      default:
          cout << "\nError: error in the input, try again, please." << endl;
          break;
      }
  }

  system("cls");
  cout << "\n\tGoodbye!\n" << endl;
  system("pause");
  return 0;
}
