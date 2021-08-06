#include <stdio.h>
#include <stdlib.h>
#include "./Graph.h"

typedef struct Edge E;
typedef struct MinHeap H;

#define add(u,v,w) add_edge_weight(g, u, v, w, 0)



struct Edge{
    int vertex;
    int weight;
};
struct MinHeap{
    E * arr;
    int size;
};

void swap(E *x, E *y){
    E t = *x;
    *x = *y;
    *y = t;
}

H * Heap_init(int size){
    H * heap = new(H, 1);
    heap->arr = new(E, size+1);
    heap->size=0;
    return heap;
}

void addHeap(H *h, E  e){
    h->arr[++h->size] = e;
    int i = h->size;
    while(i>=1){
        if(h->arr[i/2].weight>h->arr[i].weight)
            swap(h->arr[i/2], h->arr[i]);
        else break;
        i/=2;
    }
}

void removeHeap(H *h){
    swap(h->arr[1], h->arr[h->size]);
    int i = --h->size;
    while(i<=h->size){
        if(h->arr[2*i].weight< h->arr[i].weight){
            swap(h->arr[2*i], h->arr[i]);
            i = 2*i;
            continue;
        }
        else if(h->arr[2*i+1].weight< h->arr[i].nweight){
            swap(h->arr[2*i+1], h->arr[i]);
            i = 2*i+1;
            continue;
        }else{
            break;
        }
    }
}

E* topHeap(H *h){
    E *top = h->arr[0];
    return top;
}

int PrimsMST(G *g){
    H * heap = Heap_init(g->E);
    int * visited = new(int, g->V);
    int minCost = 0;
    
    for(int i=0;i<g->V;i++) visited[i]=0;

    N *top = g->list[0].head;
    E starter = {top->data, top->data2};
    addHeap(heap, starter);

    while (heap->size)
    {
        E * _top = topHeap(heap);
        removeHeap(heap);

        int weight = _top->weight;
        int vertex = _top->vertex;

        if(visited[vertex]) continue;

        
        minCost +=weight;
    
        visited[vertex] = 1;

        N * node = g->list[vertex].head;

        while(node->next!=NULL){
            if(!visited[node->data]){
                E _edge = {node->data, node->data2};
                printf("%d-[%d]->%d",vertex, node->data2, node->data );
                addHeap(heap, _edge);
            } 

            node=  node->next;
        }

    }
    

}

int main(){
    int V = 9;
    G * g = graph_init(V);
    add(0,1,4); add(1,7,11); add(0,7,8);
    add(1,2,8); add(8,6,6);  add(2,8,2);
    add(7,8,7); add(7,6, 1); add(2,3,7);
    add(2,5,4); add(6,5,2); add(3,5,14);
    add(3,4,9); add(4,5,10);

    int minCost = PrimsMST(g);

    printf("%d", 3/2);
    return 0;
}