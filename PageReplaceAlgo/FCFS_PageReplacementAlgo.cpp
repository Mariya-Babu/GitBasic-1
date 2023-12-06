// C Programme to implement the FCFS Page replacement Algorithm
#include<stdio.h>
int main(){
	printf("FCFS Page Replacement Algorithm implementation!");
	int n,m;
	printf("Enter the no.of page references : ");
	scanf("%d",&n);
	printf("Enter the no.of frames in the Main memory : ");
	scanf("%d",&m);
	
	
	int page_references[n];
	int flag[n];
	int frames[m][n];
	int hit_count = 0;
	float hit_ratio = 0;
	int fault_count = 0;
	float fault_ratio = 0;
	
	
	printf("Enter the page references \n");
	for(int i=0;i<n;i++){
		scanf("%d",&page_references[i]);
	}
	printf("\nDisplaying the page references\n");
	for(int i=0;i<n;i++){
		printf("%d ",page_references[i]);
		flag[i] = 0;
	}
	
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			frames[i][j] = -1;	
		}
	}
	
	int k = 0;
	
	//FCFS Page Replacement Algorithm Main Logic Begins here
	for(int i=0;i<n;i++){
		bool isElementPresent = false;
		for(int j=0;j<m;j++){
			if(i!=0){
				frames[j][i] = frames[j][i-1];	
			}
			if(page_references[i] == frames[j][i]){
				isElementPresent = true;
			}
		}
		if (isElementPresent){
			flag[i] = 1;
		}else{
			frames[k][i] = page_references[i];
			k = (k+1) % m;
		}
	}
	
	//Displaying the frames Matrix
	printf("\nDisplaying the frames matrxi \n");
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(frames[i][j] == -1){
				printf("  ");
			}
			else{
				printf("%d ",frames[i][j]);	
			}
		}
		printf("\n");
	}
	for(int i=0;i<n;i++){
		printf("%d ",flag[i]);
		if(flag[i] == 1){
			hit_count += 1;
		}
		else{
			fault_count += 1;
		}
	}
	hit_ratio = (hit_count / n) * 100;
	fault_ratio = (fault_count / n) * 100;
	
	printf("\nThe no.of page-hits are : %d\n",hit_count);
	printf("\nThe no.of page-faults are : %d\n",fault_count);
	
	
	
	
	
	return 0;
}

// 3 2 1 3 4 1 6 2 4 3 4 2 1 4 5 2 1 3 4 
