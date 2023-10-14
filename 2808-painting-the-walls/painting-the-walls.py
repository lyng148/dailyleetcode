class Solution:
    def paintWalls(self, cost: List[int], time: List[int]) -> int:
        @cache
        def dp(i, r):
            if r <= 0:
                return 0
            if i >= len(cost):
                return inf

            ret = min(cost[i] + dp(i + 1, r - time[i] - 1), dp(i + 1, r))
            return ret

        return dp(0, len(cost))