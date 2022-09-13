#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int pangramma(char s[]){
  char alfabeto[26],c=97;
  int i,j,trovato;
  for(i=0;i<26;i++){
    alfabeto[i]=c;
    c++;
  }
  for(i=0;i<26;i++){
    trovato=0;
    for(j=0;j<strlen(s)&&trovato==0;j++){
      if(alfabeto[i]==s[j]){
        trovato=1;
      }
    }
    if(trovato==0){
      return 0;
    }
  }
  return 1;
}

int main(){
  char stringa[39]="pac my box with five dozen liquor jugs.";
  if(pangramma(stringa)==1){
    printf("Pangramma.\n");
  }else{
    printf("Non è un pangramma.\n");
  }
  return 0;
}
