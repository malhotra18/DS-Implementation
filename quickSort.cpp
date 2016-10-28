#include <iostream>
using namespace std;

int partition(int *arr, int low, int high){
  int pivot = arr[high];
  int i = low-1;
  int temp;
  for(int j=low;j<=high-1;j++){
    if(arr[j]<=pivot){
      i++;
      temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
    }
  }
  i++;
  // temp = arr[i];
  arr[high] = arr[i];
  arr[i] = pivot;
  return i;
}

void quickSort(int *arr, int low, int high){
  if(low<high){
    int pi = partition(arr, low, high);
    quickSort(arr, low, pi-1);
    quickSort(arr, pi+1, high);
  }
}

int main(){
  // int arr[10] = {4,5,2,9,5,6,2,8,9,0};
  int n = 10;
  int *arr = new int[n];
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  quickSort(arr,0, n-1);
  cout<<"starting"<<endl;
  for(int i=0;i<10;i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
  return 0;
}
