#include "./topoloicalSorting.h"
#define add(u, v) add_edge(g, u, v, 1)

int main()
{
    G *g = graph_init(8);

    add(7, 5);
    add(7, 6);
    add(5, 4);
    add(6, 4);
    add(2, 1);
    add(3, 1);
    add(1, 0);
    add(6, 3);
    add(5, 2);

    graph_print(g);

    printf("\ntopologicalSort: ");

    topologicalSorting(g);
    // O(V + E)
    return 0;
}
