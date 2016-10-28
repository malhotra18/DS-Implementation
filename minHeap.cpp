#include <iostream>
using namespace std;
//min heap

struct heap{
  int *arr;
  int count;
  int capacity;
};

heap *createHeap(int capacity){
  heap *h = new heap();
  h->capacity = capacity;
  h->arr = new int[capacity];
  h->count = 0;
  return h;
}

int isEmpty(heap *h){
  if(h->count==0){
    return 1;
  }else{
    return 0;
  }
}

int getMin(heap *h){
  if(h->count==0){
    return -1;
  }
  return h->arr[0];
}

int leftChild(heap *h, int i){
  int left = 2*i + 1;
  if(left>=h->count){
    return -1;
  }
  return left;
}


int rightChild(heap *h, int i){
  int right = 2*i + 2;
  if(right>=h->count){
    return -1;
  }
  return right;
}

void percolateDown(heap *h, int i){
  int l, r, min, temp;
  l = leftChild(h, i);
  r = rightChild(h, i);
  if(l!=-1 && h->arr[l]<h->arr[i]){
    min = l;
  }else{
    min = i;
  }

  if(r!=-1 && h->arr[r]<h->arr[min]){
    min = r;
  }

  if(min != i){
    temp = h->arr[i];
    h->arr[i] = h->arr[min];
    h->arr[min] = temp;
    percolateDown(h, min);
  }
}

int deleteMin(heap *h){
  int data;
  if(h->count==0){
    return -1;
  }
  data = h->arr[0];
  h->arr[0] = h->arr[h->count - 1];
  h->count--;
  percolateDown(h, 0);
  return data;
}

void resizeHeap(heap *h){
  h->capacity *= 2;
  int *newArr = new int[h->capacity];
  copy(h->arr, h->arr+h->capacity, newArr);
  delete[] h->arr;
  h->arr = newArr;
}

void insert(heap *h, int data){
  cout<<"inserting "<<data<<endl;
  int i;
  if(h->count == h->capacity){
    resizeHeap(h);
  }
  h->count++;
  i = h->count-1;
  while(i>0 && data < h->arr[(i-1)/2]){
    h->arr[i] = h->arr[(i-1)/2];
    i = (i-1)/2;
  }
  h->arr[i] = data;
}

int main(){
  cout<<"starting"<<endl;
  heap *h = createHeap(20);
  insert(h, 10);
  insert(h, 35);
  insert(h, 3);
  insert(h, 5);
  insert(h, 9);
  insert(h, 90);
  insert(h, 20);
  cout<<"lets delete"<<endl;
  while(!isEmpty(h)){

    cout<<deleteMin(h)<<endl;
  }
  cout<<"ho gya"<<endl;
  return 0;
}
