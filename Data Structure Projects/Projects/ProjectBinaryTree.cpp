#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Data{
	char chr[3];
	struct Data *left, *right;
}*root = NULL;

void push(Data **curr, char c[]){
	
	if(*curr == NULL){
		*curr = (struct Data*)malloc(sizeof(struct Data));
		strcpy((*curr)->chr, c);
		(*curr)->left = (*curr)->right = NULL;
	}
	else{
		char selection;
		bool valid = false;
		do{
			printf("Select [L/R]: ");
			scanf("%c", &selection);
			getchar();
			switch(selection){
				case 'l': case 'L':
					//push left
					push(&(*curr)->left, c);
					valid = true;
					break;
				case 'r': case 'R':
					//push right
					push(&(*curr)->right, c);
					valid = true;
					break;
			}
		}while(!valid);
	}
	
}

void preOrder(Data *curr){
	
	if(curr){
		printf("%s ", curr->chr);
		preOrder(curr->left);
		preOrder(curr->right);
	}
	
}

void postOrder(Data *curr){
	
	if(curr){
		postOrder(curr->left);
		postOrder(curr->right);
		printf("%s ", curr->chr);
	}
	
}

void inOrder(Data *curr){
	
	if(curr){
		inOrder(curr->left);
		printf("%s ", curr->chr);
		inOrder(curr->right);
	}
	
}

int main(){
	
	char input[3]={};
	int i, j=0;
	
	scanf("%s", input);
	if(input == "-1"){
		printf("Check\n");
	}
	getchar();
	push(&root, input);
	for(i=0; i<3; i++){
		input[i] = '\0';
	}
	
	while(j<4){
		scanf("%s", input);
		if(input == "-1"){
			break;
		}
		getchar();
		push(&root, input);
		for(i=0; i<3; i++){
			input[i] = NULL;
		}
		j++;
	}
	
//	printf("Pre Order: ");
//	preOrder(root);
//	printf("\n");
	printf("In Order: ");
	inOrder(root);
	printf("\n");
//	printf("Post Order: ");
//	postOrder(root);
//	printf("\n");
	
	return 0;
	
}
