#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>

typedef struct tr
{ 
    int value; 
    struct tr *child[2]; 
}trie; 
  
trie* init() 
{ 
    trie * root = (trie*)malloc(sizeof(trie)); 
    root -> value = 0; 
    root -> child[0] = NULL; 
    root -> child[1] = NULL; 
    return root; 
} 
 
void insert(trie* root, int key) 
{ 
    trie* temp = root; 
      
    for(int i = 31; i >= 0; i--) 
    { 
        bool bit = (key & (1 << i)); 
          
        if (temp -> child[bit] == NULL)         
            temp -> child[bit] = init(); 
          temp = temp -> child[bit]; 
    } 

    temp -> value = key; 
} 

int findMax(trie* root, int key) 
{ 
    trie* temp = root; 
      
    for (int i = 31; i >= 0; i--) 
    { 
        bool bit = (key & ( 1 << i)); 
        if(bit==1&&temp->child[1]!=NULL&&i==31)
        {
            temp = temp->child[1];
            continue;
        }

        if(bit==0&&temp->child[0]!=NULL&&i==31)
        {
            temp = temp->child[0];
            continue;
        }
   
        if (temp -> child[1 - bit] != NULL) 
            temp = temp -> child[1 - bit]; 
       else
            temp = temp -> child[bit]; 
    } 
   
    return (key ^ (temp -> value)); 
} 
  
  
int main() 
{ 
    int n,t;
    trie * root = init(); 
    scanf("%d", &n);
    for(int i=0;i<n;i++)
    {
        int m;
        scanf("%d", &m);
        insert(root, m);
    }
    scanf("%d", &t);
    for(int i=0;i<t;i++)
    {
        int m;
        scanf("%d", &m);
        printf("%d\n", findMax(root, m));
    }
} 

