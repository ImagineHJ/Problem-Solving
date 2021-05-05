class Solution {
public:
    string longestPalindrome(string s) {
        int len, mid, max_len=1, start_idx=0, r, l;
        
        for(mid =0; mid<s.length()-1; mid++){
            
            // 이 중간지점에서 나올 수 있는 최대 길이
            if(mid<s.length()-mid-1) len=mid;
            else len=s.length()-mid-1;
            len= 1+(len)*2;
            if(len<max_len) break; // max보다 작으면 연산 종료(앞으로 더 작아질 것이기 때문)
            
            // 길이가 짝수인 substr
            l=mid; r=mid;
            while(l>=0 && r<=s.length()-1 && s[l]==s[r+1]){
                l--; r++;
            }
            
            len = r-l; // max_len 업데이트
            if(len>max_len) {
                max_len=len;
                start_idx=l+1;
            }
            
            // 길이가 홀수인 substr
            l=mid; r=mid;
            while(l>=1 && r<s.length()-1 && s[l-1]==s[r+1]){
                l--;r++;
            }
            
            len=r-l+1; // max_len 업데이트
            if(len>max_len) {
                max_len=len;
                start_idx=l;
            }
            
        }

        return s.substr(start_idx, max_len);
        
    }
};
