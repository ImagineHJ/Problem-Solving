#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1e9
using namespace std;

int n, maxM = -1001;
int map[300][300];
int sum[300][300];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    cin>>n;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>map[i][j];
            if(i==0){
                if(j==0) sum[i][j] = map[i][j];
                sum[i][j] = sum[i][j-1]+map[i][j];
            }
            else if(j==0){
                sum[i][j] = sum[i-1][j]+map[i][j];
            }
            maxM = max(maxM, map[i][j]);
        }
    }
    // calculate prefix sum
    for(int i=1; i<n; i++){
        for(int j=1; j<n; j++){
            sum[i][j] = sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+map[i][j];
            if(i==j) maxM = max(maxM, sum[i][j]);
        }
    }
    
    int sumS;
    for(int s=2; s<=n; s++){
            for(int i=0; i<n-s+1; i++){
                for(int j=0; j<n-s+1; j++){
                    if(i==0&&j!=0) sumS = sum[i+s-1][j+s-1]-sum[i+s-1][j-1];
                    else if(i!=0&&j==0) sumS = sum[i+s-1][j+s-1]-sum[i-1][j+s-1];
                    else sumS = sum[i+s-1][j+s-1]-sum[i-1][j+s-1]-sum[i+s-1][j-1]+sum[i-1][j-1];
                    maxM = max(maxM, sumS);
                }
            }
        }
    
    cout<<maxM;
    
    return 0;
}
