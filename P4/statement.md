Andy is exploring how toys impact a person's happiness level in his psychology class. He recruited a study participant named Jamie.

Jamie can select $N$ toys from the store to be his birthday gifts, and he can exchange toys with his friends. There are $M$ types of toys.

For the $i^\text{th}$ toy $(1 \le i \le M)$, Jamie can select at most $S_i$ of it from the store, and it has a base happiness value of $H_i$. However, if Jamie owns multiple of the same toy, the happiness value Jamie gets from it decreases: the second toy will only give him $\frac{1}{2}$ of $H_i$ happiness, the third toy will give him $\frac{1}{3}$ of $H_i$ happiness, and the $S_i^\text{th}$ toy will give him $\frac{1}{S_i}$ of $H_i$ happiness. Note that if the happiness value is a decimal, it will be rounded down to the nearest integer.

Jamie has $K$ friends. His $i^\text{th}$ friend, where $1 \le i \le K$, has an infinite amount of toy $B_i$ and is willing to exchange one of his toy $B_i$ with one of Jamie's toy $A_i$, but Jamie will lose $D_i$ happiness in the process. It is worth noting that Jamie can refuse an exchange or repeat an exchange as many times as he wants as long as he has the appropriate toy for exchange.

You need to find the maximum amount of happiness Jamie can achieve after some (possibly zero) exchanges.

## Constraints

For all subtasks:

$1 \le N \le 1\,000$

$1 \le M \le 100$

$0 \le K \le 100$

$0 \le S_i \le 100$

$1 \le H_i, D_i \le 10^6$

$1 \le A_i, B_i \le M$

### Subtask 1 [15%]

$K = 0$

### Subtask 2 [85%]

No additional constraints.

## Input Specification

The first line contains three integers $N$, $M$, and $K$.

The following $M$ lines contain two integers $H_i$ and $S_i$.

The following $K$ lines contain three integers $A_i$, $B_i$, and $D_i$.

## Output Specification

Output an integer that represents the maximum sum of happiness value Jamie can achieve.

## Sample Input
```
4 5 2
100 1
20 2
30 1
200 0
10 4
5 4 150
3 2 5
```

## Sample Output
```
200
```

## Sample Explanation

Jamie selects one of each toy $1, 2, 3, 5$ from the store and exchanges his toy $5$ with his first friend's toy $4$.
