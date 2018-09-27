#include <stdio.h>

int count = 0;
void topoSortCount(int n, int am[n][n], int z[n], int y[n]) {
    int flag = 0;

    for (int i = 0; i < n; ++i) {
        if (!z[i] && !y[i]) {
            z[i] = 1;

            for (int j = 0; j < n; ++j) 
            {
                if (am[i][j]) 
                {
                    y[j]--;
                }
            }
            topoSortCount(n, am, z, y);

            z[i] = 0;
            for (int k = 0; k < n; ++k) {
                if (am[i][k]) {
                    y[k]++;
                }
            }
            flag = 1;
        }
    }

    if (!flag) {
        count++;
    }
}

void topoSort(int n, int arr[n][n], int visited[n], int inDegree[n]) 
{
    for (int i = 0; i < n; ++i) 
    {
        for (int j = 0; j < n; ++j) 
        {
            if (arr[i][j]) 
            {
                inDegree[j]++;
            }
        }
    }

    topoSortCount(n, arr, visited, inDegree);
}



int main() 
{
    int n, m;
    scanf("%d", &n);

    int am[n][n], z[n], y[n];
    for (int i = 0; i < n; ++i) 
    {
        for (int j = 0; j < n; ++j) 
        {
            am[i][j] = 0;
        }   
        z[i] = y[i] = 0;
    }

    scanf("%d", &m);
    while(m--)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        am[x][y] = 1;
    }

    int parent = 0;

    for (int j = 0; j < n; ++j) 
    {
        for (int i = 0; i < n; ++i) 
        {
            if (am[i][j]) 
            {
                parent++;
                break;
            }
        }
    }

    if (parent == n) 
    {
        printf("-1");
        return 0;
    }

    topoSort(n, am, z, y);
    printf("%d", count);
}


        