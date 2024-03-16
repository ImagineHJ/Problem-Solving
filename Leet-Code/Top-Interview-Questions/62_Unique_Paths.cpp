class Solution {
public:
    int DP[100]={0};
    int uniquePaths(int m, int n) {
        DP[0]=1;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(j>0) DP[j] += DP[j-1];
            }
        }
        return DP[n-1];
    }
};
