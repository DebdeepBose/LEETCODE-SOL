class Solution:
    def maxContainers(self, n: int, w: int, maxW: int) -> int:

        maxAcceptableWight = maxW // w
        cells = n ** 2

        if maxAcceptableWight > cells:
            return cells
        elif maxAcceptableWight < cells:
            return maxAcceptableWight

        return cells
