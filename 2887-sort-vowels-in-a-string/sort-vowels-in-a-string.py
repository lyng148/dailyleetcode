class Solution:
    def sortVowels(self, s: str) -> str:
        vowels = 'aeiouAEIOU'
        vows = []
        for c in s:
            if c in vowels:
                vows.append(c)

        if not vows:
            return s

        vows.sort()
        res = ''
        for c in s:
            if c in vowels:
                res += vows.pop(0)

            else:
                res += c

        return res