/*
Tree
Functions:
1. Insert
2. View Tree Traversal

*Uses child and sibling links
*/
#include<stdio.h>
#include<stdlib.h>

struct node{//integer element for the list
	int value;
	struct node *child;
	struct node *sibling;
};

void insert(struct node *n, struct node **h){//new node, parent node
	if(*h == NULL){
		*h = n;
	}
	else{
		/*
		struct node *p = *h;
		if(p->child == NULL){
			p->child = n;
			p = p->child;
			//insert(n,p);
		}
		else{
			p = p->child->sibling;
			//insert(n,p);
		}
		*/

		struct node *p = *h;
		if(p->child == NULL){
			p->child = n;
		}
		else{
			p = p->child;
			while(p->sibling != NULL){
				p = p->sibling;
			}
			p->sibling = n;
		}
	}
}

struct node * search_parent(struct node *h, int srch){//for insert function
	struct node *q = h;
	
	if(q->value == srch){
		return q;
	}
	else{
		if(q->child != NULL){
			q = search_parent(q->child,srch);
		}
		else if(q->sibling != NULL){
			q = search_parent(q->sibling,srch);
		}
	}
	return q;
}

void preorder_print(struct node *p){
	if(p!=NULL){
		printf("%d ", p->value);
		preorder_print(p->child);
		preorder_print(p->sibling);
	}
}

void inorder_print(struct node *p){
	if(p!=NULL){
		inorder_print(p->child);
		printf("%d ", p->value);
		inorder_print(p->sibling);
	}
}

void postorder_print(struct node *p){
	if(p!=NULL){
		postorder_print(p->child);
		postorder_print(p->sibling);
		printf("%d ", p->value);
	}
}

void print_temp(struct node *p){
	struct node *q = p;
	printf("\nRoot is of Value: %d, Child: %p, Sibling: %p\n", q->value, q->child, q->sibling);
	if(q->child != NULL){
		print_temp(q->child);
	}
	if(q->sibling != NULL){
		print_temp(q->sibling);
	}
}

int main (){
	int chc,pv;

	printf("\n\tTree\n\n");
	////////////
	struct node **head = (struct node **) malloc(sizeof(struct node *));
	*head = NULL;
	//////
	struct node *temp = (struct node *) malloc(sizeof(struct node));
	//////
	//temp->value = 0;
	printf("Input Root Value: ");
	scanf("%d",&temp->value);
	temp->child = NULL;
	temp->sibling = NULL;
	insert(temp, head);
	
	//use preorder_print(*head)
	do{
		print_temp(*head);
		printf("------------------------\n\tSELECT OPERATION:\n[1] Insert Node in Tree\n[2] View Tree Traversal\n[3] Exit\n\nSelect:");
		scanf("\n%d",&chc);
		printf("------------------------\n");
		switch(chc){
			case 1:
				printf("Input Value of New Node: ");
				temp = (struct node *) malloc(sizeof(struct node));
				scanf("%d",&temp->value);
				temp->child = NULL;
				temp->sibling = NULL;
				printf("Link to Parent of Value: ");
				scanf("%d",&pv);
				struct node **prnt = (struct node **) malloc(sizeof(struct node *));
				*prnt = search_parent(*head,pv);
				//printf("search ok\n");
				printf("Parent is of Value: %d\n", (*prnt)->value);
				insert(temp,prnt);//to change function receiver
				//printf("insert ok\n");
			break;
			case 2:
				printf("Pre-order: ");
				preorder_print(*head);
				printf("\n");
				printf("In-order: ");
				inorder_print(*head);
				printf("\n");
				printf("Post-order: ");
				postorder_print(*head);
				printf("\n");
			break;
			case 3:
				printf("Terminating...\n");
			break;
			default:
				printf("Invalid Choice.");
			break;
		}

	}while(chc != 3);
	
	
	


	//temp = (struct node *) malloc(sizeof(struct node));
	//temp = search_parent(*head,0);
	//printf("Search: %d\n\n",temp->value);

	/*
	temp = (struct node *) malloc(sizeof(struct node));
	temp->value = 1;
	temp->child = NULL;
	temp->sibling = NULL;
	insert(temp, 0, head);
	*/

	return 0;
}