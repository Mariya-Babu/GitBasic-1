// Priority(Non-Preamptive) Scheduling Algorithm implementation using C (Operating System Sheduling Algorithms)
#include<stdio.h>

//Function section 
void printTable(int*,int*,int*,int*,int*,int*,int);
void swap(int*,int*);
void bubbleSort(int,int*,int*,int*,int*);
int Priority_np(int*,int*,int*,int*,int*,int,int);
void displayGanttChart(int*,int,int);
void tt_wt(int*,int*,int*,int*,int*,int*,int,int);
float calc_avg(int*,int);
void printArray(int*,int);
void printProcesses(int*,int);
//void displayGanttChart(int*,int,int);

//Main Function
int main(){
	int n;
	printf("Priority(Non-Preamptive) Algorithm implementation!");
	printf("\nEnter no.of Processes : ");
	scanf("%d",&n);
	
	int bt[n], at[n],p[n],pr[n],gc[2][n];  
	//bt = Brust_time, at = Arrival_time , p = ProcessId gc = Gantt_chart
	int btc[n], atc[n],pc[n], tt[n],wt[n],prc[n]; 
	//btc = bt_copy, atc = at_copy, pc = p_copy
	int k=0;
	float avg_tt = 0, avg_wt = 0;
	
	//Reading the process table
	printf("Enter the  Brust time, Arrival time, Priority with space seperated values \n");
	printf("Brust Time   Arrival Time Priority\n");
	for(int i=0;i<n;i++){
		scanf("%d  %d %d",&bt[i],&at[i],&pr[i]);
		p[i] = i;
		tt[i] = 0;
		wt[i] = 0;
		//duplicating the arrays
		pc[i] = p[i];
		atc[i] = at[i];
		btc[i] = bt[i];
		prc[i] = pr[i];
	}	
	
	//Sorting the arrival times and brust times according to the arrival times  using bubble sort
	bubbleSort(n,at,bt,p,pr);

	//Gantt Chart Filling
	k = Priority_np(&gc[0][0],bt,at,p,pr,k,n);
	
	//gantt chart printing
	displayGanttChart(&gc[0][0],n,k);
	
	//calculating  waiting_time &  turn_around_time of all the processes
	tt_wt(&gc[0][0],atc,btc,tt,wt,pc,k,n);
	
	printArray(tt,n);
	//printing wating_times and turn_around_times of the processes
	printf("\n");
	printTable(pc,btc,atc,prc,wt,tt,n);
	
	avg_tt = calc_avg(tt,n);
	avg_wt = calc_avg(wt,n);
	
	printf("\n");
	printf("Average Turn_around_time = %.2fms\n",avg_tt);
	printf("Average Waiting_time = %.2fms\n",avg_wt);
	
	
}

//printing the table
void printTable(int *pc, int *btc, int *atc,int *prc,int *wt, int * tt, int n){
	printf("\nPrinting the Table \n");
	printf("Pid\tBT\tAT\tPR\tWT\tTT\n");
	for(int i=0;i<n;i++){
		printf("P%d\t%d\t%d\t%d\t%d\t%d",pc[i]+1,btc[i],atc[i],prc[i],wt[i],tt[i]);
		printf("\n");
	}
}

//SJF(Non-Preemptive) Algorithm implementation (Gagtt Cart Filling)
int Priority_np(int* gc,int *bt, int* at, int* p,int* pr, int k,int n){
	gc[n*0+0] = 0;
	gc[n*1+0]= -1;
	for(int i=0;i<n;i++){
		if(gc[n*0+k]<at[i]){
			gc[n*0+(++k)] =  at[i];
			gc[n*1+(k)]= -1;
			i--;
		}else{
			int min = 999;
			int x = 0;
			for(int j=0;j<n && at[j]<= gc[k];j++){
				if(min>pr[j]){
					min = pr[j];
					x = j;
				}
			}
			gc[n*0+(++k)] = gc[n*0+(k-1)] + bt[x];
			pr[x] = 999;
			gc[n*1+k]= p[x];
		}
	}
	
	return k;
}

//Gantt Chart Printing
void displayGanttChart(int* gc,int n, int k){
	printf("\nPrinting Gantt Chart\n");
	for(int i=1;i<=k;i++){
		if(gc[n*1+i] == -1){
			printf("  -");
		}else{
			printf("  P%d",gc[n*1+i]+1);
		}	
	}
	printf("\n");
	
	for(int i=0;i<=k;i++){
		if(gc[n*0+i]<10){
			printf("0%d  ",gc[n*0+i]);
		}else{
			printf("%d  ",gc[n*0+i]);
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
void bubbleSort(int n,int *at, int* bt, int *p,int* pr){
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(at[j+1]<at[j]){
				swap(&at[j],&at[j+1]);
				swap(&bt[j],&bt[j+1]);
				swap(&p[j],&p[j+1]);	
				swap(&pr[j],&pr[j+1]);
			}
		}
	}
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

//3 2 1
//5 0 3
//3 1 2 
//4 6 1

//11 0 2
//28 5 0
//2 12 3
//10 2 1
//16 9 4
