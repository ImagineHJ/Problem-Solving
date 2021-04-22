class Solution {
public:
    int maxArea(vector<int>& height) {
        int max=0, area, i=0, j=height.size()-1, h;
        
        // only compute areas which might be larger than current max, for lower complexity
        
        while(i<j){
            h=min(height[i], height[j]);
            area=(j-i)*h;
            if(max<area) max=area;
            
            // find next vert lines that is higher
            if(height[i]==h){
                while(height[i]<=h && i<j) i++;
            }
            else if(height[j]==h){
                while(height[j]<=h && i<j) j--;
            }
        }
        return max;
    }
};
