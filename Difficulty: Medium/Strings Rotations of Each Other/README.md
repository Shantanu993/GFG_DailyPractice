<h2><a href="https://www.geeksforgeeks.org/problems/check-if-strings-are-rotations-of-each-other-or-not-1587115620/1?page=1&difficulty=Medium&status=unsolved&sortBy=submissions">Strings Rotations of Each Other</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">You are given two strings of equal lengths,&nbsp;<strong>s1 </strong>and&nbsp;<strong>s2</strong>. The task is to check&nbsp;if&nbsp;<strong>s2</strong>&nbsp;is a rotated version of the string&nbsp;<strong>s1</strong>.</span></p>
<p><span style="font-size: 18px;"><strong>Note:</strong>&nbsp;The characters in the strings are in lowercase.</span></p>
<p><span style="font-size: 18px;"><strong>Examples :</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input: </strong>s1 = "geeksforgeeks", s2 = "forgeeksgeeks"
<strong>Output: </strong>true<strong>
Explanation: </strong>s1 is geeksforgeeks, s2 is forgeeksgeeks. Clearly, s2 is a rotated version of s1 as s2 can be obtained by left-rotating s1 by 5 units.</span>
</pre>
<pre><span style="font-size: 18px;"><strong>Input: </strong>s1 = "mightandmagic", s2 = "andmagicmigth"
<strong>Output: </strong>false<strong>
Explanation: </strong>Here with any amount of rotation s2 can't be obtained by s1.</span></pre>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 &lt;= s1.size(), s2.size() &lt;= 10<sup>5</sup></span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Oracle</code>&nbsp;<code>Adobe</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Strings</code>&nbsp;<code>Data Structures</code>&nbsp;