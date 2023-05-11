#include<stdio.h>

int main(void) {
    int i, m;
    //Getting a sample stack
    struct stack *S = createStack(10);
    for (i = 0; i < 10; i++) {
        push(S, i);
    }
    printf("Enter the position whose element has to be deleted\n");
    scanf("%d", &m);
    deleteElement(S, m);
    printstack(S);
    return 0;
}
