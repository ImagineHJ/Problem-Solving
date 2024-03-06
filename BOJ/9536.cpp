#include <iostream>
#include <unordered_map>
using  namespace std;

unordered_map<string, bool> umap;
string rec;

void print_ans(){
    int i, s=0;
    string sound;
    
    for(i=1; i<rec.size()-1; i++){
        if(rec[i]==' '){
            sound = rec.substr(s, i-s);
            if(umap[sound]==0){
                cout<<sound<<' ';
            }
            s=i+1;
        }
    }
    
  // last word
    sound = rec.substr(s, i);
    if(umap[sound]==0){
        cout<<sound<<'\n';
    }
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    int t;
    string animal, goes, sound;
    
    cin>>t;
    
    for(int test=0; test<t; test++){
        umap.clear();
        
        cin.ignore();
        getline(cin, rec); // read line
        cin.ignore();
        
        while(1){
            cin>>animal>>goes>>sound;
            umap[sound]=1;
            
            if(goes=="does"){
                cin>>animal>>goes;
                print_ans();
                break;
            }
        }
    }
    return 0;
}

