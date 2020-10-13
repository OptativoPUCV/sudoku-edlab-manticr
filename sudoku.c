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

int linea_valida(Node* n) //Funcion revisa que todas las lineas sean validas
{
  int flag = 0;
  int cont = 0;
  int repetidos;
  for(int i = 0 ; i < 9 ; i++)
  {
    cont++;
    repetidos = 0;
    for(int j = 0 ; j < 9 ; j++)
    {
      if(n->sudo[i][j] == cont) repetidos++;
      if(repetidos >= 2)
      {
        flag = 1;
        return flag;
      }
    }
  }
  return flag;
}

int columna_valida(Node* n)
{
  int flag = 0;
  int cont = 0;
  int repetidos;
  for(int j = 0 ; j < 9 ; j++)
  {
    cont++;
    repetidos = 0;
    for(int i = 0 ; i < 9 ; i++)
    {
      if(n->sudo[i][j] == cont) repetidos++;
      if(repetidos >= 2)
      {
        flag = 1;
        return flag;
      }
    }
  }
  return flag;
}

int submatriz_valida(Node* n)
{
  int flag = 0;
  int k,p;
  int cont = 0;
  int repetidos;
  for(k = 1 ; k < 10 ; k++)
  {
    cont++;
    repetidos = 0;
    for(p = 0 ; p < 9 ; p++)
    {
      int i=3*(k/3) + (p/3);
      int j=3*(k%3) + (p%3);
      if(n->sudo[i][j] == cont) repetidos++;
      if(repetidos >= 2)
      {
        flag = 1;
        return flag;
      }
    }
  }
  return flag;
}

int is_valid(Node* n)
{
  int a,b,c;
  a = linea_valida(n);
  b = columna_valida(n);
  c = submatriz_valida(n);
  printf("%i, %i, %i\n", a, b, c);
  if(linea_valida(n) == 0 && columna_valida(n) == 0 && submatriz_valida(n) == 0) return 0;
  else return 0;
}


List* get_adj_nodes(Node* n){
  List* list=createList();
  for(int i = 0 ; i < 9 ; i++)
    for(int j = 0 ; j < 9 ; j++)
        if(n->sudo[i][j] == '\0')
        {
          for(int k = 1 ; k < 10 ; k++)
          {
            Node* node = copy(n);
            node->sudo[i][j] = k;
            pushBack(list, node);
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