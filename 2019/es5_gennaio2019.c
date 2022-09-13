#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* crea_stringa(char email[]){
  char* trasf;
  char punto[6]="_DOT_";
  char chiocciola[5]="_AT_";
  int i=0,j,k=0;
  trasf=malloc(strlen(email)+strlen(chiocciola)+strlen(punto)+4);
  while(email[i]!='\0'){
    if(email[i]=='.'){
      j=0;
      while(punto[j]!='\0'){
        trasf[k]=punto[j];
        k++;
        j++;
      }
      i++;
    }else if(email[i]=='@'){
      j=0;
      while(chiocciola[j]!='\0'){
        trasf[k]=chiocciola[j];
        k++;
        j++;
      }
      i++;
    }else{
      trasf[k]=email[i];
      i++;
      k++;
    }
  }
  return trasf;
}

int main(){
  char email[25]="nome.cognome@azienda.com";
  char* trasf;
  trasf=crea_stringa(email);
  printf("%s\n",trasf);
  return 0;
}
