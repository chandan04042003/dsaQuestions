class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(),deck.end());
        deque<int> dq;
        vector<int> ans(deck.size(),0);
        for(int i=0;i<deck.size();i++) dq.push_back(i);
        int adj=0;
        int i=0;
        while(!dq.empty()){
            if(adj==0){
                ans[dq.back()]=deck[i++];
                dq.pop_back();
                adj=1;
            }
            else{
                dq.push_front(dq.back());
                dq.pop_back();
                adj=0;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};