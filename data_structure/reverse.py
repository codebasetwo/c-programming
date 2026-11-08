def check_balanced_parenthesis(string: str):
    stack = []
    dictionary = {']': '[', '}':'{', ')':'('}
    for char in string:
        if char in dictionary.values():
            stack.append(char)
        else:
            if (len(stack) != 0) and (stack[-1] == dictionary[char]):
                stack.pop()

    if len(stack) == 0:
        return True
    return False

def check_balanced_parenthesis2(string: str):
    stack = []
    dictionary = {']': '[', '}':'{', ')':'('}
    for char in string:
        if char in dictionary.values():
            stack.append(char)
        else:
            if not stack or stack[-1] != dictionary[char]:
                return False
            else:
                stack.pop()

    if len(stack) == 0: return True
    return False

string: str = "[()()]"

is_balanced = check_balanced_parenthesis(string)
print(is_balanced)

is_balanced = check_balanced_parenthesis(")(")
print(is_balanced)

is_balanced = check_balanced_parenthesis("[()]")
print(is_balanced)

is_balanced = check_balanced_parenthesis("[(])")
print(is_balanced)