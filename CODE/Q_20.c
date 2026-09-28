#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

bool isValid(char* s) {
    int n = strlen(s);
    
    // An odd length string can never be valid
    if (n % 2 != 0) {
        return false;
    }
    
    // Allocate stack memory bounded by string length
    char* stack = (char*)malloc(n * sizeof(char));
    int top = -1;
    
    for (int i = 0; i < n; i++) {
        char c = s[i];
        
        if (c == '(' || c == '{' || c == '[') {
            stack[++top] = c; // push
        } else {
            // Stack is empty
            if (top == -1) {
                free(stack);
                return false;
            }
            
            // Check top element and pop
            if (c == ')' && stack[top] == '(') {
                top--;
            } else if (c == '}' && stack[top] == '{') {
                top--;
            } else if (c == ']' && stack[top] == '[') {
                top--;
            } else {
                free(stack);
                return false;
            }
        }
    }
    
    bool valid = (top == -1);
    free(stack);
    return valid;
}