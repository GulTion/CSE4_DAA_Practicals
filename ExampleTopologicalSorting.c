#include "./topoloicalSorting.h"

int main(){
    G *g = graph_init(8);

    add_edge(g, 7, 5, 1);   add_edge(g, 7, 6, 1);
    add_edge(g, 5, 4, 1);   add_edge(g, 6, 4, 1);
    add_edge(g, 2, 1, 1);   add_edge(g, 3, 1, 1);
    add_edge(g, 1, 0, 1);   add_edge(g, 6, 3, 1);   
    add_edge(g, 5, 2, 1);  

    // graph_print(g);

    printf("\n\ntopologicalSort: ");
    topologicalSorting(g);

    return 0;

}

