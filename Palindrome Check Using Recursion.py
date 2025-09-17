def is_palindrome(s):
    if len(s) <= 1:
        return True
    if s[0] != s[-1]:
        return False
    return is_palindrome(s[1:-1])
test_str = "racecar"
print(f"Is '{test_str}' a palindrome? {is_palindrome(test_str)}")

test_str2 = "hello"
print(f"Is '{test_str2}' a palindrome? {is_palindrome(test_str2)}")
