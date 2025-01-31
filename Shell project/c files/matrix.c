#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define WIDTH 100
#define HEIGHT 50
#define DELAY 100000 

void scr() {
    printf("\033[2J\033[1;1H");
}

void matrix_drawing() {

    if (!isatty(fileno(stdout))) {
        FILE *output_file = stdout; 
        if (output_file == NULL) {
            fprintf(stderr, "Not working\n");
            exit(1);
        }
        stdout = output_file;
    }

    char matrix[HEIGHT][WIDTH];
    int i, j;

    while (1) {
        clear_screen();

        for (i = 0; i < HEIGHT; i++) {
            for (j = 0; j < WIDTH; j++) {
                matrix[i][j] = rand() % 94 + 33; 
            }
        }

        for (i = 0; i < HEIGHT; i++) {
            for (j = 0; j < WIDTH; j++) {
                printf("%c", matrix[i][j]);
            }
            printf("\n");
        }

        fflush(stdout);
        usleep(DELAY);
    }
}

int main() {
    srand(time(NULL));
    scr();
    matrix_drawing();

    return 0;
}
