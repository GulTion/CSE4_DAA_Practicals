#include <stdio.h>
#define loop(l) for (int l = 0; l < n; l++)

int main()
{
    int i, j, k, n, a[10][10], indeg[10], visited[10], count = 0;
    
    count = n = 5;
    a[0][0] = a[1][0] = a[2][0] = a[1][1] = a[2][1] = a[1][2] = 
    a[0][4] = a[1][4] = a[2][2] = a[2][3] = a[3][0] = a[3][1] = 
    a[3][2] = a[3][3] = a[4][0] = a[4][1] = a[4][2] = a[4][3] = 
    a[4][4] = 0;

    a[0][1] = a[0][2] = a[0][3] = a[1][3] = a[2][4] = a[3][4] = 1;


    loop(i) indeg[i] = visited[i] = 0; loop(i) loop(j) indeg[i] += a[j][i];

    printf("\nThe topological order is:");

    while (--count) loop(k)
        {
            if ((!(indeg[k] || visited[k]))?(visited[k]=1):0) printf("%d ", (k));
            loop(i) if (a[i][k]) indeg[k]--;
        }


    // O(n^3)

    return 0;
}