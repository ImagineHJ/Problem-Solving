class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int over=0;
        
        for(int i=digits.size()-1; i>=0; i--){
            if(digits[i]<9){
                digits[i]++; 
                over = 0;
                break;
            }
            else{
                digits[i] = 0;
                over = 1;
            }
        }
        if(over==1) digits.insert(digits.begin(),1);
        
        return digits;
    }
};
