class Solution {
public:
    
    int value(char c){
        if(c=='I') return 1;
        if(c=='V') return 5;
        if(c=='X') return 10;
        if(c=='L') return 50;
        if(c=='C') return 100;
        if(c=='D') return 500;
        if(c=='M') return 1000;
        return 0;
    }
    
    bool smallfirst(char prev, char now){
        if(prev=='I' && (now=='V'||now=='X') ) return true;
        else if(prev=='X' && (now=='L'||now=='C') ) return true;
        else if(prev=='C' && (now=='D'||now=='M') ) return true;
        
        return false;
    }
    
    int romanToInt(string s) {
        char prev=s[0];
        int ans=value(s[0]);
        
        for(int i=1; i<s.length(); i++){
            if(smallfirst(prev, s[i])){
                ans-=(value(prev)*2);
            }
            ans+=value(s[i]);
            prev=s[i];
        }
        
        return ans;
        
    }
};
