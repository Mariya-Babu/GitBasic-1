// C Programme to implement the FCFS Page replacement Algorithm
#include<stdio.h>
//Main Function Start's from Here

int main(){
	printf("LRU Page Replacement Algorithm implementation!");
	int n,m;
	printf("Enter the no.of page references : ");
	scanf("%d",&n);
	printf("Enter the no.of frames in the Main memory : ");
	scanf("%d",&m);
	
	int frame[m];
	int N = m;
	int LRU = -1;  //Least Recently Used
	int MRU = -1; //Most Recently Used
	
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
	
	//LRU Page Replacement Algorithm Main Logic Begins here
	printf("\nLRU Main Logic started executing.....\n");
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
			//Updating the LRU and MRU when the element is present in the frame
			{
				int k = LRU;
				while(k!=MRU){
					if(frame[k] == page_references[i]){
						break;
					}
					k = (k+1)%N;
				}
				while(k!=MRU){
					frame[k] = frame[(k+1)%N];
					k = (k+1)%N;		
				}
				frame[MRU] = page_references[i];
			}
		}else{
			if((MRU+1)%N==LRU){
				int val = frame[LRU];
				for(int j=0;j<m;j++){
					if(frames[j][i] == val){
						frames[j][i] = page_references[i];
					}
				}
			}
			else{
				frames[(MRU+1)%N][i] = page_references[i];
			}
			//Pushing the Latest page into the main memory when the page is not present 
			{
				if(LRU == -1 && MRU == -1){
					LRU = MRU = 0;
					frame[MRU] = page_references[i];
				}
				else if( (MRU+1)%N != LRU){   
					frame[(MRU+1)%N] = page_references[i];
					MRU = (MRU+1)%N;
				}else{
					frame[(MRU+1)%N] = page_references[i];
					MRU = (MRU+1)%N;
					LRU = (LRU+1)%N;
				}
			}
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
//{
//	int x = 10;
	//Global Varibales
//int *Queue;
//int front = -1;
//int rare = -1;
//int N = 0;
//
//void displayQueue(){
//	int i=front;
//	if(front==-1 && rare==-1){
//		printf("\nThe Queue is Empty\n");
//		return;
//	}
//	printf("\nDisplaying the Queue Element's \n");
//	while(i!=rare){
//		printf("%d ",Queue[i]);
//		i = (i+1)%N;
//	}
//	printf("\n");
//}
//
//void push(int val){
////	printf("\nPush function is started!");
//	if(front == -1 && rare == -1){
//		front = rare = 0;
////		Queue[rare] = val;
//		Queue[(0+rare)] = val;
//	}
//	else if( (rare+1)%N != front){   // else if( (rare+1)%N) != front){
////		Queue[(rare+1)%N] = val;
//		Queue[0+(rare+1)%N] = val;
//		rare = (rare+1)%N;
//	}else{
//		Queue[(rare+1)%N] = val;
//		rare = (rare+1)%N;
//		front = (front+1)%N;
//	}
//}
//
//void updateQueue(int val){
//	int i = front;
//	while(i!=rare){
//		if(Queue[i] == val){
//			break;
//		}
//		i = (i+1)%N;
//	}
//	while(i!=rare){
//		Queue[i] = Queue[(i+1)%N];
//		i = (i+1)%N;		
//	}
//	Queue[rare] = val;
//}
//}
// 3 2 1 3 4 1 6 2 4 3 4 2 1 4 5 2 1 3 4 
// 7 0 1 2 0 3 0 4 2 3 0 3 1 2 0
