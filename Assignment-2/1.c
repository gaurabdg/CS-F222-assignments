#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include <limits.h>

int minnode(int n, int keyval[], bool mstset[]) 
{ 
  int mini = INT_MAX; 
  int mini_index; 

  for (int i = 0; i < n; i++) 
  { 
    if (mstset[i] == false && keyval[i] < mini) 
      mini = keyval[i], mini_index = i; 
  } 

  return mini_index; 
} 
  

void findcost(int n, int net[][n]) 
{ 

  int parent[n], keyval[n]; 
  bool mstset[n]; 
 
  for (int i = 0; i < n; i++) 
  { 
    keyval[i] = INT_MAX; 
    mstset[i] = false; 
  } 
  
  parent[0] = -1; 
  keyval[0] = 0; 
  

  for (int i = 0; i < n - 1; i++) 
  { 
  
    int u = minnode(n, keyval, mstset); 

    mstset[u] = true; 

    for (int v = 0; v < n; v++) 
    { 
      if (net[u][v] && mstset[v] == false && net[u][v] < keyval[v]) 
      { 
        keyval[v] = net[u][v]; 
        parent[v] = u; 
      } 
    } 
  }

  int cost = 0; 
  for (int i = 1; i < n; i++) 
    cost += net[parent[i]][i]; 
  printf("%d\n",cost);
} 

int main() 
{ 
  int v, e;
  scanf("%d\n%d", &v, &e);
  // printf("%d%d\n",v,e );
  int network[v][v];
  for(int i=0;i<v;i++)
    for(int j=0;j<v;j++)
        network[i][j]=0;
  while(e--)
  {
    int x,y, cost;
    scanf("%d %d %d",&x,&y,&cost);
    // printf("%d%d%d",x,y,cost);
    network[x][y]=cost;
    network[y][x]=cost;
  }  
  // network[4][4]={{81,43,16},{0,}}
  findcost(v, network); 
  
  return 0; 
} 