After a long day at school, Andy went home to visit his favourite tree.

This tree will grow every day. Let's call $T_x$ the tree on day $x$. The initial tree is $T_0$, which consists of $N$ nodes. Every day, each leaf node will be replaced with a subtree identical to $T_0$.

Nodes in the tree will be given indices based on their [preorder traversal](https://en.wikipedia.org/wiki/Tree_traversal). Note that the tree given is not necessarily a binary tree.

For example, the following graph shows a possible tree $T_0$, followed by $T_1$, and followed by an illustration of how nodes in $T_1$ would be ordered according to its preorder traversal:

![](https://static.dmoj.ca/media/martor/28bf3ecc-001f-47b4-919a-8d0ea3433c75.png)

This tree has already been growing for $K$ days, meaning the current tree is $T_k$. Andy will ask you $Q$ queries about the length of the simple path between some pair of nodes $u$ and $v$.

Recall a simple path is a path that does not have repeating vertices.

## Constraints

For all subtasks:

$2 \le N \le 10^5$

$1 \le Q \le 10^5$

$0 \le K \le 10^9$

$1 \le u, v \le 10^9$

### Subtask 1 [10%]

$K = 0$

### Subtask 2 [60%]

$K \le 30$

### Subtask 3 [30%]

No additional constraints.

## Input Specification

The first line contains an integer $N$, the initial number of nodes in the tree.

The second line contains $N-1$ integers. The $i^\text{th}$ integer is the father of node $i+1$ in $T_0$. The tree will always be rooted on node $1$. The indices of the nodes given in input are the indices according to the preorder traversal in $T_0$. It is guaranteed that the indices given in input form a valid preorder traversal in $T_0$.

The third line contains two integers $K$ and $Q$. $K$ means the tree has been growing for $K$ days, and $Q$ means the number of queries Andy will ask.

The following $Q$ lines contain two integers $u$ and $v$, meaning Andy wishes to know the length of the simple path between node $u$ and $v$.

## Output Specification

For each of the $Q$ queries, output each answer on one line.

## Sample Input 1

```
10
1 2 3 4 4 3 3 3 2
0 5
1 5
2 9
5 8
2 6
2 10
```

## Sample Output 1

```
4
2
3
3
1
```

## Sample Explanation 1

This is the tree formed:

![](https://static.dmoj.ca/media/martor/990d7994-b487-4cc2-8257-6ef7980ef7cc.png)

## Sample Input 2

```
10
1 2 3 4 4 3 3 3 2
2 5
10 20
15 16
89 99
12 98
100 1
```

## Sample Output 2

```
4
2
9
16
10
```
