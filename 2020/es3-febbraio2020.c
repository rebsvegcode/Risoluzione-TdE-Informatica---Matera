#include <stdio.h>
#include <stdlib.h>

typedef struct s_nodo{
  int info;
  struct s_nodo *next;
}t_nodo;

typedef t_nodo *p_nodo;

p_nodo rotazione(p_nodo lista,int dir){
  p_nodo primo=lista,nuovoprimo,ultimo,cestino;

  if(lista==NULL||lista->next==NULL){
    return lista;
  }else{
    if(dir==0){
      ultimo=lista;
      nuovoprimo=lista->next;
      while(lista->next!=NULL){
        lista=lista->next;
      }
      lista->next=ultimo;
      ultimo->next=NULL;
      return nuovoprimo;
    }else{
      while(lista->next!=NULL){
        ultimo=lista;
        lista=lista->next;
      }
      ultimo->next=NULL;
      nuovoprimo=lista;
      nuovoprimo->next=primo;
      return nuovoprimo;
    }
  }
}

int main(){
  int i,n,val;
  p_nodo nuovonodo,testa=NULL,nuovalista;

  printf("Inserire lunghezza lista: ");
  scanf("%d",&n);
  printf("Inserire elementi lista: ");
  for(i=0;i<n;i++){
    nuovonodo=malloc(sizeof(t_nodo));
    scanf("%d",&nuovonodo->info);
    nuovonodo->next=testa;
    testa=nuovonodo;
  }
  printf("Inserire un valore tra 0 e 1: ");
  scanf("%d",&val);
  nuovalista=rotazione(testa,val);
  while(nuovalista!=NULL){
    printf("%d -> ",nuovalista->info);
    nuovalista=nuovalista->next;
  }
  printf("NULL \n");
  return 0;
}
