#include <iostream>
#include <queue>

using namespace std;

int space;
int alph[26];
string poem;

char getCapital(char c){
    if(c>='a' && c<='z'){
        return c+('A'-'a');
    }
    return c;
}

string check(){
    char prev = ' ';
    string title = "";
    
    for(int i=0; i<poem.size(); i++){
        //cout<<"check "<<poem[i]<<endl;
        if(poem[i]==prev) continue;
        if(prev==' '){
            title+=getCapital(poem[i]);
        }
            
        if(poem[i]>='A' && poem[i]<='Z'){
            alph[poem[i]-'A']--;
            if(alph[poem[i]-'A']<0) return "-1";
        }
        else if(poem[i]>='a' && poem[i]<='z'){
            alph[poem[i]-'a']--;
            if(alph[poem[i]-'a']<0) return "-1";
        }
        else if(poem[i]==' ') {
            space--;
            if(space<0) return "-1";
        }
        prev = poem[i];
        
    }
    prev = ' ';
    for(int i=0; i<title.size(); i++){
        if(title[i]==prev) continue;
        if(title[i]>='A' && title[i]<='Z'){
            alph[title[i]-'A']--;
            if(alph[title[i]-'A']<0) return "-1";
        }
        else if(title[i]>='a' && title[i]<='z'){
            alph[title[i]-'a']--;
            if(alph[title[i]-'a']<0) return "-1";
        }
        else if(title[i]==' ') {
            space--;
            if(space<0) return "-1";
        }
        prev = poem[i];
        
    }
    
    return title;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    getline(cin, poem);
    
    cin>>space;
    for(char c ='a'; c<='z'; c+=1){
        cin>>alph[c-'a'];
    }
    cout<<check();

    
}
