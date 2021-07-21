#include "./FKnapscak.h"

int main(){
    double weight[6] = {1,2,3,4,5,6};
    double profit[6] = {7,8,9,10,11,12};
    int sizeOfItems = 6;
    int sizeOfBag = 5;
    printf("MaxProfit: %4.3f",maxProfitFKnapsack(weight, profit, sizeOfItems, sizeOfBag));
    return 0; 
}