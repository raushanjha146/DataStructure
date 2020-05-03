# Binary Search Tree

Binary search tree is a data structure that quickly allows us to maintain a sorted list of numbers.
</br> 
It has the following properties:
1.  All nodes of left subtree are less than root node
2.  All nodes of right subtree are more than root node
3.  Both subtrees of each node are also BSTs i.e. they have the above two properties

![](binary_search_tree.jpg?raw=true "Binary Search Tree")

**Binary Search Tree** is called :
* binary tree because each tree node has maximum of two children.
* search tree because it can be used to search for the presence of a number in O(log(n)) time.

## Inertion in Binary Search Tree(BST)
Inserting a value in the correct position is similar to searching because we try to maintain the rule that left subtree is lesser than root and right subtree is larger than root.
</br>

We keep going to either right subtree or left subtree depending on the value and when we reach a point left or right subtree is null, we put the new node there.
</br>

**Algorithm:**
```
If node == NULL 
    return createNode(data)
if (data < node->data)
    node->left  = insert(node->left, data);
else if (data > node->data)
    node->right = insert(node->right, data);  
return node;
```

**Element : 21, 28,14, 32, 25, 11,18, 30, 19, 15**

![Alt Text](https://github.com/raushanjha146/DataStructure/blob/master/Tree/BST/binary-search-tree-insertion-animation.gif)

### Traversing :
* **In-Order** : 11, 14, 15, 18, 19, 21, 25, 28, 32, 30
* **Pre-Order** : 21, 14, 11, 18, 15, 19, 28, 25, 32, 30
* **Post-Order** : 11, 15, 19, 18, 14, 25, 30, 32, 28, 21
* **Level-Order** : 21, 14, 28, 11, 18, 25, 32, 15, 19, 30
