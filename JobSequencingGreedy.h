#include <stdio.h>
#include 
#include "./QuickSort.h"

#define new(type, size) (type *)malloc(sizeof(type)*size);
#define loop(i) for (int i = 0; i < n; i++)

void jobSequencing(T *table, int n)
{
    QuickSort(table, 0, n, 3, 2);

    int * result = new(int, n);
    int * slot = new (int, n);

    loop(i){
        slot[i] = 0;
        result[i] = 0;
    }

    loop(i)
    {
        // Find a free slot for this job (Note that we start
        // from the last possible slot)
        for (int j = min(n, arr[i].dead) - 1; j >= 0; j--)
        {
            // Free slot found
            if (slot[j] == false)
            {
                result[j] = i;  // Add this job to result
                slot[j] = true; // Make this slot occupied
                break;
            }
        }
    }


    loop(i)
        if (slot[i])
            cout << arr[result[i]].id << " ";
}