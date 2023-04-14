#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
vector<pair<int, int>> cars;

bool comp(pair<int, int> a, pair<int, int> b){
    return a.first>b.first;
}
int solution(vector<vector<int>> routes) {
    int answer = 1;
    
    for(int i=0; i<routes.size(); i++) cars.push_back({routes[i][0], routes[i][1]});
    sort(cars.begin(), cars.end(), comp);
    
    int cam = cars[0].first;
    for(int i=1; i<cars.size(); i++){
        if(cam>cars[i].second){
            cam = cars[i].first;
            answer++;
        }
    }
    
    return answer;
}
