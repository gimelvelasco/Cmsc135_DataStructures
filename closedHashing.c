/*
DICTIONARY
Closed Hashing

Functions:
1. Insert
2. Search
3. Modify
4. Delete

Conditions:
-No Elements of the same Key
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define smax 31

struct node{//integer element for the list
	char key[smax];
	char value[smax];
	struct node *next;
};

void dic_insert(struct node *e,struct node **h){
	if(*h == NULL){//if empty
		*h = e;
	}
	else{
		printf("List is Full.\n");
	}
}

int dic_convert(char key[smax]){
	int k=0,len,i=0;
	len = strlen(key);
	while(i != len){
		k += key[i];
		i++;
	}
	k = k%13;
	return k;
}

void dic_search(char inkey[smax], struct node **h[13]){
	int i=0;
	struct node *p;
	while(i<13){
		p = *h[i];
		if(p != NULL){
			if(strcmp(inkey, p->key) == 0){
				printf("Key: %s, Value: %s\n", p->key, p->value);
				return;
			}
		}
		i++;
	}
	printf("Key does not exist.\n");

}

void dic_modify(char inkey[smax], struct node **h[13]){
	int i=0;
	struct node *p;
	while(i<13){
		p = *h[i];
		if(p != NULL){
			if(strcmp(inkey, p->key) == 0){
				printf("Input New Value: ");
				gets(p->value);
				return;
			}
		}
		i++;
	}
	printf("Key does not exist.\n");
}

void dic_delete(char inkey[smax], struct node **h[13]){
	int i=0;
	struct node *p;
	while(i<13){
		p = *h[i];
		if(p != NULL){
			if(strcmp(inkey, p->key) == 0){
				struct node *del = *h[i];
				*h[i] = (*h[i])->next;
				free(del);
				printf("Element is Deleted.\n");
				return;
			}
		}
		i++;
	}
	printf("Key does not exist.\n");
}

int dic_check(int k, struct node **h[13]){
	int i,j=0;
	for(i=0;i<13;i++){
		if(*h[i] == NULL){
			j=1;
			break;
		}
	}
	if(j==1){//if not full
		if(*h[k] != NULL){
			k++;
			k = k%13;
			k = dic_check(k,h);
		}
	}
	else{//if full
		k=0;
	}
	return k;
}

void temp_print(struct node **h){
	struct node *p = *h;
	if(p == NULL){
		printf("------------------------\nNo elements in list.\n");
	}
	else{
		printf("------------------------\n");
		while(p != NULL){
			printf("Key: %s, Value: %s, Next: %p\n", p->key, p->value, p->next);
			p = p->next;
		}
	}
}

int main (){
	int i, k, chc;
	char inkey[smax];
	char invalue[smax];
	char dmp;

	printf("\n\tDictionary\n\n");
	////////////
	struct node **head[13];
	for(i=0;i<13;i++){
		head[i] = (struct node **) malloc(sizeof(struct node *));
		*head[i] = NULL;
	}
	//////
	struct node *temp = (struct node *) malloc(sizeof(struct node));
	
	//////Hardcoded inputs here
	temp = (struct node *) malloc(sizeof(struct node));
	strcpy(temp->key,"cmsc123");
	strcpy(temp->value,"martin");
	temp->next = NULL;
	k = dic_check(dic_convert(temp->key),head);
	dic_insert(temp,head[k]);
	
	temp = (struct node *) malloc(sizeof(struct node));
	strcpy(temp->key,"cmsc131");
	strcpy(temp->value,"martin");
	temp->next = NULL;
	k = dic_check(dic_convert(temp->key),head);
	dic_insert(temp,head[k]);

	temp = (struct node *) malloc(sizeof(struct node));
	strcpy(temp->key,"cmsc55");
	strcpy(temp->value,"eloise");
	temp->next = NULL;
	k = dic_check(dic_convert(temp->key),head);
	dic_insert(temp,head[k]);

	temp = (struct node *) malloc(sizeof(struct node));
	strcpy(temp->key,"cmsc190");
	strcpy(temp->value,"joel");
	temp->next = NULL;
	k = dic_check(dic_convert(temp->key),head);
	dic_insert(temp,head[k]);

	temp = (struct node *) malloc(sizeof(struct node));
	strcpy(temp->key,"math54");
	strcpy(temp->value,"reymart");
	temp->next = NULL;
	k = dic_check(dic_convert(temp->key),head);
	dic_insert(temp,head[k]);
	
	do{
		/*//Uncomment if want to see full list
		for(i=0;i<13;i++){
			printf("Head %d", i);
			temp_print(head[i]);
		}
		*/
		printf("------------------------\n\tSELECT OPERATION:\n[1] Insert\n[2] Modify\n[3] Search\n[4] Delete\n[5] Exit\n\nSelect:");
		scanf("\n%d",&chc);
		scanf("%c", &dmp);
		printf("------------------------\n");
		switch(chc){
			case 1:
				temp = (struct node *) malloc(sizeof(struct node));
				printf("Input Key: ");
				gets(inkey);
				strcpy(temp->key,inkey);
				printf("Input Value: ");
				gets(invalue);
				strcpy(temp->value,invalue);
				temp->next = NULL;
				k = dic_check(dic_convert(temp->key),head);
				dic_insert(temp,head[k]);
			break;
			case 2:
				printf("Input Key: ");
				gets(inkey);
				dic_modify(inkey,head);
			break;
			case 3:
				printf("Input Key: ");
				gets(inkey);
				dic_search(inkey,head);
			break;
			case 4:
				printf("Input Key: ");
				gets(inkey);
				dic_delete(inkey,head);
			break;
			case 5:
				printf("Program Terminated.\n");
			break;
			default:
				printf("Invalid Choice.\n");
			break;
		}
	}while(chc != 5);
	return 0;
}