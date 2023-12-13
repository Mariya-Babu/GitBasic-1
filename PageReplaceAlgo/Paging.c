#include<stdio.h>
#include<math.h>
int main() {
    long long int ms, sol, mem_size, pbit, bits;
    int mf;
    printf("1. KB\n2. MB\n3. GB\nEnter file size format of main memory size: ");
    scanf("%d", &mf);
    printf("\nEnter the size of main memory:");
    scanf("%d",&ms);
    printf("\nEnter size of one location(in ByteAddressable): ");
	scanf("%d", &sol);
//	if (mf == 1)
//    	mem_size = ms * pow(2, 10);
//  	else if (mf == 2)
//    	mem_size = ms * pow(2, 20);
//  	else if (mf == 3)
//    	mem_size = ms * pow(2, 30); 
	mem_size = ms * pow(2, 10*mf);
	pbit = mem_size / sol;  //no_frames
	bits = (int)(log(pbit) / log(2));
  	if (mf == 1)
    	printf("\nNumber of bits required in the address for memory having size %dKBis %d bits", ms, bits);
  	else if (mf == 2)
    	printf("\nNumber of bits required in the address for memory having size %dMBis %d bits", ms, bits);
  	else if (mf == 3)
    	printf("\nNumber of bits required in the address for memory having size %d GB is %d bits", ms, bits);
}

