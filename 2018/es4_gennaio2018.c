#include <stdio.h>
#include <stdlib.h>

typedef struct s_nodo{
  char info;
  struct s_nodo *next;
}t_nodo;

typedef t_nodo* p_nodo;

p_nodo sostituisci(p_nodo testa){
  p_nodo scorr=testa,succ=scorr->next,nuovonodo;
  while(scorr->next!=NULL){
    if(scorr->info=='('){
      if(succ->info==')'){
        nuovonodo=malloc(sizeof(t_nodo));
        nuovonodo->info='#';
        nuovonodo->next=succ;
        scorr->next=nuovonodo;
        scorr=nuovonodo;
      }else{
        scorr=scorr->next;
        succ=succ->next;
        scorr->info='#';
        while(succ->info!=')'){
          succ=succ->next;
          free(scorr->next);
          scorr->next=succ;
        }
      }
    }
    scorr=scorr->next;
    succ=succ->next;
  }
  return testa;
}

int main(){
  p_nodo nuovonodo,testa=NULL;
  int i,n;
  printf("Inserire numero elementi lista: ");
  scanf("%d",&n);
  printf("Inserire elementi lista: ");
  for(i=0;i<n;i++){
    nuovonodo=malloc(sizeof(t_nodo));
    scanf("\n%c",&nuovonodo->info);
    nuovonodo->next=testa;
    testa=nuovonodo;
  }
  testa=sostituisci(testa);
  while(testa!=NULL){
    printf("%c ",testa->info);
    testa=testa->next;
  }
  return 0;
}
