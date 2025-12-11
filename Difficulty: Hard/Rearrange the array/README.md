<h2><a href="https://www.geeksforgeeks.org/problems/rearrange-the-array-1639032648/1?page=2&difficulty=Hard&status=unsolved&sortBy=submissions">Rearrange the array</a></h2><h3>Difficulty Level : Difficulty: Hard</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given an sequence from 1 to N and also given an array&nbsp;<strong>arr[]</strong>&nbsp;of size&nbsp;<strong>N</strong>. Basically the array is the permutation of 1 to N which determines that the element from i<sup>th</sup>&nbsp;position should move to the j<sup>th</sup>&nbsp;position.&nbsp;Now the task is to find the minimum number of operations such that each array element is present at its original positions.</span><br><span style="font-size: 18px;">(For more understanding please go through the examples)</span></p>
<p><span style="font-size: 18px;"><strong>Note:</strong> the answer can be large, so return the answer <strong>modulo 10^9+7.</strong></span></p>
<p><span style="font-size: 18px;"><strong>Example 1:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input:</strong> N = 3, arr[] = {1,2,3}
<strong>Output:</strong> 1
</span><span style="font-size: 18px;"><strong>Explanation: </strong>
Given special arrangement <strong>arr[]</strong>: 
1 2 3
Given sequence 
1 2 3
so 1 should go 1<sup>th</sup> position, 2 should
go 2<sup>nd</sup> position and 3 should go 3<sup>rd</sup>
position. So the minimum number of operation
needed is 1.</span></pre>
<p><span style="font-size: 18px;"><strong>Example 2:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input:</strong> N = 5, arr[] = {2,3,1,5,4}
<strong>Output:</strong> 6</span>
<span style="font-size: 18px;"><strong>Explanation:
</strong>Given special arrangement arr[]:
2 3 1 5 4
Given sequence is:
1 2 3 4 5
so, here we explained one step,
1 should go to 2<sup>nd</sup> position, 2 should go 
3<sup>rd</sup> position, 3 should go 1<sup>st</sup> position, 4 
should go 5<sup>th</sup> and 5 should go 4<sup>th</sup> position. 
these are the required. So after 1st operation
new sqquence will look like 
3 1 2 5 4.
Here we explained the complete operations.
operations for the array
0. 1 2 3 4 5
1. 3 1 2 5 4
2. 2 3 1 4 5
3. 1 2 3 5 4
4. 3 1 2 4 5
5. 2 3 1 5 4
6. 1 2 3 4 5.
So after 6th operations the 
array rearrange itself to 
its original positions.</span></pre>
<p><span style="font-size: 18px;"><strong>Your Task:</strong><br>You don't need to read or print anything. Your task is to complete the function <strong>rearrange_array()&nbsp;</strong>which take&nbsp;<strong>arr[] </strong>of size <strong>N</strong> as input parameter and returns an integer which denotes the minimum number of operations needed.</span></p>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 &lt;= N &lt;= 10<sup>5</sup></span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Flipkart</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>DFS</code>&nbsp;<code>Prime Number</code>&nbsp;<code>LCS</code>&nbsp;<code>Algorithms</code>&nbsp;