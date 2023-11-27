// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i){
    int index = i;
    int left = 2*i;
    int right = 2*i + 1;
    int largest = index;
    
    if(left < n && arr[largest] < arr[left]){
        largest = left;
    }
    if(right < n && arr[largest] < arr[right]){
        largest = right;
    }
    if(index != largest){
        swap(arr[index], arr[largest]);
        index = largest;
        heapify(arr, n, index);
    }
}
void buildHeap(int arr[], int n){
  for(int i=n/2; i>0; i--){
    heapify(arr, n, i);
  }
}
int main() {
    // Write C++ code here
    int arr[] = {-1, 12, 15, 13, 11, 14};
    int n = 6;
    buildHeap(arr, n);

    for(int i=0; i<n; i++){
      cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}