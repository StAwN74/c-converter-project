/*Bastien's Converter Project
May 2021
Sources/References: callac-soft-college.fr, openclassrooms.com, programiz.com, knowprogram.com, geeksforgeeks.org, sanfoundry.com, wikibooks.org, codescracker.com
ToDo: Use double instead of int, or long, and deal with negative numbers
      More Binary operations */

#include <stdio.h>
#include <stdlib.h>
//#include <string.h>

//Variables
int inputMode = 0; // input format
int outputMode = 0; // output format

char hexaStr[100]; // = "ffffff\0"; // Will be used at user input if input mode is hexadecimal

//Restart loop function
void restartMe()
{
    char quitStr[] = "Hello\0"; // User answer
    printf("\n");
    printf("\nType YES to start over (lowercase allowed), or anything else to quit...\n");
    scanf(" %[^\n]", &quitStr); // important space in scanf() here

    //Allowing lower or upper case
    if ((quitStr[0] == 'Y' || quitStr[0] == 'y') && (quitStr[1] == 'E' || quitStr[1] == 'e') && (quitStr[2] == 'S' || quitStr[2] == 's') && quitStr[3] == '\0')
    {
        printf("\n");
        return main();
    }
    else
    {
        printf("\nExiting Converter project...\n");
        return 0;
    }
}

//Decimal to binary calc
void decToBin (int number)
{
    int resultTab [100]; // Result
    //loop
    int i = 0;
    //int N = (number/2);
    for (i = 0; number > 0; i++)
    {
        resultTab[i] = number%2;
        number = number/2;
    }

    for(int j=i-1; j>=0; j--)
    {
        printf("%d", resultTab[j]); // From right to left
    }
}

//Decimal to octal calc
void decToOcto (int number)
{
    int resultTab [100];
    //loop
    int i = 0;
    for (i = 0; number > 0; i++)
    {
        resultTab[i] = number%8;
        number = number/8;
    }

    for(int j=i-1; j>=0; j--)
    {
        printf("%d", resultTab[j]);
    }
}

//Decimal to Hexa
void decToHexa (int number)
{
    int res = 0; // rest of modulo
    int i = 0, j = 0;
    char hexanum[] = "f\0"; // Tab to display result

    while (number != 0)
    {
        res = number % 16;
        if (res < 10)
        {
            hexanum[j] = 48 + res; // Using Ascii table
            j++;
        }
        else
        {
            hexanum[j] = 55 + res; // Using Ascii while res == 11 gives A
            j++;
        }
        number = number / 16;
    }

    //Displaying integer into char
    for (i = j-1; i >= 0; i--)
        printf("%c", hexanum[i]);
}

//Other formats
//Binary to decimal - Not using a tab this time
int binToDec (int number)
{
    //Setting base and other vars
    int dec = 0;
    int i = 0; // i will be powered with 2
    int rest = 0;
    int puiss = 1;
    //loop
    for (i = 0; number > 0; i++)
    {
        rest = number % 10;
        number = number/10;
        dec = dec + rest*puiss;
        puiss = puiss*2;
    }
    return dec;
}

//From octal to decimal
int octoToDec(int number)
{
    //Setting base and other vars
    int dec = 0;
    int i = 0; // i will be powered with 8, this time
    int rest = 0;
    int puiss = 1;
    //loop
    for (i = 0; number > 0; i++)
    {
        rest = number % 10;
        number = number/10;
        dec = dec + rest*puiss;
        puiss = puiss*8;
    }
    return dec;
}

//From hexadecimal to decimal
int hexaToDec(char hexaStr[])
{
    int dec = 0;
    int rest = 0;
    int len=0; // char[] length
    int i = 0; // i will be powered with 16

    for (int j = 0; hexaStr[j] != '\0'; j++)
    {
        len++;
    }
    len = len -1; // we now have string length

    for (i = 0; len>=0; i++)
    {
        rest = hexaStr[len];
        if(rest>=48 && rest<=57)
            rest = rest-48;
        else if(rest>=65 && rest<=70)
            rest = rest-55;
        else if(rest>=97 && rest<=102)
            rest = rest-87;
        else
        {
            printf("You've entered an invalid Hexadecimal digit\n");
            return 0; // going back to main program
        }
        dec = dec + (rest*pow(16, i));
        len--; // go to next char from right to left
    }
    return dec;
}

