class Solution:
    def check(self, v: List[int]) -> bool:
        dip = 0
        n = len(v)
        for i in range(1, n):
            if v[i - 1] > v[i]:
                dip += 1

        if v[-1] > v[0]:
            dip += 1

        return dip <= 1
