from collections import defaultdict

def at_most_k_distinct(s, K):
    count = defaultdict(int)
    left = 0
    result = 0
    distinct = 0

    for right in range(len(s)):
        count[s[right]] += 1
        if count[s[right]] == 1:
            distinct += 1
        
        while distinct > K:
            count[s[left]] -= 1
            if count[s[left]] == 0:
                distinct -= 1
            left += 1
        
        result += right - left + 1
    return result

def substrings_with_exactly_k_distinct(s, K):
    return at_most_k_distinct(s, K) - at_most_k_distinct(s, K-1)
s = "pqpqs"
K = 2
print(substrings_with_exactly_k_distinct(s, K))
