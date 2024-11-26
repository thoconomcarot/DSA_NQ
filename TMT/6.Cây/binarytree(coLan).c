void printPath (int x, Tree T){
    if (T != NULL){
        printf ("%d ", T->Key);
        if (x == T->Key){
            printf ("-> Tim thay");
        }
        else if (x > T->Key){
            printPath(x,T->Right);
        }
        else{
            printPath(x, T->Left);
        }
    }
    else{
        printf ("-> Khong thay");
    }
}



int getHeight (Tree T){
    if (T == NULL){
        return -1;
    }
    int l = getHeight (T->Left);
    int r = getHeight (T->Right);
    if (l > r){
        return l+1;
    }
    else{
        return r + 1;
    }
}


Tree getMin (Tree T){
    if (T == NULL){
        return NULL;
    }
    if (T->Left == NULL){
        return T;
    }
    return getMin (T->Left);
}

Tree getNext(int x, Tree T){
    Tree temp = T;
    Tree Ancestor = NULL;
    while (temp != NULL){
        //x nằm ngay giữa = key
        if (x == temp->Key){
            if (temp->Right == NULL){
                return Ancestor;
            }
            else{
                return getMin(temp->Right);
                // Tree temp1 = temp->Right;
                // while (temp1->Left != NULL){
                //     temp1 = temp1->Left;
                // }
                // return temp1;
            }
        }
        //x nằm ở cây con bên trái
        else if (x < temp->Key){
            Ancestor = temp;
            temp = temp->Left;
        }
        else{
      
            temp = temp->Right;
        }
    }
    return NULL;
}



Tree getMax (Tree T){
    if (T == NULL){
        return NULL;
    }
    if (T->Right == NULL){
        return T;
    }
    return getMax (T->Right);
}

Tree getPrevious(int x, Tree T){
    Tree temp = T;
    Tree Ancestor = NULL;
    while (temp != NULL){
        //x nằm ngay giữa = key
        if (x == temp->Key){
            if (temp->Left == NULL){
                return Ancestor;
            }
            else{
                return getMax(temp->Left);
                // Tree temp1 = temp->Right;
                // while (temp1->Left != NULL){
                //     temp1 = temp1->Left;
                // }
                // return temp1;
            }
        }
        //x nằm ở cây con bên trái
        else if (x < temp->Key){
            temp = temp->Left;
        }
        else{
            Ancestor = temp;
            temp = temp->Right;
        }
    }
    return NULL;
}

int findMax(Tree T) {
    if (T == NULL) {
        return 0;
    }
    int lMax = findMax(T->Left);
    int rMax = findMax(T->Right);
    int max = T->Data;
    if (lMax > max){
        max = lMax;
    }
    if (rMax > max){
        max = rMax;
    }
    return max;
}

Tree findElement (DataType x, Tree T){
    if (T == NULL){
        return 0;
    }
    if (T->Data == x){
        return T;
    }
    Tree tLeft = findElement (x, T->Left);
    if (tLeft != NULL){
        return tLeft;
    }
    return findElement (x, T->Right);
}

