#include <stdio.h>
#include <stdlib.h>

int count = 0;

struct data{
	int num;
	struct data *next;
}*head=NULL, *tail=NULL, *curr=NULL, *front=NULL, *rear=NULL;

void Push(int num){
	
	if(head == NULL){
		curr = (struct data*) malloc(sizeof(struct data));
		curr->num = num;
		front = rear = head = tail = curr;
		tail->next = head;
		rear->next = head;
	}
	else if(count < 5){
		curr = (struct data*) malloc(sizeof(struct data));
		curr->num = num;
		tail->next = curr;
		rear->next = curr;
		rear = tail = curr;
		tail->next = head;
		rear->next = head;
	}
	else if(count >= 5){
		rear = rear->next;
		rear->num = num;
	}
	
	count++;
	
}

void Pop(){
	
	if(front->num == 0 ){
		printf("\nTidak tersedia data untuk dihapus, silahkan input data kembali\n\n");
	}	
	else if(head){
		front->num = 0;
		front = front->next;
	}
	else if(head == NULL){
		printf("\nTidak tersedia data untuk dihapus, silahkan input data kembali\n\n");
	}
	
}

void Cetak(){
	
	int i, j, k, size = 0;
	
	for(i=0; i<5; i++){
		printf("%d ", i);
	}
	printf("<- Index array\n");
	curr = head;
	i = 0;
	while(i < count){
		if(i > 4){
			break;
		}
		if(curr->num == 0){
			printf("# ");
		}
		else{
			printf("%d ", curr->num);
			size++;
		}
		curr = curr->next;
		i++;
	}
	
	printf("\n");
	
	printf("Front: %d\nRear: %d\nSize: %d\n", front->num, rear->num, size);
	
}

int main(){
	
	int input;
	
	printf("Masukkan input (Input -1 untuk pop, input 0 untuk stop): ");
	scanf("%d", &input);
	if(input == 0){
		printf("Program selesai\n");
	}
	else if(input == -1){
		printf("Belum ada data, masukkan data dulu, baru bisa di pop!\n");
		while(input == -1){
			printf("Masukkan input (Input -1 untuk pop, input 0 untuk stop): ");
			scanf("%d", &input);
			printf("Belum ada data, masukkan data dulu, baru bisa di pop!\n");
		}
	}
	else{
		Push(input);
		Cetak();
	}
	
	while(input != 0){
		printf("Masukkan input (Input -1 untuk pop, input 0 untuk stop): ");
		scanf("%d", &input);
		if(input == 0){
			break;
		}
		if(input == -1){
			Pop();
		}
		else{
			Push(input);
		}
		Cetak();
	}
	
	printf("\nProgram selesai\n");
	
	return 0;
	
}
