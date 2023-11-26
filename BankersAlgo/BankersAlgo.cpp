//Bankers Algorithm 
#include<stdio.h>
//Function Declaration Section
void readMatrix(int*,int,int);
void printMatrix(int*,int,int);
void subtractMatrices(int*,int*,int*,int,int);
void addMatrices(int*,int*,int*,int,int);
//Main Function
int main(){
	printf("Bankers Algorithm Implementation using C ");
	
	int n;
	printf("Enter no.of presses : ");
	scanf("%d",&n);
	
	int m;
	printf("Enter how many types of resources are there :  ");
	scanf("%d",&m);
	
	int alo[n][m];
	int Max[n][m];
	
	printf("Enter allocation matrix\n");
	readMatrix(&alo[0][0],n,m);
	
	printf("Allocation Matrix");
	printMatrix(&alo[0][0],n,m);
	
	printf("Enter Max-Resources required to the processes in a Matrix form \n");
	readMatrix(&Max[0][0],n,m);
	
//	int need[n][m];
//	subtractMatrices(&need[0][0],&Max[0][0],&alo[0][0],n,m);
	
	printf("Allocation Matrix");
	printMatrix(&alo[0][0],n,m);
	
	printf("Max Matrix");
	printMatrix(&Max[0][0],n,m);
	
//	printf("Need Matrix");
//	printMatrix(&need[0][0],n,m);
}


//Function to read Matrix Elements 
void readMatrix(int* mat, int n, int m){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%d",&mat[n*i+j]);
		}
	}
	printf("\n");
	
}

//Function to Display the Matrix Elements
void printMatrix(int* mat,int n,int m){
	printf("\n");
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			printf("%d ",mat[n*i+j]);
		}
		printf("\n");
	}
}

//Function to subtract two matrices
void subtractMatrices(int *mat1, int *mat2,int* mat3, int n, int m){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			int x = mat2[n*i+j];
			int y = mat3[n*i+j];
//			mat1[n*i+j] = mat2[n*i+j] - mat3[n*i+j];
			mat1[n*i+j] = x - y;
		}
	}
}

//Function to add two matrices
void addMatrices(int *mat1, int *mat2,int* mat3, int n, int m){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			mat1[n*i+j] = mat2[n*i+j] + mat3[n*i+j];
		}
	}
}



//0 1 0
//2 0 0
//3 0 2
//2 1 1
//0 0 2
//
//
//7 5 3
//3 2 2 
//9 0 2
//2 2 2
//4 3 3


