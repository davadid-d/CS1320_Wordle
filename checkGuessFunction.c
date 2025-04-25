#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>
/*
strcpy(dest, src): Copies the string src to dest, including the null terminator.
strncpy(dest, src, n): Copies at most n characters from src to dest. If src is shorter than n, dest is padded with null characters.
strcat(dest, src): Appends the string src to the end of dest.
strncat(dest, src, n): Appends at most n characters from src to dest.
strcmp(str1, str2): Compares str1 and str2 lexicographically. Returns 0 if they are equal, a negative value if str1 is less than str2, and a positive value if str1 is greater than str2.
strncmp(str1, str2, n): Compares at most n characters of str1 and str2.
strlen(str): Returns the length of str, excluding the null terminator.
strchr(str, c): Finds the first occurrence of character c in str.
strstr(haystack, needle): Finds the first occurrence of the substring needle in haystack. 
*/

void checkGuess(char guess[6], char secretWord[6]){
    for(int i = 0; guess[i] != '\0'; ++i){
        guess[i] = toupper(guess[i]);
    }

    printf("%s", guess);
    
    for()
    
}

int main(){
    char secretWord[] = "HIVES";
    char guess[] = "bytes";

    printf("%s", secretWord);
    checkGuess(guess, secretWord);
}
