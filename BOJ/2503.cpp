#include <iostream>
#include <vector>
#define INF 1e9
using  namespace std;

vector<string> leftv;

struct guess{
    int num;
    int strike;
    int ball;
};

string toStr(int num){
    string r="";
    r+=(num/100)+'0';
    
    num%=100;
    r+=(num/10)+'0';
    
    num%=10;
    r+=(num)+'0';
    return r;
}

void init(){
    for(int i=1; i<=9; i++)
        for(int j=i+1; j<=9; j++)
            for(int k=j+1; k<=9; k++) {
                leftv.push_back(toStr(i*100+j*10+k));
                leftv.push_back(toStr(i*100+k*10+j));
                leftv.push_back(toStr(j*100+i*10+k));
                leftv.push_back(toStr(j*100+k*10+i));
                leftv.push_back(toStr(k*100+i*10+j));
                leftv.push_back(toStr(k*100+j*10+i));
            }
    
}

int getStrike(string a, string b){
    int ret=0;
    if(a[0]==b[0]) ret++;
    if(a[1]==b[1]) ret++;
    if(a[2]==b[2]) ret++;
    return ret;
}
int getBall(string a, string b){
    int ret=0;
    if(a[0]==b[1] || a[0]==b[2]) ret++;
    if(a[1]==b[0] || a[1]==b[2]) ret++;
    if(a[2]==b[1] || a[2]==b[0]) ret++;
    return ret;
}

void remove_left(int num, int strike, int ball){
    int s, b;
    string t = toStr(num);
    for(int i=leftv.size()-1; i>=0; i--){
        s = getStrike(leftv[i], t);
        b = getBall(leftv[i], t);
        if(s!=strike || b!=ball) leftv.erase(leftv.begin()+i);
    }
}

int solve(vector<guess> &v){
    for(int i=0; i<v.size(); i++){
        remove_left(v[i].num, v[i].strike, v[i].ball);
    }
    return leftv.size();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    int ans;
    vector<guess> v;
    
    int n;
    guess g;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>g.num>>g.strike>>g.ball;
        v.push_back(g);
    }
    init();
    ans = solve(v);
    
    cout<<ans;
    
    return 0;
}

