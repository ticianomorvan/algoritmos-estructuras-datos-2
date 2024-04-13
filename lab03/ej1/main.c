#include <stdlib.h>
#include <stdio.h>

#define MAX_SIZE 1000

static void dump(char a[], unsigned int length) {
    printf("\"");
    for (unsigned int j=0u; j < length; j++) {
        printf("%c", a[j]);
    }
    printf("\"");
    printf("\n\n");
}

static void print_help(char *program_name) {
    printf(
        "Usage: %s <path/to/file.in>\n\n"
        "Loads a file from its path and prints it on the screen.\n"
        "The input file must have the following format:\n"
        "Each line must consist of an integer and a letter, matching the pattern described below:\n\n"
        "<integer> -> *<letter>*\n\n"
        "Then, every following pair of integer and letter must be wrote in a new line.\n"
        "Finally, the file should look like this:\n\n"
        "<integer 1> -> *<letter 1>*\n"
        "<integer 2> -> *<letter 2>*\n"
        "(...)\n"
        "<integer n> -> *<letter n>*\n", program_name
    );
}

char* parse_filepath(int argc, char *argv[]) {
    char *result = NULL;

    if (argc < 2) {
        print_help(argv[0]);
        exit(EXIT_FAILURE);
    }

    result = argv[1];

    return result;
}

/* 
    Read a file from a given path and parses it following this pattern:
    <int index> -> *char letter*

    Then, assign every found index and letter to a specific array, both in the same position.
*/
unsigned int read_data_from_file(
    char *filepath,
    int max_size,
    unsigned  indexes[],
    char letters[]
) {
    FILE *file;
    int last_index;

    file = fopen(filepath, "r");
    last_index = 0;

    if (file == NULL) {
        fprintf(stderr, "File \"%s\" does not exist.\n", filepath);
        exit(EXIT_FAILURE);
    }

    while (feof(file) == 0) {
        int index;
        char letter;

        fscanf(file, "%i -> *%c*\n", &index, &letter);

        if (index > max_size) {
            printf("%i is not a valid index, as exceeds the maximum size of %i elements.\n", index, MAX_SIZE);
            exit(EXIT_FAILURE);
        }

        indexes[last_index] = index;
        letters[last_index] = letter;

        last_index++;
    }

    fclose(file);

    return last_index;
}

int main(int argc, char *argv[]) {
    char *filepath = NULL;
    char letters[MAX_SIZE];
    char sorted[MAX_SIZE];
    unsigned int indexes[MAX_SIZE];
    unsigned int length = 0; 
    
    filepath = parse_filepath(argc, argv);

    length = read_data_from_file(filepath, MAX_SIZE, indexes, letters);

    for (unsigned int i = 0u; i < length; i++) {
        sorted[indexes[i]] = letters[i];
    }

    dump(sorted, length);

    return EXIT_SUCCESS;
}

