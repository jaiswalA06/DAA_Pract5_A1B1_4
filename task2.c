#include <stdio.h>

typedef struct {
    int val;
    char dir;  
} ele;

void print_matrix(int m,int n, ele cost[][n+1]){
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            printf("%d%c\t",cost[i][j].val,cost[i][j].dir);
        }
        printf("\n");
    }
}

void print_lcs(int size, char X[], ele cost[][size+1], int k, int l) {
    if (k == 0 || l == 0)
        return;

    if (cost[k][l].dir == 'd') {
        print_lcs(size, X, cost, k - 1, l - 1);
        printf("%c", X[k]);
    }
    else if (cost[k][l].dir == 'u') {
        print_lcs(size, X, cost, k - 1, l);
    }
    else if (cost[k][l].dir == 's') {
        print_lcs(size, X, cost, k, l - 1);
    }
}

void lcs(int m, int n, char X[], char Y[], ele cost[][n + 1]) {
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                cost[i][j].val = 0;
                cost[i][j].dir = 'h';  
            }
            else if (X[i] == Y[j] && i!=j) {
                cost[i][j].val = cost[i - 1][j - 1].val + 1;
                cost[i][j].dir = 'd';  
            }
            else {
                if (cost[i - 1][j].val >= cost[i][j - 1].val) {
                    cost[i][j].val = cost[i - 1][j].val;
                    cost[i][j].dir = 'u';  
                }
                else {
                    cost[i][j].val = cost[i][j - 1].val;
                    cost[i][j].dir = 's';  
                }
            }
        }
    }
    print_matrix(m,n,cost);
    printf("LRS: ");
    print_lcs(n, X, cost, m, n);
    printf("\n");
}

int main() {
    int m, n;

    printf("Enter length of X: ");
    scanf("%d", &m);
    printf("Enter length of Y: ");
    scanf("%d", &n);

    char X[m + 1], Y[n + 1];

    printf("Enter first string: ");
    for (int i = 1; i <= m; i++) {
        scanf(" %c", &X[i]); 
    }

    printf("Enter second string: ");
    for (int i = 1; i <= n; i++) {
        scanf(" %c", &Y[i]);
    }

    ele cost[m + 1][n + 1];

    lcs(m, n, X, Y, cost);

    return 0;
}
