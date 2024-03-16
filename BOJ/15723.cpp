#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<string, string> umap;

char check(string A, string B){
    while(umap[A]!=""){
        if(umap[A]==B) return 'T';
        A = umap[A];
    }
    return 'F';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    int n, m;
    string A, is, B;
    
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>A>>is>>B;
        umap[A] = B;
    }

    cin>>m;
    for(int i=0; i<m; i++){
        cin>>A>>is>>B;
        cout<<check(A, B)<<'\n';
    }
    
}
