
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#include <stdio.h>

int main() {
    FILE *file;
    long length;

    file = fopen("gnltests", "rb");

    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Seek to the end of the file
    fseek(file, 0, SEEK_END);

    // Get the current position, which is the file size
    length = ftell(file);

    // Close the file
    fclose(file);

    printf("The length of the file is %ld bytes.\n", length);

    return 0;
}

