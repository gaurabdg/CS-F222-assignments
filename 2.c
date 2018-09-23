#include <stdio.h>
#include <stdlib.h>


int vis[100000]={0},adj[1000][1000]={{0}},nodes,T[10000]={0};

topological_sort( cur_vert, N, adj[][] ){
    visited[cur_vert] = true
    for i = 0 to N
        if adj[cur_vert][i] is true and visited[i] is false
        topological_sort(i)
    T.insert_in_beginning(cur_vert)
}


int main()
{


	return 0;
}