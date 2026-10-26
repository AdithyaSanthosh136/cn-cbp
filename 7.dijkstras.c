#include <stdio.h>
#define IN 999
#define N 6
char nodeName(int node){
    return 'A' + node - 1;
}
int dijkstra(int cost[][N], int source, int target){
    int dist[N], prev[N], selected[N] = {0};
    int i, j, current, next, min, newDist;
    int path[N], pathLength = 0;
    for (i = 1; i < N; i++) {
        dist[i] = IN;
        prev[i] = -1;
    }
    dist[source] = 0;
    printf("\n========================================");
    printf("\n   DIJKSTRA'S ALGORITHM - STEPS");
    printf("\n========================================\n");
    printf("\nInitial distances:\n");
    for (i = 1; i < N; i++) {
        if (i == source)
            printf("%c = 0\n", nodeName(i));
        else
            printf("%c = INF\n", nodeName(i));
    }
    current = source;
    while (1) {
        selected[current] = 1;
        printf("\n----------------------------------------");
        printf("\nCurrent node: %c", nodeName(current));
        printf("\n----------------------------------------\n");
        for (i = 1; i < N; i++) {
            if (selected[i] == 0 && cost[current][i] != IN) {
                newDist = dist[current] + cost[current][i];
                printf("\nChecking %c:", nodeName(i));
                printf(" %d + %d = %d",dist[current], cost[current][i], newDist);
                if (newDist < dist[i]) {
                    dist[i] = newDist;
                    prev[i] = current;
                    printf("  -> Updated");
                } else {
                    printf("  -> No update");
                }
            }
        }
        if (current == target)
            break;
        min = IN;
        next = -1;
        for (i = 1; i < N; i++) {
            if (selected[i] == 0 && dist[i] < min) {
                min = dist[i];
                next = i;
            }
        }
        if (next == -1) {
            printf("\n\nNo path exists between the source and target.\n");
            return -1;
        }
        current = next;
        printf("\n\nDistance table:");
        for (j = 1; j < N; j++) {
            if (dist[j] == IN)
                printf("\n%c = INF", nodeName(j));
            else
                printf("\n%c = %d", nodeName(j), dist[j]);
        }
        printf("\n");
    }
    current = target;
    while (current != -1) {
        path[pathLength++] = current;
        current = prev[current];
    }
    printf("\n\n========================================");
    printf("\n           FINAL RESULT");
    printf("\n========================================\n");
    printf("\nShortest Path: ");
    for (i = pathLength - 1; i >= 0; i--) {
        printf("%c", nodeName(path[i]));
        if (i != 0)
            printf(" -> ");
    }
    printf("\n");
    printf("Shortest Distance: %d\n", dist[target]);
    printf("\n========================================\n");
    return dist[target];
}
int main(){
    int cost[N][N];
    int i, j, w, source, target, shortestDistance;
    printf("\n========================================");
    printf("\n      DIJKSTRA'S SHORTEST PATH");
    printf("\n========================================\n");
    for (i = 1; i < N; i++) {
        for (j = 1; j < N; j++)
            cost[i][j] = IN;
    }
    printf("\nEnter the weights between nodes.\n");
    printf("Enter 0 if there is no direct path.\n\n");
    for (i = 1; i < N; i++) {
        for (j = i + 1; j < N; j++) {
            printf("Enter weight between %c and %c: ",
                   nodeName(i), nodeName(j));
            scanf("%d", &w);
            if (w == 0) {
                cost[i][j] = IN;
                cost[j][i] = IN;
            } else {
                cost[i][j] = w;
                cost[j][i] = w;
            }
        }
    }
    printf("\n----------------------------------------");
    printf("\nNode Mapping");
    printf("\n----------------------------------------\n");
    for (i = 1; i < N; i++)
        printf("%d = %c\n", i, nodeName(i));
    printf("\nEnter source node (1-5): ");
    scanf("%d", &source);
    printf("Enter target node (1-5): ");
    scanf("%d", &target);
    if (source < 1 || source >= N ||target < 1 || target >= N) {
        printf("\nInvalid source or target node!\n");
        return 1;
    }
    shortestDistance = dijkstra(cost, source, target);
    if (shortestDistance != -1) {
        printf("\nSource : %c", nodeName(source));
        printf("\nTarget : %c", nodeName(target));
        printf("\nCost   : %d\n", shortestDistance);
    }
    return 0;
}
