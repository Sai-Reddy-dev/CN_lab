#include <stdio.h>
int main() {
    int total_frames, window_size;
    int i, j;
    printf("Enter total number of frames: ");
    scanf("%d", &total_frames);
    printf("Enter window size: ");
    scanf("%d", &window_size);
    printf("\nSelective Repeat Simulation\n\n");
    i = 1;
    while (i <= total_frames) {
        printf("Sender sends frames: ");
        for (j = i; j < i + window_size && j <= total_frames; j++) {
            printf("%d ", j);
        }
        printf("\n");
        printf("Receiver acknowledges: ");
        for (j = i; j < i + window_size && j <= total_frames; j++) {
            printf("%d ", j);
        }
        printf("\n\n");
        i += window_size;
    }
    return 0;
}

