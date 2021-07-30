#include "./FKnapscak.h"

int main(){
    double weight[6] = { 7,  8,  6,  9,  2,  5},
    //                   0,  1,  2,  3,  4,  5
           profit[6] = {11, 12, 13, 14, 15, 16};
           
    int sizeOfItems = 6,sizeOfBag = 20;
    printf("\nMaxProfit: %4.3f",maxProfitFKnapsack( 
        weight, profit, sizeOfItems, sizeOfBag));
    return 0; 
    // O(nlogn) time
    // O(n) space
}