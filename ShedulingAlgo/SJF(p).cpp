//Shortest Job First (SJF(Preamptive)) Scheduling Algorithm implementation using C (Operating System Sheduling Algorithms)
#include<stdio.h>

//Function section 
void printTable(int*,int*,int*,int*,int*,int);
void swap(int*,int*);
void bubbleSort(int,int*,int*,int*);
int SJF_p(int*,int*,int*,int*,int,int,int);
void displayGanttChart(int*,int,int,int);
int min(int,int);
void tt_wt(int*,int*,int*,int*,int*,int*,int,int);
float calc_avg(int*,int);
void printArray(int*,int);
void printProcesses(int*,int);

//Main Function
int main(){
	int n;
	printf("SJF(Preamptive) Algorithm implementation!");
	printf("\nEnter no.of Processes : ");
	scanf("%d",&n);
	
	int n2 = 2*n;
	int bt[n], at[n],p[n],gc[2][n2];  
	//bt = Brust_time, at = Arrival_time , p = ProcessId gc = Gantt_chart
	int btc[n], atc[n],pc[n], tt[n],wt[n]; 
	//btc = bt_copy, atc = at_copy, pc = p_copy
	int k=0;
	float avg_tt = 0, avg_wt = 0;
	
	//Reading the process table
	printf("Enter the Process id, brust time, arrival time with space seperated values \n");
	printf("Brust Time   Arrival Time \n");
	for(int i=0;i<n;i++){
		scanf("%d  %d",&bt[i],&at[i]);
		p[i] = i;
		tt[i] = 0;
		wt[i] = 0;
		//duplicating the arrays
		pc[i] = p[i];
		atc[i] = at[i];
		btc[i] = bt[i];
	}
	
	//Sorting the arrival times and brust times according to the arrival times  using bubble sort
	bubbleSort(n,at,bt,p);

	//Gantt Chart Filling
	k = SJF_p(&gc[0][0],bt,at,p,k,n,n2);
	
	//gantt chart printing
	displayGanttChart(&gc[0][0],n,n2,k);
	//calculating  waiting_time &  turn_around_time of all the processes
	tt_wt(&gc[0][0],atc,btc,tt,wt,pc,k,n);
	
	//printing wating_times and turn_around_times of the processes
	printf("\n");
	printTable(pc,btc,atc,wt,tt,n);
	
	avg_tt = calc_avg(tt,n);
	avg_wt = calc_avg(wt,n);
	
	printf("\n");
	printf("Average Turn_around_time = %.2fms\n",avg_tt);
	printf("Average Waiting_time = %.2fms\n",avg_wt);
	
}

//printing the table
void printTable(int *pc, int *btc, int *atc,int *wt, int * tt, int n){
	printf("\nPrinting the Table \n");
	printf("Pid\tBT\tAT\tWT\tTT\n");
	for(int i=0;i<n;i++){
		printf("P%d\t%d\t%d\t%d\t%d",pc[i]+1,btc[i],atc[i],wt[i],tt[i]);
		printf("\n");
	}
}

//SJF(Non-Preemptive) Algorithm implementation (Gagtt Cart Filling)
int SJF_p(int* gc,int *bt, int* at, int* p, int k,int n,int n2){
	gc[n*0+0] = 0;
	gc[n*1+0]= -1;
	for(int i=0;i<n2;i++){
		{
			int min1 = 999;
			int min2 = 999;
			int x = 0;
			int y = 0;
			
			for(int j=0;j<n && at[j]<= gc[k];j++){
				if(min1>bt[j]){
					min1 = bt[j];
					x = j;
				}
				y = j;
			}
			if(y<n-1){
				if(min1==999 && gc[n2*0+k]<at[++y]){
					gc[n2*0+(++k)] =  at[y];
					gc[n2*1+(k)]= -1;
				}
				else{
					int abc = at[++y] - gc[n2*0+k];
					min2 = min(min1,abc);
					
					if(min2 == abc){
						gc[n2*0+(++k)] = gc[n2*0+(k-1)] + abc;
						bt[x] = bt[x] - abc;
						gc[n2*1+k] = p[x];
					}
					else{
						if(gc[n2*1+k]== p[x]){
							gc[n2*0+k]+= bt[x];
						}
						else{
							gc[n2*0+(++k)] = gc[n2*0+(k-1)] + bt[x];
							gc[n2*1+k] = p[x];
						}
						bt[x] = 999;
					}	
				}	
			}
			else if(min1 == 999){
				continue;
			}
			else{
					if(gc[n2*1+k]== p[x]){
						gc[n2*0+k]+= bt[x];
					}
					else{
						gc[n2*0+(++k)] = gc[n2*0+(k-1)] + bt[x];
						gc[n2*1+k] = p[x];
					}
					bt[x] = 999;	
			}
		
		}
	}
	
	return k;
}

//Gantt Chart Printing
void displayGanttChart(int* gc,int n,int n2, int k){
	printf("\nPrinting Gantt Chart\n");
	for(int i=1;i<=k;i++){
		if(gc[n2*1+i] == -1){
			printf("  -");
		}else{
			printf("  P%d",gc[n2*1+i]+1);
		}	
	}
	printf("\n");
	
	for(int i=0;i<=k;i++){
		if(gc[n2*0+i]<10){
			printf("0%d  ",gc[n2*0+i]);
		}else{
			printf("%d  ",gc[n2*0+i]);
		}
		
	}
}
//Function to swap to numbers 
void swap(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

//BubbleSort to sort the arrival times in asscending order
void bubbleSort(int n,int *at, int* bt, int *p){
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(at[j+1]<at[j]){
				swap(&at[j],&at[j+1]);
				swap(&bt[j],&bt[j+1]);
				swap(&p[j],&p[j+1]);	
			}
		}
	}
}

int min(int a, int b){
	if(a<=b){
		return a;
	}
	return b;
}

//Calculating all processes turn_around_times and waiting_times
void tt_wt(int* gc,int *atc,int *btc,int *tt,int *wt,int *pc,int k,int n){
	int x = 0;
	for(int i=0;i<n;i++){
		for(int j=k;j>=0;j--){
			if(gc[n*1+j] == pc[i]){
				x = j;
				break;
			}
		}
		tt[i] = gc[n*0+x] - atc[i];
		wt[i] = tt[i] - btc[i];
	}
}

//Function to calculate Average from a given array
float calc_avg(int *a,int n){
	
	float total = 0;
	for(int i=0;i<n;i++){
		total += a[i];
	}
	
	return total/n;
}
//printing array
void printArray(int *a,int n){
	printf("\n");
	for(int i=0;i<n;i++){
		if(a[i]<10){
			printf("0%d ",a[i]);
		}
		else{
			printf("%d ",a[i]);	
		}
	}
}

//printing Processes Id's
void printProcesses(int *pc,int n){
	printf("\n");
	for(int i=0;i<n;i++){
		printf("P%d ",pc[i]+1);
	}
}

//2  2
//6  5
//4  0
//7  0
//4  7


//3 0 
//5 0 
//2 0 
//4 0
