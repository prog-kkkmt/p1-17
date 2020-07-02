#include <stdio.h>

int main() {
    int c;
    int sum = 0;
    while ((c = getchar()) != EOF) {
       if (c == '\n' || c == '\t' || c == ' ')
           sum++;
    }
    
    printf("%d", sum);
    return 0;
}
