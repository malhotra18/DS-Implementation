#include <iostream>
using namespace std;

struct arrayQueue{
  int front, rear;
  int capacity;
  int *arr;
};

arrayQueue *createQueue(int size){
  arrayQueue *q = new arrayQueue();
  q->capacity = size;
  q->front = -1;
  q->rear = -1;
  q->arr = new int[size];
  return q;
}

int isEmpty(arrayQueue *q){
  return (q->front == -1);
}

int isFull(arrayQueue *q){
  return ((q->rear+1) % q->capacity==q->front);
}

int size(arrayQueue *q){
  return (q->capacity - q->front + q->rear + 1)%q->capacity;
}

void resize(arrayQueue *q){
  int size = q->capacity;
  q->capacity = q->capacity*2;
  int *newArr = new int[q->capacity];
  copy(q->arr, q->arr+q->capacity, newArr);
  delete[] q->arr;
  q->arr = newArr;
  if(q->front>q->rear){
    for(int i=0;i<q->front;i++){
      q->arr[i+size] = q->arr[i];

    }
    q->rear = q->rear+size;
  }
}

void enqueue(arrayQueue *q, int data){
  if(isFull(q))
    resize(q);
  q->rear = (q->rear+1)%q->capacity;
  q->arr[q->rear] = data;
  if(q->front == -1){
    q->front = q->rear;
  }
}



int dequeue(arrayQueue *q){
  int data = 0;
  if(isEmpty(q)){
    cout<<"empty"<<endl;
    return -1;
  }else{
    data = q->arr[q->front];
    if(q->front==q->rear){
      q->front = -1;
      q->rear = -1;
    }else{
      q->front = (q->front+1)%q->capacity;
    }
  }
  return data;
}

int main(){
  cout<<"starting"<<endl;
  arrayQueue *q =  createQueue(2);
  enqueue(q, 4);
  enqueue(q, 5);
  enqueue(q, 6);
  enqueue(q, 7);
  while(!isEmpty(q)){
    cout<<dequeue(q)<<endl;
  }
  cout<<"ho gya"<<endl;
  return 0;
}
