#include <stdio.h>
#include <stdlib.h>

typedef enum TypeTag {
    ADD,
    SUB,
    MUL,
    DIV,
    ABS,
    FIB,
    DEF
} TypeTag;

typedef struct Node {
    TypeTag type;
    int value;
    struct Node *left;
    struct Node *right;
} Node;

#define MAXN 100
int fib[MAXN];

Node* makeNode(TypeTag type) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->type = type;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* makeValue(int value) {
    Node *newNode = makeNode(DEF);
    newNode->value = value;
    return newNode;
}

int fibonacci(int n) {
    int fib[n+1];
    // if(n==0)
    //     return 1;
    fib[0] = 0;
    fib[1] = 1;
    for(int i = 2; i <= n; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }
    return fib[n-1];
}

int calc(Node* node) {
    switch (node->type) {
    case ADD:
        return calc(node->left) + calc(node->right);
    case SUB:
        return calc(node->left) - calc(node->right);
    case MUL:
        return calc(node->left) * calc(node->right);
    case DIV:
        return calc(node->left) / calc(node->right);
    case ABS:
        return abs(calc(node->left));
    case FIB:
        return fibonacci(calc(node->left));
    case DEF:
        return node->value;
    default:
        exit(1);
    }

}


int main() {
    Node *add = makeNode(ADD);
    add->left = makeValue(10);
    add->right = makeValue(9);
    Node *mul = makeNode(MUL);
    mul->left = makeValue(5);
    mul->right = makeValue(4);
    Node *sub = makeNode(SUB);
    sub->left = makeValue(calc(add));
    sub->right = makeValue(calc(mul));
    Node *fibo = makeNode(FIB);
    fibo->left = makeValue(abs(calc(sub)));
    fibo->value = fibonacci(calc(fibo->left));

    printf("add : %d\n", calc(add));
    printf("mul : %d\n", calc(mul));
    printf("sub : %d\n", calc(sub));
    printf("fibo : %d\n", calc(fibo));

    return 0;
}