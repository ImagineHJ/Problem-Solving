#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct worker{
    int a; int b; int i;
};

vector<worker> workers;
vector<worker> ranking;

bool comp1(worker x, worker y){
    if(x.a==y.a) return x.b>y.b;
    return x.a>y.a;
 }

bool comp2(worker x, worker y){
    if((x.a+x.b)==(y.a+y.b)) return x.i<y.i;
    return (x.a+x.b)>(y.a+y.b);
 }

int solution(vector<vector<int>> scores) {
    int answer = 0;
    
    worker w;
    for(int i=0; i<scores.size(); i++){
        w.a = scores[i][0];
        w.b = scores[i][1];
        w.i = i;
        workers.push_back(w);
    }
    sort(workers.begin(), workers.end(), comp1);
    
    int maxB = 0, prev = workers[0].a, nextmaxB =  workers[0].b;
    ranking.push_back(workers[0]);
    
    for(int i=1; i<workers.size(); i++){
        if(prev!=workers[i].a) maxB = nextmaxB;

        if(maxB>workers[i].b) continue;
        nextmaxB = max(nextmaxB, workers[i].b);
        ranking.push_back(workers[i]);
        prev = workers[i].a;
    }
    sort(ranking.begin(), ranking.end(), comp2);
    
    answer = -1;
    for(int i=0; i<ranking.size(); i++){
        if(ranking[i].i==0) {answer = i+1; break;}
    }
    
    return answer;
}
