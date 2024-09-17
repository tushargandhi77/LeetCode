class Solution:
    def uncommonFromSentences(self, s1: str, s2: str) -> List[str]:
        l1 = list(s1.split())
        l2 = list(s2.split())
        d = {}
        for x in l1:
            if x in d:
                d[x] += 1
            else:
                d[x] = 1
        for x in l2:
            if x in d:
                d[x] += 1
            else:
                d[x] = 1
        result = []
        for key,value in d.items():
            if value == 1:
                result.append(key)
        return result
        
