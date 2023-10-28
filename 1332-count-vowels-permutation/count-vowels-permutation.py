class Solution:
    def countVowelPermutation(self, n: int) -> int:
        @cache
        def dfs(c = '', k = n):
            if k == 0:
                return 1
            match c:
                case '':
                    return sum(dfs(c, k - 1) for c in 'aeiou')%int(1e9+7)
                case 'a':
                    return dfs('e', k-1)%int(1e9+7)
                case 'e':
                    return (dfs('a', k-1) + dfs('i', k-1))%int(1e9+7)
                case 'i':
                    return sum(dfs(c, k - 1) for c in 'aeou')%int(1e9+7)
                case 'o':
                    return (dfs('i', k-1) + dfs('u', k-1))%int(1e9+7)
                case 'u':
                    return dfs('a', k-1)%int(1e9+7)
        return dfs()