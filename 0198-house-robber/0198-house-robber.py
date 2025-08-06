class Solution:
    def helper(self, v: List[int], n: int, dp: List[int]) -> int:
        if n <= 0:
            return 0
        if dp[n] != -1:
            return dp[n]
        take = v[n - 1] + self.helper(v, n - 2, dp)
        skip = self.helper(v, n - 1, dp)
        dp[n] = max(take, skip)
        return dp[n]

    def rob(self, v: List[int]) -> int:
        n = len(v)
        dp = [-1] * (n + 1)
        return self.helper(v, n, dp)
