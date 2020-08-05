#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//int main() {
//    char arr[100], n;
//    int i = 0, cnt = 0, max = 0;
//    while (1) {
//        n = getchar();
//        if (n == '\n') break;
//        arr[i] = n;
//        i++;
//    }
//    i--;
//    for (int j = 0; j <= i; j++) {
//        int k = j;
//        for (int l = i; l >= j; l--) {
//            if (arr[k] == arr[l]) {
//                if (k < l) {
//                    cnt += 2;
//                    k++;
//                    if (k == l) break;
//                }
//                else if (k == l) {
//                    cnt++;
//                    break;
//                }
//            }
//            else {
//                if (cnt > 0) {
//                    cnt = 0;
//                    break;
//                }
//            }
//        }
//        if (cnt > max) {
//            max = cnt;
//            cnt = 0;
//        }
//        else cnt = 0;
//    }
//    printf("%d", max);
//    return 0;
//}

int main() {
    char arr[100], n;
    int i = 0, cnt = 0, max = 0;
    while (1) {
        n = getchar();
        if (n == '\n') break;
        arr[i] = n;
        i++;
    }
    i--;
    for (int j = 0; j <= i; j++) {
        int k = j;
        for (int l = i; l >= j; l--) {
            if (arr[k] == arr[l]) {
                if (k < l) {
                    cnt += 2;
                    k++;
                    if (k == l) break;
                }
                else if (k == l) {
                    cnt++;
                    break;
                }
            }
            else {
                if (cnt > 0) {
                    k = j;
                    l += (cnt - 1);
                    cnt = 0;
                }
            }
        }
        if (cnt > max) {
            max = cnt;
            cnt = 0;
        }
        else cnt = 0;
    }
    printf("%d", max);
    return 0;
}