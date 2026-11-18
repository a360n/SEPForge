#include <stdio.h>
#include <string.h>

static int safe_copy(char *dst, size_t capacity, const char *src) {
    size_t length = strlen(src);
    if (length >= capacity) return -1;
    memcpy(dst, src, length + 1);
    return 0;
}

int main(void) {
    char buffer[8];
    if (safe_copy(buffer, sizeof buffer, "SEP") != 0) return 1;
    printf("accepted=%s\n", buffer);
    if (safe_copy(buffer, sizeof buffer, "OVERLONG_INPUT") == 0) return 2;
    puts("rejected=overlong input");
    return 0;
}
