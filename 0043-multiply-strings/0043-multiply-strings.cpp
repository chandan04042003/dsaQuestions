class Solution {
private:
    string addn(string num1, string num2) {
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        string addMain;
        int car = 0;

        while (i >= 0 || j >= 0 || car) {
            int a = i >= 0 ? num1[i--] - '0' : 0;
            int b = j >= 0 ? num2[j--] - '0' : 0;
            int sum = a + b + car;
            if (sum > 9) {
                car = 1;
                sum = sum % 10;
            } else {
                car = 0;
            }
            addMain.push_back(sum + '0');  // Fix: convert int to char
        }

        reverse(addMain.begin(), addMain.end());
        return addMain;
    }

    string muln(string& num1, string& num2) {
        int n = num1.size();
        int m = num2.size();
        string mainAns = "0";

        for (int j = m - 1; j >= 0; j--) {
            string ans;
            for (int l = 0; l < m - 1 - j; l++) {
                ans.push_back('0');  // Padding zeros based on position
            }

            string carry = "0";
            int a = num2[j] - '0';

            for (int i = n - 1; i >= 0; i--) {
                int b = num1[i] - '0';
                string mul = addn(to_string(a * b), carry);

                if (mul.size() > 1) {
                    char lastDigit = mul.back();  // Fix: get last digit
                    mul.pop_back();               // Remove it from mul
                    ans.push_back(lastDigit);     // Append to answer
                    carry = mul;                  // Rest is the carry
                } else {
                    ans.push_back(mul[0]);        // Only one digit
                    carry = "0";
                }
            }

            if (carry != "0") {
                for (int k = carry.size() - 1; k >= 0; k--) {
                    ans.push_back(carry[k]);      // Add remaining carry
                }
            }

            reverse(ans.begin(), ans.end());
            mainAns = addn(mainAns, ans);          // Add partial product
        }

        return mainAns;
    }

public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";  // Edge case
        int n = num1.size();
        int m = num2.size();
        if (n < m) return muln(num2, num1);          // Make num1 longer
        return muln(num1, num2);
    }
};
