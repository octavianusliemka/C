#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct supermarket{
	char item[50];
	int qty;
	struct supermarket *next, *prev;
}*head, *tail, *curr;

void push(char item[], int qty){
	
	curr = (struct supermarket*) malloc(sizeof(struct supermarket));
	
	strcpy(curr->item, item);
	curr->qty = qty;
	
	if(head == NULL){
		head = tail = curr;
	}
	else if(strcmp(head->item, item) > 0){
		curr->next = head;
		head->prev = curr;
		head = curr;
		head->prev = NULL;
	}
	else if(strcmp(tail->item, item) < 0){
		tail->next = curr;
		curr->prev = tail;
		tail = curr;
		tail->next = NULL;
	}
	else{
		supermarket *temp = head;
		while(strcmp(temp->next->item, item) < 0){
			temp = temp->next;
		}
		curr->next = temp->next;
		temp->next = curr;
		curr->prev = temp;
	}
	
}

void pop(char item[]){
	
	if(head == NULL){
		printf("Anda belum membeli barang\n");
		return;
	}
	
	int flag = 0;
	
	if(strcmp(item, head->item) == 0){
		head = head->next;
		head->prev = NULL;
		free(head->prev);
	}
	else if(strcmp(item, tail->item) == 0){
		tail = tail->prev;
		tail->next = NULL;
		free(tail->next);
	}
	else{
		curr = head;
		while(curr != tail){
			curr = curr->next;
			if(strcmp(curr->item, item) == 0){
				curr->prev->next = curr->next;
				curr->next->prev = curr->prev;
				curr = NULL;
				free(curr);
				flag = 1;
				break;
			}
		}
		if(flag == 0){
			printf("Barang tidak ditemukan\n");
		}
	}
	
}

void print(){
	
	int i=1, j, k;
	
	if(head == NULL){
		printf("Anda belum membeli barang\n");
		return;
	}
	
	printf("| No. | Nama barang				| Jumlah barang |\n");
	
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
		printf("Apa yang ingin anda lakukan?\n1. Beli barang\n2. Cancel pembelian barang\n3. Lihat struk\n4. Selesai belanja\n");
		printf("Pilihan: ");
		scanf("%d", &input);
		switch(input){
			case 1:
				printf("Masukkan barang yang ingin anda beli: ");
				scanf("%s", item);
				printf("Masukkan jumlah barang yang ingin dibeli: ");
				scanf("%d", &qty);
				push(item, qty);
			break;
			case 2:
				printf("Masukkan barang yang ingin anda batalkan pembeliannya: ");
				scanf("%s", item);
				pop(item);
			break;
			case 3:
				printf("Struk:\n");
				print();
			break;
			case 4:
				printf("Terima kasih telah datang ke Indomaret, ini struknya\n");
				print();
			break;
		}
		printf("\n");
	}while(input != 4);
	
	return 0;
	
}
