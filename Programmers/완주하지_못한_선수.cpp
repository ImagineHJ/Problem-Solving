#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<string, int> um;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    for(string s:completion) um[s]++;
    
    for(string s:participant) {
        if(um[s]==0) {answer = s; break;}
        else um[s]--;
    }
    
    return answer;
}
