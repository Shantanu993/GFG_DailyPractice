<h2><a href="https://www.geeksforgeeks.org/problems/shortest-path-using-atmost-one-curved-edge--170647/1?page=2&difficulty=Hard&status=unsolved&sortBy=submissions">Shortest Path Using Atmost One Curved Edge</a></h2><h3>Difficulty Level : Difficulty: Hard</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given an undirected, connected graph with <strong>n</strong> vertices and <strong>m</strong> double-edges stored in <strong>edges[][]</strong> 2-D array. Each double-edge is represented by a tuple <strong>(x, y, w1, w2)</strong>, which indicates that there are two edges between vertices <strong>x</strong> and <strong>y</strong>: a straight edge with weight <strong>w1</strong> and a curved edge with weight <strong>w2</strong>.</span></p>
<p><span style="font-size: 18px;">You are given two vertices <strong>a</strong> and <strong>b</strong> and you have to go from <strong>a</strong> to <strong>b</strong> through a series of edges such that in the entire path, you can use at most 1 curved edge. Your task is to find the shortest path from <strong>a</strong> to <strong>b</strong> satisfying the above condition.</span></p>
<p><span style="font-size: 18px;"><strong>Examples</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input: </strong>n = 4, m = 4, a = 2, b = 4, edges[][] = [[1, 2, 1, 4], [1, 3, 2, 4],[1, 4, 3, 1], [2, 4, 6, 5]]
<strong>Output: </strong>2
</span><span style="font-size: 18px;"><img src="https://media.geeksforgeeks.org/img-practice/prod/addEditProblem/713968/Web/Other/blobid0_1745470590.jpg" width="292" height="258"><br><strong>Explanation:</strong>
We can follow the path 2 -&gt; 1 -&gt; 4.</span> <span style="font-size: 18px;">This gives a distance of 1+3 = 4 if we follow all straight paths. But we can take the curved path  from 1 -&gt; 4, which costs 1. This will result in a cost of 1 + 1 = 2</span>
</pre>
<pre><span style="font-size: 18px;"><strong>Input: </strong>n = 2, m = 1, a = 1, b = 2, edges = [[1, 2, 4, 1]]
<strong>Output : </strong>1
</span><img src="https://media.geeksforgeeks.org/img-practice/PROD/addEditProblem/713968/Web/Other/fcf19135-c88b-48ac-8fc4-bc46efc7ca3f_1685087926.png">
<span style="font-size: 18px;"><strong>Explanation:</strong>
Take the curved path from 1 to 2 which costs 1. </span>
</pre>
<p><br><span style="font-size: 18px;"><strong>Constraints:</strong></span></p>
<ul>
<li><span style="font-size: 18px;">1 ≤ n ≤ 10<sup>5</sup></span></li>
<li><span style="font-size: 18px;">1&nbsp;</span><span style="font-size: 18px;">≤ m </span><span style="font-size: 18px;">≤ 2 x&nbsp;</span><span style="font-size: 18px;">10</span><sup>5</sup></li>
<li><span style="font-size: 18px;">1 ≤ a, b ≤ n</span></li>
<li><span style="font-size: 18px;">1 ≤ edges[i][0], edges[i][1] ≤ n</span></li>
<li><span style="font-size: 18px;">0 ≤&nbsp;edges[i][2], edges[i][3] ≤ 10<sup>4</sup></span></li>
</ul></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Uber</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Graph</code>&nbsp;<code>Shortest Path</code>&nbsp;<code>Data Structures</code>&nbsp;<code>Algorithms</code>&nbsp;