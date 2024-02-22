class Solution {
    public int findJudge(int n, int[][] truth) {
       
        int truthCount[] = new int[n + 1];
        if (truth.length == n) return -1;
        else {
            for (int[] arr : truth) {
                truthCount[arr[0] - 1]--;
                truthCount[arr[1] - 1]++;
          
            }
        }
  
        for (int i = 0; i < n; i++) {
            if (truthCount[i] == n - 1) {
                return i + 1;

            }
        }
        return -1;
    }
}