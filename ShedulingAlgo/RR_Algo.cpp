// Round Robin Scheduling Algorithm implementation using C (Operating System Sheduling Algorithms)
#include<stdio.h>
#include<Math.h>
//Function section 
void printTable(int*,int*,int*,int*,int*,int);
void swap(int*,int*);
void bubbleSort(int,int*,int*,int*);
int RR_Algo(int*,int*,int*,int*,int,int,int,int);
void displayGanttChart(int*,int,int,int);
void tt_wt(int*,int*,int*,int*,int*,int*,int,int,int);
float calc_avg(int*,int);
void printArray(int*,int);
int total_bt(int*,int);
void printProcesses(int*,int);
int min(int,int);
int enqueue(int);
int dequeue();
int peek();
void printQueue();
bool isProcessExist(int);

//Global Declarations
#define N 10

int Queue[N];
int front = -1;
int rare = -1;


//Main Function
int main(){
	int n;
	printf("FCFS Algorithm implementation!");
	int TQ;
	printf("Enter Time Quantum : ");
	scanf("%d",&TQ);
	printf("\nEnter no.of Processes : ");
	scanf("%d",&n);
	
	int bt[n], at[n],p[n];  
	//bt = Brust_time, at = Arrival_time , p = ProcessId gc = Gantt_chart
	int btc[n], atc[n],pc[n], tt[n],wt[n]; 
	//btc = bt_copy, atc = at_copy, pc = p_copy
	int k=0;
	float avg_tt = 0, avg_wt = 0;
	
	//Reading the process table
	printf("Enter the Brust time, Arrival time with space seperated values \n");
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
	
	int total_brust_time = total_bt(bt,n);
//	int n2 = round((total_brust_time)/TQ)+1;
	int n2 = 10;
	int gc[2][n2];
	
	printf("\nTotalProcesses are : %d\n",n2);
	
	//Sorting the arrival times and brust times according to the arrival times  using bubble sort
	bubbleSort(n,at,bt,p);
	
	//Gantt Chart Filling
	k = RR_Algo(&gc[0][0],bt,at,p,k,n,n2,TQ);
	
	//gantt chart printing
	displayGanttChart(&gc[0][0],n,n2,k);	
	
	//calculating  waiting_time &  turn_around_time of all the processes
	tt_wt(&gc[0][0],atc,btc,tt,wt,pc,k,n,n2);
	
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
//		printf("%d  ",gc[n*0+i]);
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

//Calculating all processes turn_around_times and waiting_times
void tt_wt(int* gc,int *atc,int *btc,int *tt,int *wt,int *pc,int k,int n,int n2){
	int x = 0;
	for(int i=0;i<n;i++){
		for(int j=k;j>=0;j--){
			if(gc[n2*1+j] == pc[i]){
				x = j;
				break;
			}
		}
		tt[i] = gc[n2*0+x] - atc[i];
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

//Total Brust Times
int total_bt(int *bt,int n){
	int total = 0;
	for(int i=0;i<n;i++){
		total += bt[i];
	}
	return total;
}
//printing Processes Id's
void printProcesses(int *pc,int n){
	printf("\n");
	for(int i=0;i<n;i++){
		printf("P%d ",pc[i]+1);
	}
}
//function to find minimum 
int min(int a,int b){
	if(a<=b){
		return a;
	}
	return b;
}

//FCFS Algorithm implementation (Gantt Chart Filling)
int RR_Algo(int* gc,int *bt, int* at, int* p, int k,int n,int n2,int TQ){
	int y = 0;
	gc[n2*0+0] = 0;
	gc[n2*1+0] = -1;
    enqueue(0);
    for(int i=0;i<n2;i++){
        int x = peek();
        int m1 = min(bt[x],TQ);
        if(m1==bt[x]){
            gc[n2*0+(++k)] = gc[n2*0+(k-1)]+ bt[x];
            gc[n2*1+k] = p[x];
            bt[x] = 0;
            p[x] = -1;
        }
        else{
            gc[n2*0+(++k)] = gc[n2*0+(k-1)] + TQ;
            gc[n2*1+k] = p[x];
            bt[x] = bt[x] - TQ;
        }

        for(int j=0;j<n && at[j]<=gc[n2*0+k];j++){
            if(p[j]!=-1){
                bool b = isProcessExist(j);
                if(!b){
                    enqueue(j);
                }
            }
            y = j;
            
        } 
        x = dequeue();
        if(p[x] != -1){
            enqueue(x);
        }
        
    }

	return k;
}
//Enqueue to insert element into the queue
int enqueue(int n){
	if(front == -1 && rare == -1){
		front=rare=0;
		Queue[rare] = n;
		return 0;
	}
	if((rare+1)%N==front){
		return -1;
	}
	rare = (rare+1)%N;
	Queue[rare] = n;
	return 0;
}

//Dequeue to delete the element from the queue
int dequeue(){
	int temp = Queue[front];
	if(front==-1 && rare==-1){
		return -1;
	}
	if(front==rare){
		front=rare = -1;
		return temp;
	}
	front = (front+1)%N;
	return temp;
}

//Peek to return the peek element from the queue
int peek(){
	if(front==-1){
		return -1;
	}
	return Queue[front];
}

//printing the queue
void printQueue(){
	printf("\nPrinting Queue \n");
	if(front==-1 && rare==-1){
		return;
	}
	int i = front;
	while((i)%N!=rare+1){
		printf("%d ",Queue[i]);
		i = (i+1)%N;
	}
}
//isProcessExist function to search a process exists or not in a queue
bool isProcessExist(int j){
	if(front==-1 && rare==-1){
		return false;
	}
	int i = front;
	while(i%N!=rare+1){
		if(Queue[i] == j){
			return true;
		}
		
		i = (i+1)%N;
	}
	return false;
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

//
//int RR_Algo(){
//    enqueue(0);
//    for(int i=0;i<n;i++){
//        x = front();
//        m1 = min(bt[x],TQ);
//        if(m1==bt[x]){
//            Gc[0][++k] = Gc[0][k-1] + bt[x];
//            bt[x] = 0;
//            p[x] = -1;
//        }
//        //bt,tq,gc,p,at,n,k,
//        else{
//            Gc[0][++k] = Gc[0][k-1] + TQ;
//            bt[x] = bt[x] - TQ;
//        }
//
//        for(int j=0;j<n && a[j]<=Gc[k];j++){
//            if(p[j]!=-1){
//                bool b = isProcessesExist(j);
//                if(!b){
//                    enqueue(j);
//                }
//            }
//        } 
//        x = dequeue();
//        if(p[x] != -1){
//            enqueue(x);
//        }
//    }
//}
