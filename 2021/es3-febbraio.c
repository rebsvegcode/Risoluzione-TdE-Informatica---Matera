#include <stdio.h>
#include <stdlib.h>

typedef struct s_nodo{
  int info;
  struct s_nodo *next;
}t_nodo;

typedef t_nodo* p_nodo;

void sotto_sequenze(p_nodo L,int val){
  p_nodo nodo;
  int somma=0,j=0,k=0;
  if(L==NULL){
    printf("La lista è vuota.\n");
  }else{
    while(L->next!=NULL){
      if(L->info==val){
        printf("\n%d \n",val);
      }else{
        printf("%d ",L->info);
        somma=somma+L->info;
        if(somma+L->next->info>val){
          printf("\n");
          somma=0;
        }
        L=L->next;
      }
    }
    if(somma+L->info<=val){
      printf("%d",L->info);
    }else{
      printf("\n %d",L->info);
    }
  }
}

int main(){
  p_nodo nuovonodo,testa=NULL;
  int i,n,v;
  printf("Inserire numero elementi della lista: ");
  scanf("%d",&n);
  printf("Inserire elementi lista:\n");
  for(i=0;i<n;i++){
    nuovonodo=malloc(sizeof(t_nodo));
    scanf("%d",&nuovonodo->info);
    nuovonodo->next=testa;
    testa=nuovonodo;
  }
  printf("Inserire val: ");
  scanf("%d",&v);

  sotto_sequenze(testa,v);

  return 0;
}
