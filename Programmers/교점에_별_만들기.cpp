#include <string>
#include <vector>
#include <iostream>
#define INF 1e18

using namespace std;
vector<pair<long long, long long>> stars;
long long minx = INF, miny=INF, maxx=-INF, maxy=-INF;

void findStar(double A, double B, double E, double C, double D, double F){
    double fx, fy;
    long long ix, iy;
    
    if(A*D-B*C==0) return;
    fx = (B*F-E*D)/(A*D-B*C); fy = (E*C-A*F)/(A*D-B*C);
    if(fx-(long long)fx!=0) return;
    if(fy-(long long)fy!=0) return;
    
    ix = (long long)fx;
    iy = (long long)fy;
    stars.push_back({ix, iy});
    minx = min(minx, ix); miny = min(miny, iy);
    maxx = max(maxx, ix); maxy = max(maxy, iy); 
}

vector<string> solution(vector<vector<int>> line) {
    vector<string> answer;
    
    for(int i=0; i<line.size(); i++){
        for(int j=i+1; j<line.size(); j++){
            findStar(line[i][0], line[i][1], line[i][2], line[j][0], line[j][1], line[j][2]);
        }
    }
    
    string s;
    long long n = maxx-minx+1, m = maxy-miny+1;
    for(long long i=0; i<m; i++){
        s="";
        for(long long j=0; j<n; j++){
            s+=".";
        }
        answer.push_back(s);
    }
    
    long long sx, sy;
    for(int i=0; i<stars.size(); i++){
        sx = stars[i].first; sy = stars[i].second;
        answer[maxy-sy][sx-minx] = '*'; // draw star
    }
   
    return answer;
}
