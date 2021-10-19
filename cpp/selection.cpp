
// unsorted

#include <stdio.h>
#include <iostream>

using namespace std;

void printArray(int A[], int m){

   for (int i=0; i <m; i++)
      cout << A[i]<< " ";
   cout <<"\n";


}

void swap (int *p, int *q) {
   int t = *p;
   *p = *q;
   *q = t;
}

void selectionSort(int A[], int n){

  for (int i = 0; i < n; i++){
     int smallest = i;
     for (int j = i+1; j < n;j++){
        if (A[j] < A[i])
        	smallest= j;
     }
  
    swap(A[i], A[smallest]);
  }

  printArray(A,n);
}

int main(){

	int A[] = {1,7,6,7,8,4};

	int sizeA = sizeof(A)/ sizeof(A[0]);
	printArray(A, sizeA);
	
	selectionSort(A,sizeA);
        return 0;
}
