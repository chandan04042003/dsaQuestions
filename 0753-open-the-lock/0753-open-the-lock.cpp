class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        queue<pair<string,int>> q;
        unordered_map<string,int> mp;

        for(int i=0; i<deadends.size(); i++){
            mp[deadends[i]] = 1;
        }

        if(mp.find("0000") != mp.end()) return -1; // start is a deadend

        q.push({"0000", 0});
        mp["0000"] = 1;

        while(!q.empty()){
            int N = q.size();
            while(N--){
                string seq = q.front().first;
                int cnt = q.front().second;
                q.pop();

                if(seq == target) return cnt;

                for(int i=0; i<4; i++){
                    string temp = seq;

                    // +1 rotation
                    temp[i] = ((seq[i]-'0' + 1) % 10) + '0';
                    if(mp.find(temp) == mp.end()){
                        q.push({temp, cnt+1});
                        mp[temp] = 1;
                    }

                    temp = seq;

                    // -1 rotation
                    temp[i] = ((seq[i]-'0' - 1 + 10) % 10) + '0';
                    if(mp.find(temp) == mp.end()){
                        q.push({temp, cnt+1});
                        mp[temp] = 1;
                    }
                }
            }
        }
        return -1;
    }
};
