#include "plistlib.h"
#include <stdio.h>

int main() {
    List L;
    makeNull(&L); // Khoi tao danh sach rong
    int choice, x, pos;

    while(1) {
        printf("\n---MENU---\n");
        printf("1. Insert the first position\n");
        printf("2. Insert the last position\n");
        printf("3. Insert the position\n");
        printf("4. Delete the first position\n");
        printf("5. Delete the last position\n");
        printf("6. Delete the position\n");
        printf("7. Print list\n");
        printf("8. Return the position of the first appearance of x in the list\n");
        printf("9. Update the element at position p by a new value\n");
        printf("10. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                // Them phan tu vao dau danh sach
                printf("Enter the value to insert: ");
                scanf("%d", &x);
                insertFirst(x, &L);
                break;

            case 2:
                // Them phan tu vao cuoi danh sach
                printf("Enter the value to insert: ");
                scanf("%d", &x);
                append(x, &L);
                break;

            case 3:
                // Them phan tu vao vi tri bat ky
                printf("Enter the value to insert: ");
                scanf("%d", &x);
                printf("Enter the position to insert: ");
                scanf("%d", &pos);
                insertAt(pos, x, &L);
                break;

            case 4:
                // Xoa phan tu dau tien
                x = popFirst(&L);
                if (x == -1)
                    printf("List is empty!\n");
                else
                    printf("Deleted element: %d\n", x);
                break;

            case 5:
                // Xoa phan tu cuoi cung
                x = popLast(&L);
                if (x == -1)
                    printf("List is empty!\n");
                else
                    printf("Deleted element: %d\n", x);
                break;

            case 6:
                // Xoa phan tu o vi tri bat ky
                printf("Enter the position to delete: ");
                scanf("%d", &pos);
                x = popAt(pos, &L);
                if (x == -1)
                    printf("Invalid position!\n");
                else
                    printf("Deleted element: %d\n", x);
                break;

            case 7:
                // In danh sach
                printf("List after change: ");
                print(L);
                break;

            case 8:
                // Tim vi tri phan tu dau tien bang gia tri x
                printf("Enter the value to find: ");
                scanf("%d", &x);
                pos = locate(x, L);
                if (pos == -1)
                    printf("No value found in list!\n");
                else
                    printf("The position of the first appearance of x: %d\n", pos);
                break;

            case 9:
                //Thay đổi giá trị bằng giá trị mới
                printf("Enter the position to change the value: ");
                scanf ("%d", &pos);
                printf ("Enter the new value: ");
                scanf ("%d", &x);
                setAt(pos, x, &L);

            case 10:
                // Thoat chuong trinh
                printf("Exit...\n");
                exit(0);

            default:
                printf("Invalid choice, please choice again!\n");
                break;
        }
    }

    return 0;
}