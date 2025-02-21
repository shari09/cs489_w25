#include <sys/stat.h>
#include <stdio.h>
    
// This program prints the size of a specified file in bytes
int main(int argc, char** argv) {
    // Ensure that the user supplied exactly one command line argument
    if (argc != 2) { 
        fprintf(stderr, "Please provide the address of a file as an input.\n");
        return -1;
    }
    char *filename = argv[1];
    struct stat fs;
    if (stat(filename, &fs) == -1) {
        fprintf(stderr, "Error: File does not exist.\n");
        return -1;
    }
    printf("The size of the file is %lld bytes.\n", fs.st_size);
}
