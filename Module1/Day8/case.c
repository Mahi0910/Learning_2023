#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define BUFFER_SIZE 4096

// Function to convert the file content to Upper Case
void convertToUpper(char* buffer) {
    for (int i = 0; buffer[i] != '\0'; i++) {
        buffer[i] = toupper(buffer[i]);
    }
}

// Function to convert the file content to Lower Case
void convertToLower(char* buffer) {
    for (int i = 0; buffer[i] != '\0'; i++) {
        buffer[i] = tolower(buffer[i]);
    }
}

// Function to convert the file content to Sentence Case
void convertToSentenceCase(char* buffer) {
    int capitalizeNext = 1;  // Flag to capitalize the next character

    for (int i = 0; buffer[i] != '\0'; i++) {
        if (isspace(buffer[i])) {
            capitalizeNext = 1;
        } else if (capitalizeNext) {
            buffer[i] = toupper(buffer[i]);
            capitalizeNext = 0;
        } else {
            buffer[i] = tolower(buffer[i]);
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Insufficient arguments.\n");
        printf("Usage: ./cp <option> <source_file> <target_file>\n");
        return 1;
    }

    char* option = argv[1];
    char* sourcePath = argv[2];
    char* targetPath = argv[3];

    FILE* sourceFile = fopen(sourcePath, "r");
    if (sourceFile == NULL) {
        printf("Unable to open the source file.\n");
        return 1;
    }

    FILE* targetFile = fopen(targetPath, "w");
    if (targetFile == NULL) {
        printf("Unable to create the target file.\n");
        fclose(sourceFile);
        return 1;
    }

    char buffer[BUFFER_SIZE];
    size_t bytesRead;

    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, sourceFile)) > 0) {
        if (strcmp(option, "-u") == 0) {
            convertToUpper(buffer);
        } else if (strcmp(option, "-l") == 0) {
            convertToLower(buffer);
        } else if (strcmp(option, "-s") == 0) {
            convertToSentenceCase(buffer);
        }

        fwrite(buffer, 1, bytesRead, targetFile);
    }

    printf("File copied successfully.\n");

    fclose(sourceFile);
    fclose(targetFile);

    return 0;
}