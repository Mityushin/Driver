/*Program to produce strings and write to the character device*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    int character_count = atoi(argv[1]);
    int file_ptr = open("/dev/mityushin_device", O_RDONLY);
    if (file_ptr == -1) {
        printf("Error: Device open failure!\n");
        exit(0);
    }
    char input_string[character_count];
    int _iter = 0;
    while (1) {
        printf("Reading string\n");
        int number_of_bytes_read = (int) read(file_ptr, input_string, (size_t) character_count);
        if (number_of_bytes_read <= 0) {
            printf("Error: Insufficient space!\n");
            exit(0);
        } else {
            printf("Iteration: %d\n", ++_iter);
            printf("--------------\n");
            printf("Read successful!\n");
            printf("Number of bytes read = %d\n", number_of_bytes_read);
            printf("The string is:\n");
            printf("%s\n", input_string);
        }
        sleep(1);
    }
    close(file_ptr);
    return 0;
}
