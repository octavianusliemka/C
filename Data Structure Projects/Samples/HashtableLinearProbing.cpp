
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

const int	list_DATA_SIZE = 32;
const int	list_SIZE = 16;
char		list[list_SIZE][list_DATA_SIZE] = {};

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
	
	if (list[hash][0] == '\0') {
		// fill empty slot
		strcpy(list[hash], string);
	} else
	{
		// search for the next empty slot
		int i = hash + 1;
		while (i < list_SIZE) {
			// is the slot empty?
			if (list[i][0] == '\0') {
				strcpy(list[i], string);
				break;
			}
			i++;
		}
		
		// table is full
		if (i == list_SIZE)
			printf("\nHash table is full!\n\n");
	}
	
}

void print() {
	printf("\nHere's your hash table:\n");
	
	int i = 0;
	while (i < list_SIZE) {
		printf("%2d. %s\n", i + 1, list[i]);
		i++;
	}
	
	printf("\n");
}

int main() {
	
	char string[list_DATA_SIZE];
	
	printf("\n.* HASH TABLE with LINEAR PROBING using DIVISION HASH *.\nyou know who made this :P\n\n");
	printf("> Enter data in the form of strings.\n> Enter '?' to display the list.\n> Enter '!' to exit the program.\n\n");
	
	printf("Input: ");
	scanf("%s", string);
	
	while (string[0] != '!') {
		if (string[0] == '?')
			print();
		else
			insert(string);
		
		printf("Input: ");
		scanf("%s", string);
	}
	
	return 0;
}
