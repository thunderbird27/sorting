#include <stdio.h>
#include <iostream>

using namespace std;

void printArray(int A[], int m) {
  for (int i = 0; i < m; i++)
  	cout << A[i]<< " ";
  cout << "\n";

}

void merge(int A[], int begin, int mid, int end) {

    int leftlength = mid+1-begin;
    int rightlength = end-mid;
    
    int *leftArray = new int[leftlength];
    int *rightArray = new int[rightlength];
    
    for (int x = 0; x < leftlength; x++)
        leftArray[x] = A[begin+x];
         
    
    for (int x = 0; x < rightlength; x++) 
        rightArray[x] = A[mid+1+x];
        


    int i = begin;
    int leftindex = 0;
    int rightindex = 0;
    while (leftindex < leftlength && rightindex < rightlength){
       if (leftArray[leftindex] <= rightArray[rightindex]){
           A[i] = leftArray[leftindex];
           leftindex++;           
       }
       else{
           A[i] = rightArray[rightindex];
           rightindex++;           
       }
       i++;
       }
       
       while (leftindex < leftlength){
           A[i] = leftArray[leftindex];
           leftindex++;
           i++;           
       }
       
       while (rightindex < rightlength){
           A[i] = rightArray[rightindex];
           rightindex++;   
           i++;        
       }
    
    
 // printArray(A,i);  

}

void mergenew(int A[],  int const left, int const mid, int const right) {
    // create temporary arrays
    cout <<"Left: " << left << " ,Mid: "<< mid << " ,Right: " << right <<"\n";
    int const leftLength = mid+1-left;
    int const rightLength = right-mid;
    cout <<"Left Length: " << leftLength << " , rightLength: " << rightLength << "\n";
    int *leftArray = new int[leftLength];
    int *rightArray = new int[rightLength];
    
    // copy data to temporary arrays
    for(int x = 0; x < leftLength ; x ++)
        leftArray[x] = A[left+x];
    
    // copy data to temporary arrays
    for(int x = 0; x < rightLength ; x ++)
        rightArray[x] = A[mid+1+x];
        
    cout <<"left array \n";
    printArray(leftArray,leftLength); 
    cout <<"right array \n";
    printArray(rightArray,rightLength); 
    // index of arrays
    int indexLeft = 0;
    int indexRight = 0;
    int indexOriginal = left;
    
    while (indexLeft < leftLength && indexRight < rightLength) {
        if (leftArray[indexLeft] <= rightArray[indexRight]){
            A[indexOriginal] = leftArray[indexLeft];
            indexLeft++;
        }
        else {
            A[indexOriginal] = rightArray[indexRight];
            indexRight++;
        }
        indexOriginal++;
    }
    
    while (indexLeft < leftLength){
        A[indexOriginal] = leftArray[indexLeft];
        indexLeft++;
        indexOriginal++;
    }
    
    while (indexRight < rightLength){
        A[indexOriginal] = rightArray[indexRight];
        indexRight++;
        indexOriginal++;
    }
    
   cout <<"original array \n" ;    
   printArray(A,indexOriginal);     
        

}

void mergeSort(int A[], int begin, int end) {
    
    if (begin>=end)
    	return ;
    auto mid = begin+(end-begin)/2;
    
    mergeSort(A, begin, mid);
    mergeSort(A, mid+1, end);
    
    merge(A, begin, mid, end);


}




int main(){

  int A[] = {5,8,3,5,1,4,7};
  
  int m = sizeof(A)/ sizeof(A[0]);
  
  printArray(A,m);
  
  mergeSort(A,0,m-1);
  
  printArray(A,m);
  
   return 1; 
}
