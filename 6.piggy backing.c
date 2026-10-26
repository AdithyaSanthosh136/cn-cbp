#include <stdio.h>
#include <string.h>
typedef struct {
    int seq_num;
    int ack_num;
    char data[50];
} Frame;
int main() {
    Frame A, B;
    int n, seq_A = 0, seq_B = 0;
    printf("Enter number of bidirectional rounds: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Invalid input.\n");
        return 1;
    }
    printf("\n=== Starting Piggybacking Simulation ===\n");
    for (int i = 1; i <= n; i++) {
        printf("\n------------------- ROUND %d -------------------\n", i);
        A.seq_num = seq_A;
        A.ack_num = (i == 1) ? -1 : seq_B - 1;
        sprintf(A.data, "Data_Packet_A%d", i);
        printf("[Node A -> Node B] Transmitting Frame:\n");
        printf("  - Sequence Number : %d\n", A.seq_num);
        printf("  - Data Payload    : %s\n", A.data);
        if (A.ack_num != -1)
            printf("  - Piggybacked ACK : %d (Acknowledges Node B's Frame %d)\n", A.ack_num + 1, A.ack_num);
        else
            printf("  - Piggybacked ACK : None (First Frame)\n");
        printf("\n[Node B] Received Frame %d from Node A with data '%s'\n", A.seq_num, A.data);
        B.seq_num = seq_B;
        B.ack_num = A.seq_num;
        sprintf(B.data, "Data_Packet_B%d", i);
        printf("\n[Node B -> Node A] Transmitting Frame (with Piggybacked ACK):\n");
        printf("  - Sequence Number : %d\n", B.seq_num);
        printf("  - Data Payload    : %s\n", B.data);
        printf("  - Piggybacked ACK : %d (Acknowledges Node A's Frame %d)\n", B.ack_num + 1, B.ack_num);
        printf("\n[Node A] Received Frame %d from Node B with data '%s'\n", B.seq_num, B.data);
        printf("[Node A] ACK %d extracted successfully! (Frame %d delivery confirmed)\n", B.ack_num + 1, B.ack_num);
        seq_A++;
        seq_B++;
    }
    printf("\n=== Simulation Complete: All frames and piggybacked ACKs delivered ===\n");
    return 0;
}
