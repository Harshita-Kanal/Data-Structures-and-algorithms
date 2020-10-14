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
## A* Algorithm
A* algorithm is used to find the shortest path in a grapg/tree. As it uses an heuristic to guide the search. The algorithm starts from an initial start node, expands neighbors and updates the full path cost of each neighbor. It selects the neighbor with the lowest cost and continues until it finds a goal node, this can be implemented with a priority queue or by sorting the list of open nodes in ascending order. It is important to select a good heuristic to make A* fast in searches, a good heuristic should be close to the actual cost but should not be higher than the actual cost.

A* is complete and optimal, it will find the shortest path to the goal. A good heuristic can make the search very fast, but it may take a long time and consume a lot of memory in a large search space. The time complexity is O(n) in a grid and O(b^d) in a graph/tree with a branching factor (b) and a depth (d). The branching factor is the average number of neighbor nodes that can be expanded from each node and the depth is the average number of levels in a graph/tree.

## Edmonds–Karp algorithm
### Introduction
Finding the maximum flow for a network was first solved by the Ford-Fulkerson algorithm. A network is often abstractly defined as a graph, G, that has a set of vertices, V, connected by a set of edges, E. There is a source, s, and a sink, t, which represent where the flow is coming from and where it is going to. Finding the maximum flow through a network was solved via the max-flow min-cut theorem, which then was used to create the Ford-Fulkerson algorithm.

**Edmonds-Karp** is identical to Ford-Fulkerson except for one very important trait. The search order of augmenting paths is well defined. As a refresher from the Ford-Fulkerson wiki, augmenting paths, along with residual graphs, are the two important concepts to understand when finding the max flow of a network.

**Edmonds-Karp differs from Ford-Fulkerson in that it chooses the next augmenting path using breadth-first search (bfs). So, if there are multiple augmenting paths to choose from, Edmonds-Karp will be sure to choose the shortest augmenting path from the source to the sink.**

Edmonds-Karp improves the runtime of Ford-Fulkerson, which is O(|E|.f*), to O(|V|.|E|^2). This improvement is important because it makes the runtime of Edmonds-Karp independent of the maximum flow of the network, f*.

### Algorithm Pseudo-Code
inputs
    C[n x n] : Capacity Matrix
    E[n x n] : Adjacency Matrix
    s : source
    t : sink
output
    f : maximum flow
Edmonds-Karp:
    f = 0                // Flow is initially 0
    F = [n x n]       // residual capacity array
    while true:
        m, P = Breadth-First-Search(C, E, s, t, F)
        if m = 0:
            break
        f = f + m
        v = t
        while v != s:
            u = P[v]
            F[u, v] = F[u, v] - m       //This is reducing the residual capacity of the augmenting path
            F[v, u] = F[v, u] + m        //This is increasing the residual capacity of the reverse edges 
            v = u
    return f

### Complexity
Edmonds-Karp makes some important improvement on the Ford-Fulkerson algorithm. Ford-Fulkerson simply states that the flow increases by at least 1 in every iteration. Each iteration takes O(∣E∣) time. So, all Ford-Fulkerson can promise is that the maximum flow is found in O(|E|.f*), where f* is the maximum flow itself.

Edmonds-Karp removes the dependency on maximum flow for complexity, making it much better for graphs that have a large maximum flow,  Edmonds-Karp runs each iteration in O(∣E∣) time and that there are at most ∣V∣⋅∣E∣ iterations, Edmonds-Karp is bounded by 
O(|V|.|E^2|).

### Helpful Links
- [The Edmonds-Karp Max-Flow Algorithm](https://www.cs.cornell.edu/courses/cs4820/2012sp/handouts/edmondskarp.pdf)
- [Maximum flow - Ford-Fulkerson and Edmonds-Karp](https://cp-algorithms.com/graph/edmonds_karp.html)
- [Advanced Algorithms and Complexity](https://www.coursera.org/lecture/advanced-algorithms-and-complexity/the-edmonds-karp-algorithm-JLA96)
- [Edmonds-Karp Algorithm](https://brilliant.org/wiki/edmonds-karp-algorithm/)
- [Maximum Flows, Minimum Cuts, Residual Graphs, The Edmonds-Karp Algorithm](http://web.eecs.utk.edu/~jplank/plank/classes/cs302/Notes/Netflow1/)
- [EDMONDS-KARP ALGORITHM](https://dkim7240.wixsite.com/edmondskarp/what-is-edmonds-karp-algorithm)