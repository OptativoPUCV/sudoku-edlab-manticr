#include <stdio.h>
#include <stdlib.h>
#include "list.h"


typedef struct{
   int sudo[9][9];
}Node;

Node* createNode(){
  Node* n=(Node*) malloc(sizeof(Node));
  return n;
}

Node* copy(Node* n){
    Node* new=(Node*) malloc(sizeof(Node));
    *new = *n;
    return new;
}

Node* read_file (char* file_name){
  Node* n = createNode();
  FILE* file = fopen (file_name, "r");
  int i,j;
  for(i=0;i<9;i++){
       for(j=0;j<9;j++){
          fscanf (file, "%d", &n->sudo[i][j]);
       }
  }

  fclose (file);
  return n;
}

void print_node(Node* n){
    int i,j;
    for(i=0;i<9;i++){
       for(j=0;j<9;j++)
          printf("%d ", n->sudo[i][j]);
       printf("\n");
    }
    printf("\n");
}

int is_valid(Node* n)
{
  for(int i = 0 ; i < 9 ; i++)
  {
    for(int j = 0 ; j < 9 ; j++)
    {
      if(n->sudo[i][j] == '\0')
      {
        for(int x = i+1 ; x < 9 ; x++)
        {
          for(int y = j+1 ; y < 9 ; y++)
          {
            if(n->sudo[i][j] != 0 && (n->sudo[i][j] == n->sudo[x][y] || n->sudo[i][j] == n->sudo[x][y]+(x-1)+(y-1) || n->sudo[i][j] == n->sudo[x][y]-(x-1)-(y-1))) return 0;
          }
        }
      }
    }
  }
  return 1;
}


List* get_adj_nodes(Node* n){
    List* list=createList();
    for(int i = 0 ; i < 9 ; i++)
    {
      for(int j = 0 ; j < 9 ; j++)
      {
        if(n->sudo[i][j] == '\0')
        {
          for(int k = 1 ; k < 10 ; k++)
          {
            Node* node = copy(n);
            node->sudo[i][j] = k;
            pushBack(list, node);
          }
        } 
      }
    }
    return list;
}


int is_final(Node* n){
    return 0;
}

Node* DFS(Node* initial, int* cont){
  return NULL;
}



/*
int main( int argc, char *argv[] ){

  Node* initial= read_file("s12a.txt");;

  int cont=0;
  Node* final = DFS(initial, &cont);
  printf("iterations:%d\n",cont);
  print_node(final);

  return 0;
}*/