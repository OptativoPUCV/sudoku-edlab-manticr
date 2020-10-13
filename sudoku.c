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
  int i,j;
  //Revisar no existan numeros repetidos en filas
  int cont = 1;
  int repetidos = 0;
  for( i = 0 ; i < 9 ; i++)
    for( j = 0 ; j < 9 ; j++)
    {
      if(n->sudo[i][j] == cont) repetidos++;
      if(repetidos >= 2) return 1;
      if(j == 8)
      {
        cont++;
        repetidos = 0;
      }
    }
  //Revisar no existan numeros repetidos en columnas
  cont = 1; 
  repetidos = 0;
  for(j = 0 ; j < 9 ; j++)
    for(i = 0 ; i < 9 ; i++)
    {
      if(n->sudo[i][j] == cont) repetidos++;
      if(repetidos >= 2) return 1;
      if(i == 8)
      {
        cont++;
        repetidos = 0;
      }
    }  
  //Revisar no existan numeros repetidos en submatrices 3x3
  cont = 1;
  repetidos = 0;
  for(i = 1 ; i < 10 ; i++)
  {
    int p;
    for(p = 0 ; p < 9 ; p++)
    {
      int x = 3 * (i / 3) + (p / 3);
      int y = 3 * (i % 3) + (p % 3);
      if(n->sudo[x][y] == cont) repetidos++;
      if(repetidos >= 2) return 1;
      if(p == 8)
      {
        cont++;
        repetidos = 0;
      }
    }
  }
  return 0;
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