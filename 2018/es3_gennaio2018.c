#include <stdio.h>
#include <stdlib.h>

int main(int argc,char* argv[]){
  FILE *f1,*f2;
  int N,i,j,x,y,q,m,k,max=0,min,a,b;
  int **mat;
  if(argc!=3){
    printf("Numero parametri errato!");
  }else{
    f1=fopen(argv[1],"r");
    f2=fopen(argv[2],"w");
    if(f1==NULL||f2==NULL){
      printf("Errore apertura file.");
    }else{
      fscanf(f1,"%d",&N);
      mat=malloc(sizeof(int*)*N);
      for(j=0;j<N;j++){
        mat[j]=malloc(sizeof(int)*N);
      }
      while(!feof(f1)){
        for(i=0;i<N;i++){
          for(j=0;j<N;j++){
            fscanf(f1,"%d",&mat[i][j]);
          }
        }
      }
      printf("Inserire posizione iniziale del robot: ");
      scanf("(%d,%d)",&x,&y);
      printf("Inserire quota massima: ");
      scanf("%d",&q);
      printf("Inserire numero di mosse massimo: ");
      scanf("%d",&m);
      fprintf(f2,"Posizioni visitate dal robot:\n");
      fprintf(f2,"(%d,%d)\n",x,y);
      for(k=0;k<m&&max==0;k++){
        min=mat[x][y+1];
        if(y-1>=0&&mat[x][y-1]<=min&&mat[x][y-1]<=q){
          min=mat[x][y-1];
          a=x;
          b=y-1;
        }
        if(x-1>=0&&mat[x-1][y]<=min&&mat[x-1][y]<=q){
          min=mat[x-1][y];
          a=x-1;
          b=y;
        }
        if(x+1<N&&mat[x+1][y]<=min&&mat[x+1][y]<=q){
          min=mat[x+1][y];
          a=x+1;
          b=y;
        }
        if(x-1>=0&&y-1>=0&&mat[x-1][y-1]<=min&&mat[x-1][y-1]<=q){
          min=mat[x-1][y-1];
          a=x-1;
          b=y-1;
        }
        if(x+1<N&&y+1<N&&mat[x+1][y+1]<=min&&mat[x+1][y+1]<=q){
          min=mat[x+1][y+1];
          a=x+1;
          b=y+1;
        }
        if(x-1>=0&&y+1<N&&mat[x-1][y+1]<=min&&mat[x-1][y+1]<=q){
          min=mat[x-1][y+1];
          a=x-1;
          b=y+1;
        }
        if(x+1<N&&y-1>=0&&mat[x+1][y-1]<=min&&mat[x+1][y-1]<=q){
          min=mat[x+1][y-1];
          a=x+1;
          b=y-1;
        }
        if(min>q){
          max=1;
        }else{
          fprintf(f2,"(%d,%d)\n",a,b);
          mat[x][y]=q+1;
          x=a;
          y=b;
        }
      }
      fclose(f1);
      fclose(f2);
    }
  }
}
