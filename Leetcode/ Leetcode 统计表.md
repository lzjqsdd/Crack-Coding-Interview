###  Leetcode 统计表

| 题号   | 题型             | 耗时   | 提交次数           | 题目难度 | 卡壳原因                                     | 日期    |
| ---- | -------------- | ---- | -------------- | ---- | ---------------------------------------- | ----- |
| 86   | TwoPointers    | 15   | 1              | M    |                                          | 04.15 |
| 109  | 链表转换为BST       | 60   | 1              | M    | 二分法传递右边界错误、指针的引用传递                       | 04.15 |
| 10   | Array转为BST     | 5    | 1              | E    |                                          | 04.15 |
| 94   | InOrder遍历      | 3    | 1              | E    | 换非递归方法遍历                                 | 04.15 |
| 144  | PreOrder遍历     | 2    | 1              | E    | 换非递归方法遍历(一分钟)                            | 04.15 |
| 105  | 根据前序和中序建树      | 50   | 1              | M    | 递归建树时使用的k应该随着左子树建立变化以访问前序的值，但是使用了非引用类型，导致左子树建立完，右子树的前序的k索引又回到了第一次建树的值 | 04.15 |
| 130  | BFS求最近的0的距离    | 60   | 3(2WA/1AC)     | M    | 距离计算错误ii+jj-i-j和abs(ii-i)+abs(jj-j)不同    | 04.15 |
| 31   | 求当前排列的下一个大的全排列 | 90   | 4(2WA/1RE/1AC) | M    | 1、题意理解错误 2、交换排列元素应该用尽可能小的来交换，而不是用相邻的。3、lower_bound和upper_bound的区别没搞明白 | 04.16 |
| 46   | 写全排列           | 30   | 1AC            | M    | 使用vector 的erase问题，每次加入前导应该在同一个基础上添加      | 04.16 |

| 题号   | 题型                                       | 耗时   | 提交次数        | 题目难度 | 卡壳原因                                     | 日期    |
| ---- | ---------------------------------------- | ---- | ----------- | ---- | ---------------------------------------- | ----- |
| 60   | 求全排列第k个元素                                | 30   | 1AC         | M    | 逆推每次选择的元素的下标                             | 04.16 |
| 200  | BFS找独立的区域的个数                             | 50   | 2(1TLE/1AC) | M    | 使用BFS应该先标记visited，再入队列。否则可能出现同一个元素因为当前并未被visited，导致多次加入队列，引起死循环 | 04.16 |
| 130  | 把被X包围的O的区域反转成X                           | 20   | 1AC         | M    | 各种语法错误                                   | 04.16 |
|      |                                          |      |             |      |                                          |       |
| 241  | 表达式多种求值 Different Ways to Add Parentheses | 20   | 1AC         | M    | 递归结果返回一个元素时应该是vector<int>(1,number)而vector<int>(n)表示是n个0, | 04.19 |
| 95   | 给出1～n可能组成的BST                            | 20   | 1AC         | M    | 边界条件                                     | 04.19 |
| 398  | 水塘采样                                     | 30   | 1AC         | M    | 知识补充                                     | 04.19 |
| 382  | 水塘采样                                     | 5    | 1AC         | M    |                                          | 04.19 |
|      |                                          |      |             |      |                                          |       |



| 547  | 朋友圈问题          | 100  | 3(2WA/1AC) | 合并过程出错 | M    | 04.20 |
| ---- | -------------- | ---- | ---------- | ------ | ---- | ----- |
| 49   | 字符串分组HashTable | 5    | 1AC        |        | M    | 04.20 |
|      |                |      |            |        |      |       |
|      |                |      |            |        |      |       |
|      |                |      |            |        |      |       |
|      |                |      |            |        |      |       |
|      |                |      |            |        |      |       |





