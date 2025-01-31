#include <stdio.h>
#include <unistd.h>

void print(const char *output) {
    if (!isatty(fileno(stdout))) {
        FILE *output_file = stdout; 

        if (output_file == NULL) {
            fprintf(stderr, "Error\n");
            return;
        }
        stdout = output_file;
    }

    fprintf(stdout, "%s", output);
}

int main() {
    const char *output = "shell project\n";
    print_output(output);
    return 0;
}
