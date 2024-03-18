#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    string str;
    int k, up;
    cin>>str>>k;
    
    up = 1;
    for(int i=0; i<str.size(); i++){
        if(str[i]=='5') k--;
    }
    
    queue<int> non_five_smaller;
    int cur, max_digit;
    for(int i=str.size()-1; i>=0; i--){
        if(k<=0 && up==0) break;
        
        if(k<=0 && up==1){
            if(str[i]=='9'){
                str[i]='0';
                non_five_smaller.push(i);
            }
            else if(str[i]!='5'){
                str[i]+=1;
                max_digit=i;
                if(str[i]=='5') k--;
                up = 0;
            }
            else{
                if(k<0){
                    str[i]='6';
                    max_digit=i;
                    k++;
                    up=0;
                }
                else if(!non_five_smaller.empty()){
                    cur = non_five_smaller.front();
                    non_five_smaller.pop();
                    str[cur]='5';
                    str[i]='6';
                    max_digit=i;
                    up=0;
                }
            }
        }
        else if(k>0){
            if(str[i]=='5') continue;
            if(str[i]<'5') {
                up=0;
                max_digit=i;
            }
            else up=1;
            str[i]='5';
            k--;
        }
        //cout<<str<<endl;
    }
    if(k<=0 && up==1){
        str = "1" + str;
        max_digit=0;
    }
    else if(k>0){
        while(k>0){
            str = "5" + str;
            k--;
            max_digit = 0;
        }
    }
    for(int i=max_digit+1; i<=str.size(); i++){
        if(str[i]=='5'){
            if(k==0) continue;
            else k++;
        }
        str[i] = '0';
    }
    
    cout<<str;
    
    
}
