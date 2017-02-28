/*	stack.c: Stack application. */
//
//  James Sandoval 10July2016
//  CS 261 - Data Structures
//  Assignment 2

#include <stdio.h>
#include <stdlib.h>
#include "dynArray.h"
#include <string.h>


/* ***************************************************************
Using stack to check for unbalanced parentheses.
***************************************************************** */

/* Returns the next character of the string, once reaches end return '0' (zero)
	param: 	s pointer to a string 	
	pre: s is not null		
*/
char nextChar(char* s)
{
	static int i = -1;	
	char c;
	++i;	
	c = *(s+i);			
	if ( c == '\0' )
		return '\0';	
	else 
		return c;
}

/* Checks whether the (), {}, and [] are balanced or not
	param: 	s pointer to a string 	
	pre: s is not null	
	post:	
*/
int isBalanced(char* s)
{
    if(s == NULL){
        
        return 0;
    }
    
    int capacity = strlen(s);
    DynArr* pArr = newDynArr(capacity);
    DynArr* cArr = newDynArr(capacity);
    DynArr* sArr = newDynArr(capacity);
    
    char curChar;
    
    while((curChar = nextChar(s)) != '\0'){
        switch (curChar) {
            case ')':
                pushDynArr(pArr, curChar);
                break;
            case '(':
                if (sizeDynArr(pArr) == 0) {
                    deleteDynArr(pArr);
                    deleteDynArr(cArr);
                    deleteDynArr(sArr);
                    return 0;
                }
                popDynArr(pArr);
                break;
            case '}':
                pushDynArr(cArr, curChar);
                break;
            case '{':
                if (sizeDynArr(pArr) == 0) {
                    deleteDynArr(pArr);
                    deleteDynArr(cArr);
                    deleteDynArr(sArr);
                    return 0;
                }
                popDynArr(cArr);
                break;
            case ']':
                pushDynArr(sArr, curChar);
                break;
            case '[':
                if (sizeDynArr(sArr) == 0) {
                    deleteDynArr(pArr);
                    deleteDynArr(cArr);
                    deleteDynArr(sArr);
                    return 0;
                }
                popDynArr(sArr);
                break;
                
            default:
                continue;
        }
    }
    if (sizeDynArr(pArr) + sizeDynArr(cArr) + sizeDynArr(sArr) == 0) {
        deleteDynArr(pArr);
        deleteDynArr(cArr);
        deleteDynArr(sArr);
        return 1;
    }
    deleteDynArr(pArr);
    deleteDynArr(cArr);
    deleteDynArr(sArr);
    
    
	return 0;
}

int main(int argc, char* argv[]){
	
	char* s=argv[1];	
	int res;
	
	printf("Assignment 2\n");

	res = isBalanced(s);

	if (res)
		printf("The string %s is balanced\n",s);
	else 
		printf("The string %s is not balanced\n",s);
	
	return 0;	
}

