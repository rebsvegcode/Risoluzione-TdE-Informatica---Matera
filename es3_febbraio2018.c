#include <stdio.h>
#include <stdlib.h>

int main(int argc,char* argv[]){
	FILE *f1,*f2;
	int n,dim=0,i,k=0,trovato;
	int *numeri,*ripetizioni;


	if(argc!=3){
		printf("Errore!Numero parametri errato.");
	}else{
		f1=fopen(argv[1],"r");
		f2=fopen(argv[2],"w");
		if(f1==NULL&&f2==NULL){
			printf("Errore nell'apertura dei file.");
		}else{
			while(!feof(f1)){
				fscanf(f1,"%d",&n);
				dim++;
			}
			rewind(f1);
			numeri=malloc(dim*sizeof(int));
			ripetizioni=malloc(dim*sizeof(int));
			fscanf(f1,"%d",&n);
			numeri[k]=n;
			ripetizioni[k]=1;
			k++;
			while(!feof(f1)){
				fscanf(f1,"%d",&n);
				trovato=0;
				for(i=0;i<k&&trovato==0;i++){
					if(n==numeri[i]){
						ripetizioni[i]++;
						trovato=1;
					}
				}
				if(trovato==0){
					numeri[k]=n;
					ripetizioni[k]=1;
					k++;
				}
			}
			for(i=0;i<k;i++){
				fprintf(f2,"valore %d: %d ripetizioni\n",numeri[i],ripetizioni[i]);
			}
			fclose(f1);
			fclose(f2);
		}
	}
}
