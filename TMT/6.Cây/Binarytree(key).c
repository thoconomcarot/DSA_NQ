#include <stdio.h>
#include <stdlib.h>
typedef int KeyType;
struct Node{
	KeyType key;
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

//Tree create2(KeyType v, Tree l, Tree r){
//	Tree N;
//	N = (struct Node*)malloc(sizeof(struct Node));
//	N->key = v;
//	N->left = l;
//	N->right = r;
//	return N;
//}

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
		printf ("%d ", root->key);
		NLR(root->left);
		NLR(root->right);
	}
}

void LNR (Tree root){
	if (!emptyTree(root)){
		LNR(root->left);
		printf ("%d ", root->key);
		LNR(root->right);
	}
}

void LRN (Tree root){
	if (!emptyTree(root)){
		LRN(root->left);
		LRN(root->right);
		printf ("%d ", root->key);
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

Tree search (KeyType x, Tree T){
	if (T == NULL){
		return NULL;
	}
	else if (T->key == x){
		return T;
	}
	else if (T->key < x){
		return search(x, T->right);
	}
	else{
		return search(x, T->left);
	}
}
	
void insertNode (KeyType x, Tree *T){
	if((*T) == NULL){
		(*T) = (struct Node*)malloc(sizeof(struct Node*));
		(*T)->key = x;
		(*T)->left = NULL;
		(*T)->right = NULL;
		
	}
	else if (x < (*T)->key){
		insertNode (x, &(*T)->left);
	}
	else if (x > (*T)->key){
		insertNode (x, &(*T)->right);
	}
}

Tree readTree (){
	Tree T;
	makeNull(&T);
	int n, x;
	printf ("Nhap vao n key: ");
	scanf ("%d", &n);
	for (int i = 1; i <= n; i++){
		printf ("\tNhap vao key %d: ", i);
		scanf ("%d", &x); 
		insertNode(x, &T);
	}
	return T;
}

KeyType deleteMin (Tree *T){
	KeyType k; 
	Tree temp;
	if ((*T)->left == NULL){
		temp = (*T);
		k = (*T)->key;
		(*T)= (*T)->right;
		free(temp);
		return k;
	}
	else{
		return deleteMin (&((*T)->left));
	}
}

KeyType deleteMax(Tree *T){
	KeyType k;
	Tree temp;
	if ((*T)->right == NULL){
		temp = (*T);
		k = (*T)->key;
		(*T) = (*T)->left;
		free(temp);
		return k;
	}
	else{
		return deleteMax (&((*T)->right));
	}
}

void deleteNode (KeyType x, Tree *T){
	Tree temp;
	if ((*T) != NULL){
		if (x < (*T)->key){
			deleteNode(x, &((*T)->left));
		}
		else if(x > (*T)->key){
			deleteNode(x, &((*T)->right));
		}
		else{
			if (((*T)->left == NULL) && ((*T)->right == NULL)){
				temp = (*T);
				(*T) = NULL;
				free(temp);
			}
			else if ((*T)->left == NULL){
				temp = (*T);
				(*T) =(*T)->right;
				free(temp);
			}
			else if ((*T)->right == NULL){
				temp = (*T);
				(*T) = (*T)->left;
				free(temp);
			}
			else{
				(*T)->key = deleteMax(&((*T)->right));
			}
		}
	}
	
}


int main (){
	Tree T;
	int x;
	int n;
	//makeNull(&T);

	T = readTree();
	printf("Prefix: ");
	NLR(T);
	printf ("\n");

	//printf("Delete: \n");
	for (int i = 1; i < n; i++){
		printf ("Nhap node %d can xoa: ", i);
		scanf ("%d", &x);
		deleteNode(x,&T);
		printf("Prefix: ");
		NLR(T);
		printf ("\n");
	}
	
	
//	deleteNode(6,&T);
//	printf("Prefix: ");
//	NLR(T);
//	printf ("\n");
//	
//	deleteNode(0,&T);
//	printf("Prefix: ");
//	NLR(T);
//	printf ("\n");
	
//	printf("Infix: ");
//	LNR(T);
//	printf ("\n");
//	
//	printf("Posfix: ");
//	LRN(T);
//	printf ("\n");
	
	
	
//	printf ("Count nodes: %d\n", nb_nodes(T));
//	printf ("Count leaf: %d\n", nb_leaf(T));
	
	
	
//	search(1,T1);
//	printf ("Insert Tree: %d\n");
//	insertNode(5,&T1);
	
	return 0;
}


  