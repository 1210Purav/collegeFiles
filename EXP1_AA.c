// Bubble sort code

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define SIZE 100

// function to generate a sorted array

void generateSortedArray(int arr[], int size){
    for (int i = 0; i < size; i++)
    {
       arr[i] = i + 1;
    }
    
}

// function to generate random numbers

void generateRandomNumbers(int arr[], int size){
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 1000;
    }
    
}

// function to generate sorted array in descending order

void generateDescendingArray(int arr[], int size){
    for (int i = 0; i < size; i++)
    {
        arr[i] = size - i;
    }
    
}

// functions to swap two elements

void swap(int *a , int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int n, int *iterations){
    *iterations = 0;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            (*iterations)++;
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
            
        }
        
    }
    
}

int main(){
    int numbersBest[SIZE], numbersAverage[SIZE], numbersWorst[SIZE];
    int iterationsBest, iterationsAverage, iterationsWorst;

    srand(time(NULL));

    // best case
    generateSortedArray(numbersBest, SIZE);
    bubbleSort(numbersBest, SIZE, &iterationsBest);

    printf("Number of iterations for best case: %d\n\n", iterationsBest);

    // Average Case
    generateRandomNumbers(numbersAverage, SIZE);
    bubbleSort(numbersAverage, SIZE, &iterationsAverage);

    printf("Number of iterations for Average case: %d\n\n", iterationsAverage);

    // Worst Case
    generateDescendingArray(numbersWorst, SIZE);
    bubbleSort(numbersWorst, SIZE, &iterationsWorst);

    printf("Number of iterations for Worst case: %d\n\n", iterationsWorst);
    return 0;
}