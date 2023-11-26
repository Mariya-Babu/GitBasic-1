//C programme to implement Memory Allocation Algorithm (First-Fit)
#include<stdio.h>
#include<string.h>
//Function Declaration Section
void readArray(int*,int);
int FirstFitAlgo(int*,int*,int*,int*,int,int,int);
void JobCompletionMatrix(int*,int*,int*,int*,int,int);

//Main Section
int main(){
	printf("First Fit Algorithm Implementation");
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
//	bool status[n];
	int If[n];  //If = internal_fragmentation
	int Total_Available = 0;
	int Total_Use = 0;
	
	for(int i=0;i<n;i++){
//		status[i] = false;
		job_number[i] = -1;
		If[i] = 0;
		Total_Available += MemoryBlock[i];
	}
	
	Total_Use = FirstFitAlgo(job,MemoryBlock,job_number,If,n,m,0);
	
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
//First Fit Algorithm
int FirstFitAlgo(int* job, int* MemoryBlock, int* job_number, int* If,int n, int m,int Total_use){
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(job_number[j] == -1){
				if(job[i]<=MemoryBlock[j]){
					job_number[j] = i;
					If[j] = MemoryBlock[j] - job[i];
					Total_use += job[i];
					break;
				}
			}
		}
	}
	
	return Total_use;
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
