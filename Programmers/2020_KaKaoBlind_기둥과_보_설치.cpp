#include <string>
#include <vector>
using namespace std;

int map[102][102]; // 1: 기둥 2: 보 3: 둘다
int num;

bool bo_okay(int x, int y){
    if( (map[x][y-1]==1||map[x][y-1]==3) || //왼쪽 기둥
        (map[x+1][y-1]==1||map[x+1][y-1]==3) || // 오른쪽 기둥
        x>0&&(map[x-1][y]==2||map[x-1][y]==3)&&(map[x+1][y]==2||map[x+1][y]==3)){
        return true;
    }
    return false;
}

bool pillar_okay(int x, int y){
    if((y == 0) || // 바닥
        (map[x][y-1] == 1||map[x][y-1] == 3) || // 밑에 기둥
        (map[x][y] == 2||map[x][y] == 3) || // )오른쪽 보
        (x>0 &&(map[x-1][y] == 2||map[x-1][y] == 3))) // 왼쪽 보
        return true;
    return false;
}

bool possible(){
    for(int x=0; x<=num; x++){
        for(int y=0; y<=num; y++){
            if(map[x][y] == 1 || map[x][y] == 3 ){ // 기둥
                if(!pillar_okay(x, y)) return false;
            }
            if(map[x][y] == 2 || map[x][y] == 3){ // 보
                if(!bo_okay(x, y)) return false;
            }
        }
    }
    return true;
}

void build(int x, int y, int a, int b){
    if(a==0){ // 기둥
        if(b==0){ // 삭제
            map[x][y] -= 1;
            if(!possible()){
                map[x][y] += 1; // 삭제 실패
            }
        }
        else{ // 설치
            if(pillar_okay(x, y)) map[x][y] += 1; // 설치 성공
        }
    }
    else{ // 보
        if(b==0){ // 삭제
            map[x][y] -= 2;
            if(!possible()){ 
                map[x][y] += 2; // 삭제 실패
            }
        }
        else{ // 설치
            if(bo_okay(x, y)) map[x][y] += 2; // 설치 성공
        }
    }
}


vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    vector<int> v;
    
    num = n;
    
    for(int i=0; i<build_frame.size(); i++){
        build(build_frame[i][0], build_frame[i][1], build_frame[i][2], build_frame[i][3]);
    }
    
    for(int x=0; x<=n; x++){
        for(int y=0; y<=n; y++){
            if(map[x][y] == 1 || map[x][y] == 3 ){ // 기둥
                v.clear();
                v.push_back(x); v.push_back(y);v.push_back(0);
                answer.push_back(v);
            }
            if(map[x][y] == 2 || map[x][y] == 3){ // 보
                v.clear();
                v.push_back(x); v.push_back(y);v.push_back(1);
                answer.push_back(v);
            }
        }
    }
    
    return answer;
}
