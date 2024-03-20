#include <iostream>

using namespace std;

int map[3][3];

int check(string s){
    int Xnum=0, Onum=0;
    int x=0;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(s[x]=='X') Xnum++;
            else if(s[x]=='O') Onum++;
            map[i][j]=s[x++];
        }
    }
    if(!(Xnum==Onum || Xnum == Onum+1)) return 0;
    int bingoCount=0, xbingoCount=0, obingoCount=0;
    if(map[0][0]==map[0][1] && map[0][1]==map[0][2]){
        if(map[0][0]=='X') xbingoCount++;
        else if(map[0][0]=='O') obingoCount++;
    }
    if(map[1][0]==map[1][1] && map[1][1]==map[1][2]){
        if(map[1][0]=='X') xbingoCount++;
        else if(map[1][0]=='O') obingoCount++;
    }
    if(map[2][0]==map[2][1] && map[2][1]==map[2][2]){
        if(map[2][0]=='X') xbingoCount++;
        else if(map[2][0]=='O') obingoCount++;
    }
    
    if(map[0][0]==map[1][0] && map[1][0]==map[2][0]){
        if(map[0][0]=='X') xbingoCount++;
        else if(map[0][0]=='O') obingoCount++;
    }
    if(map[0][1]==map[1][1] && map[1][1]==map[2][1]){
        if(map[0][1]=='X') xbingoCount++;
        else if(map[0][1]=='O') obingoCount++;
    }
    if(map[0][2]==map[1][2] && map[1][2]==map[2][2]){
        if(map[0][2]=='X') xbingoCount++;
        else if(map[0][2]=='O') obingoCount++;
    }
    
    if(map[0][0]==map[1][1] && map[1][1]==map[2][2]){
        if(map[0][0]=='X') xbingoCount++;
        else if(map[0][0]=='O') obingoCount++;
    }
    if(map[0][2]==map[1][1] && map[1][1]==map[2][0]){
        if(map[0][2]=='X') xbingoCount++;
        else if(map[0][2]=='O') obingoCount++;
    }
    bingoCount = xbingoCount+obingoCount;
    if(bingoCount>2) return 0;
    if(bingoCount==0 && Xnum+Onum<9) return 0; // did not end
    if(bingoCount==2){
        if(xbingoCount!=2) return 0;
    }
    if(bingoCount==1){
        if(xbingoCount==1 && Xnum==Onum) return 0; // have to end with x
        else if(obingoCount==1 && Xnum!=Onum) return 0; // have to end with o
    }
    return 1;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    string s="";
    while(1){
        cin>>s;
        if(s=="end") break;
        
        if(check(s)) cout<<"valid\n";
        else cout<<"invalid\n";
    }
    
    return 0;
    
}
