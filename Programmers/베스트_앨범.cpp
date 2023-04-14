#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
unordered_map<string, int> um;
unordered_map<string, pair<int, int>> top2;

struct gen{
    string name;
    int total;
};

vector<gen> ranks; 

bool comp(gen a, gen b){
    return a.total>b.total;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    gen g;
    
    for(int i=0; i<genres.size(); i++){
        um[genres[i]] += plays[i];
        top2[genres[i]].first = -1;
        top2[genres[i]].second = -1;
    }
    for(int i=0; i<genres.size(); i++){
        if(top2[genres[i]].first==-1 || plays[top2[genres[i]].first]<plays[i]){
            top2[genres[i]].second = top2[genres[i]].first;
            top2[genres[i]].first = i;
        }
        else if(top2[genres[i]].second==-1 || plays[top2[genres[i]].second]<plays[i]){
            top2[genres[i]].second = i;
        }
    }
    
    for(auto a:um){
        g.name = a.first; g.total = a.second;
        ranks.push_back(g);
    }
    sort(ranks.begin(), ranks.end(), comp);
    
    for(int i=0; i<ranks.size(); i++){
        if(top2[ranks[i].name].first!=-1) answer.push_back(top2[ranks[i].name].first);
        if(top2[ranks[i].name].second!=-1) answer.push_back(top2[ranks[i].name].second);
    }
    
    return answer;
}
