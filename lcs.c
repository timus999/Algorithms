#include <stdio.h>
#include <string.h>

#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))

int lcs(char *X, char *Y) {
    int m = strlen(X), n = strlen(Y);
    int L[m+1][n+1];
    
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i-1] == Y[j-1])
                L[i][j] = L[i-1][j-1] + 1;
            else
                L[i][j] = MAX(L[i-1][j], L[i][j-1]);
        }
    }
    return L[m][n];
}

int main() {
    char X[] = "ABCBDAB";
    char Y[] = "BDCAB";
    printf("Length of LCS is %d\n", lcs(X, Y));
    return 0;
}
