/*Program to produce strings and write to the character device*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    char *input_string = argv[1];
    int input_string_length = atoi(argv[2]);
    int iterations = atoi(argv[3]);
    int file_ptr = open("/dev/mityushin_device", O_WRONLY);
    if (file_ptr == -1) {
        printf("Error: Device open failure!\n");
        exit(0);
    }
    for (int i = 0; i < iterations; ++i) {
        printf("Writing string %s\n", input_string);
        int number_of_bytes_written = (int) write(file_ptr, input_string, (size_t) input_string_length);
        if (number_of_bytes_written <= 0) {
            printf("Error: Insufficient space!\n");
            exit(0);
        } else {
            printf("Iteration: %d\n", i);
            printf("--------------\n");
            printf("Write successful!\n");
            printf("Number of bytes written = %d\n", number_of_bytes_written);
        }
        sleep(1);
    }
    close(file_ptr);
    return 0;
}