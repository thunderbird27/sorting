#include<stdio.h>
#include<iostream>

using namespace std;


void printArray(int A[], int m){
  for(int i = 0 ; i <m; i++)
  	cout << A[i]<<" ";
  cout <<"\n";

}



int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}


void countSort(int A[], int m){
  int n = getMax(A,m);
  int count[n+1] = {0};
  for(int i = 0 ; i <m; i++){
        count[A[i]]++;
  	}
  
  printArray(count,n+1);
   //do cummulative
   for(int i = 1 ; i <n+1; i++){
        count[i] = count[i-1]+count[i] ;
  	}
    printArray(count,n+1);
    	
   // shift right
   for (int i = n+1; i >=1; i --) {
       count[i] = count[i-1];
   } 
  count[0] = 0;
  printArray(count,n+1);
  
  int output[m] = {0};
   for (int i = 0; i <m; i++){
       output[count[A[i]]] = A[i];
       count[A[i]]++;
   }
   
   printArray(output,m);
  
}
int main() {

   int A[]={1,2,4,6,9,2,3,4,1,2,9,7};
   
   int m = sizeof(A) / sizeof(A[0]);
   
   printArray(A,m);
   
   countSort(A,m);
   
   
   
}
