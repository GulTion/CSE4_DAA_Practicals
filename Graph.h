#include "./LinkedList.h"
typedef struct Graph G;

#define loop(n) for (int i = 0; i < n; ++i)
#define new(type, size) (type *)malloc(sizeof(type)*size);

struct Graph
{
    int V;   // size
    int E;
    L *list; // Array type linked list
};

G *graph_init(int V)
{
    // asking for the for the space
    G *g = new(G, 1);

    g->V = V;

    g->list = new(L, V);

    loop(V)
    {
        g->list[i].head = g->list[i].tail = NULL;
        g->list[i].size = 0;
    }

    return g;
}
void add_edge_weight(G *g, int u, int v,int weight, int dir){
     if (g->V >= u && g->V >= v)
    {
        g->E++;
        push_back_data(&g->list[u], v, weight);
        if (!dir)
            push_back_data(&g->list[v], u, weight);
    }
    else
        printf("Invalid Edge\n");
}

void add_edge(G *g, int u, int v, int dir)
{
    add_edge_weight(g, u,v,0,dir);
}



void graph_print(G *g)
{

    loop(g->V)
    {
        printf("%d : ", i);
        print_linkedlist(&g->list[i]);
    }
}

int *indegreeCalculator(G *g)
{
    int *indegree = new(int, g->V);

    loop(g->V) indegree[i] = 0;

    loop(g->V)
    {
        N *p = g->list[i].head;
        while (p != NULL)
        {
            indegree[p->data]++;
            p = p->next;
        }
    }
    return indegree;
}