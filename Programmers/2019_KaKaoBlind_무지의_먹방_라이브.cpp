#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#define INF 1e9

struct food{
    int i;
    int amount;
};

struct comp{
    bool operator()(food a, food b){
        return a.amount>b.amount;
    }
};

using namespace std;

int solution(vector<int> food_times, long long k) {
    int answer = INF;
    priority_queue<food, vector<food>, comp> pq; // pop food with small amount first
    food f;
    long long time = 0, eat = 0;
    int min_amount, min_num;

    for(int i=0; i<food_times.size(); i++){
        f.i = i;
        f.amount = food_times[i];
        pq.push(f); // push in a priority queue
    }

    while(true){
        min_amount = pq.top().amount-eat; 
    
        if(time + pq.size() * min_amount > k){ // no more food to finish
            min_amount = (k-time)/pq.size();
            if(min_amount <1){ // cannot eat all the leftovers, have to stop in the middle
                break;
            }
            time += (pq.size() * min_amount);
            eat += min_amount;
            break;
        }
        
        time += (pq.size() * min_amount); // eat min_amount from all left food
        food_times[pq.top().i] = 0; // this food is finished
        pq.pop();
        while(!pq.empty() && min_amount == pq.top().amount-eat){
            food_times[pq.top().i] = 0; // this food if finished
            pq.pop();
            
        }
        eat += min_amount;
        
        if(pq.empty()){ // no more food left
            answer = -1;
            break;
        }
        if(time>=k) break;
    }
    
    if(!pq.empty()){ // time is finished, there is some food left
        int id = 0;
        while(time!=(k+1)){
            if(food_times[id]!=0) time++; // find the front most food that is now finished
            id++;
        }
        answer = id;
    }
    
    return answer;
}
