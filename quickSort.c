#include<stdio.h>
#define SIZE 6

void printArray(int a[SIZE]){
	int i;
	for(i=0; i<SIZE; i++){
		printf("%d ", a[i]);
	}
	printf("\n");
}
void quicksort(int a[SIZE], int left, int right){
	if(left>=right) return;	//If partition has one element
	int L=left, R=right;
	int p=L;
	while(L!=R){
		if(p==L){ 					//If pivot is LEFT
			if(a[p]>a[R]){ 			// If pivot > RIGHT
				int temp = a[p];
				a[p] = a[R];
				a[R] = temp;
				p = R;
				printArray(a);
			}
			else R--;
		}
		else{
			if(a[p]<a[L]){ 			// If pivot > RIGHT
				int temp = a[p];
				a[p] = a[L];
				a[L] = temp;
				p = L;
				printArray(a);
			}
			else L++;
		}
	}
	quicksort(a, left, p);
	quicksort(a, p+1, right);
}
int main(){
	int a[SIZE] = {11,69,27,23,0,15};
	printArray(a);
	quicksort(a, 0, SIZE-1); //From 0 to SIZE-1 (Left to Right)
}