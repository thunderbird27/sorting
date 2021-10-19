#include <stdio.h>
#include <iostream>


// not sorted
using namespace std;
void printArray(int A[], int n){
   for (int i= 0; i < n; i++)
   	cout << A[i]<< " ";
   cout << "\n";
}


void bubblesort(int A[], int n) {
   
  for (int i = 0; i < n; i++){
    int j = i+1;     
     while (j < n){
       if (A[j] < A[i]) {
		  int outofplace= A[i];
		  A[i] = A[j];  
		  A[j] = outofplace;   
		  printArray(A,n);              
          }
          j++;
          
     }
   
  } 
 
  printArray(A,n);
}

int main(){
   int A[]={5,2,1,3,2,1};
   int n = sizeof(A)/sizeof(A[0]);
   printArray(A,n);   
   bubblesort(A,n);
   
}
