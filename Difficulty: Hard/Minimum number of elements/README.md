<h2><a href="https://www.geeksforgeeks.org/problems/minimum-number-of-elements-which-are-not-part-of-increasing-or-decreasing-subsequence2617/1?page=1&category=Dynamic%20Programming&difficulty=Hard&status=unsolved&sortBy=submissions">Minimum number of elements</a></h2><h3>Difficulty Level : Difficulty: Hard</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">Given an array <strong>arr </strong>of size<strong> N</strong>, the task is to make strictly increasing and strictly decreasing subsequences from the array such that each array element belongs to increasing subsequence or decreasing subsequence, but not both, or can be part of none of the subsequence. Minimize the number of elements that are not part of any of the subsequences and find the count of such elements.</span></p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input</strong>: N = 12, arr[] = {7, 8, 1, 2, 4,
                 6, 3, 5, 2, 1, 8, 7}
<strong>Output:</strong> 2
<strong>Explanation</strong>: </span>
<span style="font-size:18px">Increasing sequence can be :
           {1, 2, 4, 5, 8}.
Decreasing sequence can be :
           {7, 6, 3, 2, 1}.
So, only 2 (8, 7) elements are left 
which are not part of either of 
the subsequences<strong>.</strong></span></pre>

<div><span style="font-size:18px"><strong>Example 2:</strong></span></div>

<pre><span style="font-size:18px"><strong>Input: </strong>N = 7, arr[] = {1, 4, 2, 3, 
                       3, 2, 4}
<strong>Output: </strong>0
<strong>Explanation</strong>: 
Increasing sequence can be :
            {1, 2, 3, 4}. 
Decreasing sequence can be :
             {4, 3, 2}.</span></pre>

<p><br>
<span style="font-size:18px"><strong>Your Task:&nbsp;&nbsp;</strong><br>
You don't need to read input or print anything. Complete the function <strong><code>minCount</code>()&nbsp;</strong>which takes <strong>N</strong> and array <strong>arr </strong>as input parameters and returns the integer value<br>
<br>
<strong>Expected Time Complexity:</strong> O(<strong>N<sup>3</sup></strong>)<br>
<strong>Expected Auxiliary Space:</strong> O(<strong>N<sup>3</sup></strong>)<br>
<br>
<strong>Constraints:</strong><br>
1 ≤ N ≤ 10<sup>2</sup></span></p>
</div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Dynamic Programming</code>&nbsp;<code>Algorithms</code>&nbsp;