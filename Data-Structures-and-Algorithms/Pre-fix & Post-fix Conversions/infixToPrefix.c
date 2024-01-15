#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Structure for a stack
struct Stack {
    int top;
    char items[MAX_SIZE];
};

// Function prototypes
void initialize(struct Stack* stack);
int isEmpty(struct Stack* stack);
void push(struct Stack* stack, char item);
char pop(struct Stack* stack);
int isOperator(char c);
int getPrecedence(char c);
void strrev(char *str);
void infixToPrefix(char* infix);

int main() {
    char infix[MAX_SIZE];

    printf("Enter an infix expression: ");
    fgets(infix, MAX_SIZE, stdin);
    infixToPrefix(infix);

    return 0;
}

// Function to initialize the stack
void initialize(struct Stack* stack) {
    stack->top = -1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return (stack->top == -1);
}

// Function to push an item onto the stack
void push(struct Stack* stack, char item) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
    } else {
        stack->items[++stack->top] = item;
    }
}

// Function to pop an item from the stack
char pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        return '\0';
    } else {
        return stack->items[stack->top--];
    }
}

// Function to check if a character is an operator
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Function to get the precedence of an operator
int getPrecedence(char c) {
    if (c == '+' || c == '-') {
        return 1;
    } else if (c == '*' || c == '/') {
        return 2;
    }
    return 0; // For other characters
}

// Custom function to reverse a string
void strrev(char *str) {
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

// Function to convert an infix expression to a prefix expression
void infixToPrefix(char* infix) {
    struct Stack operatorStack;
    initialize(&operatorStack);

    int length = strlen(infix);
    char prefix[MAX_SIZE];
    int prefixIndex = 0;

    // Reverse the infix expression
    for (int i = length - 1; i >= 0; i--) {
        char c = infix[i];

        if (isOperator(c)) {
            // Pop operators from the stack until the stack is empty or
            // an operator with lower precedence is encountered
            while (!isEmpty(&operatorStack) && getPrecedence(operatorStack.items[operatorStack.top]) > getPrecedence(c)) {
                prefix[prefixIndex++] = pop(&operatorStack);
            }
            push(&operatorStack, c);
        } else if (c == ')') {
            push(&operatorStack, c);
        } else if (c == '(') {
            while (!isEmpty(&operatorStack) && operatorStack.items[operatorStack.top] != ')') {
                prefix[prefixIndex++] = pop(&operatorStack);
            }
            pop(&operatorStack); // Pop the remaining '('
        } else {
            prefix[prefixIndex++] = c;
        }
    }

    // Pop any remaining operators from the stack
    while (!isEmpty(&operatorStack)) {
        prefix[prefixIndex++] = pop(&operatorStack);
    }

    // Null-terminate the prefix expression
    prefix[prefixIndex] = '\0';

    // Reverse the prefix expression to get the correct order
    strrev(prefix);

    printf("Prefix Expression: %s\n", prefix);
}
