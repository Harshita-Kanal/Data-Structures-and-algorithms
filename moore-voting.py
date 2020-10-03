# Uses python3
import sys

##  Using Moore's Voting Algorithm (Linear Time And Constant Space)
def get_majority_element_moore(a, left, right):
	if left == right:
		return -1
	if left + 1 == right:
		return a[left]
	## Step 1: Find the candidate
	candidate = a[left]
	count = 1
	for i in range(left + 1, right):
		if candidate != a[i]:
			count -= 1
		else:
			count += 1
		if count == 0:
			candidate = a[i]
			count = 1

	## Step 2: Verify if the candidate is the majority element
	count = 0
	for i in range(left, right):
		if a[i] == candidate:
			count += 1
	
	return 1 if count > (n / 2) else 0


if __name__ == '__main__':
	input = sys.stdin.read()
	n, *a = list(map(int, input.split()))
	print(get_majority_element_moore(a, 0, n))
