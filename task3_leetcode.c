// Leetcode Problem submitted code

#include<string.h>
typedef struct {
    int val;
    char dir;  
} ele;

int longestCommonSubsequence(char* text1, char* text2) {
    int m = strlen(text1);
    int n = strlen(text2);
    ele cost[m+1][n+1];
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                cost[i][j].val = 0;
                cost[i][j].dir = 'h';  
            }
            else if (text1[i-1] == text2[j-1]) {
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
    return cost[m][n].val;

}