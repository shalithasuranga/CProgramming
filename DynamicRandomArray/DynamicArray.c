#include <stdio.h>
#include <stdlib.h>
#include <time.h>



/*
* Author - Shalitha Suranga
* shalithasuranga@gmail.com
*/

/* generate random Number */

int randomNumber(){
	return rand()%10 +1 ;
}

/* make dynamic random array for given size */

void makeRandomArray(int *A,int size){
	//A=(int *) malloc(sizeof(int) * size);
	for(int i=0; i<size; i++){
		*(A+i)=randomNumber();
		//printf("%d\n",*(A+i));
	}
}

/* prints the content of givent vector */

void printArray(int *a, int n){
	printf("%s\n","Output array");
	for(int i=0; i<n; i++){
		printf("%d ",*(a+i));
	}
	printf("\n");
}



int main(){
	srand(time(NULL));
	
	
	int size;
	printf("Enter array size : ");
	scanf("%d",&size);
	int *a=(int *) malloc(sizeof(int) * size);
	makeRandomArray(a,size);

	printArray(a,size);
	
	free(a);



	return 0;
}