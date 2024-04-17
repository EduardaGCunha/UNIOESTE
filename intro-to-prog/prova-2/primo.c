nt main()

{

    int num, temp = 0;

    // read input from the user.

    printf("Enter any number to Check for Prime: ");

    scanf("%d", &num);

    // initialization

    int i = 2; 

    // loop condition

    while (i <= num / 2)

    {

        // check if num is divisible by any number.

        if (num % i == 0)

        {

            temp++;

            break;

        }

        // incrementation

        i++;

    }

    // check for the value of temp and num.

    if (temp == 0 && num != 1)

    {

        printf("%d is a Prime Number", num);

    }

    else

    {

        printf("%d is Not a Prime Number", num);

    }

    return 0;

}
