#include <stdio.h>
int main() {
    int bucket_size, output_rate, n;
    printf("Enter bucket size: ");
    scanf("%d", &bucket_size);
    printf("Enter output rate: ");
    scanf("%d", &output_rate);
    printf("Enter number of packets: ");
    scanf("%d", &n);
    int packets[n],i;
    printf("Enter packet sizes:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &packets[i]);
    }
int bucket = 0;
    for ( i = 0; i < n; i++) {
        printf("\nPacket %d of size %d arrived.", i + 1, packets[i]);
        if (packets[i] + bucket > bucket_size) {
            printf("\nBucket overflow! Packet %d discarded.", i + 1);
        } else {
            bucket += packets[i];
            printf("\nBucket status: %d/%d", bucket, bucket_size);
        }
        if (bucket >= output_rate) {
            bucket -= output_rate;
            printf("\nSent %d packets, Remaining in bucket: %d", output_rate, bucket);
        } else {
            printf("\nLess than output rate available, sending %d", bucket);
            bucket = 0;
        }
    }
    if (bucket > 0) {
        while (bucket > 0) {
            if (bucket >= output_rate) {
                bucket -= output_rate;
                printf("\nSent %d packets, Remaining in bucket: %d", output_rate, bucket);
            } else {
                printf("\nSent %d packets, Remaining in bucket: 0", bucket);
                bucket = 0;
            }
        }
    }
    return 0;
}

