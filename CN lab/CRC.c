#include <stdio.h>
#include <string.h>
void xor_op(char a[], char b[], int n) {
    int i;
    for(i = 1; i < n; i++) {
        a[i] = (a[i] == b[i]) ? '0' : '1';
    }
}
void crc(char data[], char gen[], char crcCode[]) {
    int n, m, i, j;
    n = strlen(gen);
    m = strlen(data);
    char temp[200];       
    char remainder[50];   
    for(i = 0; i < m; i++) temp[i] = data[i];
    for(i = m; i < m + n - 1; i++) temp[i] = '0';
    temp[m + n - 1] = '\0';
    for(i = 0; i < n; i++) remainder[i] = temp[i];
    remainder[n - 1] = '\0';
    for(i = 0; i < m; i++) {
        if(remainder[0] == '1') {
            xor_op(remainder, gen, n);
        }
        for(j = 0; j < n - 1; j++)
            remainder[j] = remainder[j + 1];
        remainder[n - 1] = temp[i + n - 1];
    }
    for(i = 0; i < n - 1; i++) crcCode[i] = remainder[i];
    crcCode[n - 1] = '\0';
}
int main() {
    char data[100];
    char crc12[20], crc16[20], crcCCITT[20];
    char crc12Gen[] = "1100000001111";        
    char crc16Gen[] = "11000000000000101";    
    char crcCCITTGen[] = "10001000000100001"; 
    int i;
    printf("Enter data in binary (e.g., 11101): ");
    scanf("%s", data);
    crc(data, crc12Gen, crc12);
    crc(data, crc16Gen, crc16);
    crc(data, crcCCITTGen, crcCCITT);
    printf("CRC-12 code: %s\n", crc12);
    printf("CRC-16 code: %s\n", crc16);
    printf("CRC-CCITT code: %s\n", crcCCITT);
    return 0;
}

