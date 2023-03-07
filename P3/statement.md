In biology class, Andy is playing around with a tree. The tree, of course, has $N$ vertices and $N-1$ branches connecting the vertices. Andy will perform a total of $M$ operations.

The following two operations can be performed:

* `1 u v` means Andy will cut the branch connecting node $u$ and node $v$.

* `2` means Andy will use magic glue to glue all the branches back to where they were cut off, or, in other words, restore the tree to what it initially was.

Every vertex $i$ on the tree has a certain power $a_i$.

The power of a connected component of vertices is the product of all powers of the vertices in the connected component.

The power of a set of connected components is the sum of the powers of all connected components in the set.

Before every `2` operation, Andy wants to know the total power of all connected components.

## Constraints

For all subtasks:

$1 \le N, M \le 2 \times 10^5$

$1 \le u, v \le N$

$1 \le a_i \le 10^9$

It is guaranteed that no edge will be cut twice before restoring the tree.

It is guaranteed that the edge being cut is an edge found in the tree.

It is guaranteed that the last operation will be operation `2`.

### Subtask 1 [10%]

Only the last operation will be operation `2`.

### Subtask 2 [90%]

No additional constraints.

## Input Specification

The first line contains an integer $N$.

The second line contains $N$ integers from $a_1$ to $a_N$.

The following $N-1$ lines contain two integers $u$ and $v$, meaning there is a branch connecting vertices $u$ and $v$.

The next line contains an integer $M$.

The following $M$ lines contain one or three integers, with each line being an operation. The format for operations is specified above.

## Output Specification

For every `2` operation, output the total power of connected components. Since the result could be large, output the result modulo $10^9 + 7$.

## Sample Input
```
8
1 2 3 4 5 6 7 8
1 4
4 7
5 2
5 8
6 8
1 3
5 1
6
2
1 5 8
2
1 1 4
1 6 8
2
```

## Sample Output
```
40320
888
274
```

## Sample Explanation

During the first `2` operation, there is only one connected component, so the tree's power is $1 \times 2 \times 3 \times 4\times 5 \times 6 \times 7 \times 8 = 40\,320$.

During the second `2` operation, the tree's power is $1 \times 2 \times 3 \times 4 \times 5 \times 7 + 6 \times 8 = 888$.

During the third `2` operation, the tree's power is $1 \times 2 \times 3 \times 5 \times 8 + 4 \times 7 + 6 = 274$.
