#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct stack {
    int topo;
    int *data;
    int capacity;
};

void push(struct stack *alfa, int x) {
    if (alfa->topo == alfa->capacity - 1) {
        alfa->capacity *= 2;
        alfa->data = (int *)realloc(alfa->data, alfa->capacity * sizeof(int));
    }
    alfa->topo++;
    alfa->data[alfa->topo] = x;
}

int pop(struct stack *alfa) {
    if (alfa->topo == -1) {
        printf("Stack underflow\n");
        exit(1);
    }
    int x = alfa->data[alfa->topo];
    alfa->topo--;
    return x;
}

int evaluate(char *exp) {
    struct stack s;
    s.topo = -1;
    s.capacity = 1;
    s.data = (int *)malloc(s.capacity * sizeof(int));

    int i;
    for (i = strlen(exp) - 1; i >= 0; i--) {
        if (isdigit(exp[i])) {
            push(&s, exp[i] - '0');
        } else {
            int op1 = pop(&s);
            int op2 = pop(&s);
            switch (exp[i]) {
                case '+':
                    push(&s, op1 + op2);
                    break;
                case '-':
                    push(&s, op1 - op2);
                    break;
                case '*':
                    push(&s, op1 * op2);
                    break;
                case '/':
                    push(&s, op1 / op2);
                    break;
            }
        }
    }
    int result = pop(&s);
    free(s.data);
    return result;
}

int main() {
    char exp[100];
    printf("Enter a prefix expression: ");
    fgets(exp, 100, stdin);
    printf("Result: %d\n", evaluate(exp));
    return 0;
}
