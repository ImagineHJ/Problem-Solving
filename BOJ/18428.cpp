//
//  main.cpp
//
//  Created by JinnyLim on 2023/02/08.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>
#define INF 1e18
using namespace std;

int map[6][6];
vector<pair<int, int>> teacher;
vector<pair<int, int>> student;
vector<pair<int, int>> obstacle;


bool hide(){
    bool hide = true;
    int s_x, s_y, t_x, t_y, o_x, o_y;
    for(int t=0; t<teacher.size(); t++){
        for(int s=0; s<student.size(); s++){
            s_x = student[s].first; s_y = student[s].second;
            t_x = teacher[t].first; t_y = teacher[t].second;
            if(s_x == t_x){
                hide = false; // teacher can see the student
                for(int o=0; o<3; o++){
                    o_x = obstacle[o].first; o_y = obstacle[o].second;
                    if(o_x==t_x && ((t_y<o_y && o_y<s_y)||(s_y<o_y && o_y<t_y))){ // hide in obstacle
                        hide = true;
                    }
                }
            }
            else if (s_y==t_y){ // teacher can see the student
                hide = false;
                for(int o=0; o<3; o++){
                    o_x = obstacle[o].first; o_y = obstacle[o].second;
                    if(o_y==t_y && ((t_x<o_x && o_x<s_x)||(s_x<o_x && o_x<t_x))){ // hide in obstacle
                        hide = true;
                    }
                }
            }
            if(!hide) return hide; // cannot hide in the obstacle
        }
    }
    return hide;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    int n;
    char c;
    cin>>n;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>c;
            if(c=='S') student.push_back({i, j});
            if(c=='T') teacher.push_back({i, j});
            if(c=='X') map[i][j] = 1;
        }
    }
    for(int ax=0; ax<n; ax++){
        for(int ay=0; ay<n; ay++){
            if(map[ax][ay]!=1) continue; // cannot put obstacle when there is teacher or student
            for(int bx=0; bx<n; bx++){
                for(int by=0; by<n; by++){
                    if(map[bx][by]!=1 || ((ax==bx)&&(ay==by))) continue; // already obstacle here
                    for(int cx=0; cx<n; cx++){
                        for(int cy=0; cy<n; cy++){
                            if(map[cx][cy]!=1 || ((cx==ax)&&(cy==ay)) || ((cx==bx)&&(cy==by))) continue;
                            obstacle.push_back({ax, ay}); // choose 3 diff place to put obstacle
                            obstacle.push_back({bx, by});
                            obstacle.push_back({cx, cy});
                            if(hide()){
                                cout<<"YES";
                                return 0;
                            }
                            obstacle.clear();
                        }
                    }
                }
            }
        }
    }
    cout<<"NO";
    return 0;
}
