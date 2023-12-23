
5)

class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        max_word_len = len(words) * len(words[0])
        result = []
        
        for i in range(len(s) - max_word_len + 1):
            substring = s[i:i + max_word_len]
            sub = []
            
            for j in range(0, len(substring), len(words[0])):
                sub.append(substring[j:j + len(words[0])])
                
            if sorted(sub) == sorted(words):
                result.append(i)
        
        return result





6)

class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        m = len(s)
        n = len(t)
        dp = [[0] * (n+1) for _ in range(m+1)]
        
        for i in range(m+1):
            dp[i][0] = 1
        
        for i in range(1, m+1):
            for j in range(1, n+1):
                dp[i][j] += dp[i-1][j]
                if s[i-1] == t[j-1]:
                    dp[i][j] += dp[i-1][j-1] 
        return dp[-1][-1]




7)

class Solution:
   def minWindow(self, s: str, t: str) -> str:
    if len(t) > len(s):
        return ""
    
    minLength = len(s) + 1
    count = Counter(t)
    distincts = len(count)
    
    i, j = 0, 0
    minI, minJ = -1, -1
    
    while j < len(s):
        if s[j] in count:
            count[s[j]] -= 1
            if count[s[j]] == 0:
                distincts -= 1
        
        while distincts == 0:
            if j - i + 1 < minLength:
                minLength = j - i + 1
                minI = i
                minJ = j
            if s[i] in count:
                count[s[i]] += 1
                if count[s[i]] == 1:
                    distincts += 1
            i += 1
        j += 1
    
    substring = s[minI:minJ + 1]
    
    return substring




8)

class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        return(re.match('^'+p+'$',s))

9)

class Solution:
    def trap(self, height: List[int]) -> int:
        max_left = 0
        max_right = 0
        total_water = 0

        left, right = 0, len(height) - 1
        while left < right:
            if height[left] > height[right]:
                max_right = max(max_right, height[right])
                total_water += (max_right - height[right])
                right -= 1
            elif height[left] <= height[right]:
                max_left = max(max_left, height[left])
                total_water += (max_left - height[left])
                left += 1

        return total_water


10)

class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        n = len(word1)
        m = len(word2)

        memo = [([0] * (n + 1)) for _ in range(m + 1)]

        for i in range(1, m + 1):
            memo[i][0] = i
        for j in range(1, n + 1):
            memo[0][j] = j

        for i in range(1, m + 1):
            for j in range(1, n + 1):
                memo[i][j] = min(
                    memo[i - 1][j] + 1,
                    memo[i][j - 1] + 1,
                    memo[i - 1][j - 1] + (0 if word1[j - 1] == word2[i - 1] else 1),
                )

        return memo[m][n]