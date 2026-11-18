#include <stdio.h>

__attribute__((noinline)) int add_numbers(int a, int b) {
    volatile int sum = a + b;
    return sum;
}

int main(void) {
    printf("sum=%d\n", add_numbers(7, 11));
    return 0;
}
