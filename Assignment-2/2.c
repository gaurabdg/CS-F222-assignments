#include <stdlib.h>
#include <string.h>
#include<stdio.h>
 
void swap(int *a,  int *b)
{
     int temp = *a;
    *a = *b;
    *b = temp;
}
 
void tsp(int adjmat[5][5],  int v, 
         int opt_path[5],  int *opt_cost,  int curr_path[5],
         int *curr_cost,  int level)
{
    if (level == v - 1)
    {
         int tour_cost = *curr_cost 
                + adjmat[curr_path[v - 2]][curr_path[v - 1]]
                + adjmat[curr_path[v - 1]][0];
        if (*opt_cost == 0 || tour_cost < *opt_cost) 
        {
            memcpy(opt_path, curr_path, v * sizeof( int));
            *opt_cost = tour_cost;
        }
    }
    else 
    {
        for (int i = level; i < v; i++) 
        {
            if (*opt_cost == 0 || *curr_cost + adjmat[curr_path[level - 1]][curr_path[i]] < *opt_cost)
            {  
                swap(&curr_path[level], &curr_path[i]);
                int cost = adjmat[curr_path[level - 1]][curr_path[level]];
                *curr_cost += cost;
                tsp(adjmat, v, opt_path, opt_cost,
                        curr_path, curr_cost, level + 1);
                *curr_cost -= cost;
                swap(&curr_path[level], &curr_path[i]);
            }
        }
    }
}
 
int main(void)
{
    // Input
    int v, e;
    scanf("%d %d", &v, &e);
    int g[5][5]={{0}};

    for(int i=0;i<e;i++)
    {
        int x,y,c;
        scanf("%d %d %d", &x, &y, &c);
        g[x][y]=c;
        g[y][x]=c;
    }

    // Parameters
    int opt_path[5], curr_path[5], opt_cost = 0, curr_cost=0;

    for (int i = 0; i < v; i++) 
        curr_path[i] = i;

    tsp(g, v, opt_path, &opt_cost, curr_path, &curr_cost, 1);
    
    // Results
    printf("Best tour cost: %u\n", opt_cost);
    printf("Vertices:\n");
    for (int i = 0; i < v; i++) {
        printf("%c=>", (char)(65+opt_path[i]));
    }
    printf("A");
    putchar('\n');
    printf("Edge weights:\n");
    for (int i = 0; i < v - 1; i++) {
        printf("%u ", g[opt_path[i]][opt_path[i + 1]]);
    }
    printf("%u\n", g[opt_path[v - 1]][0]);
 }