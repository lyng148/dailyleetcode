class Solution {
    public int longestStrChain(String[] words) {
        HashMap<Integer, List<String>> groupByLen = new HashMap<>();
        HashMap<String, Integer> dp = new HashMap<>();
        int ans = 0;

        for (String word: words) {
            Integer key = word.length();
            groupByLen.putIfAbsent(key, new ArrayList<>());
            groupByLen.get(key).add(word);
        }

        for (int len = 1; len <= 16; len++) {
            if (!groupByLen.containsKey(len)) {
                continue;
            }

            for (String word: groupByLen.get(len)) {
                dp.put(word, 1);
                for (int i = 0; i < len; i++) {
                    StringBuilder strBuilder = new StringBuilder(word);
                    strBuilder.deleteCharAt(i);
                    String subStr = strBuilder.toString();

                    if (groupByLen.containsKey(len - 1) && groupByLen.get(len-1).contains(subStr)) {
                        dp.put(word, Math.max(dp.get(word), dp.get(subStr) + 1));
                    }
                }
                ans = Math.max(ans, dp.get(word));
            }
        }
        return ans;
    }
}