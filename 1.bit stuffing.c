#include <stdio.h>
#include <string.h>
int main() { 
    char a[50];
    int count = 0, i = 0, j, l, k = 0; 
    printf("Enter the input binary string: ");
    scanf("%s", a);
    l = strlen(a);
    // ================= BIT STUFFING =================
    for(i = 0; i < l; i++) {
        if(a[i] == '1') {
            k = i; 
            count = 0;
            while(a[k] == '1') { 
                count += 1; 
                k++;
                if(count == 5) {
                    for(j = l; j >= k; j--) {
                        a[j + 1] = a[j];
                    } 
                    a[k] = '0'; 
                    l++;       
                    break;
                }
            }
            i = k - 1; 
        }
    }
    printf("The bitstuffed string is: %s\n", a);
    // ================= BIT UNSTUFFING =================
    l = strlen(a); 
    for(i = 0; i < l; i++) {
        if(a[i] == '1') {
            k = i; 
            count = 0;
            while(a[k] == '1') { 
                count += 1;
                k++;
                if(count == 5 && a[k] == '0') {
                    for(j = k; j < l; j++) {
                        a[j] = a[j + 1];
                    } 
                    l--; 
                    break;
                }
            }
            i = k - 1; 
        }
    }
    printf("String after unstuffing:  %s\n", a); 
    return 0;
}
