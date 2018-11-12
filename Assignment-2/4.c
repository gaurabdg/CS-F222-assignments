#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

int a[6][6]={0}, b[6][6]={0}, str1[6]={0}, str2[6]={0}, v1,v2,e1,e2;
bool av=false;

void swap(int *x, int *y) 
{ 
    int temp; 
    temp = *x; 
    *x = *y; 
    *y = temp; 
} 

void printArr(int a[],int n) 
{ 
    for (int i=0; i<n; i++) 
        printf("%d", a[i]); 
    printf("\n"); 
} 

void checkIso(int str[], int n)
{
    int f=1;
    for(int i=0;i<v1;i++)
    {
        for(int j=0;j<v1;j++)
        {
            // If for a connected pair vi,vj in A.nodes is present, 
            // check if w1,wj in a perm of B.nodes is also connected or not
            if(a[str1[i]][str1[j]]==1&&b[str[i]][str[j]]!=1)
                f=0;
        }
    }
    if(f){
        printf("Yes");
        av = true;
        exit(0);
    }
}

void heapPermutation(int a[], int size, int n) 
{ 
    if (size == 1) 
    { 
        checkIso(a,n);
        return; 
    } 
  
    for (int i=0; i<size; i++) 
    { 
        heapPermutation(a,size-1,n); 

        if (size%2==1) 
            swap(&a[0], &a[size-1]); 
        else
            swap(&a[i], &a[size-1]); 
    } 
} 


int main()
{
    // Create utils
    scanf("%d %d",&v1, &e1);
    for(int i=0;i<e1;i++)
    {
        int x,y;
        scanf("%d %d", &x, &y);
        a[x][y]=1;
    }
    for(int i=0;i<v1;i++)
    {
        str1[i]=i;
    }

    scanf("%d %d",&v2, &e2);
    for(int i=0;i<e2;i++)
    {
        int x,y;
        scanf("%d %d", &x, &y);
        b[x][y]=1;
    }
    for(int i=0;i<v2;i++)
    {
        str2[i]=i;
    }

    // Generate permutations of graph B nodes and check if isomorphic with graph A
    heapPermutation(str2, v2, v2);
    if(!av)
        printf("No");
}