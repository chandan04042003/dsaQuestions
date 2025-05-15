class Solution {
public:
    int compress(vector<char>& chars) {
        if (chars.size() == 1) return 1;

        int i = 0;     
        int j = 1;     
        int k = 0;     

        while (j<=chars.size()) {
            while(j<chars.size() && chars[j]==chars[i]) j++;
            chars[k++]=chars[i];
            if(j-i>1){
                string cnt=to_string(j-i);
                for(char x:cnt){
                    chars[k++]=x;
                }
            }
            i=j;
            j++;
        }
        return k;
    }
};
