<h2><a href="https://www.geeksforgeeks.org/problems/-regex-matching1145/1?page=2&difficulty=Hard&status=unsolved&sortBy=submissions">RegEx matching</a></h2><h3>Difficulty Level : Difficulty: Hard</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given a <strong>pattern</strong> string and a <strong>test</strong> string, If the pattern is preceded by a ^, the pattern(excluding the ^) will be matched with the starting position of the test string. Similarly, if it is succeded by a $, the pattern(excluding the $) will be matched with the ending position of the test string. If no such markers are present, it will be checked whether pattern is a <strong>substring</strong> of test.</span></p>
<p><span style="font-size: 18px;"><strong>Example 1:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input:
P = </strong>"^coal"
<strong>S = </strong>"coaltar"
<strong>Output</strong>:
1
<strong>Explanation:</strong>
The pattern "coal" is present at the
beginning of the string, so Output is 1.
</span></pre>
<p><span style="font-size: 18px;"><strong>Example 2:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input:
P = </strong>"tar$"
<strong>S = </strong>"coaltar"
<strong>Output</strong>:
1
<strong>Explanation:</strong> 
The pattern "tar" is present at the
end of the string, so Output is 1.</span></pre>
<p><span style="font-size: 18px;"><strong>Example 3:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input:
P = </strong>"rat"
<strong>S = </strong>"algorate"
<strong>Output</strong>:
1
<strong>Explanation:</strong>
The pattern "rat" is present as a
substring of the string S,
so Output is 1.</span></pre>
<p><span style="font-size: 18px;"><strong>Example 4:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input:
P = </strong>"abcd"
<strong>S = </strong>"efgh"
<strong>Output</strong>:
0
<strong>Explanation:</strong>
There is no substring which is equal
to P in string S, so output is 0.</span></pre>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 &lt;= |S| &lt;= 10<sup>5</sup><br>1 &lt;= |P| &lt;= 10<br>String S may contain both Uppercase and Lowercase letters.</span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Microsoft</code>&nbsp;<code>Amazon</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Strings</code>&nbsp;