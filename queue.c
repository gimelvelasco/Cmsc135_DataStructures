/*
Queue List

Functions:
1.Check Front
2.Check if empty
3.Enqueue
4.Dequeue
5.Clear

Conditions:
1.No Duplicate Elements
2.Sorting in Ascending Order
*/
//Note: uncomment all   usleep() functions when using windows os; comment otherwise.
///////////ME02

#include<stdio.h>
#include<stdlib.h>

struct node{//integer element for the list
	int value;
	struct node *next;
};

struct node * queue_checkfirst(struct node **h){
	struct node *p = *h;
	return p;
}

void queue_enqueue(struct node *e,struct node **h){
	if(*h == NULL){//if empty
		*h = e;
	}
	else{
		struct node *p = *h;
		while(p->next != NULL){
			p = p->next;
		}
		e->next = p->next;
		p->next = e;
	}
}

void queue_dequeue(struct node **h){
	struct node *del = *h;
	*h = (*h)->next;
	free(del);//de-allocate memory for node
}

void print_temp(struct node **h){
	struct node *p = *h;
	if(p == NULL){
		printf("No elements in list.\n");
	}
	else{
		printf("\tLIST\n");
		while(p != NULL){
			printf("Value: %d, Next: %p\n\n", p->value, p->next);
			p = p->next;
		}
	}
}

int main (){
	printf("\n\tQUEUE LIST\n\n");
	////////////
	struct node **head = (struct node **) malloc(sizeof(struct node *));
	*head = NULL;
	//////
	struct node *temp = (struct node *) malloc(sizeof(struct node));
	int chc,dval,nval;
	char ch;
	///////Initial List
	temp = (struct node *) malloc(sizeof(struct node));
	temp->value = 0;
	temp->next = NULL;
	queue_enqueue(temp,head); //queue_enqueue(element, position, list); //inserts node into list
	////
	temp = (struct node *) malloc(sizeof(struct node));
	temp->value = 1;
	temp->next = NULL;
	queue_enqueue(temp,head);
	/////
	temp = (struct node *) malloc(sizeof(struct node));
	temp->value = 2;
	temp->next = NULL;
	queue_enqueue(temp,head);
	///////
	temp = (struct node *) malloc(sizeof(struct node));
	temp->value = 3;
	temp->next = NULL;
	queue_enqueue(temp,head);
	
	do{
		print_temp(head);
		printf("------------------------\n\tSELECT OPERATION:\n[1] Check Front of List\t[2] Check if Empty\n[3] Enqueue\t\t[4] Dequeue\n[5] Clear\t\t[6] Exit\n\nSelect:");
		scanf("\n%d",&chc);
		printf("------------------------\n");

		switch(chc){
			case 1://Function #1
				if(*head != NULL){
					temp = queue_checkfirst(head);
					printf("Front: Value = %d, Next at = %p\n------------------------\n",temp->value,temp->next);
				}
			break;
			case 2://Function #2
				if(*head != NULL){
					temp = queue_checkfirst(head);
					if(temp == NULL){
						printf("List is Empty\n------------------------\n");
					}
					else{
						printf("List is NOT Empty\n------------------------\n");
					}
				}
			break;
			case 3://Function #3
				printf("Insert New Value: ");
				scanf("\n%d",&nval);
				temp = (struct node *) malloc(sizeof(struct node));
				temp->value = nval;
				temp->next = NULL;
				queue_enqueue(temp,head);
			break;
			case 4://Function #4
				if(*head != NULL){
					queue_dequeue(head);
				}
			break;
			case 5://Function #5
				while(*head != NULL){
					queue_dequeue(head);
				}
			break;
			case 6://Exit
				printf("Terminating...\n");
			break;
			default:
				printf("Invalid Choice.");
			break;
		}
	}while(chc != 6);
	//
	return 0;
}