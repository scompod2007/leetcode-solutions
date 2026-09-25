class Solution:
    def braceExpansionII(self, expression: str) -> List[str]:
        self.expr = expression
        self.i = 0
        return sorted(self.parse())

    def parse(self) -> set:
        result = {""}
        while self.i < len(self.expr) and self.expr[self.i] not in (",", "}"):
            if self.expr[self.i] == "{":
                self.i += 1
                group = self.parse_braces()
                self.i += 1
            else:
                start = self.i
                while self.i < len(self.expr) and self.expr[self.i].isalpha():
                    self.i += 1
                group = {self.expr[start:self.i]}
            result = {a + b for a in result for b in group}
        return result

    def parse_braces(self) -> set:
        result = set()
        result |= self.parse()
        while self.i < len(self.expr) and self.expr[self.i] == ",":
            self.i += 1
            result |= self.parse()
        return result