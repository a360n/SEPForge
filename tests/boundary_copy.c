#include <assert.h>
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

    assert(safe_copy(buffer, sizeof buffer, "") == 0);
    assert(strcmp(buffer, "") == 0);

    assert(safe_copy(buffer, sizeof buffer, "1234567") == 0);
    assert(strcmp(buffer, "1234567") == 0);

    assert(safe_copy(buffer, sizeof buffer, "12345678") == -1);
    assert(safe_copy(buffer, sizeof buffer, "OVERLONG_INPUT") == -1);

    puts("PASS: all 4 boundary tests");
    return 0;
}
