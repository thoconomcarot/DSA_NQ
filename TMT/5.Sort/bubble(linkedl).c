#include "alistlib.h"
#include <stdio.h>

int a[] = {32, 51, 27, 83, 66, 11, 45, 75};

// a.ham nhap theo thu tu nhap
void appendList(int a[], int n, List *L)
{
	makeNull(L);
	for (int i = 0; i < n; i++)
	{
		append(a[i], L);
	}
}
// ham tao danh sach dao
void reverseList(int a[], int n, List *L)
{
	makeNull(L);
	for (int i = 0; i < n; i++)
	{
		insertFirst(a[i], L);
	}
}

void swap(Position p, Position q, List *L)
{
    int temp;
    temp = getAt(p, *L);
    setAt(p, getAt(q, *L), L);
    setAt(q, temp, L);
}
void bubbleSort(List *L)
{
    int n = len(*L);
    int firstList = first(*L);
    for (int i = firstList; i < n; i++)
    {
        for (int j = firstList; j < n - i; j++)
        {
            if (getAt(j, *L) > getAt(j + 1, *L))
            {
                swap(j, j + 1, L);
            }
        }
    }
}

int main(int argc, char *argv[])
{
	List L1;
	appendList(a, sizeof(a) / sizeof(int), &L1);
	print(L1);
	reverseList(a, sizeof(a) / sizeof(int), &L1);
	print(L1);
	insertAt(3, 22, &L1);
	print(L1);
	bubbleSort(&L1);
	print(L1);
}