#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
void sender(int total_frames, int window_size);
void receiver(int frame_no, bool *ack);
int main() {
    srand(time(0));
    int n, w;
    printf("Enter total number of frames: ");
    scanf("%d", &n);
    printf("Enter window size: ");
    scanf("%d", &w);
    printf("\nGo-Back-N Simulation\n");
   sender(n, w);
    return 0;
}
void sender(int total_frames, int window_size) {
    int base = 0,i, next_seq_num = 0;
    bool ack[total_frames];
    for(i=0;i<total_frames;i++) ack[i]=false;
    while (base < total_frames) {
        while (next_seq_num < base + window_size && next_seq_num < total_frames) {
            printf("Sending frame %d\n", next_seq_num);
            receiver(next_seq_num, ack);
            next_seq_num++;
        }
        for (i = base; i < next_seq_num; i++) {
            if (ack[i]) {
                printf("Acknowledgment received for frame %d\n", i);
            } else {
                printf("Frame %d lost. Resending from frame %d\n", i, i);
                next_seq_num = i;
                break;
            }
        }
        while (ack[base] && base < total_frames) base++;
    }
    printf("All frames sent successfully!\n");
}

void receiver(int frame_no, bool *ack) {
    int r = rand() % 100;
    if (r < 20) {
        printf("Frame %d lost during transmission\n", frame_no);
        ack[frame_no] = false;
    } else {
        printf("Frame %d received\n", frame_no);
        ack[frame_no] = true;
    }
}

