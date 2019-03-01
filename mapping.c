/*
Mapping

Functions:
1.Assign
2.Retrieve
3.Clear
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{//integer element for the list
	//DOMAIN
	int id;
	//RANGE
	char name[30];
	int age;
	struct node *next;
};

void map_assign(struct node *temp2, int pos, struct node **h){
	if(*h == NULL){
		*h = temp2;
	}
	else{
		int i=0;
		struct node *p = *h;
		for(i=0;i<pos-1;i++){
			if(p->next == NULL){
				break;
			}
			else{
				p = p->next;
			}	
		}
		temp2->next = p->next;
		p->next = temp2;
	}
}

void map_clear(struct node **h){
	struct node *p = *h;
	while(*h != NULL){
		p = *h;
		*h = p->next;
		free(p);
	}
}

void print_map(struct node **h){
	struct node *p = *h;
	//Display All Nodes
	if(p == NULL){
		printf("------------------------\nNo elements in list.\n");
	}
	else{
		printf("------------------------\n\tLIST\n");
		while(p != NULL){
			//usleep(200000);
			printf("ID: %d, Name: %s, Age: %d, Next: %p\n\n", p->id, p->name, p->age, p->next);
			p = p->next;
		}
	}
}

void map_retrieve(int id2, struct node **h){
	struct node *p = *h;

	while(p != NULL){
		if(p->id == id2){
			printf("ID: %d\nName: %s\nAge: %d\n",p->id,p->name,p->age);
		}
		p = p->next;//hindi ptr++
	}
}

int main (){
	printf("\n\tMAPPING List\n\n");
	////////////
	struct node **head = (struct node **) malloc(sizeof(struct node *));
	*head = NULL;
	//////
	struct node *temp = (struct node *) malloc(sizeof(struct node));
	int chc,srch,newValue,dval,npos,nval;
	char ch,str[30],dump;
	///////Initial List
	temp = (struct node *) malloc(sizeof(struct node));
	temp->id = 1;
	strcpy(temp->name,"Gimel");
	temp->age = 19;
	temp->next = NULL;
	map_assign(temp,0,head);
	////
	temp = (struct node *) malloc(sizeof(struct node));
	temp->id = 2;
	strcpy(temp->name,"David");
	temp->age = 20;
	temp->next = NULL;
	map_assign(temp,1,head);
	////////
	temp = (struct node *) malloc(sizeof(struct node));
	temp->id = 3;
	strcpy(temp->name,"Kenneth");
	temp->age = 18;
	temp->next = NULL;
	map_assign(temp,2,head);
	////////
	npos=3;
	//////////MAIN MENU
	do{
		print_map(head);
		///////
		printf("------------------------\n\tSELECT OPERATION:\n[1] Assign\t\t[2] Retrieve\n[3] Clear\t\t[4] Exit\n\nSelect:");
		scanf("\n%d",&chc);
		printf("------------------------\n");
		switch(chc){
			case 1://Function #0
				temp = (struct node *) malloc(sizeof(struct node));
				printf("Input ID:");
				scanf("%d",&temp->id);
				scanf("%c",&dump);
				printf("Input Name:");
				gets(temp->name);
				printf("Input Age:");
				scanf("%d",&temp->age);
				map_assign(temp,npos,head);
				npos++;
			break;
			case 2://Function #1
				printf("Retrieve Name and Age with ID of:");
				scanf("%d",&srch);
				map_retrieve(srch,head);
			break;
			case 3://Function #2
				map_clear(head);
			break;
			case 4:
				printf("Terminating...\n");
			break;
			default:
				printf("Invalid Choice.");
			break;
		}
	}while(chc != 4);
	
	return 0;
}