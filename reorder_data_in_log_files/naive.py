from typing import List
class Solution:
    def reorderLogFiles(self, logs: List[str]) -> List[str]:
        letter = [x.split() for x in logs if x.split()[1].isalpha()]
        letter.sort(key = lambda x: x[0])
        letter.sort(key = lambda x: x[1:])
        letter = [" ".join(x) for x in letter]
        digit = [x for x in logs if x.split()[1].isnumeric()]
        return(letter+digit)
# sorted(range(len(logs)), key=lambda k: logs[k].split(" ")[0])
b = Solution()
print(b.reorderLogFiles(["dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"]))