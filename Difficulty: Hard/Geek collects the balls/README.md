<h2><a href="https://www.geeksforgeeks.org/problems/geek-collects-the-balls5515/1?page=1&difficulty=Hard&status=unsolved&sortBy=submissions">Geek collects the balls</a></h2><h3>Difficulty Level : Difficulty: Hard</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">There are two parallel roads, each containing <strong>n</strong> and <strong>m</strong> buckets, respectively. Each bucket may contain some balls. The balls in the first road are given in an array <strong>a of size n</strong>&nbsp;and balls in the second road in an array <strong>b&nbsp;</strong></span><strong style="font-size: 18px;">of size m</strong><span style="font-size: 18px;">. The buckets on both roads are kept in such a way that they are </span><strong style="font-size: 18px;">sorted according</strong><span style="font-size: 18px;"> to the number of balls in them. Geek starts from the </span><strong style="font-size: 18px;">left side</strong><span style="font-size: 18px;"> of the road. Geek&nbsp;can change the road only at a </span><strong style="font-size: 18px;">point of intersection</strong><span style="font-size: 18px;"> i.e.&nbsp;a point where&nbsp;buckets have&nbsp;the</span><strong style="font-size: 18px;"> same number of balls</strong><span style="font-size: 18px;"> on&nbsp;two roads. Help Geek&nbsp;collect the </span><strong style="font-size: 18px;">maximum number of balls.</strong></p>
<p>&nbsp;</p>
<p><strong><span style="font-size: 18px;">Example 1:</span></strong></p>
<pre><span style="font-size: 18px;"><strong>Input:</strong> 
n = 5, m = 5
a[] = {1, 4, 5, 6, 8}
b[] = {2, 3, 4, 6, 9}
<strong>Output:</strong> 29
<strong>Explanation:</strong> The optimal way to get the 
maximum number of balls is to start from 
road 2. Get 2+3. Then switch at intersection 
point 4. Get 4+5+6. Then switch at intersection
point 6. Get 9. Total = 2+3+4+5+6+9 = 29.</span></pre>
<p><strong><span style="font-size: 18px;">Example 2:</span></strong></p>
<pre><span style="font-size: 18px;"><strong>Input:
</strong>n = 3, m = 3
a[] = {1, 2, 3}
b[] = {4, 5, 6}
<strong>Output:&nbsp;</strong>15</span>
</pre>
<p>&nbsp;</p>
<p><br><span style="font-size: 18px;"><strong>Your Task:</strong><br>You do not need to read input or print anything. Your task is to complete the function <strong>maxBalls()</strong> which takes n, m, a[] and b[] as input parameters and returns the maximum number of balls that can be collected.</span></p>
<p>&nbsp;</p>
<p>&nbsp;</p>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 ≤ n, m ≤ 10<sup>5</sup><br>1 ≤ a[i], b[i] ≤ 10<sup>9</sup>&nbsp;&nbsp;</span></p></div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Greedy</code>&nbsp;<code>Algorithms</code>&nbsp;<code>Dynamic Programming</code>&nbsp;<code>Recursion</code>&nbsp;