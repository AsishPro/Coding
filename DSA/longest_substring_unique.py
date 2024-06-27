class Solution(object):
    def recur(self, start, end, s, ans):
        if end == len(s):
            return ans

        if s[end] not in s[start:end]:
            ans = max(ans, end - start + 1)
            return self.recur(start, end + 1, s, ans)

        return self.recur(start + 1, end, s, ans)

    def lengthOfLongestSubstring(self, s):
        if not s:
            return 0
        start = 0
        end = 0
        ans = 0
        result = self.recur(start, end, s, ans)
        return result

a = Solution()
s = 'aaabcdc'
result = a.lengthOfLongestSubstring(s)
print(result)

