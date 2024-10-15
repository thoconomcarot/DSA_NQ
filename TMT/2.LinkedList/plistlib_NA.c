#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct NodeTag
{
    ElementType data;
    struct NodeTag *next;
} Node;

typedef Node *List;
typedef Node *Position;

void makeNull(List *L); // Initialize an empty list

int len(List L); // Number of elements

int empty(List L); // Check whether the list is empty?

void print(List L); // Traverse the list to print out all elements

ElementType getAt(int idx, List L); // return the element at position idx

Position getPosition(int idx, List L); // return the pointer referring to the pos_th element

Position first(List L); // return the pointer referring tho the first element of L

Position end(List L); // return the pointer to the last element of L

void setAt(int idx, ElementType x, List *L); // Update the element at position p by a new value x

void insertAt(int idx, ElementType x, List *L); // Insert a new element x at position p

ElementType popAt(int idx, List *L); // Remove and return the element at position p

void insertFirst(ElementType x, List *L); // Inset x to the first element at position p

ElementType popFirst(List *L); // Remove and return the first element

void append(ElementType x, List *L); // Append a new element to the first

ElementType popLast(List *L); // Remove and return a last element

int locate(ElementType x, List L); // Return the position of the first appearance of x in the list

Position next(int idx, List L); // return the pointer referring to the next position of pos in L

Position previous(int idx, List L);

ElementType retrieve(Position p, List L);

void makeNull(List *L)
{
    Node *header = (Node *)malloc(sizeof(Node));
    header->next = NULL;
    (*L) = header;
}

int len(List L)
{
    int count = 0;
    while (L->next != NULL)
    {
        count++;
        L = L->next;
    }
    return count;
}

int empty(List L)
{
    List p;
    p = L;
    return p->next == NULL;
}

void print(List L)
{
    List header = L;
    if (empty(L))
    {
        printf("<!> Empty\n");
        return;
    }
    while (header->next != NULL)
    {
        printf("%d ", retrieve(header, L));
        header = header->next;
    }
}

ElementType getAt(int idx, List L)
{
    Position p = getPosition(idx, L);
    return retrieve(p, L);
}

Position getPosition(int pos, List L)
{
    List p = L;
    int count = 0;
    while (p->next != NULL && count < pos)
    {
        count++;
        p = p->next;
    }
    return p;
}

Position first(List L)
{
    return L;
    // List p = L;
    // return p;
}

Position end(List L)
{
    Position p = L;
    while (p->next->next != NULL)
    {
        p = p->next;
    }
    return p;
}

void setAt(int idx, ElementType x, List *L)
{
    List p = getPosition(idx, *L);
    p->next->data = x;
}

void insertAt(int idx, ElementType x, List *L)
{
    List source = getPosition(idx, *L);
    List newNode = (Node *)malloc(sizeof(Node));
    newNode->data = x;
    newNode->next = source->next;
    source->next = newNode;
}

ElementType popAt(int idx, List *L)
{
    if (idx >= 0 && idx <= len(*L))
    {
        List p = getPosition(idx, *L);
        ElementType value = retrieve(p, *L);
        List delNode = p->next;
        p->next = delNode->next;
        free(delNode);
        return value;
    }
    else
    {
        printf("invalid position!");
    }
}

void insertFirst(ElementType x, List *L)
{
    List newNode = (Node *)malloc(sizeof(Node));
    newNode->data = x;
    newNode->next = (*L)->next;
    (*L)->next = newNode;
}

ElementType popFirst(List *L)
{
    if (!empty(*L))
    {
        // popAt(0,L);
        int value = retrieve(first(*L), *L);
        List new = (*L)->next;
        (*L)->next = (*L)->next->next;
        free(new);
        return value;
    }
    else
    {
        printf("<!> Empty\n");
        exit(EXIT_FAILURE);
    }
}

Position next(int pos, List L)
{
    List p = L;
    int count = 0;
    while (p->next != NULL && count < pos)
    {
        count++;
        p = p->next;
    }
    return p->next;
}

Position previous(int idx, List L)
{
    List header = L;
    if (!empty(L))
    {
        int count = 0;
        while (header->next != NULL && count < idx - 1)
        {
            count++;
            header = header->next;
        }
        return header;
    }
    printf("<!> Empty\n");
    exit(EXIT_FAILURE);
}

void append(ElementType x, List *L)
{
    insertAt(len(*L), x, L);
}

ElementType popLast(List *L)
{
    Position last = end(*L);
    int value = retrieve(last, *L);
    popAt(len(*L) - 1, L);
    return value;
}

int locate(ElementType x, List L)
{
    List p = L;
    int pos = 0, found = 0;
    while (p->next != NULL && !found)
    {
        if (x == retrieve(p, L))
        {
            found = 1;
        }
        pos++;
        p = p->next;
    }
    return pos - 1;
}

ElementType retrieve(Position p, List L)
{
    if (p->next != NULL)
    {
        return p->next->data;
    }
}

int main()
{
    int temp;
    List L;
    makeNull(&L);
    // DONE
    //  printf("\n------------------CHECK EMPTY FUNCTION----------------------\n");
    //  print(L);

    printf("--------------------APPEND FUNCTION-------------------------\n");
    for (int i = 15; i > 7; i--)
    {
        append(i, &L);
    }
    print(L);

    // DONE
    //  printf("\n--------------------LENGTH FUNCTION-------------------------\n");
    //  printf("Length: %d", len(L));

    printf("\n-------------GET AT POSITION FUNCTION-------------------------\n");
    temp = 1;
    printf("At %d value is: %d", temp, getAt(temp, L));

    printf("\n-------------FIRST END NEXT PREVIOUS--------------------------\n");
    temp = 3;
    printf("Current: %d\t", retrieve(getPosition(temp, L), L));
    printf("First: %d\t", retrieve(first(L), L));
    printf("End: %d\t", retrieve(end(L), L));
    printf("Next: %d\t", retrieve(next(temp, L), L));
    printf("Previous: %d\n", retrieve(previous(temp, L), L));

    printf("---------------------POP--------------------------------------\n");
    print(L);
    temp = 4;
    printf("\nCurrent: %d\n", popFirst(&L));
    printf("New value at first: %d\n", retrieve(first(L), L));
    printf("Current: %d\n", popLast(&L));
    printf("New value at last: %d\n", retrieve(end(L), L));
    print(L);
    temp = 3;
    printf("\nCurrent: %d\n", popAt(temp, &L));
    printf("New value at %d: %d\n", temp, retrieve(getPosition(temp, L), L));

    printf("---------------------INSERT--------------------------------------\n");
    print(L);
    temp = 5;
    insertFirst(55, &L);
    printf("\nInsert first: %d\n", getAt(0, L));
    print(L);
    insertAt(temp, 60, &L);
    printf("\nInsert at %d: %d\n", temp, getAt(temp, L));
    print(L);
    setAt(temp, 70, &L);
    // print(L);
    printf("\nSet at %d: %d\n", temp, getAt(temp, L));
    print(L);

    printf("\n---------------------LOCATE--------------------------------------\n");
    temp = 9;
    printf("Locate %d: %d\n", temp, locate(temp, L));
    printf("value: %d\n", getAt(locate(temp, L), L));
}