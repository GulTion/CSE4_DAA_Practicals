#include "./JobSequencingGreedy.h"

int main()
{
    int n = 5;
    T table = {{1, 2, 100, 0}, {2, 1, 19 0}, {3, 2, 27, 0}, {4, 1, 25, 0}, { 5, 3, 15, 0 }};
    // JobID, DeadLine, Profit, ignore
    printf("Jobs for Max Profit is :"); jobSequencing(&table, n)
}