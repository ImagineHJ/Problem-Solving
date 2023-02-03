#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = s.length(), i, len, rep_num;
    string now, prev;
    
    for(int c=1; c<=s.length()/2; c++){
        prev = s.substr(0, c);
        len = c; rep_num = 1; i=c;
        while(i+c<=s.length()){
            now = s.substr(i, c);
            if(now==prev){ // repeated string
                if(rep_num==1 || rep_num==9 || rep_num==99){ // add num digit char
                    len++;
                    rep_num ++;
                }
                else rep_num++;
            }
            else{
                len += c;
                rep_num = 1;
            }
            // cout<<i<<" "<<now<<" "<<len<<endl;
            prev = now;
            i += c;
        }
        if(i<s.length()) len += s.length()-i;
        // cout<<"total len"<<len<<endl;
        answer = min(answer, len);
    }
    
    return answer;
}
