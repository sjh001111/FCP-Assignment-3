#include<stdio.h>

int find(int sorted_dataset[] , int length_of_array, int search) {
    int first, last, middle; //에러 , count;
    //에러 count = 0; 
    first = 0;
    last = length_of_array - 1;
    middle = (first+last)/2;
    while (first <= last) {
      if (sorted_dataset[middle] < search)
         first = middle + 1;    
      else if (sorted_dataset[middle] == search) {
         printf("%d is present at index %d.\n", search, middle+1);
         return middle+1; // The index of the finding data
      }
      else
        last = middle - 1;
      middle = (first + last)/2;
   }
   if (first > last)
   //에러 printf("Error, Insert the correct number\n", search);
   return 0; 
}
/* main.c에 이미 메인 함수 있어서 여기 또 넣으면 중복됨
int main() {
    
    int sorted_dataset[] = { 1,2,3,4,5,6,7,8,9,10};  //should be the dataset
    int length_of_array = sizeof(sorted_dataset) / sizeof(sorted_dataset[0]);
    int search = 3; // 이거는 유저한테 몇번 ID찾을건지 얻는거 What data are we going to find
    find(sorted_dataset, length_of_array, search); // Returns the index number of where the data is.
    return 0;
}
*/