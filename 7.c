#include <stdio.h>

void initialize(int n, int arr[n][n], int visited[n], int inDegree[n]);
void topoSortCount(int n, int arr[n][n], int visited[n], int inDegree[n]);
void topoSort(int n, int arr[n][n], int visited[n], int inDegree[n]);

int count = 0;

int main() 
{
    int n, m;
    scanf("%d", &n);

    int arr[n][n], visited[n], inDegree[n];
    initialize(n, arr, visited, inDegree);

    scanf("%d", &m);
    for (int i = 0; i < m; ++i) 
    {
        int x, y;
        scanf("%d%d", &x, &y);
        arr[x][y] = 1;
    }

    int parent = 0;

    for (int j = 0; j < n; ++j) 
    {
        for (int i = 0; i < n; ++i) 
        {
            if (arr[i][j]) 
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

    topoSort(n, arr, visited, inDegree);
    printf("%d", count);
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

void topoSortCount(int n, int arr[n][n], int visited[n], int inDegree[n]) {
    int flag = 0;

    for (int i = 0; i < n; ++i) {
        if (!visited[i] && !inDegree[i]) {
            visited[i] = 1;

            for (int j = 0; j < n; ++j) {
                if (arr[i][j]) {
                    inDegree[j]--;
                }
            }
            topoSortCount(n, arr, visited, inDegree);

            visited[i] = 0;
            for (int k = 0; k < n; ++k) {
                if (arr[i][k]) {
                    inDegree[k]++;
                }
            }
            flag = 1;
        }
    }

    if (!flag) {
        count++;
    }
}

void initialize(int n, int arr[n][n], int visited[n], int inDegree[n]) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            arr[i][j] = 0;
        }
        visited[i] = inDegree[i] = 0;
    }
}