////String length
//int strLength (char str [])
//{
//    int i = 0;
//    for (i = 0; str[i] != '\0'; i++)
//    {
//
//    }
//    return i;
//}
//
////Displaying any string
//void displayStr (char str [])
//{
//    int i = 0;
//    for (i = 0; i < strLength(str); i++)
//    {
//        printf("%c", str[i]);
//    }
//}
//
////String reverse
//void strReverse (char str [], char newStr [])
//{
//    int i =0;
//    int j = strLength(newStr)-1;
//
//    for (i = 0; str[i] != '\0'; i++)
//    {
//        newStr[j] = str[i];
//        j--;
//    }
//}

//Main function
int main()
{
    inputMode = 0;
    outputMode = 0;
    int number = 0;

    printf("-=Starting Converter project=-\n");

    //User inputs
    printf("\nPlease choose initial format to convert (2, 8, 10, or 16): \n"); // Could use chars (b,o,d,h and 'n' to quit)
    scanf(" %d", &inputMode);

    printf("Choose output format: \n");
    scanf(" %d", &outputMode);

    //Returning to main() for easy testing purpose
    if ((inputMode != 2 && inputMode != 8 && inputMode != 10 && inputMode != 16) || (outputMode != 2 && outputMode != 8 && outputMode != 10 && outputMode != 16))
    {
        printf("Please enter valid formats: 2, 8, 10, or 16.\n");
        char quitStr[4]; // = "Hello"; // See below
        scanf("%[^\n]", &quitStr); //Prevents infinite loop in case of invalid (or space using) character.
        printf("\n");
        //printf("\n%s\n", quitStr); // displaying failure typing before going back to main for debug
        return main();
    }

    else
    {
        //switching modes - Planning to do a switch in a switch, was fuzzy because of breaks and indentation
        if (inputMode == 2)
        {
            //switching output mode for calc
            if (outputMode == 2)
            {
                printf("You entered twice the same format.\n");

                //Offer binary operations, let's start with adding 2 binary numbers
                int number1 = 0;
                int number2 = 0;
                printf("Enter first binary: \n");
                scanf(" %d", &number1);

                char quitStr1[4]; // = "Hello"; // See below
                scanf("%[^\n]", &quitStr1); //Prevents invalid (or space using) user input

                printf("Enter second binary number to add: \n");
                scanf(" %d", &number2);

                char quitStr2[4]; // = "Hello"; // See below
                scanf("%[^\n]", &quitStr2); //Prevents invalid (or space using) user input

                int x1 = binToDec(number1);
                int x2 = binToDec(number2);
                int x3 = x1+x2;
                printf("Result: ");
                decToBin(x3); // calc & display

                //Asking to restart while fixing incorrect input again (user input numbers)
                char quitStr[4];
                scanf("%[^\n]", &quitStr);
                restartMe();
            }

            else if (outputMode == 8)
            {
                printf("Enter number to convert: \n");
                scanf(" %d", &number);
                printf("Result: ");
                int decR = binToDec(number);
                decToOcto(decR); // calc & display

                //Asking to restart
                char quitStr[4];
                scanf("%[^\n]", &quitStr);
                restartMe();
            }
            else if (outputMode == 10)
            {
                printf("Enter number to convert: \n");
                scanf(" %d", &number);
                printf("Result: %d", binToDec(number)); // display & calc

                //Asking to restart
                char quitStr[4];
                scanf("%[^\n]", &quitStr);
                restartMe();
            }
            else if (outputMode == 16)
            {
                printf("Enter number to convert: \n");
                scanf(" %d", &number);
                int decR2 = binToDec(number);
                printf("Result: ");
                decToHexa(decR2); // calc & display

                //Asking to restart
                char quitStr[4];
                scanf("%[^\n]", &quitStr);
                restartMe();
            }
        }
        else if (inputMode == 8)
        {
            //switching output mode for calc
            if (outputMode == 2)
            {
                printf("Enter number to convert: \n");
                scanf(" %d", &number);
                int decR3 = octoToDec(number);
                printf("Result: ");
                decToBin(decR3); // calc & display

                //Asking to restart
                char quitStr[4];
                scanf("%[^\n]", &quitStr);
                restartMe();
            }
            else if (outputMode == 8)
            {
                printf("You entered twice the same format.");

                //Asking to restart, nothing to fix here
                restartMe();
            }
            else if (outputMode == 10)
            {
                printf("Enter number to convert: \n");
                scanf(" %d", &number);
                int decR4 = octoToDec(number);
                printf("Result: %d", octoToDec(decR4)); // display & calc

                //Asking to restart
                char quitStr[4];
                scanf("%[^\n]", &quitStr);
                restartMe();
            }
            else if (outputMode == 16)
            {
                printf("Enter number to convert: \n");
                scanf(" %d", &number);
                int decR5 = octoToDec(number);
                printf("Result: ");
                decToHexa(decR5); // calc & display

                //Asking to restart
                char quitStr[4];
                scanf("%[^\n]", &quitStr);
                restartMe();
            }
        }
        else if (inputMode == 10)
        {
            //switching output mode for calc
            if (outputMode == 2)
            {
                printf("Enter number to convert: \n");
                scanf(" %d", &number);
                //int tabRes[100]; // Will be used in function
                //int tabInv[100];
                //tabReverse(strRes, tabResInv);
                printf("Result: ");
                decToBin(number); // calc & display

                //Asking to restart
                char quitStr[4];
                scanf("%[^\n]", &quitStr);
                restartMe();
            }
            else if (outputMode == 8)
            {
                printf("Enter number to convert: \n");
                scanf(" %d", &number);
                printf("Result: ");
                decToOcto(number); // calc & display

                //Asking to restart
                char quitStr[4];
                scanf("%[^\n]", &quitStr);
                restartMe();
            }
            else if (outputMode == 10)
            {
                printf("You entered twice the same format.");

                //Asking to restart
                restartMe();
            }
            else if (outputMode == 16)
            {
                printf("Enter number to convert: \n");
                scanf(" %d", &number);
                printf("Result: ");
                decToHexa(number); // calc & display

                //Asking to restart
                char quitStr[4];
                scanf("%[^\n]", &quitStr);
                restartMe();
            }
        }
        else if (inputMode == 16)
        {
            //switching output mode for calc with a string
            if (outputMode == 2)
            {
                printf("Enter number to convert: \n");
                scanf(" %s", &hexaStr);
                int decR6 = hexaToDec(hexaStr);
                decToBin(decR6); // calc & display

                //Asking to restart
                char quitStr[4];
                scanf("%[^\n]", &quitStr);
                restartMe();
            }

            else if(outputMode == 8)
            {
                printf("Enter number to convert: \n");
                scanf(" %s", &hexaStr);
                int decR7 = hexaToDec(hexaStr);
                decToOcto(decR7); // calc & display

                //Asking to restart
                char quitStr[4];
                scanf("%[^\n]", &quitStr);
                restartMe();
            }

            else if(outputMode == 10)
            {
                printf("Enter number to convert: \n");
                scanf(" %s", &hexaStr);
                printf("Result: %d", hexaToDec(hexaStr)); // display & calc

                //Asking to restart
                char quitStr[4];
                scanf("%[^\n]", &quitStr);
                restartMe();
            }

            else if(outputMode == 16)
            {
                printf("You entered twice the same format.");

                //Asking to restart
                restartMe();
            }
        }
    }
    return 0; // return main() is possible if we add 'n' to quit like mentioned at line 220
}

//End
