#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 26

void occorrenze_caratteri(FILE* fp,char sequenza[]){
  int v[max],i,l=strlen(sequenza);

  while(!feof(fp)){
    c=fgetc(fp);
    for(i=0;i<l;i++){
      if(sequenza[i]==c){
        v[i]++;
      }
    }
  }

  for(i=0;i<l;i++){
    printf("%c: %d \n",sequenza[i],v[i]);
  }

}

int main(int argc,char* argv[]){
  FILE* f;
  char stringa[max],c;

  if(argc!=2){
    printf("Errore! Numero parametri inseriti errato.");
  }else{
    printf("Immettere la sequenza di caratteri: ");
    scanf("%s",stringa);
    f=fopen(argv[1],"r");
    if(f==NULL){
      printf("Errore di apertura file.");
    }else{
      occorrenze(f,stringa);
    }
    fclose(f);
  }
}
