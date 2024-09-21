#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct NodeTag{
	ElementType data;
	struct NodeTag *next;
}Node;
typedef Node* List;
typedef Node* Position;
List header;

ElementType retieve(Position p, List L){ 
	if(p->next != '\0'){
		return p->next->data;
	}
	// else{
	// 	return header;
	// }
}
 ElementType getPosition(int posi, List L){
	List p = L;
	int count = 0;
	while ((p ->next != '\0') && (count < posi) ){
		count++;
		p = p->next;
	}
	
 }

 //Viết hàm firstList
 ElementType first(List L){
	List p = L;
	return p;
 }

 //Viết hàm next
 ElementType next(int posi, L){
	List p = L;
	int count = 0;
	while((p -> next != '\0') && (count < posi)){
		count++;
		p = p->next;
	}
	return p->next;
 }


 //Viết hàm endList
 ElementType endList(L){
	List p = L;
	while(p->next != '\0'){
		p = p->next;
	}
	return p;
 }


