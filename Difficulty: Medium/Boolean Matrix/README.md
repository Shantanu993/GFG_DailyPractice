<h2><a href="https://www.geeksforgeeks.org/problems/boolean-matrix-problem-1587115620/1?page=1&difficulty=Medium&status=unsolved&sortBy=submissions">Boolean Matrix</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given a boolean matrix of size RxC where each cell contains either 0 or 1, modify it such that if a matrix cell matrix[i][j] is 1 then all the cells in its i</span><sup>th</sup><span style="font-size: 18px;">&nbsp;row and j</span><sup>th</sup><span style="font-size: 18px;">&nbsp;column will become 1.</span></p>
<p><strong><span style="font-size: 18px;">Example 1:</span></strong></p>
<pre><span style="font-size: 18px;"><strong>Input:</strong>
matrix[][] = {{1, 0},
              {0, 0}}
<strong>Output: </strong>
1 1
1 0 </span>
<span style="font-size: 18px;"><strong>Explanation:</strong>
Only cell that has 1 is at (0,0) so all 
cells in row 0 are modified to 1 and all 
cells in column 0 are modified to 1.</span></pre>
<p><br><span style="font-size: 18px;"><strong>Example 2:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input:</strong>
matrix[][] = {{ 1, 0, 0},
              { 1, 0, 0},
              { 1, 0, 0},
              { 0, 0, 0}}</span>
<span style="font-size: 18px;"><strong>Output: </strong>
1 1 1
1 1 1
1 1 1
1 0 0 </span>
<span style="font-size: 18px;"><strong>Explanation:</strong>
The position of cells that have 1 in
the original matrix are (0,0), (1,0)
and (2,0). Therefore, all cells in row
0,1,2 are and column 0 are modified to 1. </span></pre>
<p><span style="font-size: 18px;"><strong>Your Task:</strong><br>You dont need to read input or print anything. Complete the function <strong>booleanMatrix()</strong> that takes the matrix as input parameter and modifies it <strong>in-place</strong>.</span></p>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 ≤ R, C ≤ 1000<br>0 ≤ matrix[i][j] ≤ 1</span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Microsoft</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Arrays</code>&nbsp;<code>Matrix</code>&nbsp;<code>Data Structures</code>&nbsp;