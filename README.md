# Data-Structures-and-algorithms
### Hello World! :wave:
This repository will be my documentation while I learn Data structures and algorithms.
I will add my solved problems here :smile:

## Binary Search
https://www.topcoder.com/community/competitive-programming/tutorials/binary-search/
### Beyond arrays: the discrete binary search <br>
This is where we start to abstract binary search. A sequence (array) is really just a function which associates integers (indices) with the corresponding values. However, there is no reason to restrict our usage of binary search to tangible sequences. In fact, we can use the same algorithm described above on any monotonic function f whose domain is the set of integers. The only difference is that we replace an array lookup with a function evaluation: we are now looking for some x such that f(x) is equal to the target value. The search space is now more formally a subinterval of the domain of the function, while the target value is an element of the codomain. The power of binary search begins to show now: not only do we need at most O(log N) comparisons to find the target value, but we also do not need to evaluate the function more than that many times. Additionally, in this case we aren’t restricted by practical quantities such as available memory, as was the case with arrays.
<br>

What we can call the main theorem states that binary search can be used if and only if for all x in S, p(x) implies p(y) for all y > x. This property is what we use when we discard the second half of the search space. It is equivalent to saying that ¬p(x) implies ¬p(y) for all y < x (the symbol ¬ denotes the logical not operator), which is what we use when we discard the first half of the search space. The theorem can easily be proven, although I’ll omit the proof here to reduce clutter. <br>

These two parts are most often interleaved: when we think a problem can be solved by binary search, we aim to design the predicate so that it satisfies the condition in the main theorem.

## Floyd's cycle-finding algorithm
Floyd's cycle-finding algorithm is a pointer algorithm that uses only two pointers, which move through the sequence at different speeds. It is also called the "tortoise and the hare algorithm", alluding to Aesop's fable of The Tortoise and the Hare.



The algorithm is named after Robert W. Floyd, who was credited with its invention by Donald Knuth.[3][4] However, the algorithm does not appear in Floyd's published work, and this may be a misattribution: Floyd describes algorithms for listing all simple cycles in a directed graph in a 1967 paper,[5] but this paper does not describe the cycle-finding problem in functional graphs that is the subject of this article. In fact, Knuth's statement (in 1969), attributing it to Floyd, without citation, is the first known appearance in print, and it thus may be a folk theorem, not attributable to a single individual.[6]

The key insight in the algorithm is as follows. If there is a cycle, then, for any integers i ≥ μ and k ≥ 0, xi = xi + kλ, where λ is the length of the loop to be found and μ is the index of the first element of the cycle. Based on this, it can then be shown that i = kλ ≥ μ for some k if and only if xi = x2i. Thus, the algorithm only needs to check for repeated values of this special form, one twice as far from the start of the sequence as the other, to find a period ν of a repetition that is a multiple of λ. Once ν is found, the algorithm retraces the sequence from its start to find the first repeated value xμ in the sequence, using the fact that λ divides ν and therefore that xμ = xμ + v. Finally, once the value of μ is known it is trivial to find the length λ of the shortest repeating cycle, by searching for the first position μ + λ for which xμ + λ = xμ.

The algorithm thus maintains two pointers into the given sequence, one (the tortoise) at xi, and the other (the hare) at x2i. At each step of the algorithm, it increases i by one, moving the tortoise one step forward and the hare two steps forward in the sequence, and then compares the sequence values at these two pointers. The smallest value of i > 0 for which the tortoise and hare point to equal values is the desired value ν.


## QuickSort Algorithm
Quick Sort is a sorting algorithm, which is commonly used in computer science. Quick Sort is a divide and conquer algorithm. It creates two empty arrays to hold elements less than the pivot value and elements greater than the pivot value, and then recursively sort the sub arrays. There are two basic operations in the algorithm, swapping items in place and partitioning a section of the array.
....)-->Steps on how it works:
Find a “pivot” item in the array. This item is the basis for comparison for a single round.
Start a pointer (the left pointer) at the first item in the array.
Start a pointer (the right pointer) at the last item in the array.
While the value at the left pointer in the array is less than the pivot value, move the left pointer to the right (add 1). Continue until the value at the left pointer is greater than or equal to the pivot value.
While the value at the right pointer in the array is greater than the pivot value, move the right pointer to the left (subtract 1). Continue until the value at the right pointer is less than or equal to the pivot value.
If the left pointer is less than or equal to the right pointer, then swap the values at these locations in the array.
Move the left pointer to the right by one and the right pointer to the left by one.
If the left pointer and right pointer don’t meet, go to step 1.

