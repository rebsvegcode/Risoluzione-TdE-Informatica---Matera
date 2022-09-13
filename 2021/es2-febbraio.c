#include <stdio.h>
#include <stdlib.h>


int cifre(char s[],int conta,int i){
  if(s[i]=='\0'){
    return conta;
  }else{
    if(s[i]<=57&&s[i]>=48){
      return cifre(s,conta+1,i+1);
    }else{
      return cifre(s,conta,i+1);
    }
  }
}

int main(){
  char stringa[]="spazio1998";
  printf("Numero cifre della stringa: %d\n",cifre(stringa,0,0));
  return 0;
}
