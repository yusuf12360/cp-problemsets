# Palindrome Division

**Time Limit:** 2 seconds  
**Memory Limit:** 128 MB

**Estimated Difficulty:** 1400 (Codeforces-based)  
**Tags:** Brute Force, Constructive Algorithms, Math

## Description

Define a palindrome as an integer without leading zeros that reads the same forwards and backwards. For instance, 13431 and 543345 are palindromes, whilst 0110 and 6767 are not.

Given 2 integers $N$ and $K$. For every $0 \leq i < K$, output the count of palindromes from $1$ to $N$ inclusive, which, when divided by $K$, leave a remainder of $i$.

## Constraints

* $1 \leq N \leq 10^{11}$
* $1 \leq K \leq 10^5$

## Subtasks

1. (50 points) $1 \leq N \leq 10^{6}$
2. (50 points) No additional constraints.

## Input

Contains only 1 line consisting of 2 integers $N$ and $K$.

## Output

Output a single line containing $K$ integers as requested in the description.

## Example

### Input

```
100 3
```

### Output

```
6 6 6
```

### Explanation

For every $0 \leq i < 3$, we must output the count of palindromes from $1$ to $100$ inclusive, which, when divided by $3$, yield a remainder of $i$.

For $i = 0$, there are 6 satisfying palindromes: 3, 6, 9, 33, 66, 99.

For $i = 1$, there are 6 satisfying palindromes: 1, 4, 7, 22, 55, 88.

For $i = 2$, there are 6 satisfying palindromes: 2, 5, 8, 11, 44, 77.

## Editorial

<details>
<summary><b>Click to view the Editorial</b></summary>

### Subtask 1

For $N \leq 10^6$, we can simply iterate through every integer from $1$ to $N$. For each integer, we check if it is a palindrome by reversing its string or integer representation. If it is a palindrome, we compute modulo $K$ and update the frequency array.

**Time complexity:** $O(N \log N)$.

### Subtask 2 (Full Solution)

Since $N$ can be up to $10^{11}$, iterating up to $N$ will result in a Time Limit Exceeded (TLE). We need a way to generate palindromes directly rather than checking every number.

Observe that a palindrome is determined entirely by its first $\lceil L/2 \rceil$ digits, where $L$ is the length of the palindrome.
* **Even length palindromes:** Constructed by taking a number $X$ and appending the reverse of $X$. (e.g., $12 \to 1221$).
* **Odd length palindromes:** Constructed by taking a number $X$, appending a middle digit, and then appending the reverse of $X$. (e.g., $12 \xrightarrow{3} 12321$).

Since $N \leq 10^{11}$, the palindromes can have at most 11 digits. The "half" of the palindrome (the seed number $X$) will therefore be at most roughly $\sqrt{10^{11}} \approx 316,227$.
We can iterate a seed number $i$ from $1$ up to $10^6$ (a safe upper bound) to generate all necessary palindromes.

**Time Complexity:** $O(\sqrt{N})$.  
**Space Complexity:** $O(K)$.

</details>