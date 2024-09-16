#include "alistlib.h"
#include <stdio.h>
 void menu(List *L);

int main (){
    List L;
    makeNull(&L); 
    menu(L);
    return 0;
}

void menu(List *L){
    int choice, position, element;
    while(1){
        printf ("\n\n1. Initialize an empty list (makeNull)\n");
        printf ("2. Check whether the list is empty? (empty)\n");
        printf ("3. Check whether the list is full? (fullList)\n");
        printf ("4. Insert x to the first position (insertFirst)\n");
        printf ("5. Remove and return the first element (popFirst)\n");
        printf ("6. Insert x at position p (insertAt)\n");
        printf ("7. Remove and return the element at position(popAt)\n");
        printf ("8. Append a new element to the last list (append)\n");
        printf ("9. Remove and return the last element (popLast)\n");
        printf ("10. Number of element: (len)\n");
        printf ("11. Return the position of the first appearance of x in the list (locate)\n");
        printf ("12. Return the element at position (getAt)\n");
        printf ("13. Update the element at position p by a new value x(setAt)\n");
        printf ("14. Traverse the list to print out all elements (print)\n");
        printf ("15. Return the first position (fisrt)\n");
        printf ("16. Returns the last position (end)\n");
        printf ("17. Returns the next position (next)\n");
        printf ("18. Returns the previous position (previous)\n");
        printf ("19. Sort the list (sort)\n");
        printf ("EXIT\n");
        printf ("------------------------------\n");

        printf ("Enter your choice: ");
        scanf ("%d", &choice);

        switch(choice){
            case 0:
                printf ("Exit the program.\n");
                return;

            case 1:
                makeNull(L);
                printf("The list has been initialized empty.\n");
                break;

            case 2:
                if(empty(*L)){
                    printf ("List is empty.\n");
                }
                else{
                    printf ("List is not empty.\n");
                }
                break;
            
            case 3:
                if(fullList(*L)){
                    printf ("List is full.\n");
                }
                else{
                    printf ("List is not full.\n");
                }
                break;

            case 4:
                printf ("Enter the element to insert to the top of list: ");
                scanf ("%d", &element);
                insertFirst(element, L);
                break;

            
            case 5:
                popFirst(position, L);
                printf ("Deleted the first element.\n");
                break;
               
            case 6:
                printf ("Enter the position to insert: ");
                scanf ("%d", &position);
                printf ("Enter the value to insert: ");
                scanf ("%d", &element);
                insertAt(position, element, L);
                break;

            case 7:
                printf ("Enter the position to delete: ");
                scanf ("%d", &position);
                printf ("Deleted element: %d\n", popAt(position, L));
                break;


            case 8:
                printf ("Enter the element to insert to the end of list: ");
                scanf ("%d", &element);
                append(element, L);
                break;
            
            case 9:
                popLast(L);
                printf ("Deleted the last element.\n");
                break;

            case 10:
                printf ("Length of the list: %d\n", len(*L));
                break;

            case 11:
                printf ("Enter the element you want to find first in the list: ");
                scanf ("%d", &element);
                printf ("Position of the first appearance of the element: %d\n", locate(element, *L));
                
            case 12:
                printf ("Enter the position to get the element: ");
                scanf ("%d", &position);
                printf ("Element at position %d: %d\n", position, getAt(position, *L));
                break;
                

            case 13:
                printf ("Enter the position to change: ");
                scanf ("%d", &position);
                setAt(position, element, L);
                printf ("Enter the value to change: ");
                scanf ("%d", &element);
                break;

            case 14:
                print(*L);
                break;
                

            case 15:
                printf ("The first position of the list: %d\n", first(*L));
                break;
                
            
            case 16:
                printf ("The last position of the list: %d\n", end(*L));
                break;
                

            case 17:
                printf ("Enter the position to return next: ");
                scanf ("%d", &position);
                printf ("Next position: %d\n", next(position, *L));
                break;
                

            case 18:
                printf ("Enter the position to return previous: ");
                scanf ("%d", &position);
                printf ("Previous position: %d\n", previous(position, *L));
                break;
                
            case 19:
                sort(L);
                printf ("The list is sorted. \n");
                break;

            default:
                printf("Inappropriate choice. Please try again.\n");
                break;
        }
    }
    return;
}
