#include <stdio.h>
#include <stdlib.h>

typedef struct element{
    int data;
    int numSwaps;
}element;


void bubbleSort(int arr[], int n)
{
    int i, j, numSwap = 0;
    element * tempArr = malloc(sizeof(element) * n);
    element temp;

    for(int k = 0; k < n; k++)
    {
        tempArr[k].data = arr[k];
        tempArr[k].numSwaps = 0;
    }

    for (i = 0; i < n-1; i++)
    {
        for (j = 0; j < n-i-1; j++)
        {
            if (tempArr[j].data > tempArr[j+1].data)
            {
                tempArr[j].numSwaps += 1;
                tempArr[j+1].numSwaps += 1;

                temp = tempArr[j];
                tempArr[j] = tempArr[j+1];
                tempArr[j+1] = temp;
                
                numSwap += 1;
            }
        }
    }

    for(int i = 0; i< n; i++)
    {
        printf("%d: %d\n", tempArr[i].data, tempArr[i].numSwaps);
    }

    printf("%d\n", numSwap);

    free(tempArr);
}

void selectionSort(int arr[], int n)
{
    int min_idx, numSwap = 0;
    element *tempArr = malloc(sizeof(element) * n);
    element temp;

    //copy elements from arr to tempArr
    for(int k = 0; k < n; k++)
    {
        tempArr[k].data = arr[k];
        tempArr[k].numSwaps = 0;
    }

    for(int i = 0; i < n-1; i++)
    {
        min_idx = i;

        for (int j = i+1; j < n; j++)
        {
            if (tempArr[j].data < tempArr[min_idx].data)
            {
                min_idx = j;
            }
        }
        tempArr[i].numSwaps++;
        tempArr[min_idx].numSwaps++;

        temp = tempArr[i];
        tempArr[i] = tempArr[min_idx];
        tempArr[min_idx] = temp;

        numSwap++;
    }

    for(int i = 0; i< n; i++)
    {
        printf("%d: %d\n", tempArr[i].data, tempArr[i].numSwaps);
    }

    printf("%d\n", numSwap/2);

    free(tempArr);
}


int main()
{
    int arr1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int arr2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};

    printf("array 1 bubble sort: \n");
    bubbleSort(arr1, 9);
    printf("\n");
    printf("array 2 bubble sort: \n");
    bubbleSort(arr2, 9);
    printf("\n");
    printf("array 1 selection sort: \n");
    selectionSort(arr1, 9);
    printf("\n");
    printf("array 2 selection sort: \n");
    selectionSort(arr2, 9);
    
    return 0;
}