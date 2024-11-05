#include <time.h>
#include "Queue.h"
#include "Stack.h"

int code = 0;

void PnC (Queue *warehouse){
    int random = rand() % 100 + 1;
    printf ("\tRandom number: %d\n", random%2);
    if(random%2 == 0){
        if(!isEmptyQueue(*warehouse)){
            printf ("\tConsumer product: %d\n", deQueue(warehouse));
        }
        else{
            printf ("\tError!\n");
        }
    }
    else{
        if(!isFullQueue(*warehouse)){
            enQueue(++code, warehouse);
            printf ("\tProduced successfully: %d\n", code);
        }
        else{
            printf("Error!\n");
        }
    }
}
void runAutoPnC(Queue *warehouse){
    for (int i =0; i < 15; i++){
        PnC(warehouse);
        printQueue(*warehouse);
        printf ("-----------------------------\n");
    }
    printf ("End of PnC\n");
}

void runPnC(Queue *warehouse){
    int bool = 1;
    printf ("Choose begin(1) or exit(0): ");
    scanf ("%d", &bool);

    while(bool){
        PnC(warehouse);
        printf ("Choose continue(1) or exit(0): ");
        scanf ("%d", &bool);
        printQueue(*warehouse);
        printf("-----------------------------\n");
    }
    printf ("End of PnC!\n");
}

int main (){
    Stack S;
    makeNullStack(&S);
    Queue Q;
    makeNullQueue(&Q);

    // printf ("---Test PnC---\n");
    Queue warehouse;
    makeNullQueue(&warehouse);
    code = 0;
    // runPnC(&warehouse);
    runAutoPnC(&warehouse);
    return 0;

}