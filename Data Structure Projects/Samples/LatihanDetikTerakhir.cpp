#include <stdio.h>
#include <stdlib.h>

struct Data{
	int num;
	struct Data *left, *right;
}*root;

struct Data *add(struct Data *node, int num){
	
	if(node == NULL){
		node = (struct Data*) malloc(sizeof(struct Data));
		node->num = num;
		node->left = node->right = NULL;
	}
	else{
		if(num < node->num){
			node->left = add(node->left, num);
		}
		else if(num > node->num){
			node->right = add(node->right, num);
		}
	}
	
	return node;
	
}

struct Data *findMax(struct Data *curr){
	
	if(curr != NULL){
		while(curr->right != NULL){
			curr = curr->right;
		}
		return curr;
	}
	
}

struct Data *del(struct Data *node, int num){
	
	if(node == NULL){
		printf("Gk ad data coeg\n");
		return node;
	}
	
	if(num < node->num){
		node->left = del(node->left, num);
	}
	else if(num > node->num){
		node->right = del(node->right, num);
	}
	else{
		if(node->left == NULL && node->right == NULL){
			free(node);
			node = NULL;
		}
		else if(node->left == NULL){
			struct Data *temp = node;
			node = node->right;
			free(temp);
		}
		else if(node->right == NULL){
			struct Data *temp = node;
			node = node->left;
			free(temp);
		}
		else{
			struct Data *temp = findMax(node->left);
			node->num = temp->num;
			node->left = del(node->left, num);
		}
	}
	
	return node;
	
}

void pre(struct Data *curr){
	
	if(curr!=NULL){
		printf("%d ", curr->num);
		pre(curr->left);
		pre(curr->right);
	}
	
}

void in(struct Data *curr){
	
	if(curr!=NULL){
		in(curr->left);
		printf("%d ", curr->num);
		in(curr->right);
	}
	
}

void post(struct Data *curr){
	
	if(curr!=NULL){
		post(curr->left);
		post(curr->right);
		printf("%d ", curr->num);
	}
	
}

int main(){
	
	root = add(root, 5);
	root = add(root, 3);
	root = add(root, 7);
	root = add(root, 2);
	root = add(root, 4);
	root = add(root, 6);
	root = add(root, 8);
	
	printf("Hasil pre:\n");
	pre(root);
	printf("\n");
	printf("Hasil in:\n");
	in(root);
	printf("\n");
	printf("Hasil post:\n");
	post(root);
	printf("\n");
	
	printf("Setelah dihapus 5\n");
	
	root = del(root, 2);
	
	printf("Hasil pre:\n");
	pre(root);
	printf("\n");
	printf("Hasil in:\n");
	in(root);
	printf("\n");
	printf("Hasil post:\n");
	post(root);
	printf("\n");
	
	return 0;
	
}
