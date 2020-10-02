import math

num = int(input("Enter a number = "))

def is_prime(number: int) -> bool:
    if number < 2:
        return False
    if number < 4:
        return True
    if number % 2 == 0:
        return False
    
    odd_numbers = range(3, int(math.sqrt(number)) + 1, 2)
    return not any(number % i == 0 for i in odd_numbers)

print(f"{num} is a prime number" if is_prime(num) else f"{num} is not a prime number")
