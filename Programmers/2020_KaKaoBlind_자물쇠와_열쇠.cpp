#include <string>
#include <vector>

using namespace std;
int glo_key[21][21];
int glo_lock[21][21];
int moved_key[21][21];
int m, n;

bool unlock(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(glo_lock[i][j]==0 && moved_key[i][j]!=1) return false;
            if(glo_lock[i][j]==1 && moved_key[i][j]==1) return false;
        }
    }
    return true;
}

void move_key(int r, int x, int y){
    int temp, new_x, new_y;
    int temp_key[21][21];
    int rotated_key[21][21];
    
    for(int i=0; i<m; i++){
        for(int j=0; j<m; j++){
            rotated_key[i][j] = glo_key[i][j]; // copy
        }
    }
    /*
    r=0 : no rotate
    r=1 : 90 rotate
    r=2 : 180 rotate
    r=3 : 270 rotate
    */
    for(int h=0; h<r; h++){
        for(int i=0; i<m; i++){
            for(int j=0; j<m; j++){
                temp_key[i][j] = rotated_key[j][m-1-i];
            }
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<m; j++){
                rotated_key[i][j] = temp_key[i][j];
            }
        }
    }
    
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            moved_key[i][j] = -1; // initialize
        }
    }
    
    for(int i=0; i<m; i++){
        for(int j=0; j<m; j++){
            new_x = i+x; new_y = j+y;
            if(0<=new_x && new_x<n && 0<=new_y && new_y<n){
                moved_key[new_x][new_y] = rotated_key[i][j];
            }
        }
    }
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
    
    m = key.size(); n = lock.size();
    // copy
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            glo_lock[i][j] = lock[i][j];
        }
    }
    for(int i=0; i<m; i++){
        for(int j=0; j<m; j++){
            glo_key[i][j] = key[i][j];
        }
    }
    
    // calculate each case
    for(int i= -(m-1); i<=(n-1); i++){
        for(int j= -(m-1); j<=(n-1); j++){
            for(int r=0; r<4; r++){ // rotate 0~3 times
                move_key(r, i, j);
                if(unlock()) answer = true; // if can unlock
            }
        }
    }
    return answer;
}
