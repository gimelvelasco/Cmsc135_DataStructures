/*
Binary Tree
Functions:
1. Encode
2. Decode
3. Display (Pre-order)

*Uses left and right child links
*Inputs are hardcoded
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define strmax 31

struct node{//integer element for the list
	char value;
	int freq;
	struct node *left;
	struct node *right;
	struct node *templink;
};

void insert(struct node *n, struct node **h){//new node, parent node
	if(*h == NULL){
		*h = n;
	}
	else{
		struct node *p = *h;
		while(p->templink != NULL){
			p = p->templink;
		}
		n->templink = p->templink;
		p->templink = n;
	}
}

void preorder_print(struct node *p){
	if(p!=NULL){
		printf("%d ", p->freq);
		preorder_print(p->left);
		preorder_print(p->right);
	}
}

void encode(char *str, struct node *h){
	printf("Hihihihi T-T\n");
}

void decode(char *str, struct node *h){
	int len = strlen(str);
	int i=0,j=0,k=0;
	struct node *p = h;
	char dstr[strmax];
	while(j != len){
		if(str[j] == '0'){
			p = p->left;
			if(p->value == '0'){
				if(j == len-1){
					k = 1;
				}
			}
			else{
				dstr[i] = p->value;
				p = h;
				i++;
			}
		}
		else{
			p = p->right;
			if(p->value == '0'){
				if(j == len-1){
					k = 1;
				}
			}
			else{
				dstr[i] = p->value;
				p = h;
				i++;
			}
		}
		j++;
	}
	if(k==0){
		printf("Decoded: %s\n", dstr);	
	}
	else{
		printf("Invalid Sequence.\n");
	}
}

void temp_print(struct node **h){
	struct node *p = *h;
	if(p == NULL){
		printf("------------------------\nNo elements in list.\n");
	}
	else{
		printf("------------------------\n\tLIST\n");
		while(p != NULL){
			printf("V: %c, F: %d, TL: %p, L: %p, R: %p\n\n", p->value, p->freq, p->templink, p->left, p->right);
			p = p->templink;
		}
	}
}

void temp_sort(struct node **h,int sz){
	struct node *p = *h;
	int i,j,q;
	char r;
	struct node *s;
	struct node *t;
	for(i=0;i<sz-1;i++){
		p = *h;
		for(j=0;j<(sz-1-i);j++){
			if((p->freq) > (p->templink->freq)){//swap
				q = p->freq;
				p->freq = p->templink->freq;
				p->templink->freq = q;

				r = p->value;
				p->value = p->templink->value;
				p->templink->value = r;
			
				s = p->left;
				p->left = p->templink->left;
				p->templink->left = s;
			
				t = p->right;
				p->right = p->templink->right;
				p->templink->right = t;
			}
			p = p->templink;
		}
	}
}

int temp_length(struct node **h){
	struct node *p = *h;
	int len = 0;
	while(p != NULL){
		len++;
		p = p->templink;
	}
	return len;
}

void huffman(struct node **h){

	if(temp_length(h) == 1){
		return;
	}
	else{
		temp_sort(h, temp_length(h));
		//temp_print(h);
		struct node *p = *h;

		struct node *temp = (struct node *) malloc(sizeof(struct node));
		temp->value = '0';
		temp->freq = p->freq + p->templink->freq;
		temp->left = p;
		temp->right = p->templink;
		temp->templink = NULL;
		insert(temp,h);

		p = *h;
		*h = (*h)->templink;
		p->templink = NULL;
		p = *h;
		*h = (*h)->templink;
		p->templink = NULL;
		
		huffman(h);
	}
	//sort
	//add first two then insert parent
	//link left and right to parent
	//remove temp link of two
	//repeat first until templink==1
}

int main (){
	int chc,pv;
	char str[strmax];

	printf("\n\tTree\n\n");
	////////////
	struct node **head = (struct node **) malloc(sizeof(struct node *));
	*head = NULL;
	//////
	struct node *temp = (struct node *) malloc(sizeof(struct node));
	//////
	//Hardcode inputs here
	temp = (struct node *) malloc(sizeof(struct node));
	temp->value = 'a';
	temp->freq = 1;
	temp->left = NULL;
	temp->right = NULL;
	temp->templink = NULL;
	insert(temp,head);

	temp = (struct node *) malloc(sizeof(struct node));
	temp->value = 'b';
	temp->freq = 2;
	temp->left = NULL;
	temp->right = NULL;
	temp->templink = NULL;
	insert(temp,head);

	temp = (struct node *) malloc(sizeof(struct node));
	temp->value = 'c';
	temp->freq = 3;
	temp->left = NULL;
	temp->right = NULL;
	temp->templink = NULL;
	insert(temp,head);

	temp = (struct node *) malloc(sizeof(struct node));
	temp->value = 'e';
	temp->freq = 5;
	temp->left = NULL;
	temp->right = NULL;
	temp->templink = NULL;
	insert(temp,head);

	temp = (struct node *) malloc(sizeof(struct node));
	temp->value = 'd';
	temp->freq = 4;
	temp->left = NULL;
	temp->right = NULL;
	temp->templink = NULL;
	insert(temp,head);
	///////
	huffman(head);
	///////
	do{
		//temp_print(head);
		printf("------------------------\n\tSELECT OPERATION:\n[1] Encode\n[2] Decode\n[3] Display(Pre-order)\n[4] Exit\n\nSelect:");
		scanf("\n%d",&chc);
		printf("------------------------\n");
		switch(chc){
			case 1:
				printf("Encode\nInput: ");
				scanf("%s", &str);
				encode(str, *head);
			break;
			case 2:
				printf("Decode\nInput: ");
				scanf("%s", &str);
				decode(str, *head);
			break;
			case 3:
				printf("Pre-order: ");
				preorder_print(*head);
				printf("\n");
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