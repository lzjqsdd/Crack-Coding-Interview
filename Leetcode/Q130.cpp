//给定一个棋盘格，'O'和'X'组成,找出'O'被X包围的区域。然后把该区域的'O'替换成'X';
// X X X X
// X O O X
// X X O X
// X O X X

//思路：BFS,UnionFind


//为什么选择并查集：如果应用场景只关注联通性，而不关注连通的路径问题，并查集可以处理，不需要记录其路径。否则使用比如 DFS 或者 BFS
//并查集几个关键步骤：
// make_set
// find_set
// union_set
// 为什么使用树的结构？而不是给每个节点分配组号。
// 结构包括：data,rank,parent. 