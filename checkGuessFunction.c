#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>

//Uses #define to create macros to print output in color
//Color codes defined by ANSI X3.64 escape sequences
//References:
//https://stackoverflow.com/questions/3585846/color-text-in-terminal-applications-in-unix/23657072#23657072
//https://learn.microsoft.com/en-us/cpp/preprocessor/hash-define-directive-c-cpp?view=msvc-170

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

/*
string.h
strcpy(dest, src): Copies the string src to dest, including the null terminator.
strncpy(dest, src, n): Copies at most n characters from src to dest. If src is shorter than n, dest is padded with null characters.
strcat(dest, src): Appends the string src to the end of dest.
strncat(dest, src, n): Appends at most n characters from src to dest.
strcmp(str1, str2): Compares str1 and str2 lexicographically.
    Returns 0 if they are equal, a negative value if str1 is less than str2, and a positive value if str1 is greater than str2.
strncmp(str1, str2, n): Compares at most n characters of str1 and str2.
strlen(str): Returns the length of str, excluding the null terminator.
strchr(str, c): Finds the first occurrence of character c in str.
strstr(haystack, needle): Finds the first occurrence of the substring needle in haystack. 
*/

/*
Here's a list of some common functions declared in ctype.h:
isalnum(): Checks if a character is alphanumeric (letter or digit).
isalpha(): Checks if a character is an alphabet (letter).
isdigit(): Checks if a character is a decimal digit.
isxdigit(): Checks if a character is a hexadecimal digit.
isspace(): Checks if a character is a whitespace character.
isupper(): Checks if a character is an uppercase letter.
islower(): Checks if a character is a lowercase letter.
ispunct(): Checks if a character is a punctuation character.
isprint(): Checks if a character is a printable character.
iscntrl(): Checks if a character is a control character.
toupper(): Converts a lowercase letter to uppercase.
tolower(): Converts an uppercase letter to lowercase.
*/

//FIXME
//Return number of lives or indicate whether or not user has won

//checkGuess function: compares user's guess to secret word
//Prints color coded output in uppercase
void checkGuess(char guess[6], char secretWord[6]){
    bool charFound = false;
    //Makes user's guess all uppercase letters
    for(int i = 0; guess[i] != '\0'; ++i){
        guess[i] = toupper(guess[i]);
    }

    //Makes secret word all uppercase letters
    for(int i = 0; secretWord[i] != '\0'; ++i){
        secretWord[i] = toupper(secretWord[i]);
    }

    //DELETE ME
    printf("secretWord: %s\n", secretWord);
    printf("guess:\t    %s\n", guess);

    //Prints guess to the screen in green if correct
    if(strcmp(guess, secretWord) == 0){
        printf(GRN "%s\n" RESET, guess);
    }
    
    //If guess is incorrect, check each character in guess & print in appropriate color
    else{

        for(int i = 0; guess[i] != '\0'; ++i){

            //Checks if letter in guess matches letter in secretWord; if yes print it in green
            if(guess[i] == secretWord[i]){
                printf(GRN "%c" RESET, guess[i]);
            }
                        
            else{
                //Checks every character in secretWord for character in guess
                for(int j = 0; secretWord[j] != '\0'; ++j){
                    charFound = false;

                    //Print character in yellow if found
                    if(guess[i] == secretWord[j]){
                        printf(YEL "%c" RESET, guess[i]);
                        charFound = true;
                        break;
                    }

                }

                //Print in red if not found
                if(!charFound){
                    printf(RED "%c" RESET, guess[i]);
                }
                
            }
        }
    }
    
}

int main(){
    //Secret word will be randomly selected by another function
    char secretWord[6] = "hives";

    //Guess will be taken from user input by another function
    char guess[6] = "hevxx";

    checkGuess(guess, secretWord);
}
