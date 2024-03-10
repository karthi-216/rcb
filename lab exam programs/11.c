#include<stdio.h>
#include<ctype.h>
int precedence(char operator) {
    switch (operator) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return -1;
    }
}
int isOperator(char ch) {
    switch (ch) {
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
            return 1;
        default:
            return 0;
    }
}
void infixtopostfix(char in[50]) {
    char stack[50], postfix[50];
    int top = -1, i, j;
    for (i = 0, j = 0; in[i] != '\0'; i++) {
        if (isalnum(in[i])) {
            postfix[j++] = in[i];  
        }
        else if (in[i] == '(' ) {
            stack[++top] = in[i];
        }
        else if ( in[i] == ')' ) {
            while (top > -1 && stack[top] != '(') {
                postfix[j++] = stack[top--];
            }
            top--;
        }
        else if (isOperator(in[i])) {
            printf("operator:%c\n", in[i]);
            while ((top > -1) && precedence(stack[top]) >= precedence(in[i])) {
                postfix[j++] = stack[top--];    
            }
            stack[++top] = in[i];
        }
    }
    while (top > -1) {
        if (stack[top] == '(') {
            printf("Invalid Exp");
        }
        postfix[j++] = stack[top--];
    }
    postfix[j] = '\0';
    printf("The corresponding postfix expression is:");
    printf("%s", postfix);
}
int main() {
    char infix[50];
    printf("Enter the expression:");
    scanf("%s",infix);
    infixtopostfix(infix);
    return 0;
}