#include "Solution1318.h"

int Solution1318::minFlips(int a, int b, int c) {
    if (a + b == c) {
        return 0;
    }
    long int count = 0;
    while (a > 0 || b > 0 || c > 0) {
        int a_last = a & 1;
        int b_last = b & 1;
        int c_last = c & 1;
        if ((a_last | b_last) != c_last) {
            if (c_last == 1) {
                count++;
            }
            else if (c_last == 0) {
                if (a_last == b_last) {
                    count += 2;
                }
                else {
                    count++;
                }
            }
        }
        a >>= 1;
        b >>= 1;
        c >>= 1;
    }
    return count;
}