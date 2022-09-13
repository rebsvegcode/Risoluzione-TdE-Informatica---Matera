#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_nodo{
  char c;
  int occ;
  struct s_nodo* next;
}t_nodo;

typedef t_nodo* p_nodo;

p_nodo scomposizione(char s[]){
  p_nodo testa=NULL,prec=NULL,succ=NULL,nuovonodo=NULL,scorr=NULL;
  int i=0,flag;
  while(s[i]!='\0'){
    if(testa==NULL){
      testa=malloc(sizeof(t_nodo));
      testa->c=s[i];
      testa->occ=1;
      testa->next=NULL;
    }else{
      scorr=testa;
      flag=0;
      while(scorr!=NULL&&flag==0){
        if(scorr->c==s[i]){
          scorr->occ++;
          flag=1;
        }
        scorr=scorr->next;
      }
      if(flag==0){
        nuovonodo=malloc(sizeof(t_nodo));
        nuovonodo->c=s[i];
        nuovonodo->occ=1;
        if(nuovonodo->c<testa->c){
          nuovonodo->next=testa;
        }else{
          prec=testa;
          succ=testa->next;
          while(succ!=NULL&&!(nuovonodo->c>prec->c&&nuovonodo->c<succ->c)){
            prec=prec->next;
            succ=succ->next;
          }
          nuovonodo->next=succ;
          prec->next=nuovonodo;
        }
      }
    }
    i++;
  }
  return testa;
}


int main(){
  p_nodo nuovalista;
  char stringa[50];
  printf("Inserire una stringa: ");
  scanf("%s",stringa);
  printf("ok");
  nuovalista=scomposizione(stringa);
  while(nuovalista!=NULL){
    printf("\n%c,%d",nuovalista->c,nuovalista->occ);
    nuovalista=nuovalista->next;
  }
  return 0;
}
