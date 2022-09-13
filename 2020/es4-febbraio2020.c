#include <stdio.h>
#include <stdlib.h>
#define N 3
#define M 4

typedef struct s_index{
  int riga;
  int colonna;
}t_index;

t_index search_submat(int mat[N][M],int r,int c,int submat[][c]){
  int i,j,h=0,k=0,corrisponde;
  t_index ris;
  for(i=0;i<=N-r;i++){
    for(j=0;j<=M-c;j++){
      if(mat[i][j]==submat[h][k]){
        corrisponde=1;
        for(h=0;h<r&&corrisponde==1;h++){
          for(k=0;k<c&&corrisponde==1;k++){
            if(mat[i+h][j+k]!=submat[h][k]){
              corrisponde=0;
            }
          }
        }
        if(corrisponde==1){
          ris.riga=i;
          ris.colonna=j;
          return ris;
        }
      }
    }
  }
  ris.riga=-1;
  ris.colonna=-1;
  return ris;
}

int main(){
  int matrice[N][M]={{-7,7,-4,-34},{-3,9,-2,18},{-15,-5,3,29}};
  int r=2,c=2;
  int sottomatrice[2][2]={{9,-2},{-5,3}};
  t_index coppia;
  coppia=search_submat(matrice,r,c,sottomatrice);
  printf("%d, %d\n",coppia.riga,coppia.colonna);
  return 0;
}
