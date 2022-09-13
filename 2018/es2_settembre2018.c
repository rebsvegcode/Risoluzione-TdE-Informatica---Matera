#include <stdio.h>
#include <stdlib.h>

typedef struct s_nodo{
  char info;
  struct s_nodo* next;
}t_nodo;

typedef t_nodo* p_nodo;

p_nodo parentesi(p_nodo testa){
  p_nodo lista=testa,scorr;
  char somma;
  while(lista!=NULL){
    if(lista->info=='('){
      scorr=lista->next;
      somma='0';
      while(scorr->info!=')'){
        somma=somma+scorr->info;
        scorr=scorr->next;
        free(lista->next);
        lista->next=scorr;
      }
      scorr=scorr->next;
      free(lista->next);
      lista->next=scorr;
      lista->info=somma;
    }
    lista=lista->next;
  }
  return testa;
}

int main(){
  int i,n;
  p_nodo nuovonodo,testa=NULL;

  printf("Inserire lunghezza lista: ");
  scanf("%d",&n);
  printf("Inserire elementi lista: ");
  for(i=0;i<n;i++){
    nuovonodo=malloc(sizeof(t_nodo));
    scanf("%c\n",&nuovonodo->info);
    nuovonodo->next=testa;
    testa=nuovonodo;
  }
  testa=parentesi(testa);
  while(testa!=NULL){
    printf("%c -> ",testa->info);
    testa=testa->next;
  }
  return 0;
}
