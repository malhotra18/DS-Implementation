#include <iostream>

using namespace std;

struct arrayStack{
  int top;
  int capacity;
  int *arr;
};

arrayStack* createStack(int n){
  arrayStack *st = new arrayStack();
  st-> capacity = n;
  st->top = -1;
  st->arr = new int[st->capacity];
  return st;
}

int isEmpty(arrayStack *st){
  return (st->top == -1);
}

int isFull(arrayStack *st){
  return (st->top == st->capacity-1);
}

void doubleSize(arrayStack *st){
  st-> capacity *= 2;
  int *newArr = new int[st->capacity];
  copy(st->arr, st->arr + st->capacity, newArr);
  delete[] st->arr;
  st->arr = newArr;
}

void push(arrayStack *st, int x){
  if(isFull(st))
    doubleSize(st);
  st->arr[++st->top] = x;
}

int pop(arrayStack *st){
  if(isEmpty(st))
    return -1;
  return st->arr[st->top--];
}

int main(){
  arrayStack *st = createStack(2);
  cout<<"created stack of size "<<st->capacity <<endl;
  cout<<isEmpty(st)<<endl;
  push(st, 1);
  push(st, 2);
  push(st, 3);
  while(!isEmpty(st)){
    cout<<pop(st)<<endl;
  }
  cout<<"ho gya"<<endl;
  return 0;
}
