#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100

// Function to generate a sorted array
void generateSortedArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = i + 1;
    }
}

// Function to generate a randomly shuffled array
void generateRandomArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 1000; // You can adjust the range as needed
    }
}

// Function to generate a sorted array in descending order
void generateDescendingArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = size - i;
    }
}

// Function to perform Insertion Sort and count iterations
void insertionSort(int arr[], int n, int *iterations)
{
    *iterations = 0;

    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        (*iterations)++;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
            (*iterations)++;
        }

        arr[j + 1] = key;
    }
}

int main()
{
    int numbersBest[SIZE], numbersAverage[SIZE], numbersWorst[SIZE];
    int iterationsBest, iterationsAverage, iterationsWorst;

    srand(time(NULL));

    // Best Case: Already sorted array
    generateSortedArray(numbersBest, SIZE);
    insertionSort(numbersBest, SIZE, &iterationsBest);
    printf("Insertion Sort - Best Case: %d iterations\n", iterationsBest);

    // Average Case: Randomly shuffled array
    generateRandomArray(numbersAverage, SIZE);
    insertionSort(numbersAverage, SIZE, &iterationsAverage);
    printf("Insertion Sort - Average Case: %d iterations\n", iterationsAverage);

    // Worst Case: Sorted in descending order
    generateDescendingArray(numbersWorst, SIZE);
    insertionSort(numbersWorst, SIZE, &iterationsWorst);
    printf("Insertion Sort - Worst Case: %d iterations\n", iterationsWorst);

    return 0;
}
