class Solution {
public:
    int compress(vector<char>& chars) {
        if (chars.size() == 1) return 1;

        int i = 0;     
        int j = 1;     
        int k = 0;     

        while (j <= chars.size()) {
            if (j == chars.size() || chars[i] != chars[j]) {
                chars[k++] = chars[i];
                int count = j - i;
                if (count > 1) {
                    string cntStr = to_string(count);
                    for (char c : cntStr) {
                        chars[k++] = c;
                    }
                }
                i = j;  
            }
            j++;
        }
        return k;
    }
};
