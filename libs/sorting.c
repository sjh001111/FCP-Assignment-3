#include "../main.h"
#include "sorting.h"

#include "../main.h"
#include "searching.h

#include<stdio.h>

//citation <https://www.sanfoundry.com/c-program-implement-radix-sort/>

int getMax(int dataset[], int length_of_array) {
    int max = dataset[0]; //first set the first value as the max
    int i;
     // Go through all the values in the dataset and configure max value
    for(i = 1; i < length_of_array; i++)
        if (dataset[i] > max)
            max = dataset[i];
    return max;
}

void countSort(int dataset[], int length_of_array, int value) {
    int sort_dataset[length_of_array];
    int i, count[10] = { 0 };
    
    
    // Store count of occurrences in count[]
    for (i = 0; i < length_of_array; i++)
        count[(dataset[i] / value) % 10]++;
 
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
        
    // Build the output array
    for (i = length_of_array - 1; i >= 0; i--) {
        sort_dataset[count[(dataset[i] / value) % 10] - 1] = dataset[i];
        count[(dataset[i] / value) % 10]--;
    }
    for (i = 0; i < length_of_array; i++)
        dataset[i] =sort_dataset[i];
}
// Sorts the dataset
void radixsort(int dataset[], int length_of_array) {
    int max = getMax(dataset, length_of_array);
    int value;
    
    for (value = 1; max / value > 0; value *= 10)
        countSort(dataset, length_of_array, value);
}

void show(int dataset[], int length_of_array) {
    int i;
    for (i = 0; i < length_of_array; i++)
        printf("%d ", dataset[i]);
}
//Doesn't work
/*t sortdata(int dataset[]){
  int length_of_array = sizeof(dataset) / sizeof(dataset[0]);
  radixsort(dataset, length_of_array);
  sorted_dataset[] = dataset[];
  return sorted_dataset[]; 
}*/ 

/*int main() {
    int dataset[] = { 16,326,23,21,123,123,125,16,7,87,23,12}; // for 돌려서 우리 array의 몇번째 column만 여기 넣기 ex:chart[i][3]
    int length_of_array = sizeof(dataset) / sizeof(dataset[0]); //means length()
    radixsort(dataset, length_of_array);
    show(dataset, length_of_array);
    return 0;
}
