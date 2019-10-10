#include<stdio.h> 
#include<string.h> 
#include<stdbool.h> 
// Checking if the string is palindrome or not
bool isPalindrome(char *str) {
    int len = strlen(str);
    // single character is always palindrome 
    if (len == 1)
        return true; 
    // pointing to first character 
    char *ptr1 = str; 
    // pointing to last character 
    char *ptr2 = str+len-1; 
    while (ptr2 > ptr1) { 
        if (*ptr1 != *ptr2)
            return false;
        ptr1++; 
        ptr2--; 
    }
    return true; 
} 

int noOfAppends(char s[]) {
    if (isPalindrome(s))
        return 0;
        // Removing first character of string by
        // incrementing base address pointer.
    s++;
    return 1 + noOfAppends(s); 
} 

int main() {
    char s[100];
    int noofapp = 0;
    printf("Enter a string (max length 100):");
    scanf("%s",s);
    noofapp = noOfAppends(s);
    if(noofapp) {
        printf("Not a Palindrome. Needs %d appends\n",noofapp);
    }
    else {
        printf("Already a Palindrome\n");
    }
    return 0; 
}
