#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_nodo{
  char stringa[200];
  int freq;
  struct s_nodo *next;
}t_nodo;

typedef t_nodo *p_nodo;

p_nodo frequenza(FILE* fp){
  char parola[200];
  p_nodo nuovonodo=NULL,succ=NULL,prec=NULL,testa=NULL;
  int flag=1;
  while(!feof(fp)){
    fscanf(fp,"%s",parola);
    printf("%s",parola);
    if(strlen(parola)>=2){
      if(testa==NULL){
        testa=malloc(sizeof(t_nodo));
        strcpy(testa->stringa,parola);
        testa->freq=1;
        testa->next=NULL;
      }else{
        if(strcmp(testa->stringa,parola)==-1){
          nuovonodo=malloc(sizeof(t_nodo));
          strcpy(nuovonodo->stringa,parola);
          nuovonodo->freq=1;
          nuovonodo->next=testa;
          testa=nuovonodo;
        }else{
          succ=testa;
          flag=1;
          while(flag==1&&succ!=NULL&&strcmp(succ->stringa,parola)!=1){
            if(strcmp(succ->stringa,parola)==0){
              succ->freq++;
              flag=0;
            }
            prec=succ;
            succ=succ->next;
          }
          if(flag==1){
            nuovonodo=malloc(sizeof(t_nodo));
            strcpy(nuovonodo->stringa,parola);
            nuovonodo->freq=1;
            nuovonodo->next=succ;
            prec->next=nuovonodo;
          }
        }
      }
    }
  }
  return testa;
}


int main(int argc, char* argv[])
{
  FILE* f;
  p_nodo lista;

  if(argc!=2){
    printf("Numero parametri errato. Inserire un solo parametro (il nome del file di testo) dopo il nome del programma.");
  }else{
    f=fopen(argv[1],"r");
    if(f==NULL){
      printf("Il file non è stato aperto correttamente.");
    }else{
      printf("ciao\n");
      lista=frequenza(f);
      while(lista!=NULL){
        printf("%s %d -> ",lista->stringa,lista->freq);
        lista=lista->next;
      }
    }
    fclose(f);
  }
  return 0;
}
