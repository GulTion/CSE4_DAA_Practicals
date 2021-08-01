#include "./LinkedList.h"
typedef struct Graph G;

struct Graph
{
    int V; // size
    L *list; // Array type linked list
};

G *graph_init(int V)
{
    // asking for the for the space
    G *g = (G *)malloc(sizeof(G));

    g->V = V;

    g->list = (L *)malloc(V * sizeof(L)); // | | | | | | | |
    
    for (int i = 0; i < V; i++)
    {
        g->list[i].head = g->list[i].tail = NULL;
        g->list[i].size = 0;
    }

    return g;
}

void add_edge(G *g, int u, int v, int dir)
{
    // dir 0 = undirected edge
    // dir 1 = directed edge
    if (g->V >= u && g->V >= v)
    {
        push_back(&g->list[u], v);
        if (!dir)
            push_back(&g->list[v], u);
    }
    else
        printf("Invalid Edge\n");
}

void graph_print(G *g)
{

    for (int i = 0; i < g->V; i++)
    {
        printf("%d->", i);
        print_linkedlist(&g->list[i]);
    }
}

int * indegreeCalculator(G *g){
    int * indegree = (int *)malloc(sizeof(int)*g->V);

    for(int i=0;i<g->V;i++){
        indegree[i] = 0;

        N * p = g->list[i].head;
        while(p!=NULL){
            indegree[p->data]++;
            p=p->next;
        }
    }

    return indegree;
}