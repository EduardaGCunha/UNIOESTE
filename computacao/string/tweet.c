#include <stdio.h>
#include <string.h>

int main() {
    char str[507];
    while (scanf(" %[^\n]", str) != EOF) {
        if (strlen(str) <= 140) {
            printf("TWEET\n");
        } else {
            printf("MUTE\n");
        }
    }
    return 0;
}
