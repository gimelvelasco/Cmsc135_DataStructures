/*
Linked List

Functions:
0.Insert Node
1.Locate Value
2.Access Node
3.Modify Value
4.Delete Node
5.Delete All Nodes
6.Display First Node
7.Display All Nodes

Conditions:
1.No Duplicate Elements
2.Sorting in Ascending Order
*/
//Note: uncomment all usleep() functions when using windows os; comment otherwise.
///////////HW
#include<stdio.h>
#include<stdlib.h>

struct node{//integer element for the list
	int value;
	struct node *next;
};

void list_insert(struct node *e, int pos, struct node **lhead){
	if(*lhead == NULL){//if empty
		*lhead = e;
	}
	else if(pos<=0){//if ___
		e->next = *lhead;
		*lhead = e;
	}
	else{//everything else
		int i=0;
		struct node *ptr = *lhead;
		for(i=0;i<pos-1;i++){
			if(ptr->next == NULL){
				break;
			}
			else{
				ptr = ptr->next;
			}	
		}
		e->next = ptr->next;
		ptr->next = e;
	}
}

void print_list(struct node **h, int con){
	struct node *p = *h;
	if(con==1){//Display First Node
		if(p == NULL){
			printf("------------------------\nNo elements in list.\n");
		}
		else{
			printf("------------------------\nFirst Element\n");
			printf("Value: %d, Next: %p\n\n", p->value, p->next);
		}
	}
	else{//Display All Nodes
		if(p == NULL){
			printf("------------------------\nNo elements in list.\n");
		}
		else{
			printf("------------------------\n\tLIST\n");
			while(p != NULL){
				//usleep(200000);
				printf("Value: %d, Next: %p\n\n", p->value, p->next);
				p = p->next;
			}
		}
	}
}

int list_positionOf(int v, struct node **h){//LOCATE 1
	int pos=0,i;
	struct node *p = *h;

	while(p != NULL){
		if(p->value == v){
			return pos;
		}
		else{
			//walang gagawin
		}
		p = p->next;//hindi ptr++
		pos++;
	}
	return -1;//if no match detected, return value pos = -1
}

struct node * list_at(int pos, struct node **h){//ACCESS node at specified position 2
	if(pos < 0){//invalid position
		return NULL;
	}
	
	int i;
	struct node *p = *h;
	for(i=0;i<pos;i++){
		if(p->next == NULL){
			break;
		}
		else{
			p = p->next;
		}
	}
	return p;
};

struct node * list_changeValue(int pos, int v, struct node **h){//CHANGE value of node at specified position 3
	struct node *temp = list_at(pos,h);
	temp->value = v;
	return temp;
}

void list_deleteByValue(int dv, struct node **h){//DELETE Node by finding value 4
	int pos = list_positionOf(dv,h);
	if(pos<0){//invalid position
		printf("Number %d is not in the list.\n",dv);
	}
	else if(pos == 0){//case for deleteing node at position 0.
		struct node *del = *h;
		*h = (*h)->next;
		free(del);//de-allocate memory for node
	}
	else{//case for others
		pos -= 1;
		struct node *p = list_at(pos,h);
		struct node *del = p->next;
		p->next = (del)->next;
		free(del);
	}
}

void list_deleteAll(struct node **h){
	struct node *p = *h;
	while(*h != NULL){
		p = *h;
		*h = p->next;
		free(p);
	}
}

int list_length(struct node **h){
	struct node *p = *h;
	int len = 0;
	while(p != NULL){
		len++;
		p = p->next;
	}
	return len;
}

void list_sort(struct node **h,int sz){
	struct node *p = *h;
	int i,j,q,b=0;
	
	for(i=0;i<sz-1;i++){
		p = *h;
		for(j=0;j<(sz-1-i);j++){
			if((p->value) > (p->next->value)){//swap
				q = p->value;
				p->value = p->next->value;
				p->next->value = q;
				b=1;
			}
			p = p->next;
		}
	}
	if(b==1){
		printf("Sorted in Ascending Order.\n");
	}
}

void list_dupl(struct node **h){
	struct node *p = *h;
	struct node *q;
	int dval;

	while(p->next != NULL){
		q = p->next;
		if(p->value == p->next->value){
			printf("Repeated Values Detected.\n");
			dval = p->value;
			list_deleteByValue(dval,h);
		}
		p = q;
	}

}

