#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_FRAMES 100
int main() {
    int total_frames, window_size;
    int ack_status[MAX_FRAMES] = {0}; 
    int send_base = 0;
    int i, ack_result;
    srand(time(NULL));
    printf("Enter total number of frames to send: ");
    if (scanf("%d", &total_frames) != 1 || total_frames <= 0) {
        printf("Invalid input.\n");
        return 1;
    }
    printf("Enter window size (N): ");
    if (scanf("%d", &window_size) != 1 || window_size <= 0) {
        printf("Invalid input.\n");
        return 1;
    }
    printf("\n=== Starting Selective Repeat ARQ Simulation ===\n\n");
    while (send_base < total_frames) {
        int window_end = send_base + window_size;
        if (window_end > total_frames) {
            window_end = total_frames;
        }
        printf("Current Window: [ ");
        for (i = send_base; i < window_end; i++) {
            printf("%d ", i + 1);
        }
        printf("]\n");
        printf(" Transmitting frames:\n");
        for (i = send_base; i < window_end; i++) {
            if (ack_status[i] == 0) {
                printf("  -> Sending [Frame %d]\n", i + 1);
            }
        }
        printf("\n Processing Acknowledgments:\n");
        for (i = send_base; i < window_end; i++) {
            if (ack_status[i] == 0) {
                ack_result = rand() % 5;
                if (ack_result != 0) {
                    printf("  [ACK Received] Frame %d acknowledged.\n", i + 1);
                    ack_status[i] = 1; // Mark frame as individually ACKed
                } else {
                    printf("  [NAK / LOSS] Frame %d lost or corrupted!\n", i + 1);
                }
            }
        }
        while (send_base < total_frames && ack_status[send_base] == 1) {
            send_base++; 
        }
        printf("\n------------------------------------------------\n\n");
    }
    printf("=== All %d frames transmitted and acknowledged successfully! ===\n", total_frames);
    return 0;
}
