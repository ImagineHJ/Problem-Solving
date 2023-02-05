#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
struct Fail{
    int stage;
    float failure;
};

bool comp(Fail a, Fail b){
    if(a.failure == b.failure) return a.stage<b.stage;
    return a.failure>b.failure;
}

using namespace std;

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<Fail> fail_list;
    int stage = 1, first_idx, reach_num, stay_num;
    Fail f;
    
    sort(stages.begin(), stages.end());
    for(int i=0; i<stages.size(); i++){
        if(stages[i-1]!=stages[i] || i==0) first_idx = i;
        if(stages[i+1]!=stages[i] || i==stages.size()-1){
            reach_num = stages.size()-first_idx;
            stay_num = i-first_idx+1;
            while(stage<stages[first_idx]){ // stages without staying player
                f.stage = stage;
                f.failure = 0.0;
                fail_list.push_back(f);
                stage++;
            }
            f.stage = stages[first_idx]; // save failure rate, stage num
            f.failure = (float)stay_num/reach_num;
            fail_list.push_back(f);
            stage++;
        }
        if(stage>N) break;
    }
    while(stage<=N){
                f.stage = stage;
                f.failure = 0;
                fail_list.push_back(f);
                stage++;
            }

    sort(fail_list.begin(), fail_list.end(), comp); // sort by failure rate
    for(int i=0; i<fail_list.size(); i++){
        if(fail_list[i].stage <=N ) answer.push_back(fail_list[i].stage);
    }
    
    return answer;
}