## 未完成题目
- [ ] 10    Regular Expression Matching 
- [ ] 12    Integer to Roman   
- [ ] 25    Reverse Nodes in k-Group   
- [ ] 37    Sudoku Solver   
- [ ] 39    Combination Sum   
- [ ] 44    Wildcard Matching   
- [ ] 51    N-Queens   
- [ ] 52    N-Queens II   
- [ ] 54    Spiral Matrix   
- [ ] 59    Spiral Matrix II   
- [ ] 61    Rotate List   
- [ ] 65    Valid Number   
- [ ] 68    Text Justification   
- [ ] 71    Simplify Path   
- [ ] 76    Minimum Window Substring   
- [ ] 77	Combinations   
- [ ] 79	Word Search   
- [ ] 80	Remove Duplicates from Sorted Array II   
- [ ] 81	Search in Rotated Sorted Array II   
- [ ] 82	Remove Duplicates from Sorted List II   
- [ ] 87	Scramble String   
- [ ] 89	Gray Code   
- [ ] 90	Subsets II   
- [ ] 92	Reverse Linked List II   
- [ ] 93	Restore IP Addresses   
- [ ] 97	Interleaving String   
- [ ] 99	Recover Binary Search Tree   
- [ ] 106	Construct Binary Tree from Inorder and Postorder Traversal   	
- [ ] 114	Flatten Binary Tree to Linked List   
- [ ] 115	Distinct Subsequences   
- [ ] 116	Populating Next Right Pointers in Each Node   
- [ ] 117	Populating Next Right Pointers in Each Node II   
- [ ] 126	Word Ladder II   
- [ ] 127	Word Ladder   
- [ ] 131	Palindrome Partitioning   
- [ ] 132	Palindrome Partitioning II   
- [ ] 133	Clone Graph   
- [ ] 135	Candy   
- [ ] 138	Copy List with Random Pointer   
- [ ] 139	Word Break   
- [ ] 140	Word Break II   
- [ ] 143	Reorder List   
- [ ] 145	Binary Tree Postorder Traversal   
- [ ] 146	LRU Cache   
- [ ] 147	Insertion Sort List   
- [ ] 148	Sort List  
- [ ] 149	Max Points on a Line   
- [ ] 150	Evaluate Reverse Polish Notation   
- [ ] 162	Find Peak Element   
- [ ] 164	Maximum Gap   
- [ ] 173	Binary Search Tree Iterator   
- [ ] 174	Dungeon Game   
- [ ] 187	Repeated DNA Sequences   
- [ ] 188	Best Time to Buy and Sell Stock IV   
- [ ] 207	Course Schedule   
- [ ] 209	Minimum Size Subarray Sum   
- [ ] 210	Course Schedule II   
- [ ] 212	Word Search II   
- [ ] 214	Shortest Palindrome   
- [ ] 218	The Skyline Problem   
- [ ] 224	Basic Calculator   
- [ ] 227	Basic Calculator II   
- [ ] 230	Kth Smallest Element in a BST   
- [ ] 233	Number of Digit One   
- [ ] 235	Lowest Common Ancestor of a Binary Search Tree   
- [ ] 236	Lowest Common Ancestor of a Binary Tree   
- [ ] 239	Sliding Window Maximum   
- [ ] 264	Ugly Number II   
- [ ] 273	Integer to English Words   
- [ ] 274   H-Index   
- [ ] 275	H-Index II   
- [ ] 279	Perfect Squares   
- [ ] 282	Expression Add Operators   
- [ ] 284	Peeking Iterator   
- [ ] 295	Find Median from Data Stream   
- [ ] 297	Serialize and Deserialize Binary Tree   
- [ ] 301	Remove Invalid Parentheses   
- [ ] 304	Range Sum Query 2D - Immutable   
- [ ] 306	Additive Number   
- [ ] 307	Range Sum Query - Mutable   
- [ ] 310	Minimum Height Trees   
- [ ] 312	Burst Balloons   
- [ ] 313	Super Ugly Number   
- [ ] 315	Count of Smaller Numbers After Self   
- [ ] 319	Bulb Switcher   
- [ ] 321	Create Maximum Number   
- [ ] 322	Coin Change   
- [ ] 324	Wiggle Sort II   
- [ ] 327	Count of Range Sum   
- [ ] 328	Odd Even Linked List   
- [ ] 329	Longest Increasing Path in a Matrix   +
- [ ] 330	Patching Array   
- [ ] 331	Verify Preorder Serialization of a Binary Tree   
- [ ] 332	Reconstruct Itinerary   
- [ ] 335	Self Crossing   
- [ ] 337	House Robber III   
- [ ] 341	Flatten Nested List Iterator   
- [ ] 354	Russian Doll Envelopes   
- [ ] 355	Design Twitter   
- [ ] 363	Max Sum of Rectangle No Larger Than K   
- [ ] 365	Water and Jug Problem   
- [ ] 368	Largest Divisible Subset   
- [ ] 373	Find K Pairs with Smallest Sums   
- [ ] 375	Guess Number Higher or Lower II   
- [ ] 377	Combination Sum IV   
- [ ] 378	Kth Smallest Element in a Sorted Matrix   
- [ ] 381	Insert Delete GetRandom O(1) - Duplicates allowed   
- [ ] 385	Mini Parser   
- [ ] 386	Lexicographical Numbers   
- [ ] 388	Longest Absolute File Path   
- [ ] 390	Elimination Game   
- [ ] 391	Perfect Rectangle   
- [ ] 393	UTF-8 Validation   
- [ ] 394	Decode String   
- [ ] 395	Longest Substring with At Least K Repeating Characters   
- [ ] 399	Evaluate Division   
- [ ] 403	Frog Jump   
- [ ] 407	Trapping Rain Water II   
- [ ] 410	Split Array Largest Sum   
- [ ] 416	Partition Equal Subset Sum   
- [ ] 417	Pacific Atlantic Water Flow   
- [ ] 420	Strong Password Checker   
- [ ] 424	Longest Repeating Character Replacement   
- [ ] 432	All O`one Data Structure   
- [ ] 440	K-th Smallest in Lexicographical Order   
- [ ] 445	Add Two Numbers II   
- [ ] 446	Arithmetic Slices II - Subsequence   
- [ ] 447	Number of Boomerangs    
- [ ] 449	Serialize and Deserialize BST   
- [ ] 450	Delete Node in a BST   
- [ ] 456	132 Pattern   
- [ ] 460	LFU Cache   
- [ ] 463	Island Perimeter   
- [ ] 464	Can I Win   
- [ ] 466	Count The Repetitions   
- [ ] 467	Unique Substrings in Wraparound String   
- [ ] 468	Validate IP Address   
- [ ] 472	Concatenated Words   
- [ ] 473	Matchsticks to Square   
- [ ] 474	Ones and Zeroes   
- [ ] 475	Heaters   
- [ ] 480	Sliding Window Median   
- [ ] 481	Magical String   
- [ ] 482	License Key Formatting   
- [ ] 483	Smallest Good Base   
- [ ] 488	Zuma Game   
- [ ] 491	Increasing Subsequences   
- [ ] 492	Construct the Rectangle   
- [ ] 493	Reverse Pairs   
- [ ] 498	Diagonal Traverse   
- [ ] 500	Keyboard Row   
