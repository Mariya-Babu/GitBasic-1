import java.util.*;

class BankersAlgo {

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Banker's Algorithm implementation using java");
        System.out.println("Enter no.of Processes : ");
        int n = sc.nextInt();
        System.out.println("Enter how many types resourceses are there : ");
        int m = sc.nextInt();

        // Allocation, Max, Need Matrices declaration
        int[][] alo = new int[n][m];
        int[][] MAX = new int[n][m];
        int[][] need = new int[n][m];
        int[] available = new int[m];

        System.out.println("Enter allocation matrix ");
        readMatrix(alo, n, m);

        System.out.println("Enter Max matix ");
        readMatrix(MAX, n, m);

        System.out.println("Enter Availabe Processes : ");
        readArray(available, m);

        System.out.println("Displaying the allocation matrix elements ");
        printMatrix(alo, n, m);

        System.out.println("Displaying the MAX matrix elements ");
        printMatrix(MAX, n, m);

        fillNeedMatrix(need, alo, MAX, n, m);
        System.out.println("Displaying the need matrix elements ");
        printMatrix(need, n, m);

        System.out.println("Displaying Available Resources ");
        printArray(available, m);

        System.out.println("Bankers Algorithm implementation ");
        bankersAlgo(alo,need,available,n,m);
    }

    public static void bankersAlgo(int[][] alo, int[][] need, int[] available, int n, int m) {

        boolean[] isProcessCompelted = new boolean[n];
        int[] sequence = new int[n];
        int p = 0;
        int count = 0;
        boolean b1 = true;

        for (int i = 0; i < n; i++) {
            isProcessCompelted[i] = false;
            sequence[i] = -1;
        }

        for (int i = 0; i < n; i++) {
            b1 = true;
            for (int j = 0; j < n; j++) {

                boolean b2 = true;
                if (!isProcessCompelted[j]) {
                    for (int k = 0; k < m; k++) {
                        if (!(need[j][k] <= available[k])) {
                            b2 = false;
                            break;
                        }
                    }

                    if (b2) {
                        for (int k = 0; k < m; k++) {
                            available[k] += alo[j][k];
                        }
                        System.out.println();
                        printArray(available, m);
                        count++;
                        b1 = false;
                        isProcessCompelted[j] = true;
                        sequence[p++] = j;
                    }
                }
            }
            if (b1 || count >= n) {
                break;
            }
        }

        if(count<n){
            System.out.println("System is Not in safe State ");
        }
        else{
            System.out.println("Total Avalibale Processes are ");
            printArray(available,m);
            System.out.println("\nSystem is in Safe State ");
            System.out.println("Sequence of processes that system has to complete are ");
            printArray(sequence,n);
        }
    }

    public static void readMatrix(int[][] a, int n, int m) {
        Scanner sc = new Scanner(System.in);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                a[i][j] = sc.nextInt();
            }
        }
    }

    public static void printMatrix(int[][] a, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                System.out.print(a[i][j] + " ");
            }
            System.out.println();
        }
    }

    public static void readArray(int[] a, int n) {
        Scanner sc = new Scanner(System.in);
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
    }

    public static void printArray(int[] a, int n) {
        for (int i = 0; i < n; i++) {
            System.out.print(a[i] + " ");
        }
    }

    public static void fillNeedMatrix(int[][] need, int[][] alo, int[][] MAX, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                need[i][j] = MAX[i][j] - alo[i][j];
            }
        }
    }
}


// Problem - 1
// Allocation
// 1 1 2 
// 2 1 2 
// 4 0 1 
// 0 2 0 
// 1 1 2

// MAX 
// 4 3 3 
// 3 2 2 
// 9 0 2 
// 7 5 3 
// 1 1 2 

// Availabe
// 2 1 0



// Problem - 2
// Allocation
// 0 1 1 0
// 1 2 3 1
// 1 3 6 5
// 0 6 3 2 
// 0 0 1 4 

// MAX 
// 0 2 1 0
// 1 6 5 2
// 2 3 6 6 
// 0 6 5 2
// 0 6 5 6

// Availabe
// 1 5 2 0



// Problem - 3
// Allocation
// 0 1 1 0
// 1 4 4 1
// 1 3 6 5
// 0 6 3 2 
// 0 0 1 4 

// MAX 
// 0 2 1 0 
// 1 6 5 2 
// 2 3 6 6 
// 0 6 5 2 
// 0 6 5 6

// Availabe
// 1 3 1 0



// Problem - 4
// Allocation
// 1 0 1
// 2 1 2
// 3 0 0
// 1 0 1

// MAX 
// 2 1 1
// 5 4 4
// 3 1 1
// 1 1 1

// Availabe
// 2 1 1
