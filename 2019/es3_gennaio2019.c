#include <stdio.h>
#include <stdlib.h>
#define N 5

int main(int argc,char *argv[]){
  FILE* f;
  int mat[N][N],n,conta=0,el,no=0,trovato,j,i;
  int* v;
  if(argc!=2){
    printf("Numero parametri errato");
  }else{
    f=fopen(argv[1],"r");
    if(f==NULL){
      printf("Errore apertura file");
    }else{
      fscanf(f,"%d",&n);
      v=malloc(sizeof(int)*n);
      for(i=0;i<n;i++){
        v[i]=++conta;
      }
      while(!feof(f)&&no==0){
        for(i=0;i<n&&no==0;i++){
          fscanf(f,"%d",&el);
          if(el>n){
            no=1;
          }else{
            trovato=0;
            for(j=0;j<n&&trovato==0;j++){
              if(el==v[j]){
                v[j]=n+1;
                trovato=1;
              }
            }
          }
        }
        for(i=0;i<n&&no==0;i++){
          if(v[i]!=n+1){
            no=1;
          }
        }
        conta=0;
        for(i=0;i<n;i++){
          v[i]=++conta;
        }
      }
      if(no==1){
        printf("Non è un quadrato latino.\n");

      }else{
        printf("Si tratta di un quadrato latino.\n");
      }
      fclose(f);
    }
  }
  return 0;
}
