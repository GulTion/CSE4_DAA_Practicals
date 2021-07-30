#include <stdlib.h>
#include <stdio.h>

#include "./QuickSort.h"

double maxProfitFKnapsack(
    double *weight,
    double *profit,
    int itemSize,
    int bagSize)
{

    int currentWeight = 0;
    double maxProfit = 0;
    // allocation for the Array of size item size for the store result profit/weight for each items
    double *perWeightProfit = (double *)malloc(itemSize * sizeof(double));
    double *itemsIndex = (double *)malloc(itemSize * sizeof(double));

    //allcation for a Table
    T *table = (T *)malloc(sizeof(T));

    // initalization the rows in table
    table->first = weight;
    table->second = profit;
    table->third = perWeightProfit; // blank p/w array
    table->fourth = itemsIndex;

    // Performing the calculation and store back result in the table
    for (int j = 0; j < itemSize; j++)
    {
        table->third[j] = profit[j] / weight[j];
        table->fourth[j] = j;
    } // filling of p/w array

    //Sort the table as per the row third
    QuickSort(table, 0, itemSize, 4, 2);
    // QuickSort(
    //     Table<which table want to sort>,
    //     startingIndexToSort,
    //     EndingIndexToSort,
    //     NumbersOfRowInTable,
    //     WhichTableWantToSort)

    int i;
    printf("Items:");
    // Loop that fills the item in the bag in Greedy Approch, loop will stop if items are unable to fill in the bag due to capacity of the bag
    for (i = itemSize - 1; i >= 0; --i)
    {
        //add the item weight in the `currentWeight`
        currentWeight += table->first[i];
        // currentWeight = currentWeight + table->first[i];
        //
        if (currentWeight <= bagSize)
        { //check for the bag, if some space then fill it else remove the item
            maxProfit += table->second[i];
            printf("%1.0f ", table->fourth[i]);
        }
        else
        {
            currentWeight -= table->first[i];

            break;
        }
    }

    int restWeight = (bagSize - currentWeight);

    if (restWeight)
        printf("%1.0f", table->fourth[i]);

    maxProfit += restWeight * table->third[i];
    currentWeight += restWeight;

    free(table);
    free(perWeightProfit);

    return maxProfit;
}