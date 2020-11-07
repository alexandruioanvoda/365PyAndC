from typing import List
class Solution:
    def trap(self, height: List[int]) -> int:
        if (len(height) == 0):
            return(0)
        if (max(height) < 1):
            return(0)
        def water_per_level(base_case):
            water = [0]*len(base_case)
            for i in range(len(base_case)-1):
                if base_case[i] == 1:
                    if (i == len(base_case)):
                        break
                    if (base_case[i+1] == 1):
                        next
                    if (i+1 == len(base_case)):
                        if (base_case[i] == 0 and base_case[i+1] == 1):
                            water[i] = 1
                            break
                        else:
                            break
                    end_wall = None
                    for j in range(i+1, len(base_case)):
                        if base_case[j] == 1:
                            end_wall = j
                            break
                    if end_wall is not None:
                        for j in range(i+1, end_wall):
                            water[j] = 1
            return(water)
        if (max(height) == 1):
            return(sum(water_per_level([min(1, x) for x in height])))
        bases = [height]
        bases.append([min(1, x) for x in bases[0]])
        sums = 0
        for i in range(1, max(height)+1):
            bases[0] = [bases[0][j] - bases[i][j] for j in range(len(height))]
            bases.append([min(1, x) for x in bases[0]])
            sums += sum(water_per_level(bases[i]))
        return(sums)
b = Solution()
print(b.trap([4,2,3]))

