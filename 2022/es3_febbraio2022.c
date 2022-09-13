#include <stdio.h>
#include <stdlib.h>

typedef struct s_nodo1{
  int info1;
  struct s_nodo1 *next1;
}t_nodo1;

typedef struct s_nodo2{
  int info2;
  int rip;
  struct s_nodo2 *next2;
}t_nodo2;

typedef t_nodo1 *p_nodo1;
typedef t_nodo2 *p_nodo2;

p_nodo2 costruisciLista(p_nodo1 testa1){
  p_nodo2 testa2=NULL,s,nuovonodo2,prec,succ;
  int flag;

  while(testa1!=NULL){
    if(testa2==NULL){
      testa2=malloc(sizeof(t_nodo2));
      testa2->info2=testa1->info1;
      testa2->rip=1;
    }else{
      s=testa2;
      flag=0;
      while(s!=NULL&&flag==0){
        if(s->info2==testa1->info1){
          s->rip++;
          flag=1;
        }
        s=s->next2;
      }
      if(flag==0){
        nuovonodo2=malloc(sizeof(t_nodo2));
        nuovonodo2->info2=testa1->info1;
        nuovonodo2->rip=1;
        if(nuovonodo2->info2<testa2->info2){
          nuovonodo2->next2=testa2;
          testa2=nuovonodo2;
        }else{
          prec=testa2;
          succ=testa2->next2;
          while(succ!=NULL&&!(nuovonodo2->info2>prec->info2&&nuovonodo2->info2<succ->info2)){
            prec=prec->next2;
            succ=succ->next2;
          }
          prec->next2=nuovonodo2;
          nuovonodo2->next2=succ;
        }
      }
    }
    testa1=testa1->next1;
  }
  return testa2;
}

int main(){
  int i,n,val;
  p_nodo1 nuovonodo,testa=NULL;
  p_nodo2 lista2;

  printf("Inserire lunghezza lista: ");
  scanf("%d",&n);
  printf("Inserire elementi lista: ");
  for(i=0;i<n;i++){
    nuovonodo=malloc(sizeof(t_nodo1));
    scanf("%d",&nuovonodo->info1);
    nuovonodo->next1=testa;
    testa=nuovonodo;
  }

  lista2=costruisciLista(testa);

  while(lista2!=NULL){
    printf("(%d,%d) -> ",lista2->info2,lista2->rip);
    lista2=lista2->next2;
  }
  printf("NULL");

}
