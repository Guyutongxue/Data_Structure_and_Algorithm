#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char s[1000010] = {};
int next[1000010] = {};

void getNext(void) {
	int j = -1;
	int i = 0;
	next[0] = -1;
    size_t len = strlen(s);
    while (i < len) {
		if (j == -1 || s[i] == s[j]) {
			next[++i] = ++j;
		}
		else j = next[j];
	}
}

int main(void) {
	while (scanf("%s", s), strcmp(s,".")) {
		getNext();
		size_t len = strlen(s);
		if (len % (len - next[len]) == 0) {
            printf("%d\n", len / (len - next[len]));
        } else {
            puts("1");
        }
    }
    return 0;
}