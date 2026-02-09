# Safe Cracking

**Time Limit:** 1 second  
**Memory Limit:** 256 MB

**Estimated Difficulty:** 1200  
**Topics:** Combinatorics, Math

## Description

Pak Dengklek is a reliable safe cracker. However, today, the safe he wishes to crack is rather unique; its PIN is a base-
$
K
$ 
number with $N$ digits numbered from $1$ to $N$ (leading zeros are allowed), where naturally each digit is an integer from $0$ to $K - 1$ inclusive.

To crack this safe, Pak Dengklek must correctly guess all the digits. However, somehow, Pak Dengklek has managed to acquire information regarding the safe's PIN in the form of an array $A$ of length $N$, where each element in this array is an integer from $-1$ to $K - 1$ inclusive. If $A_i \geq 0$, it indicates that the $i$-th digit is definitely greater than or equal to $A_i$. Meanwhile, all digits with index $i$ where $A_i = -1$ are definitely distinct. In other words, there are no two indices $i$ and $j$ where $1 \leq i < j \leq N$ satisfying $A_i = A_j = -1$ such that the $i$-th digit is equal to the $j$-th digit.

Before Pak Dengklek commences his action, he is curious: how many possible PINs satisfy the information he has received? Assist Pak Dengklek in calculating the number of such possibilities! As the answer can be very large, output the answer modulo $10^9 + 7$. Note that it is possible that no PIN satisfies the conditions; in this case, it means the information Pak Dengklek received is incorrect.

## Constraints

* $1 \leq N, K \leq 200 \, 000$
* $-1 \leq A_i < K$
* All variables in the input are integers

## Subtasks

1. (50 points) Contains only the following test case:

   ```
   10 3
   -1 0 1 1 0 -1 1 0 0 1
   ```

2. (50 points) No additional constraints.

## Input

The first line contains 2 integers $N$ and $K$. It is followed by $N$ integers $A_1, A_2, ..., A_N$ on the second line.

## Output

Output a single line containing the answer requested by Pak Dengklek modulo $10^9 + 7$.

## Example 1

### Input

```
3 3
-1 2 -1
```

### Output

```
6
```

### Explanation

The possible PINs that satisfy the conditions are 021, 022, 120, 122, 220, and 221. There are 6 possibilities.

## Example 2

### Input

```
7 4
2 -1 -1 -1 0 -1 -1
```

### Output

```
0
```
### Explanation

There are 5 digits whose values must be distinct, namely digits 2, 3, 4, 6, and 7, whilst there are only $K = 4$ possible values for a single digit. Thus, it is impossible for a valid PIN to exist.

## Editorial

<details>
<summary><b>Click to view the Editorial</b></summary>

### Subtask 1

In this subtask, we are given fixed values: $N=10$, $K=3$, and the array $A = [-1, 0, 1, 1, 0, -1, 1, 0, 0, 1]$.

1.  **Fixed positions ($A_i \geq 0$):**
    For each position where $A_i$ is specified, the number of valid digits is $K - A_i$.
    * $A_2=0 \to 3$ choices
    * $A_3=1 \to 2$ choices
    * $A_4=1 \to 2$ choices
    * $A_5=0 \to 3$ choices
    * $A_7=1 \to 2$ choices
    * $A_8=0 \to 3$ choices
    * $A_9=0 \to 3$ choices
    * $A_{10}=1 \to 2$ choices  
    Product: $3 \times 2 \times 2 \times 3 \times 2 \times 3 \times 3 \times 2 = 1296$.

2.  **Distinct positions ($A_i = -1$):**
    There are two indices ($i=1$ and $i=6$) where $A_i = -1$. We must pick 2 distinct values from $K=3$ available digits.
    Permutation: $P(3, 2) = 3 \times 2 = 6$.

Total: $1296 \times 6 = 7776$.

### Subtask 2 (Full Solution)

The problem can be decomposed into two independent counting tasks based on the constraints provided in array $A$.

**1. Lower Bound Constraints ($A_i \geq 0$):**
For any index $i$ where $A_i$ is non-negative, the digit $d_i$ must satisfy $A_i \leq d_i < K$. This gives exactly $K - A_i$ choices for that specific position. As these choices are independent, we multiply them together modulo $10^9 + 7$.

**2. Distinctness Constraints ($A_i = -1$):**
Let $C$ be the total count of indices where $A_i = -1$. These $C$ positions must all contain unique values chosen from the set $\{0, 1, \dots, K-1\}$.
* If $C > K$, it is impossible to assign unique values (Pigeonhole Principle), resulting in $0$ possibilities.
* If 
$
C \leq K
$
, the number of ways to assign these digits is the number of permutations of $K$ items taken $C$ at a time: $P(K, C) = K \times (K-1) \times \dots \times (K - C + 1)$.

The final result is the product of the independent choices from both steps, calculated under modulo $10^9 + 7$.

**Complexity:**
* **Time Complexity:** $O(N)$ as each element is processed once.
* **Space Complexity:** $O(N)$ to store the array, or $O(1)$ if processed on the fly.

</details>