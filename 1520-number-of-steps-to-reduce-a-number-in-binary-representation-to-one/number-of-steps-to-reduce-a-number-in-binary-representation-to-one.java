class Solution {
    public int numSteps(String s) {
        int ans = 0;
        int mem = 0;
        int length = s.length();
        for (int i = length - 1; i > 0; i--) {
            if (s.charAt(i) == '1' && mem == 0)
            {
                ans += 2;
                mem = 1;
            }
            else if (s.charAt(i) == '1' && mem == 1)
            {
                ans += 1;
                mem = 1;
            }
            else if (s.charAt(i) == '0' && mem == 0)
            {
                ans += 1;
            }
            else
            {
                ans += 2;
                mem = 1;
            }
        }
        if (mem == 1) ans += 1;
        return ans;
    }
}