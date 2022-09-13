#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 3
#define N 5

int main(int argc,char* argv[]){
  FILE* f1,*f2;
  char c1,c2;
  if(argc!=3){
    printf("Numero parametri errato");
  }else{
    f1=fopen(argv[1],"r");
    f2=fopen(argv[2],"w");
    if(f1==NULL||f2==NULL){
      printf("Errore apertura file");
    }else{
      fscanf(f1,"%c",&c2);
      while(!feof(f1)){
        c1=c2;
        fscanf(f1,"%c",&c2);
        if(c2!=39){
          fprintf(f2,"%c",c1);
        }else{
          if(c1=='o'){
            fprintf(f2,"ò");
          }else if(c1=='a'){
            fprintf(f2,"à");
          }else if(c1=='e'){
            fprintf(f2,"è");
          }else if(c1=='i'){
            fprintf(f2,"ì");
          }else if(c1=='u'){
            fprintf(f2,"ù");
          }
          fscanf(f1,"%c",&c2);
        }
      }
    }
  }

}
