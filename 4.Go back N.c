#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
    int total_frames, window_size;
    int sent = 0, i, ack;
    srand(time(NULL));
    printf("Enter total number of frames to send: ");
    scanf("%d", &total_frames);
    printf("Enter window size (N): ");
    scanf("%d", &window_size);
    printf("\n--- Starting Go-Back-N Transmission ---\n\n");
    while (sent < total_frames) {
        printf("Transmitting frames in window: ");
        for (i = 0; i < window_size && (sent + i) < total_frames; i++) {
            printf("[Frame %d] ", sent + i + 1);
        }
        printf("\n");
        for (i = 0; i < window_size && sent < total_frames; i++) {
            ack = rand() % 5;
            if (ack != 0) {
                printf("  -> ACK %d received successfully.\n", sent + 1);
                sent++; 
            } else {
                printf("  !! Frame / ACK %d lost or corrupted!\n", sent + 1);
                printf("  !! Timeout occurred. Going back N frames...\n\n");
                break;
            }
        }
        printf("\n");
    }
    printf("--- All %d frames transmitted successfully! ---\n", total_frames);
    return 0;
}
