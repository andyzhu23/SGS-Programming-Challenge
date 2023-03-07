It's lunchtime, and as usual, Andy is trying to buy drinks from the vending machine.

The vending machine wants to play a game with Andy.

The vending machine hides a $0$-indexed array $a$ consisting of $N$ distinct integers from $0$ to $N-1$. The vending machine defines the rank of a number as the number of numbers smaller than it in the array.

Andy will try to find the index of the numbers in array $a$ with rank $2^0, 2^1, 2^2, \dots, 2^k$, where $k$ is the largest number such that $2^k < N$. In other words, find the indices of the numbers $2^0, 2^1, 2^2, \dots, 2^k$.

Andy struggles to get the answer and asks you to help out.

You can perform two types of queries:

Query 1: You provide the vending machine with two indices $i$ and $j$ $(0 \le i, j < N)$, and the vending machine will compare the two numbers at those indices and output `1` if $a_i > a_j$ and `0` if $a_i < a_j$. This query costs $1$ dollar.

Query 2: You provide the vending machine with an array $v$ of size $m$ $(1 \le m \le N)$ which consists of distinct integers $v_i$ $(0 \le v_i < N$ for all indices $i$ in $v)$ and an integer $x$ $(0 \le x < m)$. The machine will return an integer $y$, which is the index of the $x^\text{th}$ ranked number within the array $a_{v_1}, a_{v_2}, \cdots, a_{v_m}$. $y$ is given as the index in the original $0$-indexed array $a$. This query costs $m$ dollars.

You need to get the answer by spending at most $6N$ dollars.

## Constraints

For all subtasks:

$2 \le N \le 10^4$

All integers in $a$ are distinct.

### Subtask 1 [10%]

$N \le 50$

### Subtask 2 [90%]

No additional constraints.

## Interaction

This is an interactive problem. The first line of input contains an integer $N$.

To ask query 1, you output the following:

$?$ $i$ $j$ (followed by `\n` character)

To ask query 2, you output the following:

$$$ $m$ $v_1$ $v_2$ $\dots$ $v_m$ $x$ (followed by `\n` character)

If you believe you found the answer, output $!$ followed by $k$, where $k$ is the largest integer such that $2^k < N$, followed by $k+1$ integers (followed by `\n` character), representing the numbers with rank $2^0, 2^1, 2^2, \dots, 2^k$, respectively. You must terminate your program immediately after performing this operation. Note that this operation does not cost anything.

The grader is not adaptive.

If at any point your query is malformed or your cost exceeds $6N$ dollars, your program will receive `-1`, and the interactor will terminate. Upon receiving `-1`, your program should terminate to avoid an undefined verdict.

Please note: the judge requires your whitespace to match **exactly**.

If you attempt an invalid operation (such as an invalid output format), you will receive a `Presentation Error` verdict.

If you exceed a cost of $6N$ dollars, query incorrectly, or output incorrect final result, you will receive a `Wrong Answer` verdict.

Please note that you may need to flush `stdout` after each operation, or interaction may halt. In C++, this can be done with `fflush(stdout)` or `cout << flush` (depending on whether you use `printf` or `cout`). In Java, this can be done with `System.out.flush()`. In Python, you can use `sys.stdout.flush()`.

## Sample Interaction

`>>>` denotes your output. Do not print this out.

The array $a$ is $[3, 5, 6, 4, 2, 0, 1]$.

```
7
>>> ? 1 3
1
>>> ? 5 6
0
>>> $ 7 0 1 2 3 4 5 6 0
5
>>> $ 4 0 2 4 6 3
2
>>> ! 2 6 4 3
```

## Explanation for Sample

For the first query, $5 > 4$, so it prints $1$.

For the second query, $0 < 1$, so it prints $0$.

For the third query, the whole array is being asked, and $0$ at index $5$ is ranked $0$. Thus, it prints $5$.

For the fourth query, the array $[3, 6, 2, 1]$ is being asked. The number with a rank of $3$ is $6$, with an index of $2$ in array $a$. Thus, it prints $2$.

For the final operation, $k = 2$. The number $2^0 = 1$ has index $6$. The number $2^1 = 2$ has index $4$. The number $2^2 = 4$ has index $3$.

The total cost of this interaction is $1 + 1 + 7 + 4 = 13$ dollars, which is less than $6N = 6 \times 7 = 42$ dollars.
