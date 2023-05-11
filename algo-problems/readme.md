# Algorithm Problems

## Index

| Serial no. | Name                                      |
|------------|-------------------------------------------|
| 1          | Huffman Coding Algorithm                  |
| 2          | Matrix Multiplication - simple            |
| 3          | Matrix Multiplication - D&C               |
| 4          | Matrix Multiplication - Strassen's Method |
| 5          | Maximum Subarray Problem                  |
| 6          | Travelling Salesmen                       |
| 7          | Maximum and Minimum in a given array      |
| 8          | Fractional Knapsack                       |
| 9          | Knapsack                                  |
| 10         | LCS                                       |
| 11         | Matrix Chain multiplication               |
| 12         | N Queens Problem                          |
| 13         | Knights tour on chess board               |
| 14         | Pascals Triangle                          |

DP- Dynamic Programming

## 5. Maximum subarray problem

> Divide & Conquer

## 4. Matrix Multiplication - Strassen's Method

1. Logic

```

```

2. Algorithm

```
1. 
2. 
3. 
4. 
5. 
5. 
```

3. Time Complexity

```
O()
```

4. Resources

```
1. https://www.geeksforgeeks.org/strassens-matrix-multiplication/
2. https://en.wikipedia.org/wiki/Strassen_algorithm
```

## 3. Matrix Multiplication - D&C

1. Logic

```
Assumption : Matrices must be of order 2^n n>0
Reason : To ensure that matrix is equally divided into size n/2 as neded by algorithm
```

2. Algorithm

```
1. 
2. 
3. 
4. 
5. 
5. 
```

3. Time Complexity

```
O()
```

## 2. Matrix Multiplication - simple

1. Logic

```
Direct Formula application
```

2. Algorithm

```
1. Input the matrices.
2. Using double for loop to iterate through each element.
3. Use third for loop inside double loop to apply formula.
4. Sum of (mat1[i][k] + mat[k][j])
5. Store the sum after completion of third loop in resulatnt matrix.
5. Print the result
```

3. Time Complexity

```
O(n^3)
```

## 1. Huffman Coding Algorithm

> Greedy -

1. Logic

```
Every alphabet uses 8 bits and some are repeated more frequenty.
This algorithm assign small binary codes to more frequent alphabets thus reducing the size of total file.
```

2. Algorithm

```
1: Find character frequencies
2: Make a binary tree for each charcter which contains itself and its frquency.
3: Find two characters with minimum frequencies
4: Add their frequencies
5: Create new node and store sum of frequencies from step 4
6. Add least frequency node to left and other one to right
7. Repeat step 3-6 until there is only one tree
8: Now traverse the tree from root to leaf
9: Assign 0 to path to left subtree and 1 to right subtree
10: To obatin binarycode for a character traverse from root to the leaft node 
    contating charcter while tracing the bits along the path
11: New Binary code table is formed by repeating step 10 for all chracters

Note:
    One code cannot be prefix of any other code.
    To check if it worked correct check if  all leaf nodes are charcters.
    Time Complexity: O(nlog(n))
```

3. Use Cases / Benefits

```
1: On average saves 10-30 % size of file.
```

