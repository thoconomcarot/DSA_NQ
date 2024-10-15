#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
struct Node{
    ElementType data;
    struct Node *next;
};
typedef struct Node* Position;
typedef Position List;


// kh?i t?o danh sách r?ng
void makenullList(List *L) {
struct Node* header;
header = (struct Node*)malloc(sizeof(struct Node));
header->next = NULL;
(*L) = header;
} 


Position first(List L){
    List p = L;
    return p;
}


//thêm ph?n t? vào ds
void insertList(int x, Position p, List *L){
    Position q;
    q=(struct Node*)malloc(sizeof(struct Node));
    q->data = x;
    q->next = p->next;
    p->next = q;
} 



//d?c danh sách
void readList(List *L){
	Position p;
    int n,x;
    makenullList(L);
    printf ("Enter n: ");
    scanf("%d", &n);
    for (int i =0; i <n; i++){
        printf ("Enter element %d: ", i+1);
        scanf ("%i", &x);
        insertList(x, first(*L), L);
    }
}


//tr? v? ph?n t? ? v? trí p
int retrieve (Position p, List L){
    if(p->next != NULL){
        return p->next->data;
    }
}


//Ð? dài c?a danh 
int len(List L){
    Position p = L;
    int cnt = 0;
    while(p->next != NULL){
        cnt++;
        p = p->next;
    }
    return cnt;
}


//Ð? ph?c t?p O(n)
Position endList(List L){
    List p = L;
    while(p->next != NULL){
        p = p->next;
    }
    return p;
}


Position next(Position p, List L){
	return p->next;
}


//in danh sách
void printList1(List L){
Position p = L;
    while (p->next != NULL){
        printf("%d ", p->next->data);
        p = p->next;
    }
    printf ("\n");
}


//Do phuc tap O(n)
void printList2(List L){
	Position p = first(L);
	Position e = endList(L);
	while(p != e){
		printf ("%d", retrieve(p,L));
		p = next(p,L);
	}
	printf ("\n");
}




//Ð? ph?c t?p O(n)
//Tr? v? d?a ch? c?a ph?n t? th? i trong danh sách
ElementType getPosition(int i , List L){
    List p = L;
    int c = 0;
    while(p->next != NULL && c < i){
        c++;
        p = p->next;
    }
}


//xóa ph?n t?
void delete(Position p, List *L){
    Position q;
    if (p->next!=NULL){
        q = p->next;
        p->next = q->next;
    	free(q);
    }
}



//Xóa ph?n t? th? i trong ds
Position popAt(int i, List *L){
    if(i > 1 && i < len(*L)){
        Position p = getPosition(i, *L);                                                                                                                                                                                                                                                                                                                                                                                                   
        delete(p, &L);
    }
}

//tr? v? giá tr? c?a ph?n t? i
Position getAt(int i, List L){
	Position p = getPosition(i, L);
    return retrieve(p, L);
}

//thay d?i giá tr? c?a ph?n t? i
void setAt(Position x, int i, List *L){
    x = getPosition(i, *L);
}


//tra ve vt truoc p
Position previous(Position P, List L){
	Position q;
	while(q->next != p){
		q = q->next;
	}
	return q;
}


//do phuc tap O(n)
//tim phan tu x trong ds lien ket
Position locate1(ElementType x, List L){
	Position p = L;
	while(p->next != NULL){
		if(x == p->next->data){
			return p;
		}
		p = p->next;
	}
	return p;
}


//Do phuc tap O(n)^2
//tim ptu x tai sd trong ds dac
Position locate2(ElementType x, List L){
	Position p = L;
	while(p != endList(L)){     
 		if(retrieve(p,L) == x){
			return p;
		}
		p = next(p, L);
	}
	return p;
}

//Do phuc tap O(n)
Position locate3(ElementType x, List L){
	Position p = first(L);
	Position e = endList(L);  //gan endlist bang e de giam bot do phuc tap thanh O(n)
	while(p != e){     
 		if(retrieve(p,L) == x){
			return p;
		}
		p = next(p, L);
	}
	return p;
}


void insertAt(ElementType x, int i, List *L){
	Position p = L;
	getPosition(i, L);
	insertList(x, p, *L);
	
	
}

int main (){
    List L, p;
    makenullList(&L); 

    int n;
    printf ("Enter the number of elements in list: ");
    scanf ("%d", &n);

    printf ("\n");
    
    printf ("Xoa phan tu: ");
    delete(p, &L);
    printList1(L);

    return 0;
    
}