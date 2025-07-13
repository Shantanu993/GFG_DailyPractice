<h2><a href="https://www.geeksforgeeks.org/problems/travelling-salesman-problem2732/1?page=1&difficulty=Hard&status=unsolved&sortBy=submissions">Travelling Salesman Problem</a></h2><h3>Difficulty Level : Difficulty: Hard</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given a matrix cost of size n where cost[i][j] denotes the cost of moving from city i to city j. Your task is to complete a tour from city 0 (0-based index) to all other cities such that you visit each city exactly once and then at the end come back to city 0 at minimum cost.</span></p>
<p><span style="font-size: 18px;"><strong>Examples:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input: </strong>cost = [[0, 111], [112, 0]]
<strong>Output: </strong>223
<strong>Explanation: </strong>We can visit 0-&gt;1-&gt;0 and cost = 111 + 112.</span>
</pre>
<pre><span style="font-size: 18px;"><strong>Input: </strong>cost = [[0, 1000, 5000], [5000, 0, 1000], [1000, 5000, 0]]
<strong>Output: </strong>3000
<strong>Explanation: </strong>We can visit 0-&gt;1-&gt;2-&gt;0 and cost = 1000+1000+1000 = 3000</span>
</pre>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 &lt;= cost.size() &lt;= 20<br>1 &lt;= cost[i][j] &lt;= 10<sup>3</sup></span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Microsoft</code>&nbsp;<code>Samsung</code>&nbsp;<code>Google</code>&nbsp;<code>Opera</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Matrix</code>&nbsp;<code>Dynamic Programming</code>&nbsp;<code>Bit Magic</code>&nbsp;<code>Arrays</code>&nbsp;<code>Data Structures</code>&nbsp;<code>Algorithms</code>&nbsp;