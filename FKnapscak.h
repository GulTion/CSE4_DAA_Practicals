#include<stdlib.h>
#include<stdio.h>

#include "./QuickSort.h"


double maxProfitFKnapsack(double *weight, double *profit, int itemSize, int bagSize){
    int currentWeight = 0;
    double maxProfit = 0;
    double * perWeightProfit = (double*)malloc(itemSize*sizeof(double));
    T *table = (T*)malloc(sizeof(T));

    table->first = weight;
    table->second=profit;
    table->third = perWeightProfit;

    for(int j=0;j<itemSize;j++)
            table->third[j]=profit[j]/weight[j];


    QuickSort(table, 0,itemSize,3,2);

    //PrintTable
    // for(int i=0;i<3;i++){
    //     for(int j=0;j<itemSize;j++)
    //         printf("%4.1f ",selector(table, i)[j]);
    //     printf("\n");
    // }

    int i;
   for(i=itemSize-1;i>=0;--i){
       
       currentWeight += table->first[i];
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