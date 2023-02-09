#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>
#define INF 1e18
using namespace std;

long long n2, n3, n5, n7;
int id2, id3, id5, id7;
vector<long long> humble_nums;

string suffix(int n){
    n = n%100;
    if(n==11 || n==12 || n==13) return "th";
    n = n%10;
    if(n==1) return "st";
    if(n==2) return "nd";
    if(n==3) return "rd";
    return "th";
}

void add_humble_num(){
    long long n = min({n2, n3, n5, n7});
    if(n)
    humble_nums.push_back(n);
    if(n == n2){
        id2++;
        n2 = 2*humble_nums[id2];
    }
    if(n == n3){
        id3++;
        n3 = 3*humble_nums[id3];
    }
    if(n == n5){
        id5++;
        n5 = 5*humble_nums[id5];
    }
    if(n == n7){
        id7++;
        n7 = 7*humble_nums[id7];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    int n;
    humble_nums.push_back(1);
    id2 = id3 = id5 = id7 = 0;
    n2 = 2; n3 = 3; n5 = 5; n7 = 7;
    
    while(true){
        cin>>n;
        if(n==0) break;
        
        while(humble_nums.size()<n) add_humble_num();
        cout<<"The "<<n<<suffix(n)<<" humble number is "<<humble_nums[n-1]<<"."<<'\n';
    }
    
    return 0;
}
