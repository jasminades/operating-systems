#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void wc(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "File can't be opened '%s'\n", filename);
        return;
    }

    int lines = 0, words = 0, bytes = 0;
    char c;
    int word = 0;
    

    while ((c = fgetc(file)) != EOF) {
        bytes++;

        if (c == '\n') {
            lines++;
        }

        if (!isspace(c)) {
            if (!word) {
                word = 1;
                words++;
            }
        } else {
            word = 0;
        }
    }

    fclose(file);

    printf("The file has %d words, %d lines, %d bytes:  %s\n", lines, words, bytes, filename);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "The file %s <filename>\n", argv[0]);
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        wc(argv[i]);
    }

    return 0;
}
