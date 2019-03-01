/*
Binary Search Tree
Functions:
1. Insert a new Element in the Tree
2. Delete an Element of the Tree
3. Check an Element of the Tree
4. Maximum Element of the Tree
5. Minimum Element of the Tree
6. View Tree Traversal - this is just for the convenience of the user (not actually part of the BST Functions)

Conditions:
-No duplicate elements
-Code uses Pre-order Tree Traversal

Coded by:
2012-58922
VELASCO, Gimel David F.
*/
#include <stdio.h>
#include <stdlib.h>

struct node {
	float value;
	struct node *left;
	struct node *right;
	struct node *parent;
};

struct node * preorder_check(struct node *p, float cval){
	struct node *q;//secondary pointer
	struct node *r;//tertiary pointer
	if(p!=NULL){
		if(p->value == cval){
			return p;
		}
		q = preorder_check(p->left, cval);
		if(q != NULL) return q;					//checks if the element is found then returns
		r = preorder_check(p->right, cval);
		if(r != NULL) return r;
	}
}

int dupl(struct node *p, float cval){	//function used for checking if the desired new element has a duplicate
	struct node *q;
	q = preorder_check(p,cval);
	if(q == NULL){
		return 1;
	}
	else{
		return 2;	
	}
}

struct node * insert(struct node * e, float nval){
	int i = dupl(e,nval);
	if(i == 1){		//this if-else block is to avoid inserting duplicate elements
		if(e == NULL){
			e = (struct node*) malloc(sizeof(struct node));
			e->value = nval;
			e->left = NULL;
			e->right = NULL;
		}
		else if(nval < e->value){
			e->left = insert(e->left, nval);
			e->left->parent = e;	//links the node to its supposed parent
		}
		else{
			e->right = insert(e->right, nval);
			e->right->parent = e;
		}
		return e;
	}
	else{
		printf("Element already exists.\n");
		return e;
	}
}

void preorder_print(struct node *p){
	if(p!=NULL){
		printf("%.2f ", p->value);
		preorder_print(p->left);
		preorder_print(p->right);
	}
}

struct node * maximum(struct node *p){
	while(p->right != NULL){
		p = p->right;
	}
	return p;
}

struct node * minimum(struct node *p){
	while(p->left != NULL){
		p = p->left;
	}
	return p;
}

void preorder_delete(struct node *p, float dval){
	struct node *q;		//node to be deleted
	struct node *r;		//maximum of left subtree of q
	q = preorder_check(p,dval);
	if(q != NULL){
		if(q->left != NULL){
			r = maximum(q->left);
			printf("to Del: %f\nLmax: %f\n",q->value,r->value);
			q->value = r->value;
			r->parent->right = r->left;
			free(r);
		}
		else{
			printf("to Del: %f\nw/o left subtree.\n",q->value);
			if(q->parent->right == q){
				q->parent->right = q->right;
				free(q);
			}
			else{
				q->parent->left = q->right;
				free(q);
			}
		}
	}
	else{
		printf("%f is NOT a member.\n", dval);
	}
}

int main (){
	int chc;
	float nval;

	printf("\n\tTree\n\n");
	////////////
	struct node **head = (struct node **) malloc(sizeof(struct node *));
	*head = NULL;
	//////
	struct node *temp = (struct node *) malloc(sizeof(struct node));
	//////Insert hardcoded inputs here.
	*head = insert(*head, 2);
	*head = insert(*head, 1);
	*head = insert(*head, 3);
	
	//
	do{
		printf("------------------------\n\tSELECT OPERATION:\n[1] Insert Node in Tree\n[2] Delete Node in Tree\n[3] Check Member\n[4] Tree Maximum\n[5] Tree Minimum\n[6] View Pre-order Tree Traversal\n[7] Exit\n\nSelect:");
		scanf("\n%d",&chc);
		printf("------------------------\n");
		switch(chc){
			case 1:
				printf("Input Value: ");
				scanf("%f", &nval);
				*head = insert(*head, nval);
			break;
			case 2:
				printf("Input Value: ");
				scanf("%f", &nval);
				preorder_delete(*head, nval);
			break;
			case 3:
				printf("Input Value: ");
				scanf("%f", &nval);
				temp = (struct node *) malloc(sizeof(struct node));
				temp = preorder_check(*head, nval);
				if(temp != NULL){
					printf("Element %f is a member.\n", temp->value);
				}
				else{
					printf("%f is NOT a member.\n", nval);
				}
			break;
			case 4:
				if(*head != NULL){
					temp = (struct node *) malloc(sizeof(struct node));
					temp = maximum(*head);
					printf("Maximum is %f\n", temp->value);
				}
				else{
					printf("Tree is empty.\n");
				}
			break;
			case 5:
				if(*head != NULL){
					temp = (struct node *) malloc(sizeof(struct node));
					temp = minimum(*head);
					printf("Minimum is %f\n", temp->value);
				}
				else{
					printf("Tree is empty.\n");
				}
			break;
			case 6:
				if(*head != NULL){
					printf("Pre-order: ");
					preorder_print(*head);
					printf("\n");
				}
				else{
					printf("Tree is empty.\n");
				}
			break;
			case 7:
				printf("Program Terminated.\n");
			break;
			default:
				printf("Invalid Choice.\n");
			break;
		}
	}while(chc != 7);
	return 0;
}