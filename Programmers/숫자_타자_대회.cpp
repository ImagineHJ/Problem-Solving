#include <string>
#include <vector>
#define INF 1e9

using namespace std;
int cost[10][10] = {
    {1, 7, 6, 7, 5, 4, 5, 3, 2, 3},
    {7, 1, 2, 4, 2, 3, 5, 4, 5, 6},
    {6, 2, 1, 2, 3, 2, 3, 5, 4, 5},
    {7, 4, 2, 1, 5, 3, 2, 6, 5, 4},
    {5, 2, 3, 5, 1, 2, 4, 2, 3, 5},
    {4, 3, 2, 3, 2, 1, 2, 3, 2, 3},
    {5, 5, 3, 2, 4, 2, 1, 5, 3, 2},
    {3, 4, 5, 6, 2, 3, 5, 1, 2, 4},
    {2, 5, 4, 5, 3, 2, 3, 2, 1, 2},
    {3, 6, 5, 4, 5, 3, 2, 4, 2, 1}
};
int dp[10][10];

void cal(int n){
    int temp[10][10];
    
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            temp[i][j] = INF; // init
        }
    }
    
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            if(dp[i][j]!=INF){
                // left
                if(j!=n) temp[n][j] = min(temp[n][j], dp[i][j] + cost[i][n]);
                // right
                if(i!=n) temp[i][n] = min(temp[i][n], dp[i][j] + cost[j][n]);
            }
        }    
    }
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            dp[i][j] = temp[i][j]; // copy back
        }
    }
}

int solution(string numbers) {
    int answer = INF;
    int n;
    
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            dp[i][j] = INF; // init
        }
    }
    
    dp[4][6] = 0;    
    for(int i=0; i<numbers.size(); i++){
        cal(numbers[i]-'0');
    }
    n = numbers[numbers.size()-1]-'0';
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            if(i==n || j==n ) answer = min(answer, dp[i][j]);
        }
    }
        
    return answer;
}
