#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* replace(char str[],char sost[],char ch){
  char* stringa;
  int i,k=0,j,dim;
  dim=strlen(str)-1+strlen(sost);
  stringa=malloc(dim+1);
  for(i=0;i<strlen(str);i++){
    if(str[i]==ch){
      for(j=0;j<strlen(sost);j++){
        stringa[k]=sost[j];
        k++;
      }
    }else{
      stringa[k]=str[i];
      k++;
    }
  }
  return stringa;
}

int main(){
  char stringa1[7]="CULLA";
  char stringa2[1]="ARTE";
  char c='U';
  char* stringa3;
  stringa3=replace(stringa1,stringa2,c);
  printf("%s\n",stringa3);
  return 0;
}
