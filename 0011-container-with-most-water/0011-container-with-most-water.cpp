class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0;
        int j=height.size()-1;
        int val=min(height[i],height[j]);
        int area= val*(j-i);
        while(i<j){
            if(height[i]<=height[j]) i++;
            else j--;
            val=min(height[i],height[j]);
            area=max(area,val*(j-i));
        }
        return area;
    }
};