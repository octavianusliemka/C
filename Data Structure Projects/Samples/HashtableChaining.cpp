
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

const int	list_DATA_SIZE = 32;
const int	list_SIZE = 16;

/* STRUCT(s) */

struct Node {
	char string[list_DATA_SIZE];
	struct Node *next;
	
} *head[list_SIZE], *tail[list_SIZE];

typedef struct Node *node;

/* LINKED LIST FUNCTION(s) */

void pushTail(char string[], int index) {
	node newNode = (node)malloc(sizeof(struct Node));
	newNode->next = NULL;
	
	strcpy(newNode->string, string);
	
	if (head[index] == NULL) {
		head[index] = tail[index] = newNode;
		return;
	}
	
	tail[index]->next = newNode;
	tail[index] = newNode;
	
}

/* HASH TABLE FUNCTION(s) */
 
int hashDivision(char string[]) {
	
	/*
		the hash key is:
		the sum of all ASCII of each char from the string % the size of the list
	*/
	
	int ascii_sum = 0;
	
	int i = 0;
	while (string[i] != '\0') {
		ascii_sum += (int)string[i];
		i++;
	}
	
	return ascii_sum % list_SIZE;
}

void insert(char string[]) {
	int hash = hashDivision(string);
	pushTail(string, hash);
}

void print() {
	printf("\nHere's your hash table:");
	
	int i = 0;
	while (i < list_SIZE) {
		printf("\n%2d.", i + 1);
		
		if (head[i] == NULL) {
			i++;
			continue;
		}
		
		node curr = head[i];
		while (curr != NULL) {
			printf(" %s,", curr->string);
			curr = curr->next;
		}
		i++;
	}
	
	printf("\n\n");
}

/* MAIN FUNCTION */

int main() {
	
	char string[list_DATA_SIZE];
	
	printf("\n.* HASH TABLE with CHAINING using DIVISION HASH *.\nyou know who made this :P\n\n");
	printf("> Enter data in the form of strings.\n> Enter '?' to display the list.\n> Enter '!' to exit the program.\n\n");
	
	printf("Input: ");
	scanf("%[^\n]", string);
	getchar();
	
	while (string[0] != '!') {
		if (string[0] == '?')
			print();
		else
			insert(string);
		
		printf("Input: ");
		scanf("%[^\n]", string);
		getchar();
	}
	
	return 0;
	
}

