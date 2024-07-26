#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <fcntl.h>

#define IO_BUFSIZE 1024

// Build Your Own wc Tool
// This challenge is to build your own version of the Unix command line tool wc!
// The 'wc' (word count) command counts lines, words, and bytes (or characters) in text files.
// This simplified version will support basic options for counting lines, words, characters, and bytes.

int is_start_of_utf8_char(unsigned char byte)
{
    return (byte & 0x80) == 0x00 || (byte & 0xE0) == 0xC0 || (byte & 0xF0) == 0xE0 || (byte & 0xF8) == 0xF0;
}

int main(int argc, char *argv[])
{

    char c;
    int countword = 0,
        countchar = 0,
        countline = 0,
        in_word = 0,
        countbytes = 0;

    char buffer[IO_BUFSIZE];
    if (argc < 2 || argc > 3)
    {
        printf("Usage: %s [-l|-w|-m|-c] [file]\n", argv[0]);
        return 1;
    }

    char option = '\0';
    int file_index = 1;
    FILE *fptr;

    if (argc > 1 && argv[1][0]=='-')
    {

        file_index = 2;

        if (strcmp(argv[1], "-l") == 0)
            option = 'l';
        else if (strcmp(argv[1], "-c") == 0)
            option = 'c';
        else if (strcmp(argv[1], "-w") == 0)
            option = 'w';
        else if (strcmp(argv[1], "-m") == 0)
            option = 'm';

        else
        {
            printf("Invalid option: %s\n", argv[1]);
            return 1;
        }
    }

    else if (argc == 2 && strcmp(argv[1], "--help") == 0)
    {
        printf("Usage: wc [OPTION]... [FILE]...\n"
               "Print newline, word, and byte counts for each FILE.\n"
               "Options:\n"
               "  -c, --bytes  print the byte counts\n"
               "  -m, --chars  print the character counts (same as byte counts in this implementation)\n"
               "  -l, --lines  print the newline counts\n"
               "  -w, --words  print the word counts\n"
               "  --help       display this help message\n");
        return 0;
    }

    if (argc > file_index)
    {
        fptr = fopen(argv[file_index], "r");
        if (fptr == NULL)
        {
            perror("Error opening file");
            return 1;
        }
    }
    else
    {
        fptr = stdin;
    }

    ssize_t bytes_read;
    while ((bytes_read = fread(buffer, 1, IO_BUFSIZE, fptr)) > 0)
    {

        countbytes += bytes_read;

        for (ssize_t i = 0; i < bytes_read; i++)
        {
            if (is_start_of_utf8_char(buffer[i]))
                countchar++;
            if (buffer[i] == '\n')
                countline++;
            if (isspace(buffer[i]))
            {
                if (in_word)
                {
                    in_word = 0;
                    countword++;
                }
            }
            else
            {
                in_word = 1;
            }
        }
    }
    if (in_word)
        countword++;

    switch (option)
    {
    case 'c':
        if (argc == 3)
            printf("%d  %s\n", countbytes, argv[file_index]);
        else
            printf("%d \n", countbytes);
        break;
    case 'l':
        if (argc == 3)
            printf("%d  %s\n", countline, argv[file_index]);
        else
            printf("%d \n", countline);
        break;
    case 'w':
        if (argc == 3)
            printf("%d %s\n", countword, argv[file_index]);
        else
            printf("%d \n", countword);
        break;
    case 'm':
        if (argc == 3)
            printf("%d %s\n", countchar, argv[file_index]);
        else
            printf("%d\n", countchar);
        break;

    default:
    if (argc == 2 && fptr == stdin)
            printf("%d  %d %d\n", countline, countword, countbytes);
        else 

        printf("  %d  %d %d %s\n", countline, countword, countbytes, argv[file_index]);

        break;
    }

    if (fptr != stdin)
        fclose(fptr);

    return 0;
}