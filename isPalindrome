#include <stdio.h>
#include <string.h>

// function will not account for case-sensitivity* (e.g. aDda is not a palindrome)

int ispalindrome(char x[]){
     int length;
     length = strlen(x);

     int mid;
     mid = length/2;

     int i;
     for (i = 0; i < mid; i++){
          if (x[i] != x[length-1-i]){     // if at any time x[i] is not equal to x[length-1-i], then x is not a palindrome
          return 0;
          }
     }
     return 1;          // if x[i] = x[lengt-1-i] for all elements in x, then  x is a palindrome
}

int main(){
     printf("enter a word ");
     
     char input[500];          // string is represented by character array in C
     scanf("%s", &input);
     
     int result;
     result = ispalindrome(input);     // store the result of calling the function on the user input into var result
     
     if (result == 1){
          printf("the word \"%s\" is a palindrome\n", input);
     }

     else{
          printf("the word \"%s\" is not a palindrome\n", input);
          return 0;
     }     
     return 0;
}
