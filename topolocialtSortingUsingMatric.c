#include <stdio.h>

int main()
{
    int i, j, k, n, a[10][10], indeg[10], visited[10], count = 0;

    // printf("Enter the no of vertices:\n");
    // scanf("%d",&n);

    // printf("Enter the adjacency matrix:\n");
    // for(i=0;i<n;i++){
    // printf("Enter row %d\n",i+1);
    // for(j=0;j<n;j++)
    // scanf("%d",&a[i][j]);
    // }

    n = 5;
    a[0][0] = 0;
    a[1][0] = 0;
    a[2][0] = 0;
    a[0][1] = 1;
    a[1][1] = 0;
    a[2][1] = 0;
    a[0][2] = 1;
    a[1][2] = 0;
    a[0][3] = 1;
    a[1][3] = 1;
    a[0][4] = 0;
    a[1][4] = 0;

    a[2][2] = 0;
    a[2][3] = 0;
    a[2][4] = 1;

    a[3][0] = 0;
    a[3][1] = 0;
    a[3][2] = 0;
    a[3][3] = 0;
    a[3][4] = 1;

    a[4][0] = 0;
    a[4][1] = 0;
    a[4][2] = 0;
    a[4][3] = 0;
    a[4][4] = 0;

    // initilaztion for making random value to 0
    for (i = 0; i < n; i++)
    {
        indeg[i] = 0;
        visited[i] = 0;
    }

    // indegree calculate
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            indeg[i] = indeg[i] + a[j][i];

    printf("\nThe topological order is:");

    while (count < n)
    {
        for (k = 0; k < n; k++)
        {
            if ((indeg[k] == 0) && (visited[k] == 0))
            {
                printf("%d ", (k));
                visited[k] = 1;
            }

            // Check for the current edge and remove it
            // then recalculate the indegree
            for (i = 0; i < n; i++)
            {
                if (a[i][k] == 1)
                    indeg[k]--;
            }
        }

        count++;
    }

    // O(n^3)

    return 0;
}