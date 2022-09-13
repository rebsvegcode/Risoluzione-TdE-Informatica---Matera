#include <stdio.h>
#include <stdlib.h>
#define N 3
#define dim 2

/*MODO CON STRUCT
typedef struct s_op{
  int somma;
  int prodotto;
}t_op;

t_op operazioni(int mat[N][N]){
  int i,j,sum=0,mul=1;
  t_op res;
  for(i=0;i<N;i++){
    for(j=0;j<N;j++){
      sum=sum+mat[i][j];
    }
  }
  for(i=0;i<N;i++){
    for(j=0;j<N;j++){
      mul=mul*mat[i][j];
    }
  }
  res.somma=sum;
  res.prodotto=mul;
  return res;
}
*/

int* operazioni(int mat[N][N]){
  int i,j,sum=0,mul=1;
  int *res;
  for(i=0;i<N;i++){
    for(j=0;j<N;j++){
      sum=sum+mat[i][j];
    }
  }
  for(i=0;i<N;i++){
    for(j=0;j<N;j++){
      mul=mul*mat[i][j];
    }
  }
  res=malloc(sizeof(int)*dim);
  res[0]=sum;
  res[1]=mul;
  return res;
}

int main(void){
  int matrice[N][N]={{1,2,3},{4,5,6},{7,8,9}};
  int* ris=operazioni(matrice);
  printf("Somma: %d\nProdotto: %d\n",ris[0],ris[1]);
  return 0;
}
