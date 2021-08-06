
#include <stdio.h>
#include <stdlib.h>
typedef struct Edge E;
#define loop(i, n) for (int i = 0; i < n; i++)
#define new(type, size) (type *)malloc(sizeof(type) * size);

struct Edge
{
    int weight;
    int u;
    int v;
};

void swap(E *x, E *y)
{
    E t = *x;
    *x = *y;
    *y = t;
}
int Partition(E *Graph, int startingIndex, int endingIndex)
{
    E pivit = Graph[endingIndex];
    int i = startingIndex - 1;
    for (int j = startingIndex; j <= endingIndex - 1; j++) 
        if (Graph[j].weight <= pivit.weight) 
            swap(&Graph[++i], &Graph[j]);

    swap(&Graph[i + 1], &Graph[endingIndex]);
    return i + 1;
}
void QuickSort(E *Graph, int startingIndex, int endingIndex)
{
    if (startingIndex < endingIndex)
    {
        int pivitIndex = Partition(Graph, startingIndex, endingIndex);
        QuickSort(Graph, startingIndex, pivitIndex - 1);
        QuickSort(Graph, pivitIndex + 1, endingIndex);
    }
}


int Find(int i, int *parent)
{
    if (parent[i] == -1)
        return i;
        
    return Find(parent[i], parent);
}


void Union(int u, int v, int *parent)
{
    int s1 = Find(u, parent);
    int s2 = Find(v, parent);
    if (s1 != s2)
    {
        parent[s2] = s1;
    }
}


void Sort(E *Graph, int edgeSize)
{
    QuickSort(Graph, 0, edgeSize - 1);
}

int KruskalMST(E *Graph, int edgeSize)
{
    int *parent = new (int, edgeSize); // number edges
    int minCost = 0;

    // as per the concept of DSU 
    loop(i, edgeSize) parent[i] = -1;

    // Quick nlogn
    Sort(Graph, edgeSize);


    loop(i, edgeSize)
    {
        int u = Graph[i].u, v = Graph[i].v, weight = Graph[i].weight;

        if (Find(u, parent) != Find(v, parent))
        {
            minCost += weight;
            Union(u, v, parent);
            printf("%d-[%d]-%d\n", u,weight,v);
        }
    }


    return minCost;
}

int main()
{

    E Graph[14] = {
        {4, 0, 1}, {8, 0, 7}, {11, 1, 7}, {8, 1, 2},
         {1, 7, 6}, {7, 7, 8}, {6, 8, 6}, {2, 2, 8},
          {7, 2, 3}, {2, 6, 5}, {14, 3, 5}, {4, 2, 5},
           {9, 3, 4}, {10, 4, 5}};

    int minCost = KruskalMST(Graph, 14);// bhai sorted edge

    printf("MINCOST :%d ", minCost);
    return minCost;
}