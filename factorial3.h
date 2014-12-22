#include <stdio.h>
#include <stdlib.h>

void multiply_by_int(char *n, int m);

int main(int argc, char *argv[]){
    int input, i;
    char prod[3000] = "1";
    printf("%c\n",prod[0]);
    printf("Enter a positive integer with up to 3 digits.\n");
    scanf("%d", &input);
    if (input < 0 || input > 999) return -1;
    for (i = 2; i <= input; i++)
        multiply_by_int(prod, i);
    printf("%d! = %s\n", input, prod);
    return 0;
}

void multiply_by_int(char *n, int m){
    int i=0;
    int c;
    int tmp;
    for(i=0;i<strlen(n); i++){
        tmp = atoi(&n[i])*m+c;
        n[i] = tmp%10 + '0';
        c = tmp/10;
    }
}