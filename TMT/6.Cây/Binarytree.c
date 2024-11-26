#include <stdio.h>
#include <stdlib.h>
typedef char DataType;
struct Node{
	DataType data;
	struct Node *left;
	struct Node *right;
};
typedef struct Node* Tree;
Tree T;

void makeNull(Tree *T){
	(*T) = NULL;
}

int emptyTree(Tree T){
	return T == NULL;
}

Tree create2(DataType v, Tree l, Tree r){
	Tree N;
	N = (struct Node*)malloc(sizeof(struct Node));
	N->data = v;
	N->left = l;
	N->right = r;
	return N;
}

Tree leftChild(Tree n){
	if (n != NULL){
		return n->left;
	}
	return NULL;
}

Tree rightChild(Tree n){
	if (n != NULL){
		return n->right;
	}
	return NULL;
}

int isLeaf (Tree n){
	if (n != NULL){
		return (leftChild(n) == NULL) && (rightChild(n) == NULL);
	}
	return 0;
}

void NLR (Tree root){
	if (!emptyTree(root)){
		printf ("%c ", root->data);
		NLR(root->left);
		NLR(root->right);
	}
}

void LNR (Tree root){
	if (!emptyTree(root)){
		LNR(root->left);
		printf ("%c ", root->data);
		LNR(root->right);
	}
}

void LRN (Tree root){
	if (!emptyTree(root)){
		LRN(root->left);
		LRN(root->right);
		printf ("%c ", root->data);
	}
}

int nb_nodes (Tree root){
	if(!emptyTree(root)){
		return nb_nodes(root->left) + nb_nodes(root->right) + 1;
	}
	return 0;
}

int nb_leaf (Tree root){
	if(!emptyTree(root)){
		if(isLeaf(root)){
			return 1;
		}
		else{
			return nb_leaf(root->left) + nb_leaf(root->right);
		}
	}
	return 0;
}

int main (){
	Tree T1,t1,t2,t3,t4,t5,t6,T2;
	makeNull(&T1);
	makeNull(&t1);
	makeNull(&t2);
	makeNull(&t3);
	makeNull(&t4);
	makeNull(&t5);
	makeNull(&t6);
	makeNull(&T2);
	
	
	printf("----------------\n");
	printf("Test 1\n");
	T1 = create2('+',create2('*', create2('3', NULL, NULL), create2('5', NULL, NULL)), create2('7', NULL, NULL));
	printf("Prefix: ");
	NLR(T1);
	printf ("\n");
	printf("Infix: ");
	LNR(T1);
	printf ("\n");
	printf("Posfix: ");
	LRN(T1);
	printf ("\n");
	printf ("Count nodes: %d\n", nb_nodes(T1));
	printf ("Count leaf: %d\n", nb_leaf(T1));
	
	
	printf("----------------\n");
	printf("Test 2\n");
	t1 = create2('+',create2('a',NULL,NULL),create2('b',NULL,NULL));
	t2 = create2('+',create2('d',NULL,NULL),create2('e',NULL,NULL));
	t3 = create2('*',create2('c',NULL,NULL),t2);
	t4 = create2('+',t1, t3);
	t5 = create2('+',t4,create2('f',NULL,NULL));
	t6 = create2('+',create2('g',NULL,NULL), create2('8',NULL,NULL));
	T2 = create2('*',t5,t6);
	printf("Prefix: ");
	NLR(T2);
	printf ("\n");
	printf("Infix: ");
	LNR(T2);
	printf ("\n");
	printf("Posfix: ");
	LRN(T2);
	printf("\n");
	printf ("Count nodes: %d\n", nb_nodes(T2));
	printf ("Count leaf: %d\n", nb_leaf(T2));
}


  