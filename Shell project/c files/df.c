#include <stdio.h>
#include <stdlib.h>
#include <sys/statvfs.h>

void df(const char *path) {
    struct statvfs stat;

    if (statvfs(path, &stat) != 0) {
        perror("No information");
        return;
    }

    unsigned long long free_blocks = fs_info.f_bfree;
    unsigned long long block_size = fs_info.f_frsize;
    unsigned long long total_blocks = fs_info.f_blocks;

    unsigned long long total = total_blocks * block_size;
    unsigned long long free = free_blocks * block_size;

    printf("Total space: %llu bytes\n", total);
    printf("Free space: %llu bytes\n", free);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <path>\n", argv[0]);
        return 1;
    }

    df(argv[1]);

    return 0;
}
