#include <stdio.h>
#include <iostream>

using namespace std;

// unsorted


void printArray(int A[], int n){
   for (int i = 0; i < n; i++)
   	cout << A[i] << " ";
   cout << "\n";
}


void insertionsort(int A[], int n)
{

   for (int i = 1; i <n; i++){
      int j = i -1;
      int key = A[i];      
      while (j >=0 && A[j] > key){
         A[j+1] =A[j];      	
          j--;  
           printArray(A,n);    
      }
      A[j+1] = key;
      printArray(A,n);
   }

    printArray(A,n);
}

void insertionsortV(int A[], int n)
{

   for (int i = 0; i <n; i++){
      int j = i +1;
      int key = A[j];      
      while (j >0 && A[j-1] > key){
         A[j] =A[j-1];      	
          j--;  
           printArray(A,n);    
      }
      A[j] = key;
      printArray(A,n);
   }

    printArray(A,n);
}

int main(){
   int A[] = {2,3,1,8,5,2};
   
   int n = sizeof(A)/ sizeof(A[0]);
   
   printArray(A,n);
   
   cout << "Insertion sort correct \n";
   insertionsort(A,n);
   
   int B[] = {2,3,1,8,5,2};
   
   cout << "Insertion sort tried \n";
   insertionsortV(B,n);
   
   return 1;
   

}
