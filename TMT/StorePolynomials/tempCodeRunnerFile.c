
    printf("\tSecond polynomial: ");
    printList(b);

    printf ("......................\n");
    ListPolynomial sum = addPolynomial(a,b);
    printf("Sum of two polynomial: ");
    printList(sum);

    printf ("Derivative of sum: ");
    derivative(&sum);