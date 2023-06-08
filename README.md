# fibonacci Sequence

In mathematics, the Fibonacci sequence is a sequence in which each number is the sum of the two preceding ones.
## How to run
You will need to manually add the nodes which you want to calculate the add, multiplication, division or fibonacci sequence by adding a left and right node.
## Addition
```c
    Node *add = makeNode(ADD);
    add->left = makeValue(10);
    add->right = makeValue(6);
```
## Multiplication 2
```c
    Node *mul = makeNode(MUL);
    mul->left = makeValue(5);
    mul->right = makeValue(4);
```
# Divison
```c
    Node *div = makeNode(DIV);
    div->left = makeValue(10);
    div->right = makeValue(5);
```
# Fibonacci
```c
    Node *fibo = makeNode(FIB);
    fibo->left = makeValue(abs(calc(sub)));
    fibo->value = fibonacci(calc(fibo->left));
```
**_NOTE:_**  the in fib you will need to provide a node not a number.
# How to Compile and run
After declaring the nodes for each operation you will need to compile the code by writing the following piece of code:

```bash
gcc fib.c -o output
```
then you will need to run the compiled output file
```bash
./output
```
Then the output of the functions will be printed on your beautiful console ^_^
