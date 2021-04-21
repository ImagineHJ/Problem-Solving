#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    vector<int> vec;
    
    int n; cin>>n;
    
    while(n--){
        int num; cin>>num;
        vec.push_back(num);
        push_heap(vec.begin(), vec.end());
        for(int i=0; i<vec.size(); i++) cout<<vec[i]<<' ';
        cout<<'\n'<<vec[vec.size()/2]<<'\n';
    }
    
    return 0;
}
