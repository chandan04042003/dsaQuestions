class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        vector<vector<int>> vec;
        int i=0;
        while(i<meetings.size()){
            int start=meetings[i][0];
            int end = meetings[i][1];
            while(i<meetings.size()-1 && end>=meetings[i+1][0]){
                i++;
                end = max(end, meetings[i][1]);
            } 
            vec.push_back({start, end});
            i++;
        }
        int busy = 0;
        for (auto& x : vec) {
            busy += x[1] - x[0] + 1;
        }

        return days - busy;
    }
};