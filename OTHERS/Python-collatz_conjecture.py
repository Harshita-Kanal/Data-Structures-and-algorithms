"""
The Collatz conjecture is a conjecture in mathematics that concerns a sequence 
defined as follows: start with any positive integer n. Then each term is obtained
from the previous term as follows: if the previous term is even, the next term is
one half of the previous term. If the previous term is odd, the next term is 3 
times the previous term plus 1. The conjecture is that no matter what value of n, 
the sequence will always reach 1.(From Wikipedia)"""

def collatz(number):
  if number % 2 ==0: 
    answer = number //2
  else: 
    answer = 3 *number + 1
  
  print(answer)
  return answer 

while True: 
  try: 
    result = int (input("Enter a number: "))
    print(result)
  except ValueError:
    print("That's not a number.Try again")
    continue
    
  while result != 1:   #1 is the point we want to reach 
    result = collatz(result)
  quit = input("Do you want to continue? y / n ")
  if quit == 'n': 
    break