#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct supermarket{
	char item[50];
	int qty;
	struct supermarket *next;
}*head, *tail, *curr;

void push(char item[], int qty){
	
	curr = (struct supermarket*) malloc(sizeof(struct supermarket));
	
	strcpy(curr->item, item);
	curr->qty = qty;
	
	if(head == NULL){
		head = tail = curr;
	}
	else if(qty == 2){
		tail->next = curr;
		tail = curr;
		tail->next = NULL;
	}
	else if(head->qty == 2){
		curr->next = head;
		head = curr;
	}
	else{
		supermarket *temp = head;
		while(temp->next->qty == 1){
			temp = temp->next;
		}
		curr->next = temp->next;
		temp->next = curr;
	}
	
}

void pop(){
	
	if(head == NULL){
		printf("Anda belum membeli barang\n");
		return;
	}
	
	//head = NULL;
	head = head->next;
	
}

void print(){
	
	int i=1, j, k;
	
	if(head == NULL){
		printf("Anda belum membeli barang\n");
		return;
	}
	
	printf("| No. | Nama barang				| Tingkat prioritas |\n");
	
	curr = head;
	
	if(head == tail){
		printf("| %d.  | %-10s				| %-10d 	|\n", i, curr->item, curr->qty);
	}
	else{
		do{
			printf("| %d.  | %-10s				| %-10d 	|\n", i, curr->item, curr->qty);
			i++;
			curr = curr->next;
		}while(curr != tail);
		printf("| %d.  | %-10s				| %-10d 	|\n", i, tail->item, tail->qty);
	}
	
}

int main(){
	
	int i, j, k, qty, input;
	char item[50];
	
	do{
		printf("Apa yang ingin anda lakukan?\n1. Beli barang\n2. Cancel pembelian barang\n3. Exit\n");
		printf("Pilihan: ");
		scanf("%d", &input);
		switch(input){
			case 1:
				printf("Masukkan barang yang ingin anda beli: ");
				scanf("%s", item);
				printf("Masukkan tanda prioritas[1 utk prio | 2 utk normal]: ");
				scanf("%d", &qty);
				push(item, qty);
				print();
			break;
			case 2:
				printf("Barang pertama akan di pop\n");
				pop();
				print();
			break;
			case 3:
				printf("Terima kasih telah menggunakan program\n");
				print();
			break;
		}
		printf("\n");
	}while(input != 3);
	
	return 0;
	
}
