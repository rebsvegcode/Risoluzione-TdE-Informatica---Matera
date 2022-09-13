#include <stdio.h>
#include <stdlib.h>

typedef struct s_nodo{
  int info;
  struct s_nodo* next;
}t_nodo;

typedef t_nodo* p_nodo;

p_nodo modifica_lista(p_nodo lista){
  p_nodo head=lista;
  int val=0,t;
  while(lista!=NULL){
    t=val;
    val=lista->info;
    lista->info=lista->info+t;
    lista=lista->next;
  }
  return head;
}

int main(){
  p_nodo testa=NULL,nuovonodo,nuovalista;
  int i,n;
  printf("Inserire numero elementi lista: ");
  scanf("%d",&n);
  printf("Inserire elementi lista: ");
  for(i=0;i<n;i++){
    nuovonodo=malloc(sizeof(t_nodo));
    scanf("%d",&nuovonodo->info);
    nuovonodo->next=testa;
    testa=nuovonodo;
  }
  nuovalista=modifica_lista(testa);
  for(i=0;i<n;i++){
    printf("%d -> ",nuovalista->info);
    nuovalista=nuovalista->next;
  }
  printf("NULL \n");

}
