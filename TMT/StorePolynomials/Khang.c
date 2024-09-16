#include<stdio.h>
#include<math.h>
#define MaxLength 100
typedef struct{
    float coefficient;
    int exponent;
}ElementType;
typedef int Position;
typedef struct{
    ElementType Field[MaxLength];
    Position Last;
}Polynomial;

void makenullList(Polynomial *L){
    L->Last = 0;
}

Position first(Polynomial L){
    return 0;
}

Position endList(Polynomial L){
    return L.Last;
}


//Advance Part:
//CÃ¢u 1:
void readList(Polynomial *pL, int numberOfTerm){
    Position Q;
    makenullList( pL );
    for(Q = first(*pL); Q < numberOfTerm; Q++){
        printf("Enter coefficient and exponent: ");
        scanf("%f %d",&pL->Field[Q].coefficient,&pL->Field[Q].exponent);
        printf("\n");
        pL->Last++;
    }
}

//CÃ¢u 2:
void printList(Polynomial pL){
    Position Q = first(pL);
    while (Q != endList(pL)){
        if ( pL.Field[Q].exponent > 1 ){
            if ( Q == first(pL) && pL.Field[Q].coefficient < 0 ) printf(" - ");
            printf("%gx^%d",fabs(pL.Field[Q].coefficient), pL.Field[Q].exponent);
        }
        else if ( pL.Field[Q].exponent == 1 )
                 printf("%gx", fabs(pL.Field[Q].coefficient));
            else  printf("%g", fabs(pL.Field[Q].coefficient));

        if ( Q < endList(pL) - 1 ){
            if ( pL.Field[Q+1].coefficient >= 0 ) printf (" + ");
                else printf(" - ");
        }
        Q++;
    }
    printf("\n");
}

//CÃ¢u 3:
float calculatePolynomial(int n, Polynomial pL){
    float result = 0.0;
    Position Q;
    for ( Q = first(pL); Q < endList(pL);Q++ ){
        result += pL.Field[Q].coefficient*pow(n,pL.Field[Q].exponent);
    }
    return result;
}

//CÃ¢u 4:
void derivative(Polynomial pL,Polynomial *pLder){
    makenullList(pLder);
    Position Q;
    for ( Q = first(pL); Q != endList(pL); Q++ ){
        pLder->Field[pLder->Last].coefficient = pL.Field[Q].exponent*pL.Field[Q].coefficient;
        pLder->Field[pLder->Last].exponent = pL.Field[Q].exponent - 1;
        if ( pL.Field[Q].exponent*pL.Field[Q].coefficient == 0 ) pLder->Last--;
        pLder->Last++;
        
    }
}

//CÃ¢u 5:
void multiplyPoly(int x, Polynomial pL, Polynomial *pLder){
    makenullList(pLder);
    Position Q = first(pL);
    while ( Q != endList(pL) ){
        pLder->Field[pLder->Last].coefficient = x*pL.Field[Q].coefficient;
        pLder->Field[pLder->Last].exponent = pL.Field[Q].exponent;
        pLder->Last++;
        Q++;
    } 
}

//CÃ¢u 6:
void add(Polynomial pL1, Polynomial pL2, Polynomial *pLSum){
    makenullList(pLSum);
    Position Q = first(pL1);
    Position J = first(pL2);

    while ( Q != endList(pL1) && J != endList(pL2) ){
        if ( pL1.Field[Q].exponent == pL2.Field[J].exponent ){
            pLSum->Field[pLSum->Last].coefficient = pL1.Field[Q].coefficient + pL2.Field[J].coefficient;
            pLSum->Field[pLSum->Last].exponent = pL1.Field[Q].exponent;
            pLSum->Last++; Q++; J++;
        }
        else if( pL1.Field[Q].exponent > pL2.Field[J].exponent ){
            pLSum->Field[pLSum->Last].coefficient = pL1.Field[Q].coefficient;
            pLSum->Field[pLSum->Last].exponent = pL1.Field[Q].exponent;
            pLSum->Last++; Q++;
        }
        else{
            pLSum->Field[pLSum->Last].coefficient = pL2.Field[J].coefficient;
            pLSum->Field[pLSum->Last].exponent = pL2.Field[J].exponent;
            pLSum->Last++; J++;
        }
    }
    while ( Q != endList(pL1) ){
            pLSum->Field[pLSum->Last].coefficient = pL1.Field[Q].coefficient;
            pLSum->Field[pLSum->Last].exponent = pL1.Field[Q].exponent;
            pLSum->Last++; Q++;
    }
    while( J != endList(pL2) ){
            pLSum->Field[pLSum->Last].coefficient = pL2.Field[J].coefficient;
            pLSum->Field[pLSum->Last].exponent = pL2.Field[J].exponent;
            pLSum->Last++; J++;
    }

}



int main(){
    Polynomial P, Pder, Pmul, PSum;
    //BÃ i 1:
    int numberOfTerm;
    printf("Enter the number of term: ");
    scanf("%d", &numberOfTerm);
    readList(&P, numberOfTerm);

    //BÃ i 2:
    printf("Poylynomial P: ");
    printList(P);

    //BÃ i 3:
    int n;
    printf("Enter x to calculate Polynomial: ");
    scanf("%d",&n);
    printf("Polynomial P multiply by %d: ", n);
    printf("%g\n", calculatePolynomial(n,P));
    //BÃ i 4:
    derivative(P, &Pder);
    printf("Derivative of Polymial P: ");
    printList(Pder);
    
    //BÃ i 5:
    int x;
    printf("Enter constant x: ");
    scanf("%d", &x);
    multiplyPoly(x,P, &Pmul );
    printf("Polynomial P multiply by %d: ", x);
    printList(Pmul);

    //BÃ i 6:
    add( P, Pder, &PSum );
    printf("Sum of Polynomial P1 and P2: ");
    printList(PSum);
}