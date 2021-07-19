#include<stdlib.h>
#include<stdio.h>

#include "./QuickSort.h"


double maxProfitFKnapsack(double *weight, double *profit, int itemSize, int bagSize){
    double * perWeightProfit = (double*)malloc(itemSize*sizeof(double));
    T *table = (T*)malloc(sizeof(T));

    table->first = weight;
    table->second=profit;
    table->third = perWeightProfit;

    for(int j=0;j<itemSize;j++)
            table->third[j]=profit[j]/weight[j];


    QuickSort(table, 0,itemSize,3,2);

    //PrintTable
    for(int i=0;i<3;i++){
        for(int j=0;j<itemSize;j++)
            printf("%3.1f ",selector(table, i)[j]);
        printf("\n");
    }
    // while()
        

    free(table);
    free(perWeightProfit);
}