#include <string.h>
class Solution {
public:
    int reverse(int x) {
        bool minus=false;
        
        if(x<0){
            minus=true;
            x=abs(x);
        }
        
        string str=to_string(x);
        int n=str.length();
        
        
        for(int i=0; i<n/2; i++){
            swap(str[i], str[n-i-1]);
        }

        if(n>=10 && (strcmp("2147483648",str.c_str())<0||strcmp("2147483648",str.c_str())==0 && minus==false)){
            return 0;   
        }
        int ans=stoi(str);
        if(minus)
            ans=-ans;
        
        return ans;
        
    }
};
