class Solution(object):
    def canBeEqual(self, s1, s2):
        def swappedStrings(s):
            chars = list(s)
            return [
                s,
                ''.join([chars[2], chars[1], chars[0], chars[3]]),
                ''.join([chars[0], chars[3], chars[2], chars[1]]),
                ''.join([chars[2], chars[3], chars[0], chars[1]])
            ]

        return any(a == b
                   for a in swappedStrings(s1)
                   for b in swappedStrings(s2))