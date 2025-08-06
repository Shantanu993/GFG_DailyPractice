<h2><a href="https://www.geeksforgeeks.org/problems/longest-path-in-a-matrix3019/1?page=1&difficulty=Hard&status=unsolved&sortBy=submissions">Longest Path in a matrix</a></h2><h3>Difficulty Level : Difficulty: Hard</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given a matrix, find the maximum length path (starting from any cell) such that all cells along the path are in strictly increasing order.<br></span><span style="font-size: 18px;">We can move in 4 directions from a given cell (i, j), i.e., we can move to (i+1, j) or (i, j+1) or (i-1, j) or (i, j-1).</span><br>&nbsp;<br><span style="font-size: 18px;"><strong>Examples :</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input: </strong>matrix[][] = [[1,2,9],[5,3,8],[4,6,7]]
<strong>Output: </strong>7
<strong>Explanation: </strong>The longest increasing path is [1,2,3,6,7,8,9].</span>
</pre>
<pre><span style="font-size: 18px;"><strong>Input: </strong>matrix[][] = [[3,4,5],[3,2,6],[2,2,1]]
<strong>Output: </strong>4
<strong>Explanation: </strong>The longest increasing path is [3,4,5,6].<br></span></pre>
<pre><strong>Input: </strong>matrix[][] = [[3,2,1,4,9,10,8,6,7],[10,5,1,5,10,2,6,7,5],[2,5,6,2,4,6,10,10,7]]
<strong>Output: </strong>4</pre>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 &lt;= matrix.size(), matrix[0].size() &lt;= 1000<br>1 &lt;= matrix[i][j] &lt;= 10<sup>3</sup></span></p></div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Dynamic Programming</code>&nbsp;<code>Algorithms</code>&nbsp;