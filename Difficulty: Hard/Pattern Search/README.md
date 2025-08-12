<h2><a href="https://www.geeksforgeeks.org/problems/distinct-pattern-search-1587115620/1?page=1&difficulty=Hard&status=unsolved&sortBy=submissions">Pattern Search</a></h2><h3>Difficulty Level : Difficulty: Hard</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given a string <strong>S</strong> and a pattern <strong>P</strong> consisting of lowercase characters. The task is to check if pattern P exists in the given string S or not.</span><br>&nbsp;</p>
<p><span style="font-size: 18px;"><strong>Example 1:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input:
</strong>S = abceabcdabceabcd
P = abcd
<strong>Output: </strong>Yes<strong>
Explanation: </strong>Given pattern abcd is
present at index 4.</span>
</pre>
<p><span style="font-size: 18px;"><strong>Example 2:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input:
</strong>S = abceabcdabceabcd
P = gfhij
<strong>Output: </strong>No<strong>
Explanation: </strong>Given pattern gfhij is
not found in the string.</span></pre>
<p><span style="font-size: 18px;"><strong>Your Task:</strong><br>The task is to complete the function <strong>search</strong>() which&nbsp;takes string and pattern as parameters and returns either<strong> true or false</strong>. Return true if pattern is found else return false.</span></p>
<p><span style="font-size: 18px;"><strong>Expected Time Complexity:&nbsp;</strong>O(N + M).<br><strong>Expected Auxiliary Space:&nbsp;</strong>O(1).<br>Note: N = |S|, M = |P|.</span></p>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 &lt;= |S|, |P| &lt;= 10<sup>3</sup></span></p></div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Strings</code>&nbsp;<code>Data Structures</code>&nbsp;