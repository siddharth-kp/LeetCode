# DSU

class SummaryRanges:

    def __init__(self):
        self.parent = [-1] * 10001
        self.intervals = {}

    def addNum(self, value: int) -> None:
        if self.parent[value] >= 0:
            return

        leftMerge = value - 1 >= 0 and self.parent[value - 1] >= 0
        rightMerge = value + 1 < 10001 and self.parent[value + 1] >= 0

        if leftMerge and rightMerge:
            self._merge_intervals(value)
        elif leftMerge:
            leftParent = self._find_parent(value - 1)
            self.intervals[leftParent] = (self.intervals[leftParent][0], value)
            self.parent[value] = leftParent
        elif rightMerge:
            rightParent = self._find_parent(value + 1)
            self.intervals[rightParent] = (value, self.intervals[rightParent][1])
            self.parent[value] = rightParent
        else:
            self.parent[value] = value
            self.intervals[value] = (value, value)

    
    def _merge_intervals(self, value):
        leftParent = self._find_parent(value - 1)
        rightParent = self._find_parent(value + 1)
        
        leftRange = self.intervals[leftParent]
        rightRange = self.intervals[rightParent]

        self.intervals[leftParent] = (leftRange[0], rightRange[1])
        del self.intervals[rightParent]
        self.parent[rightParent] = leftParent
        self.parent[value] = leftParent

    
    def _find_parent(self, value):
        while self.parent[value] != value:
            value = self.parent[value]
        return value


    def getIntervals(self) -> List[List[int]]:
        return sorted(self.intervals.values(), key = lambda k: k[0])
        


# Your SummaryRanges object will be instantiated and called as such:
# obj = SummaryRanges()
# obj.addNum(value)
# param_2 = obj.getIntervals()