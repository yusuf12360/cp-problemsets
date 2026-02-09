# Absolute

**Time Limit:** 3 seconds  
**Memory Limit:** 256 MB

**Estimated Difficulty:** 1600 (Codeforces-based)  
**Tags:** Math, Geometry, Sorting, Implementation

## Description

Magnus has just arrived in his class and is greeted by $N$ of his friends. Each of them gives him a number; the $i$-th friend gives Magnus an integer $A_i$.

When the first session began, the teacher gave the students the freedom to do self-study, and Magnus's decision at that moment was **absolute**, that is to solve the following equation:

$$
|x - A_1| + |x - A_2| + |x - A_3| + \dots + |x - A_N| = S
$$

Help Magnus to determine all real numbers $x$ that satisfy that equation, or report that there are infinitely many solutions.

## Input

The first line contains 2 integers $N$ and $S$.  
The second line contains $N$ integers $A_1, A_2, \dots, A_N$.

## Output

On the first line, output an integer $k$ denoting the number of real solutions that satisfy the equation described above, or output $-1$ if the number of solutions is infinite.

If there are infinitely many solutions, the output consists of a single line. Otherwise, output $k$ real numbers on the second line denoting the solutions of the equation described above. Output these integers in increasing order.

Contestant's output will be considered accepted if and only if the number on the first line in contestant's and jury's output is the same. If there's a second line, then the number of real numbers on that line in contestant's and jury's output must be the same and the absolute difference between each corresponding number in contestant's and jury's output must be less than $10^{-9}$.

## Constraints

* $1 \leq N \leq 500\,000$
* $0 \leq S \leq 10^{9}$
* $0 \leq |A_i| \leq 10^{9}$ for all $1 \leq i \leq N$

## Subtasks

1. (7 points) $A_1 = A_2 = A_3 = \dots = A_N$
2. (10 points) $N = 2$
3. (23 points) $N, S, |A_i| \leq 2\,000$
4. (20 points) $N = 10$
5. (40 points) No additional constraints.

## Example 1

### Input

```
2 5
1 1
```

### Output

```
2
-1.50000000000 3.50000000000
```

### Explanation

$$
|x - 1| + |x - 1| = 5
$$

$$
2|x - 1| = 5
$$

$$
|x - 1| = \frac{5}{2} \implies \displaystyle{\begin{cases} x - 1 = \frac{5}{2} \implies x = 3.5 \\ x - 1 = -\frac{5}{2} \implies x = -1.5 \end{cases}}
$$

## Example 2

### Input

```
3 0
-1 3 -2
```

### Output

```
0

```

### Explanation

$|x - (-1)| + |x - 3| + |x - (-2)| = 0$

Note that the absolute value of a number must be non-negative. In this case, because the sum is 0, the absolute value of each of the 3 parts must be $0$, which will lead us to a contradiction (if the absolute value of one part is $0$, then the absolute value of another part must be positive because the numbers are distinct). Therefore, no solutions exist.

## Editorial

<details>
<summary><b>Click to view the Editorial</b></summary>

### Subtask 1
Since all $A_i$ are equal, let $A = A_1 = A_2 = \dots = A_N$.  
The equation becomes:  

$\sum_{i=1}^N |x - A| = S \implies N|x - A| = S \implies |x - A| = \frac{S}{N}$

Thus, the solutions are $x = A + \frac{S}{N}$ and $x = A - \frac{S}{N}$. Note that if $S=0$, there is only 1 solution ($x=A$).

### Subtask 2
We have $|x - A_1| + |x - A_2| = S$.
Geometrically, this represents the sum of distances from $x$ to $A_1$ and $A_2$ on the number line.
The minimum value of this function is $|A_1 - A_2|$, occurring when $x$ is anywhere between $A_1$ and $A_2$ (inclusive).
* If $S < |A_1 - A_2|$, there are 0 solutions.
* If $S = |A_1 - A_2|$, there are infinitely many solutions (the interval $[ \min(A_1, A_2), \max(A_1, A_2) ]$). Output -1.
* If $S > |A_1 - A_2|$, there are exactly 2 solutions outside the range $[A_1, A_2]$.

### Subtask 3 & 4
With small constraints, one can observe that the function $f(x) = \sum |x - A_i|$ is convex. We can simply iterate through ranges or use the logic from Subtask 5.

### Subtask 5 (Full Solution)
Let $f(x) = \sum_{i=1}^N |x - A_i|$.
This is a convex function comprised of linear segments. The slope of the function changes at every point $x = A_i$.
1.  First, sort the array $A$ in non-decreasing order.
2.  For $x < A_1$, every term $|x - A_i|$ becomes $-(x - A_i) = A_i - x$. The slope is $-N$.
3.  As we move $x$ past $A_1$, the term $|x - A_1|$ changes from $-(x - A_1)$ to $+(x - A_1)$. The slope increases by $+2$.
4.  In general, for $x \in [A_i, A_{i+1}]$, the function is linear: $y = mx + c$.
5.  We start with $m = -N$ and calculate the initial constant $c$ for $x < A_1$. We iterate through the sorted array. At each step, we update the slope and check if the target $S$ intersects the line segment $y = mx + c$ within the current interval.
6.  **Infinite Solutions:** If at any point the slope $m=0$ (which happens at the median for even $N$) and the current value of the function equals $S$, then the entire interval $[A_i, A_{i+1}]$ is a solution set. Output -1.

**Time Complexity:** $O(N \log N)$ due to sorting.  
**Space Complexity:** $O(N)$ to store the array.

</details>