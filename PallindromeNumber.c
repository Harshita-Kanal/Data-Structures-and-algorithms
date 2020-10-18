// C program to check whether a number is Palindrome or not
//This is one of the very Foundational Programs for Starting in any Programming Language
//Including Library File for input output
#include <stdio.h> 

/* Iteratively calculate the reverse of a number*/
int calculateReverse(int num) 
{ 
	int rev_num = 0; 
	while (num > 0) { 
		rev_num = rev_num * 10 + num % 10; 
		num = num / 10; 
	} 
	return rev_num; 
} 

/* Function to check if n is Palindrome*/
int checkPallindrome(int n) 
{ 

	// Calculate the reverse of this digit
	int rev_n = calculateReverse(n); 

	// If Number is same as reverse then Pallindroma. 
	if (rev_n == n) 
		return 1; 
	else
		return 0; 
} 

/*Driver program to test reversDigits*/
int main() 
{ 
	printf("Enter a number to Check Pallindroma");
    scanf("%d",&n) ;
	printf("Is %d a Palindrome number? -> %s\n", n, checkPallindrome(n) == 1 ? "true" : "false"); 

	return 0; 
} 
