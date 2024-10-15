//Using abstract operations on lists, write a function that sorts the list in ascending order.
#include <stdio.h>
//Khai bao
#define MAXSIZE 1001
typedef int ElementType;
typedef int Position;
typedef struct{
	ElementType elements[MAXSIZE];
	int size;
}List;

//Vi tri dau tien 
Position first(List L){
	return 1;
}
//chay tiep den khi gap vi tri cuoi cung
Position next(Position p, List L){
	if(p < L.size-1){
		return p + 1;
	}
	return L.size;
}
// tra ve vi tri cuoi cung
Position endList(List L){
	return L.size + 1;
}
//hàm tra ve chinh no hoac bao loi neu vi tri p hong co trong ds
ElementType retrieve (Position p, List L){
	if (p < L.size){
		return L.elements[p];
	}
	return -1;
}
//ham doi vi tri neu vi tri chua duoc sap xep tang dan
//truyen con tro vi muon sua doi gia tri goc 
void swap (Position p, Position q, List *L){
//	if (p < L-> elements && q < L.elements){
		ElementType temp = L->elements[p];
		L->elements[p] = L->elements[q];
		L->elements[q] = temp; 
}

//Viet ham sap xep tang dan
void Sort(List L){
	Position p,q;
	p = first(L);
	while(p != endList(L)){
		q = next(p, L);
		while(q != endList(L)){
			if(retrieve(p,L) > retrieve (q,L))
				swap (p,q, &L);
			q = next(q,L);
		}
		p = next(p, L);
	}
}

int main (){
	List a;
	
	printf ("Enter the number of elements in the list: ");
	scanf ("%d", &a.size);
	
	if(a.size > MAXSIZE){
		printf ("ERROR");
		return 1;
	}
	
	printf ("Enter elements: ");
}