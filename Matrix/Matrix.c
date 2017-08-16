#include <stdio.h>
#include <stdlib.h>
#include <time.h>



/*
* Author - Shalitha Suranga
* shalithasuranga@gmail.com
*/


int **A;
int **B;
int **C;
int N;
double runtime=0;
int sizes[]= {100,300,500,700,900,1100,1300,1500,1700,1900,2100,2300,2500};
//int sizes[]= {2,4,800};

void freeMemory(){
	for(int i=0; i<N; i++){
		free(A[i]);
		free(B[i]);
		free(C[i]);
	}
	free(A);
	free(B);
	free(C);
}

int randomNumber(){
	return rand()%10 +1 ;
}

void fillMatrix(int **S){
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			S[i][j]=randomNumber();
		}
	}
}

void setupMatrices(int n){
	N=n;
	A=(int**)malloc(N*sizeof(int*));
	for(int i=0; i<N; i++) A[i]=(int*)malloc(N*sizeof (int));

	B=(int**)malloc(N*sizeof(int*));
	for(int i=0; i<N; i++) B[i]=(int*)malloc(N*sizeof (int));

	C=(int**)malloc(N*sizeof(int*));
	for(int i=0; i<N; i++) C[i]=(int*)malloc(N*sizeof (int));


	fillMatrix(A);
	fillMatrix(B);
}




void multiplication(){
	clock_t begin = clock();
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			int total=0;
			for(int k=0; k<N; k++){
				total+=*(*(A+i)+k) * *(*(B+k)+j);
			}
			C[i][j]=total;
		}
	}
	clock_t end = clock();
	runtime = (double)(end - begin) / CLOCKS_PER_SEC;

}

int ** showMatrix(int ** S){
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			printf("%d ",*(*(S+i)+j));
		}
		printf("\n");
	}
}

void saveMatrices(int exTime){
	char filename[100];
	sprintf(filename,"output/file%d-%d.txt",N,exTime);
	FILE *f=fopen(filename,"w");
	if(f!=NULL){
		fprintf(f, "INPUT A\n");
		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++){
				fprintf(f,"%d ",*(*(A+i)+j));
			}
			fprintf(f,"\n");
		}
		fprintf(f, "INPUT B \n");
		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++){
				fprintf(f,"%d ",*(*(B+i)+j));
			}
			fprintf(f,"\n");
		}
		fprintf(f, "OUTPUT C\n");
		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++){
				fprintf(f,"%d ",*(*(C+i)+j));
			}
			fprintf(f,"\n");
		}
	}
	fclose(f);
}

int main(){
	srand(time(NULL));

	int exTimes=2;
	double runtimeForSession=0.0f;
	double avgRuntime=0.0f;


	for(int i=0 ;i<sizeof(sizes)/sizeof(int); i++){
		runtimeForSession=0.0f;
		for(int rt=0; rt<exTimes; rt++){
			//printf("N=%d ", sizes[i]);
			setupMatrices(sizes[i]);
			multiplication();
			runtimeForSession+=runtime;
			//printf("T : %0.8llf secs\n",runtime);
			//saveMatrices(rt);
			freeMemory();
			
		}
		avgRuntime=runtimeForSession/exTimes;
		printf("ROUND #%d N=%d, T(avg)=%0.8llf secs\n",i,sizes[i],avgRuntime);

	}
	

	return 0;
}