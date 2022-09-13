#include <stdio.h>
#include <stdlib.h>

typedef struct s_nodo{
  int info;
  struct s_nodo *next;
}t_nodo;

typedef t_nodo* p_nodo;

p_nodo funzione(p_nodo testa,int x){
  int *numeri,*ripetizioni,conta=0,i=0,k=0,flag;
  p_nodo scorr=testa,prec=NULL;
  while(scorr!=NULL){
    conta++;
    scorr=scorr->next;
  }
  scorr=testa;
  numeri=malloc(conta*sizeof(int));
  ripetizioni=malloc(conta*sizeof(int));
  while(scorr!=NULL){
    flag=0;
    for(i=0;i<k&&!flag;i++){
      if(scorr->info==numeri[i]){
        ripetizioni[i]++;
        flag=1;
      }
    }
    if(!flag){
      numeri[k]=scorr->info;
      ripetizioni[k]=1;
      k++;
    }
    scorr=scorr->next;
  }
  for(i=0;i<k;i++){
    if(ripetizioni[i]>=x){
      scorr=testa;
      prec=NULL;
      while(scorr!=NULL){
        if(scorr->info==numeri[i]){
          if(prec==NULL){
            testa=testa->next;
            free(scorr);
            scorr=testa;
          }else{
            prec->next=scorr->next;
            free(scorr);
            scorr=prec->next;
          }
        }else{
          prec=scorr;
          scorr=scorr->next;
        }
      }
    }
  }
  return testa;
}

int main(){
  int i,n,val,x=3;
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
  testa=funzione(testa,x);
  while(testa!=NULL){
    printf("%d -> ",testa->info);
    testa=testa->next;
  }
  return 0;
}
