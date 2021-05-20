#include <stdio.h>
#include <stdlib.h>


//node structure
struct Node {
	int value;
	struct Node ** children;
};
//tree structure
struct Tree{
	struct Node * pTree;
};
//creates tree
struct Tree createTree(){
	struct Tree newTree;
	newTree.pTree = NULL;
	return newTree;
}
//creates node
struct Node* createNode(int value){
	struct Node* newNode = malloc(sizeof(struct Node));
	newNode->value = value;
	newNode->children = malloc(2*sizeof(int*));
	newNode->children[0] = NULL;
	newNode->children[1] = NULL;
	return newNode;
}
//prints tree
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
//finds the location to add a node into the tree
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
//adds a node of value "value" to the given tree
void addNode(struct Tree* tree, int value){
	if(tree->pTree == NULL){
		
		(*tree).pTree = createNode(value);
		return;
	}
	struct Node* newNode = createNode(value);;
	struct Node* parentNode = findSpot(*tree, value);
	if(parentNode->value>=value){
		parentNode->children[0] = newNode;
	}else{
		parentNode->children[1] = newNode;
	}
	return;
	

	
}
//frees memory for a sub-tree
void freeSubTree(struct Node* node){
	if(node->children[0] != NULL){
		freeSubTree(node->children[0]);
	}
	if(node->children[1] != NULL){
		freeSubTree(node->children[1]);
	}
	free(node->children);
	free(node);
}
//frees entire tree memory
void freeTree(struct Tree* tree){
	freeSubTree(tree->pTree);
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
	freeTree(&myTree);


	return 0;

}




















