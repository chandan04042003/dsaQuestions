class RecentCounter {
public:
    vector<int> q;
    int f=-1;
    RecentCounter() {
    }
    int ping(int t) {
        if(q.empty()){
            f++;
            q.push_back(t);
            return 1;
        }
        while(f<q.size() && q[f]<t-3000) f++;
        q.push_back(t);
        return q.size()-f;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */