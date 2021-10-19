#include <stdio.h>
#include <iostream>

using namespace std;

void printArray(int A[], int m) {
   for (int i= 0; i <m; i++)
   	cout << A[i] << " ";
   cout << "\n";
}


void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int A[], int m, int i){
   
   int largest = i;
   int left = 2*i+1;
   int right = 2*i+2;
   
   if ( left < m && A[left] > A[largest])
       largest = left;
   
   if (right < m && A[right] > A[largest])
        largest = right;
        
    if (i != largest){
       swap(A[i], A[largest]);
       heapify(A, m, largest);
    }
        

}


void heapsort(int A[], int m) {

  for(int i = m/2; i >=0; i--)
  	heapify(A, m, i);
 
 for(int i = m-1; i >0; i--){
	swap(A[i], A[0]);
  	heapify(A, i, 0);
  	}
  	
  	
}


int main(){
 int A[] = {4,3,5,6,7,2,2,1,4,5,6};
 int m = sizeof(A)/ sizeof(A[0]);
 printArray(A,m);
 heapsort(A,m);
 printArray(A,m);
 
}
