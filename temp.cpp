// g++ -Wall -o yourprog temp.cpp
// ./yourprog

#include <iostream>
using namespace std;

int main() {
  /* code */
  // int** ary = new int*[rowCount];
  // for(int i = 0; i < rowCount; ++i)
  //     ary[i] = new int[colCount];

  cout<<"starting"<<endl;
  int size = 5;
  int *arr = new int[size];
  arr[0] = 1;
  arr[1] = 2;
  arr[2] = 3;
  arr[3] = 0;
  arr[4] = 5;
  int *newArr = new int[10];
  copy(arr, arr+10, newArr);
  delete[] arr;
  arr = newArr;
  cout<<sizeof(*arr)<<endl;
  return 0;
}
