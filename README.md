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

## Merge Sort
The **Merge Sort** algorithm is one of the many sorting algorithms known to mankind, but it specifically features many interesting aspects. But first, a short explanation of the way the algorithm works:

MergeSort is a recursive sorting algorithm. Given an array **A** of size **n**, split the array (virtually) into two halves, and call the algorithm on each half seperatly. After that, merge the two sorted arrays into one big sorted array (in place of the original array) - and that's it. Since this is a recursive algorithm we must have a base case - in this case (no pun intended) it is when `n = 1`, meaning when the array only has one element. In that case, no merging needs to be done, and the array is already sorted (because an array with one elemnt is always sorted).

One interesting feature of this algorithm is it's _divide and conquer_ nature. Instead of "gulping down" the whole array at once and doing a lot of computation in the same abstraction level, we "digest" it in smaller bites. The only thing we do on the surface level is the recursive call and then the merge - two very simple tasks (this is also one of the pros of recursive algorithms in general).

An important factor that chips in when deciding which algorithm to use is time complexity. MergeSort's time complexity is (along with Quick Sort and Heap Sort) `O(n log n)`. This is quicker than other algorithms usually taught in high school or university which are `O(n<sup>2</sup>)` (like Bubble Sort, Insertion Sort and Selection Sort).

Let us see why it is `O(n log n)`. Let's call MergeSort's time complexity `T(n)` (n being the length of the given array). Every call to MergeSort does `T(n) = 2 * T(n / 2) + n` because we call MergeSort on the half-sized arrays and then merge them (which goes over all the elements in both seperated array - hence `O(n)`). Without getting into too much recursive formula solving - We shall see that the solution `n log n` solves the equation. `n log n = 2 * (n log n) + n` = `n log n + n` = `n log n` (for more information on why this is true and what this means look up _Big-O Notation_).