class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n= gas.size();
        int temp=0;
        int fuel=0;
        int ind=0;
        for(int i=0;i<n;i++){
            int diff = (gas[i]-cost[i]);
            temp += diff;
            fuel+= diff;
            if(fuel<0){
                fuel=0;
                ind=i+1;
            }
        }
        if(temp<0) return -1;
        return ind;
    }
};