class Solution(object):
    def recur(self, i, l, temp, res, memo):
        if len(temp) == 3:
            if tuple(temp) not in memo:
                memo.add(tuple(temp))
                res.append(temp[::])
            return

        if i == len(l):
            return

        self.recur(i + 1, l, temp, res, memo)

        if not temp or temp[-1] < l[i]:
            self.recur(i + 1, l, temp + [l[i]], res, memo)

    def numTeams(self, l):
        res = []
        temp = []
        memo = set()

        self.recur(0, l, temp, res, memo)
        temp = []
        self.recur(0, l[::-1], temp, res, memo)
        print(res)
        return len(res)

# Example usage:
solution = Solution()
nums = [2, 5, 3, 4, 1,6]
result = solution.numTeams(nums)
print(result)
