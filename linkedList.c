#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Node{
	int value;
	struct Node* link;
};	

struct Node* createList(int value){

	struct Node * linkedList = NULL;
	linkedList = (struct Node*) malloc(sizeof(struct Node));
	linkedList->value = value;
	linkedList->link = NULL;
	return linkedList;
}

void addNodeToEnd(int value, struct Node * linkedList){
	struct Node* pointer = linkedList;
	while(pointer->link != NULL){
		pointer = pointer->link;
	}
	pointer->link = (struct Node*) malloc(sizeof(struct Node));
	pointer = pointer->link;
	pointer->value = value;
	pointer->link = NULL;
}

void addNodeToBeginning(int value, struct Node * linkedList){
	
	
	struct Node* pointer = (struct Node*) malloc(sizeof(struct Node));
	pointer->value = linkedList->value;
	pointer->link = linkedList->link;
	linkedList->link = pointer;
	linkedList->value = value;

}

void printList(struct Node * linkedList){
	
	struct Node* pointer = linkedList;
	while(pointer->link != NULL){
		printf("-> %d ",pointer->value);
		pointer = pointer->link;
	}
	printf("-> %d -> NULL\n", pointer->value);

}

void clearMemory(struct Node * linkedList){
	
	struct Node* pointer = linkedList;
	while(pointer->link != NULL){
		struct Node* temp = pointer;
		pointer = pointer->link;
		free(temp);
	}
	free(pointer);

}

int main(){

	struct Node * linkedList = NULL;
	linkedList = createList(82);
	addNodeToEnd(4, linkedList);
	addNodeToEnd(2, linkedList);
	addNodeToEnd(-23, linkedList);
	addNodeToBeginning(42, linkedList);
	addNodeToEnd(68, linkedList);
	addNodeToEnd(5, linkedList);
	addNodeToEnd(5, linkedList);
	
	printList(linkedList);
	clearMemory(linkedList);
}


 
