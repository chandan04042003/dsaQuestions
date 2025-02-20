class Solution {
    public String predictPartyVictory(String senate) {
         int i = 0;
        StringBuffer str = new StringBuffer(senate);
        int j = 0;

        while (str.length() > 1) {
            if (str.charAt(i) == 'R') {
               
                j = (i + 1) % str.length();
                while (str.charAt(j) != 'D' && j != i) {
                    j = (j + 1) % str.length();
                }
                if (str.charAt(j) == 'D') {
                    str.deleteCharAt(j);
                    if (j < i) i--; 
                }
            } else {
              
                j = (i + 1) % str.length();
                while (str.charAt(j) != 'R' && j != i) {
                    j = (j + 1) % str.length();
                }
                if (str.charAt(j) == 'R') {
                    str.deleteCharAt(j);
                    if (j < i) i--;
                }
            }

            i = (i + 1) % str.length();

          
            if (str.indexOf("R") == -1) return "Dire";
            if (str.indexOf("D") == -1) return "Radiant";
        }

        return str.charAt(0) == 'R' ? "Radiant" : "Dire";
    }
}