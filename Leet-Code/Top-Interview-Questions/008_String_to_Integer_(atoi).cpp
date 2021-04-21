class Solution {
public:
    int myAtoi(string s) {
        bool neg=false;
        int i=0;
        long long num=0;
        
        //Step 1: ignore whitespace
        while(s[i]==' ')
            i++;
        
        //Step 2: get '-' or '+''
        if(s[i]=='-'){
            i++;
            neg=true;
        }
        else if(s[i]=='+')
            i++;
        
        //Step 3: String to Int
        while('0'<=s[i] && s[i]<='9'){
            num*=10;
            num+=s[i]-'0';
            
            //Check overflow
            if(neg && num > 2147483648) {num=2147483648; break;}
            if(!neg && num > 2147483647) {num=2147483647; break;}
            
            i++;
            if(i==s.length()) break;
        }
        
        if(neg) num=-num;
        
        return (int)num;
        
    }
};
