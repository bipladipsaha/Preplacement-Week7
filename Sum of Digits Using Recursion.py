def sum_of_digits(n):
    if n == 0:
        return 0
    return n % 10 + sum_of_digits(n // 10)
num = 12345
print(f"Sum of digits of {num} is:", sum_of_digits(num))
