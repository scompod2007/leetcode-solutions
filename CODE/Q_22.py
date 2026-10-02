class Solution:
    def func(self, result, ch, index, open, close):
        if open == 0 and close == 0:
            result.append("".join(ch))
            return

        if open > 0:
            ch[index] = '('
            self.func(result, ch, index + 1, open - 1, close)

        if close > open:
            ch[index] = ')'
            self.func(result, ch, index + 1, open, close - 1)

    def generateParenthesis(self, n):
        result = []
        ch = [' '] * (2 * n)

        self.func(result, ch, 0, n, n)

        return result