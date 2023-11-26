//C Programme to implement Best-Fit 
#include<stdio.h>
#include<string.h>
//Function Declaration
int BestFitAlgo(int*,int*,int*,int*,int,int,int);
void readArray(int*,int);
void JobCompletionMatrix(int*,int*,int*,int*,int,int);

//Main Section
int main(){
	printf("Best Fit Algorithm Implementation");
	int n,m;
	printf("\nEnter how many no.of memory blocks are available : ");
	scanf("%d",&n);
	int MemoryBlock[n];
	
	printf("\nEnter how many no.of processes are available : ");
	scanf("%d",&m);
	int job[m];
	
	printf("\nEnter block sizes \n");
	readArray(MemoryBlock,n);
	
	printf("\nEnter Job sizes \n");
	readArray(job,m);
	
	int job_number[n];
	bool status[n];
	int If[n];  //If = internal_fragmentation
	int Total_Available = 0;
	int Total_Use = 0;
	
	for(int i=0;i<n;i++){
		status[i] = false;
		job_number[i] = -1;
		Total_Available += MemoryBlock[i];
		If[i] = 0;
	}
	
	Total_Use = BestFitAlgo(MemoryBlock,job_number,job,If,n,m,0);
	
	JobCompletionMatrix(MemoryBlock,job_number,job,If,n,m);
	printf("\nTotal Available : %d",Total_Available);
	printf("\nTotal Used : %d",Total_Use);
	
}

//read Array Elements
void readArray(int* arr,int n){
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
}
//BestFitAlgorithm 
int BestFitAlgo(int* MemoryBlock,int* job_number,int* job,int* If,int n,int m, int Total_Use){
	printf("\nBest First Algo");
	for(int i=0;i<m;i++){
		int bf = 9999; //bf = Best_Fit = infinity;
		int bfi = -1; //bfi = Best_Fit_Indext;
		for(int j=0;j<n;j++){
			if(job_number[j] ==-1){
				if(MemoryBlock[j] < bf && MemoryBlock[j]>=job[i]){
					bfi = j;
					bf = MemoryBlock[bfi];
				}
			}
		}
		
		if(bfi != -1){
			job_number[bfi] = i;
//			status[bfi] = true;
			If[bfi] = MemoryBlock[bfi] - job[i]; 
			Total_Use += job[i];
		}
	}
	return Total_Use;
}


//Function to display Job Completation Matrix
void JobCompletionMatrix(int* MemoryBlock, int* Job_Number, int* job, int* If, int n, int m ){
	printf("\nMb\tjob_no\tjob\tstatus\tIf");
	char status[30];
	for(int i=0;i<n;i++){
		if(Job_Number[i]!=-1){
			strcpy(status,"Busy");
		}
		else{
			strcpy(status,"Free");
		}
		printf("\n%d\t%d\t%d\t%s\t%d",MemoryBlock[i],Job_Number[i]+1,job[Job_Number[i]],status,If[i]);
	}
}
