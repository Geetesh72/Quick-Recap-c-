/*
Understanding Types of Binary Trees
Binary trees have various classifications based on their structure and properties. Here's an overview:

1. Full Binary Tree
A binary tree is full if every node has either 0 or 2 children.
Example:
markdown
Copy code
        1
       / \
      2   3
     / \
    4   5
Properties:
All non-leaf nodes have 2 children.
Leaf nodes do not have children.
2. Complete Binary Tree
A binary tree is complete if all levels are completely filled, except possibly the last level, which must be filled from left to right.
Example:
markdown
Copy code
        1
       / \
      2   3
     / \
    4   5
Properties:
It is often used in heaps.
Every level except possibly the last is completely filled.
3. Perfect Binary Tree
A binary tree is perfect if all levels are completely filled, and all leaf nodes are at the same level.
Example:
markdown
Copy code
        1
       / \
      2   3
     / \ / \
    4  5 6  7
Properties:
The number of nodes is 

 −1, where 
ℎ
h is the height.
The number of leaf nodes is 

 .
4. Balanced Binary Tree
A binary tree is balanced if the difference in height between the left and right subtrees of any node is at most 1.
Example:
markdown
Copy code
        1
       / \
      2   3
     / 
    4  
Properties:
Balanced binary trees ensure operations like search, insertion, and deletion take 
𝑂
(
log
⁡
𝑛
)
O(logn).
5. Degenerate Binary Tree
A binary tree is degenerate if every parent node has only one child.
It resembles a linked list.
Example:
markdown
Copy code
        1
         \
          2
           \
            3
Properties:
Degenerate trees result in operations taking 
𝑂
(
𝑛
)
O(n), reducing the efficiency of binary tree operations.

*/