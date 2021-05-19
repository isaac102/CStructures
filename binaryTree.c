#include <stdio.h>
#include <stdlib.h>



struct Node {
	int value;
	struct Node ** children;
};

struct Tree{
	struct Node * pTree;
};

struct Tree createTree(){
	struct Tree newTree;
	newTree.pTree = malloc(sizeof(int*));
	newTree.pTree = NULL;
	return newTree;
}

struct Node* createNode(int value){
	struct Node* newNode = malloc(sizeof(struct Node));
	newNode->value = value;
	newNode->children = malloc(2*sizeof(int*));
	newNode->children[0] = NULL;
	newNode->children[1] = NULL;
	return newNode;
}

void printTree(struct Node node){
	printf("%d\n", node.value);
	if(node.children[0] == NULL && node.children[1] == NULL){
		return;
	}

	if(node.children[0] != NULL){
		printTree(*(node.children[0]));
	}

	if(node.children[1] != NULL){
		printTree(*(node.children[1]));
	}
	return;
}


struct Node* findSpot(struct Tree tree, int value){
	struct Node* currentNode = tree.pTree;
	int searching = 1;
	while(searching){
		
		if(currentNode->value >= value){
			if(currentNode -> children[0] == NULL){
				return currentNode;
			} 
			currentNode = currentNode -> children[0];
		}else{
			if(currentNode -> children[1] == NULL){
				return currentNode;
			}
			currentNode = currentNode -> children[1];

		}
	}
	return currentNode;
	
	
}
void addNode(struct Tree* tree, int value){
	if(tree->pTree == NULL){
		
		(*tree).pTree = createNode(value);
		return;
	}
	struct Node* newNode = malloc(sizeof(struct Node));
	newNode = createNode(value);;
	struct Node* parentNode = findSpot(*tree, value);
	printf("spot is %d\n", parentNode->value);
	if(parentNode->value>=value){
		parentNode->children[0] = newNode;
	}else{
		parentNode->children[1] = newNode;
	}
	return;
	

	
}

int main(){
	
	struct Tree myTree = createTree();
	
	addNode(&myTree, 138);
	addNode(&myTree, 9);
	addNode(&myTree, 9);
	addNode(&myTree, 18);
	addNode(&myTree, 983);
	addNode(&myTree, 10);
	addNode(&myTree, 150);
	addNode(&myTree, 15);
	printTree(*(myTree.pTree));
	printf("----------------Manual printer---------------------\n");
	printf("root is: %d with children pointers %p and %p \n", myTree.pTree->value, myTree.pTree->children[0], myTree.pTree->children[1]);
	printf("l2 is: %d with children pointers %p and %p \n", myTree.pTree->children[0]->value, myTree.pTree->children[0]->children[0], myTree.pTree->children[0]->children[1]);
	printf("l3 is: %d with children pointers %p and %p \n", myTree.pTree->children[0]->children[0]->value, myTree.pTree->children[0]->children[0]->children[0], myTree.pTree->children[0]->children[0]->children[1]);

	return 0;
}




















