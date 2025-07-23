#include <stdio.h>

int main() {
    unsigned long x;
    for (x=1; x<= 4300000000; x++){
        if (x % 2 == 0){
            printf("%ld  ", x);
        }
    }
    return 0;
}
