#include<stdio.h>
#include<iostream>

using namespace std;


void printArray(int A[], int m){

   for (int i = 0; i < m; i++)
   	cout << A[i] <<" ";
   cout << "\n";
}

void swap (int *p, int *q) {
   int t = *p;
   *p = *q;
   *q = t;

}

int partition(int A[], int begin, int end) {
  // set last element as the key 
  int pivot = A[end];
  int initial = begin;
  for(int i = begin; i <= end-1; i++){
     if (A[i] < pivot){         
         swap(A[initial], A[i]);
         initial++;
         }
  }
   swap(A[initial], A[end]);
  return initial;
}

int partition_r(int A[], int begin, int end) {
      srand(time(NULL));
     int random = begin + rand() % (end - begin);
 
    // Swap A[random] with A[high]
    swap(A[random], A[end]);
    return partition(A,begin, end);
}

void quick(int A[], int begin, int end) {

        if ( begin < end){            
		int p = partition(A,begin, end);
		quick(A,begin, p-1);
		quick(A,p+1, end);
	}
	
}

int main(){

  int A[] ={1,3,1,5,4,1,4,8,9,2};
  
  int n = sizeof(A)/sizeof(A[0]);
  
  printArray(A,n);
  quick(A,0,n-1);
  
  printArray(A,n);
  
}
