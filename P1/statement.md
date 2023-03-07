Andy recently learned about the [bitwise XOR](https://en.wikipedia.org/wiki/Bitwise_operation#XOR) operation in computer class.

One of Andy's friends owns an array $a$, which has a length of $N$. Andy wants to make his friend sad by XORing all of the numbers in $a$ by a non-negative number $x$ such that the sum of the sums of each subarray is minimal. Since Andy is not an expert at XOR, he asks you to find $x$ for him. If multiple solutions exist for $x$, output the smallest one.

Recall subarrays are consecutive subsequences. For example, the subarrays of the array $[1, 2, 3]$ are $[1], [2], [3], [1, 2], [2, 3], [1, 2, 3]$. The sum of the sums of each subarray for this array will be $(1) + (2) + (3) + (1 + 2) + (2 + 3) + (1 + 2 + 3) = 20$.

## Constraints

For all subtasks:

$1 \le N \le 2 \times 10^5$

$0 \le a_i \le 10^9$

### Subtask 1 [30%]

$0 \le a_i \le 1$

### Subtask 2 [70%]

No additional constraints.

## Input Specification

The first line contains an integer $N$.

The second line contains $N$ integers, his friend's array $a$.

## Output Specification

Output the minimal solution for $x$, which is the number that Andy wishes to know.

## Sample Input 1

```
3
1 2 3
```

## Sample Output 1

```
3
```

## Explanation for Sample 1

After XORing by 3, the array becomes $[2, 1, 0]$. The sum of the sums of each subarray is $(2) + (1) + (0) + (2 + 1) + (1 + 0) + (2 + 1 + 0) = 10$.
It can be shown that $10$ is the smallest possible sum of the sums of each subarray.

## Sample Input 2

```
7
7 9 10 43 56 2 4
```

## Sample Output 2

```
10
```
