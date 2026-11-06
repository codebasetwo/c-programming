#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    const char* fname = "./tmp/unique_name.txt"; // or tmpnam(NULL);
    int is_ok = EXIT_FAILURE;

    FILE* fp = fopen(fname, "w+");
    if (!fp)
    {
        perror("File opening failed");
        return is_ok;
    }
    fputs("Hello, world!\n", fp);
    rewind(fp); // takes the cursor back to the begining

    int c; // note: int, not char, required to handle EOF
    while ((c = fgetc(fp)) != EOF) // standard C I/O file reading loop
        putchar(c); // writes a character to stdout

    if (ferror(fp))
        puts("I/O error when reading");
    else if (feof(fp))
    {
        puts("End of file is reached successfully");
        is_ok = EXIT_SUCCESS;
    }

    fclose(fp);
    // int exit_code = remove(fname); // deletes file 0 for succesful deletion and non zero for failed deletion
    return is_ok;
}
