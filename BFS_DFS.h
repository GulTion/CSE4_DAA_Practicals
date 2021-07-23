#include "./Graph.h"

void bfs(G *g, int src)
{
    //inilization of Queue using linkedList
    L *queue = list_init();

    // initialization of visited array in dynamic way and size of the array is
    // depend upon the number of vertex
    int *visted = (int *)malloc(g->V * sizeof(int));

    // loop for make all value zero in visited array
    for (int i = 0; i < g->V; i++)
        visted[i] = 0;

    // make `src` vertex as visited by put 1 for visited vertex
    visted[src] = 1;
    // after visited, just put in the Queue
    push_back(queue, src);

    // run the loop till queue size got 0 or queue got empty
    while (queue->size)
    {   
        // a temparary variable that store the poped value from the queue
        int t = pop_front(queue);
        printf("%d ", t);
        N * tmp = g->list[t].head;
        while (tmp != NULL)
        {

            int node = tmp->data;

            if (!visted[node])
            {
                visted[node] = 1;
                push_back(queue, node);
            }
            tmp = tmp->next;
        }
    }
    free(queue);
    free(visted);
}

void dfs_handler(G *g, int src, int *visited)
{
    visited[src] = 1;
    printf("%d ", src);
    N * _p=g->list[src].head;
    while (_p != NULL)
    {
        // int node = pop_front(&g->list[src]);
        int node = _p->data;
        if (!visited[node])
            dfs_handler(g, node, visited);
        _p = _p->next;
    }
}

void dfs(G *g, int src)
{
    int *visited = (int *)malloc(g->V * sizeof(int));
    
    for (int i = 0; i < g->V; i++) visited[i] = 0;

    dfs_handler(g, src, visited);
    free(visited);
}