int main () {
	printf("\n\tLINKED LIST\n\n");
	//usleep(999999);
	////////////
	struct node **head = (struct node **) malloc(sizeof(struct node *));
	*head = NULL;
	//////
	struct node *temp = (struct node *) malloc(sizeof(struct node));
	int chc,srch,newValue,dval,npos,nval;
	char ch;
	///////Initial List
	temp = (struct node *) malloc(sizeof(struct node));
	temp->value = 0;
	temp->next = NULL;
	list_insert(temp,0,head); //list_insert(element, position, list); //inserts node into list
	////
	temp = (struct node *) malloc(sizeof(struct node));
	temp->value = 1;
	temp->next = NULL;
	list_insert(temp,1,head);
	/////
	temp = (struct node *) malloc(sizeof(struct node));
	temp->value = 2;
	temp->next = NULL;
	list_insert(temp,2,head);
	///////
	temp = (struct node *) malloc(sizeof(struct node));
	temp->value = 3;
	temp->next = NULL;
	list_insert(temp,3,head);
	////////

	//////////MAIN MENU
	do{
		///////
		printf("------------------------\n\tSELECT OPERATION:\n[1] Insert Node\t\t[2] Locate Value\n[3] Access Node\t\t[4] Modify Value\n[5] Delete Node\t\t[6] Delete All Nodes\n[7] Display First Node\t[8] Display All Nodes\n[9] Exit\n\nSelect:");
		scanf("\n%d",&chc);
		printf("------------------------\n");
		switch(chc){
			case 1://Function #0
				printf("Input Value:");
				scanf("\n%d",&nval);
				printf("Input Position:");
				scanf("\n%d",&npos);
				temp = (struct node *) malloc(sizeof(struct node));
				temp->value = nval;
				temp->next = NULL;
				list_insert(temp,npos,head);
				print_list(head,0);
				list_sort(head,list_length(head));//Condition #1
				list_dupl(head);//Condition #2
			break;
			case 2://Function #1
				printf("Find Position with Value of:");
				scanf("%d",&srch);
				int posi = list_positionOf(srch,head);
				
				if(posi<0){
					printf("The Number %d is not in the list.\n", srch);
				}
				else{
					printf("The Number %d is at position %d.\n",srch,posi);
				}
			break;
			case 3://Function #2
				printf("Find Value and Address of Node at Position:");
				scanf("%d",&posi);
				temp  = list_at(posi,head);
				if(temp == NULL){
					printf("Invalid Position\n");
				}
				else{
					printf("Node at position %d: Value = %d, Next at = %p\n",posi,temp->value,temp->next);
				}
			break;
			case 4://Function #3
				printf("Change value of node at position:");
				scanf("%d",&posi);
				printf("New Value:");
				scanf("%d",&newValue);
				temp = list_changeValue(posi,newValue,head);
				print_list(head,0);
				list_sort(head,list_length(head));//Condition #1
				list_dupl(head);//Condition #2
			break;
			case 5://Function #4
				printf("Delete Node with Value:");
				scanf("%d",&dval);
				list_deleteByValue(dval,head);
				print_list(head,0);
			break;
			case 6://Function #5
				printf("Delete All Nodes? (y/n):");
				scanf("\n%c",&ch);
				if(ch == 'y'){
					list_deleteAll(head);
				}
				print_list(head,0);
			break;
			case 7://Function #6
				print_list(head,1);
			break;
			case 8://Function #7
				print_list(head,0);
			break;
			case 9:
				printf("Terminating...");
			break;
			default:
				printf("Invalid Choice.");
			break;
		}
		//usleep(750000);
	}while(chc != 9);
	
	return 0;
}
/*
Un-organized vs Self-organizing Linked List (wrt Time Complexity)
	Similarities:
		-
	Differences:
		-Navigating through the Self-organizing Linked List would be faster than the other due to the availability of a tree structure finding in the list.
		-Overwriting same values would be faster for S.O. Linked Lists since checking it would just require adjacency instead of checking the whole list.
		-Also in the concept of Page Ranking, a S.O. Linked List is much more beneficial. e.g. Google's Pagerank
*/
/*/////////////////////////////////////////
2012-58922
VELASCO, Gimel David F.
/////////////////////////
2014-80002
FAJARDO, John Kenneth D.
*//////////////////////////////////////////