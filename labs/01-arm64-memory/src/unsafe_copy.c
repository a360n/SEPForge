/* INTENTIONALLY VULNERABLE. Local sanitizer demonstration only. */
#include <stdio.h>
#include <string.h>

__attribute__((noinline)) static void unsafe_copy(const char *src) {
    char buffer[8];
    volatile size_t n = strlen(src) + 1;
    memcpy(buffer, src, n); /* no capacity check: stack-buffer-overflow */
    printf("%s\n", buffer);
}

int main(void) {
    unsafe_copy("OVERLONG_INPUT");
    return 0;
}
