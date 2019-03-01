/*
PRIORITY QUEUE

Functions:
1. Insert
2. Retrieve
3. Remove

Conditions:
-Array is of size 16
-Parent Priority >= Child Priority
*/

#include <stdio.h>
#include <stdlib.h>

struct element{
	int priority;
	float v1;
	float v2;
};

void pq_insert(struct element *e,struct element **h){
	if(*h == NULL){//if empty
		*h = e;
	}
}

int pq_length(struct element **h[16]){
	int len=0, i;
	for(i=0;i<16;i++){
		if(*h[i] != NULL){
			len++;
		}
	}
	return len;
}

void pq_swap(struct element **p1,struct element **p2){
	struct element *t = *p1;
	*p1 = *p2;
	*p2 = t;
}

void pq_retrieve(struct element **h){
	printf("Index: 1\nPriority: %d\nv1: %f\nv2: %f\n\n", (*h)->priority, (*h)->v1, (*h)->v2);
}

void pq_checkin(struct element **h[16], int k){
	if(k != 0){
		if((*h[k/2])->priority < (*h[k])->priority){//par < chi
			pq_swap(h[k/2], h[k]);
			pq_checkin(h, k/2);
		}
	}
}

void pq_checkout(struct element **h[16], int k){
	if(k <= 7){
		if(*h[(k*2)+1] != NULL){
			if(((*h[k])->priority < (*h[k*2])->priority)&&((*h[k])->priority < (*h[(k*2)+1])->priority)){
				if((*h[k*2])->priority < (*h[(k*2)+1])->priority){
					pq_swap(h[k],h[(k*2)+1]);//swap par, Rchi
					pq_checkout(h,(k*2)+1);
				}
				else{
					pq_swap(h[k],h[k*2]);//swap par, Lchi
					pq_checkout(h,k*2);
				}
			}
			else if((*h[k])->priority < (*h[k*2])->priority){
				pq_swap(h[k],h[k*2]);
				pq_checkout(h,k*2);
			}
			else if((*h[k])->priority < (*h[(k*2)+1])->priority){
				pq_swap(h[k],h[(k*2)+1]);
				pq_checkout(h,(k*2)+1);
			}
		}
		else if(*h[k*2] != NULL){
			if((*h[k])->priority < (*h[k*2])->priority){
				pq_swap(h[k],h[k*2]);
			}
		}
	}
}

void pq_remove(struct element **h[16]){
	int len = pq_length(h);
	pq_swap(h[1],h[len-1]);
	*h[len-1] = NULL;
	pq_checkout(h,1);
}

int main (){
	int i, j, chc, k=0;

	printf("\n\tPriority Queue\n\n");
	////////////
	struct element **head[16];
	for(i=0;i<16;i++){
		head[i] = (struct element **) malloc(sizeof(struct element *));
		*head[i] = NULL;
	}
	//////
	struct element *temp = (struct element *) malloc(sizeof(struct element));
	//////
	temp = (struct element *) malloc(sizeof(struct element));
	temp->priority = 111;
	temp->v1 = 0;
	temp->v2 = 0;
	pq_insert(temp,head[k]);//extra
	k++;

	/*//Input block//for testing purposes
	for(i=1;i<16;i++){
		temp = (struct element *) malloc(sizeof(struct element));
		temp->priority = 15-i;
		temp->v1 = i-1;
		temp->v2 = i-1;
		pq_insert(temp,head[k]);
		pq_checkin(head,k);
		k++;
	}
	*/
	
	//Put Hardcoded Inputs here
	temp = (struct element *) malloc(sizeof(struct element));
	temp->priority = 0;
	temp->v1 = 0;
	temp->v2 = 0;
	pq_insert(temp,head[k]);
	pq_checkin(head,k);
	k++;
	////
	temp = (struct element *) malloc(sizeof(struct element));
	temp->priority = 1;
	temp->v1 = 1;
	temp->v2 = 1;
	pq_insert(temp,head[k]);
	pq_checkin(head,k);
	k++;
	////







	////
	do{
		/*//Uncomment if want to see full list
		printf("Array: ");
		for(i=0;i<16;i++){
			if(*head[i] != NULL){
				printf("%d ", (*head[i])->priority);
			}	
		}
		printf("\n");
		*/
		
		printf("------------------------\n\tSELECT OPERATION:\n[1] Insert Element\n[2] Retrieve Highest Priority\n[3] Remove Highest Priority\n[4] Exit\n\nSelect:");
		scanf("\n%d",&chc);
		printf("------------------------\n");
		switch(chc){
			case 1:
				if(k == 16){
					printf("Can't Insert Element. Already Full.\n");
				}
				else{
					temp = (struct element *) malloc(sizeof(struct element));
					printf("Input Priority: ");
					scanf("%d", &temp->priority);
					printf("Input v1: ");
					scanf("%f", &temp->v1);
					printf("Input v2: ");
					scanf("%f", &temp->v2);
					pq_insert(temp,head[k]);
					pq_checkin(head,k);
					k++;
				}
			break;
			case 2:
				if(pq_length(head) != 1){
					pq_retrieve(head[1]);
				}
				else{
					printf("Priority Queue is empty.\n");
				}
			break;
			case 3:
				if(pq_length(head) != 1){
					pq_remove(head);
					k--;
				}
				else{
					printf("Priority Queue is already empty.\n");
				}
			break;
			case 4:
				printf("Program Terminated.\n");
			break;
			default:
				printf("Invalid Choice.\n");
			break;
		}
	}while(chc != 4);
	return 0;
}