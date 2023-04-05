#include<iostream>

using namespace std;

int n, k, maxLen = 0;
int map[8][8];
bool visited[8][8];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void makePath(int x, int y, int len, bool canCut){ // DFS
    int newX, newY, newH, h = map[x][y];
    bool isEnd = true;
    
    visited[x][y] = true;
    for(int i=0; i<4; i++){
        newX = x+dx[i]; newY = y+dy[i]; newH = map[newX][newY];
        if(newX<0||newX>=n||newY<0||newY>=n||visited[newX][newY]) continue;
        
        if(h>newH){ // without cutting
            makePath(newX, newY, len+1, canCut);
            isEnd = false;
        }
        else if(canCut && h>newH-k){ // need to cut
            map[newX][newY] = h-1; // cut path
            makePath(newX, newY, len+1, false);
            map[newX][newY] = newH; // return to original path
            isEnd = false;
        }
    }
    if(isEnd){
        maxLen = max(maxLen, len); // end of the path
    }
    visited[x][y] = false;
}

int main(int argc, char** argv)
{
    int test_case;
    int T;
    int maxH = 0;
    
    //freopen("input.txt", "r", stdin);
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        cin>>n>>k; maxLen = 0; maxH = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin>>map[i][j];
                maxH = max(maxH, map[i][j]);
                visited[i][j] = false;
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(map[i][j]==maxH) makePath(i, j, 1, true);
            }
        }
        cout<<'#'<<test_case<<' '<<maxLen<<'\n';
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
