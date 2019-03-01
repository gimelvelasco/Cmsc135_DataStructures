/*
BIN SORT
which is also known as Bucket Sort

Code by:
2012-58922
VELASCO, Gimel David F.

Sources:
Pseudocode on
https://www.safaribooksonline.com/library/view/algorithms-in-a/9780596516246/httpatomoreillycomsourceoreillyimages595757.png
Recycled codes on discussion code

Note:
The bubble sort instead of the insertion sort is used for sorting the buckets
*redefine SIZE and array 'a' in main function to input initial array
*/

#include <stdio.h>
#define SIZE 8
#define LMT 999

void printArray(int a[SIZE]){//this printArray function is from the discussion code
	int i;
	for(i=0;i<SIZE;i++){
		printf("%d ", a[i]);
	}
	printf("\n\n");
}

void bubblesort(int a[SIZE]){//this bubblesort function is recycled from the discussion code
	int i,j;
	for(i=0;i<SIZE-1;i++){
		for(j=0;j<SIZE-1;j++){
			if(a[j]>a[j+1]){
				int temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
}

int hash(int k){//this function groups each element into the floor function of its 1/3 value
	k = k/3;
	return k;
}

void extract(int b[SIZE][SIZE], int a[SIZE]){//this function sorts each bucket in B and then inserts it into A
	int i,j,idx = 0;
	for(i=0;i<SIZE;i++){
		bubblesort(b[i]);
		for(j=0;j<SIZE;j++){
			if(b[i][j] != LMT){
				a[idx] = b[i][j];
				idx++;
			}
			else{
				break;
			}
		}
	}
}

int main(){//bucket sort function

	int a[SIZE] = {8,7,6,5,4,3,2,1};
	int b[SIZE][SIZE];
	int min,max,i,j,k;

	for(i=0;i<SIZE;i++){//initializes B array
		for(j=0;j<SIZE;j++){
			b[i][j] = LMT;
		}
	}
	for(i=0;i<SIZE;i++){
		k = hash(a[i]);
		for(j=0;j<SIZE;j++){//this for loop adds the ith element in A to the kth bucket in B
			if(b[k][j] == LMT){
				b[k][j] = a[i];
				break;
			}
		}
	}
	printf("Initial Array:\n");
	printArray(a);

	extract(b,a);
	
	printf("Sorted Array:\n");
	printArray(a);
	return 0;
}