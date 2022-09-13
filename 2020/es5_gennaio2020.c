#include <stdio.h>
#include <stdlib.h>
#define dim 26

typedef struct s_cf{
  char carattere;
  int freq;
}t_cf;

t_cf trovacarattere(FILE* fp){
  int i,max,c,contatore[dim]={0},car_alf=97;
  t_cf ris;
  while(!feof(fp)){
    c=fgetc(fp);
    if(c>96&&c<123){
      contatore[c-97]++;
    }
  }
  for(i=0;i<dim;i++){
    printf("%d ",contatore[i]);
  }
  printf("\n");
  max=contatore[0];
  for(i=1;i<dim;i++){
    if(contatore[i]>max){
      max=contatore[i];
      ris.freq=max;
      ris.carattere=i+97;
    }
  }
  return ris;
}

int main(int argc,char* argv[]){
  FILE* f;
  t_cf res;

  if(argc!=2){
    printf("Errore, numero parametri errato.");
  }else{
    f=fopen(argv[1],"r");
    if(f==NULL){
      printf("Il file non è stato aperto correttamente.");
    }else{
      res=trovacarattere(f);
      printf("%c %d\n",res.carattere,res.freq);
      fclose(f);
    }
  }

  return 0;
}
