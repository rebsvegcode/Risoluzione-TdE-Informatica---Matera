#include <stdio.h>
#include <stdlib.h>

typedef struct s_nodo{
  int info;
  struct s_nodo *next;
}t_nodo;

typedef t_nodo* p_nodo;

float medium(p_nodo lista){
  int* v;
  int n=0,i,k=0,trovato,conta=0,somma=0;
  float media;
  p_nodo scorr=lista;
  while(scorr!=NULL){
    n++;
    scorr=scorr->next;
  }
  v=malloc(sizeof(int)*n);
  while(lista!=NULL){
    trovato=0;
    for(i=0;i<conta&&trovato==0;i++){
      if(lista->info==v[i]){
        trovato=1;
      }else{
        v[k]=lista->info;
        conta++;
        somma=somma+v[k];
        k++;
      }
    }
    lista=lista->next;
  }
  media=somma/conta;
  return media;
}

int main(){
  int i,n;
  p_nodo nuovonodo,testa=NULL;

  printf("Inserire lunghezza lista: ");
  scanf("%d",&n);
  printf("Inserire elementi lista: ");
  for(i=0;i<n;i++){
    nuovonodo=malloc(sizeof(t_nodo));
    scanf("%d",&nuovonodo->info);
    nuovonodo->next=testa;
    testa=nuovonodo;
  }
  printf("La media risulta: %.2f",medium(testa));
  return 0;
}
