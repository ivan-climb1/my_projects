/**
 * This program checks the string on the palindrome.
 * You can use it, enter ./palindrome <you string>
 */

#include <stdio.h>  // Nedeed for 'printf'
#include <string.h> // Nedeed for 'strlen'
#include <ctype.h>  // Nedeed for 'islower, toupper'


// This function cheks the register and 
// changes it if necessary.
char Check_Letter(char letter);


int main(int argc, char *argv[])
{
    // If arguments not equal 2, exit.
    if (argc != 2)
    {
        printf("Sorry. Pleaze, give me a one argument. Try again.\n");
        return 1;
    }
    
    printf("Excelent, I will check you string - '%s' on the palindrome!\n", *(argv + 1));
    
    // Create pointer. This pointer point to the string from user.
    char *sentence = *(argv + 1);
    
    int n = strlen(sentence);
    // Create integer equal to the middle string of user.
    int middle = n/2;
    
    
    for (int i = 0; i < middle; i++)
    {
        // Call the function 'Check_Letter' for the first letter in this comparison.
        *(sentence + i) = Check_Letter(*(sentence + i));
        
        // Call the function 'Check_Letter' for the second letter in this comparison.
        *(sentence + n - 1 - i) = Check_Letter(*(sentence + n - 1 - i));
        
        // Compare the first letter with last, then the
        // second latter with penultimate..asf.
        if (*(sentence + i) != *(sentence + n - 1 - i))
        {
            printf("NOT PALINDROME\nIt is nice to work with you, bye)\n");
            return 1;
        }
    }
    
    
    printf("SUCCESS! You string is a PALINDROME!\nIt is nice to work with you, bye)\n");
    return 0;
}


char Check_Letter(char letter)
{
    // If the letter is in lowercase, I change to uppercase.
    if (islower(letter))
    {
        letter = toupper(letter);
    }
    return letter;
}

