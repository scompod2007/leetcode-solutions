class Solution:
    def evaluate(self, s: str, knowledge: List[List[str]]) -> str:
        knowledge_dict = {key: value for key, value in knowledge}
        index = 0
        string_length = len(s)
        result = []

        while index < string_length:
            if s[index] == '(':
                closing_bracket_index = s.find(')', index + 1)
                key = s[index + 1 : closing_bracket_index]
                replacement_value = knowledge_dict.get(key, '?')
                result.append(replacement_value)
                index = closing_bracket_index
            else:
                result.append(s[index])
            index += 1

        return ''.join(result)