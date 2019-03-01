#include <stdio.h>
#define SIZE 8


void printArray(int a[SIZE]){
	int i;
	for (i=0; i<SIZE; i++){
		printf("%d", a[i]);
	}	printf("\n");
}

void insertion(int a[SIZE]){
	int i, j;										//  
	for(i=1; i<SIZE; i++){							//	Outer loop executes SIZE-1 times =>	O(n-1) => O(N)			
		for(j=i-1; j>=0; j--){						//	Inner loop executes SIZE-1 times => O(n-1) => O(N)	
			if(a[j]>a[j-1]){						//			
				int temp = a[j];					//	Therefore, (N^2)		
				a[j] = a[j+1];						//			
				a[j+1] = temp;						//			
				printArray(a);
			}else break;							// 	
		}
		printf("end of iteration # %d\n",i);
	}
}

void selection(int a[SIZE]){
	int i,j;										//
	for (i=0; i<SIZE-1; i++){						//	Outer loop executes SIZE-1 times =>	O(n-1) => O(N)	
		int min = a[i],ind =i;						//								
		for (j=i; j<SIZE; j++){						//	Inner loop executes SIZE-1 times => O(n-1) => O(N)		
			if (a[j]<a[ind]) ind=j;					//	Therefore, (N^2)		
		}
		//SWAP````
		int temp = a[i];							//2		
		a[i]=a[ind];								//2		
		a[ind] =temp;								//1		
		printArray(a);
	}
}

void bubblesort(int a[SIZE]){
	int i, j;
	for(i=0; i<SIZE-1; i++){						// Outer loop executes SIZE-1 times => O(n-1) => O(N)
		for(j=0; j<SIZE-1;j++){						// Inner loop executes SIZE-1 times => O(n-1) => O(N)	
			if(a[j]>a[j+1]){						// Therefore, (N^2)	
				//swap
				int temp = a[j]								//
				a[j] = a[j+1];								//
				a[j+1] = temp;								//
				printArray(a);
			}
		}
	}
}

int main(){
	int a[SIZE] ={8,7,6,5,4,3,2,1};
	selection(a);
}