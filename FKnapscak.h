#include<stdlib.h>
#include<stdio.h>

#include "./QuickSort.h"


double maxProfitFKnapsack(double *weight, double *profit, int itemSize, int bagSize){
    int currentWeight = 0;
    double maxProfit = 0;
    // allocation for the Array of size item size for the store result profit/weight for each items
    double * perWeightProfit = (double*)malloc(itemSize*sizeof(double));

    //allcation for a Table
    T *table = (T*)malloc(sizeof(T));

    // initalization the rows in table
    table->first = weight;
    table->second=profit;
    table->third = perWeightProfit;

    // Performing the calculation and store back result in the table
    for(int j=0;j<itemSize;j++)
            table->third[j]=profit[j]/weight[j];

    //Sort the table as per the row third
    QuickSort(table, 0,itemSize,3,2);
    
    
    int i;
    // Loop that fills the item in the bag in Greedy Approch, loop will stop if items are unable to fill in the bag due to capacity of the bag
   for(i=itemSize-1;i>=0;--i){
       //add the item weight in the `currentWeight`
       currentWeight += table->first[i];
       // 
       if(currentWeight<=bagSize){
           maxProfit += table->second[i];
       }else{
           currentWeight -= table->first[i];
           break;
       }
   }

//    printf("%4.1f %d\n", maxProfit, currentWeight);
   maxProfit += (bagSize - currentWeight)*table->third[i];
   currentWeight += (bagSize - currentWeight);
//    printf("%4.1f %d\n", maxProfit, currentWeight);
    



    // while()
        

    free(table);
    free(perWeightProfit);

    return maxProfit;
}