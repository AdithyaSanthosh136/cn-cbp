#include <stdio.h>
#include <string.h>
#define MAX 200
void characterStuffing(char *input, char *stuffed) {
    int i = 0, j = 0;
    stuffed[j++] = 'D'; stuffed[j++] = 'L'; stuffed[j++] = 'E';
    stuffed[j++] = 'S'; stuffed[j++] = 'T'; stuffed[j++] = 'X';
    while (input[i] != '\0') {
        if (input[i] == 'D' && input[i+1] == 'L' && input[i+2] == 'E') {
            stuffed[j++] = 'D'; 
            stuffed[j++] = 'L'; 
            stuffed[j++] = 'E';
        }
        stuffed[j++] = input[i++];
    }
    stuffed[j++] = 'D'; stuffed[j++] = 'L'; stuffed[j++] = 'E';
    stuffed[j++] = 'T'; stuffed[j++] = 'X';
    stuffed[j] = '\0'; 
}
void characterDestuffing(char *stuffed, char *destuffed) {
    int i = 6; 
    int j = 0;
    int stuffedLen = strlen(stuffed);
    int limit = stuffedLen - 5;
    while (i < limit) {
        if (stuffed[i] == 'D' && stuffed[i+1] == 'L' && stuffed[i+2] == 'E') {
            if (stuffed[i+3] == 'D' && stuffed[i+4] == 'L' && stuffed[i+5] == 'E') {
                destuffed[j++] = 'D'; destuffed[j++] = 'L'; destuffed[j++] = 'E';
                i += 6; 
                continue;
            }
        }
        destuffed[j++] = stuffed[i++];
    }
    
    destuffed[j] = '\0'; 
}
int main() {
    char originalData[MAX];
    char stuffedData[MAX * 2];
    char destuffedData[MAX];
    printf("--- Character Stuffing Program (DLE/STX/ETX) ---\n");
    printf("Enter the frame text: ");
    if (fgets(originalData, sizeof(originalData), stdin)) {
        originalData[strcspn(originalData, "\n")] = '\0';
        characterStuffing(originalData, stuffedData);
        printf("\nStuffed text:    %s\n", stuffedData);
        characterDestuffing(stuffedData, destuffedData);
        printf("Destuffed text:  %s\n", destuffedData);
    }
    return 0;
}
