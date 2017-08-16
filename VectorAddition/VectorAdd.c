#include <stdio.h>
#include <stdlib.h>
#include <time.h>



/*
* Author - Shalitha Suranga
* shalithasuranga@gmail.com
*/

/* c=a+b vector size is n */

void addVectors(int *a, int *b, int *c,int n){
	for(int i=0; i<n ;i++){
		*(c+i)=*(a+i)+ *(b+i);
	}
}

/* prints the content of givent vector */

void printVector(int *a, int n){
	printf("%s\n","Output vector");
	for(int i=0; i<n; i++){
		printf("%d ",*(a+i));
	}
	printf("\n");
}



int main(){
	srand(time(NULL));

	/* input vectors - dynamic but same size */

	int a[]={2,3,4,5,3,5,7};
	int b[]={4,5,6,7,5,5,4};
	
	int n=sizeof(a)/sizeof(int);
	int *c=(int*) malloc(sizeof(int) * n);

	addVectors(a,b,c,n);

	printVector(c,n);
	
	free(c);



	return 0;
}