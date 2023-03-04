class Solution {
public:
    int countSetBits(int num){
        int cnt = 0;
        while(num!=1){
            if(num%2==1) cnt++;
            num/=2;
        }
        cnt++;
        return cnt;
    }
    int countSetBits(int num, vector<bool> &s){
        int cnt = 0;
        while(num!=1){
            if(num%2==1){
                cnt++;
                s.push_back(true);
            }
            else{
                s.push_back(false);
            }
            num/=2;
        }
        cnt++;
        s.push_back(true);
        return cnt;
    }
    int minimizeXor(int num1, int num2) {
        int num2SetBits = countSetBits(num2), num1SetBits;
        vector<bool> num1BitV;
        num1SetBits = countSetBits(num1, num1BitV);
        
        int diff = num2SetBits-num1SetBits, i=0, cnt = 0, ans = 0;
        bool now;
        for(i= 0; i<num1BitV.size(); i++){
            now = num1BitV[i];
            if(diff>0 && cnt<diff && now==false){
                ans += pow(2, i);
                cnt++;
            }
            else if(diff<0 && cnt>diff && now==true){
                cnt--;
            }
            else if(now==true)ans += pow(2, i);
        }
        if(diff>0 && cnt<diff){
            while(cnt<diff){
                ans += pow(2, i);
                cnt++;
                i++;
            }
        }
        
        return ans;
    }
};
