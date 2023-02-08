#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare(string a, string b){
    if(a.length()==b.length()) return a<b;
    return a.length()<b.length();
}

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    vector<string> words_reverse;
    string query, sub_query, word, wild_card_a, wild_card_z;
    int wild_start, wild_cnt=0, idx, bound, cnt;
    
    for(int i=0; i<words.size(); i++){
        word = words[i];
        reverse(word.begin(), word.end());
        words_reverse.push_back(word); // reverse all the words
    }
    
    sort(words.begin(), words.end(), compare);
    sort(words_reverse.begin(), words_reverse.end(), compare);
    for(int i=0; i<queries.size(); i++){
        query = queries[i];
        wild_cnt = 0; wild_card_a = ""; wild_card_z = "";
        for(int j=0; j<query.length(); j++){
            if(query[j]=='?') {
                wild_cnt++; wild_card_a += "a"; wild_card_z += "z";
            }
        }
        cnt = 0;
        if(query[0] == '?'){ // query starts with "?"
            reverse(query.begin(), query.end());
            sub_query = query.substr(0, query.size()-wild_cnt);
            idx = lower_bound(words_reverse.begin(), words_reverse.end(), sub_query+wild_card_a, compare)-words_reverse.begin();
            bound = upper_bound(words_reverse.begin(), words_reverse.end(), sub_query+wild_card_z, compare)-words_reverse.begin();
            cnt  = bound - idx;
        }
        else{ // query starts with an alphabet
            sub_query = query.substr(0, query.size()-wild_cnt);
            idx = lower_bound(words.begin(), words.end(), sub_query+wild_card_a, compare)-words.begin();
            bound = upper_bound(words.begin(), words.end(), sub_query+wild_card_z, compare)-words.begin();
            cnt  = bound - idx;
        }
        answer.push_back(cnt);
    }
    return answer;
}
