<h2><a href="https://www.geeksforgeeks.org/problems/shortest-unique-prefix-for-every-word/1?page=2&difficulty=Hard&status=unsolved&sortBy=submissions">Shortest Unique prefix for every word</a></h2><h3>Difficulty Level : Difficulty: Hard</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given an array of words, find all shortest unique prefixes to represent each word in the given array. Assume that no word is prefix of another.</span></p>
<p><span style="font-size: 18px;"><strong>Example 1:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input: 
</strong>N = 4
arr[] = {"zebra", "dog", "duck", "dove"}
<strong>Output: </strong>z dog du dov
<strong>Explanation: </strong>
z =&gt; zebra 
dog =&gt; dog 
duck =&gt; du 
dove =&gt; dov </span>
</pre>
<p><strong><span style="font-size: 18px;">Example 2:</span></strong></p>
<pre><span style="font-size: 18px;"><strong>Input: 
</strong>N = 3
arr[] =  {"geeksgeeks", "geeksquiz",
                       "geeksforgeeks"};
<strong>Output: </strong>geeksg geeksq geeksf
<strong>Explanation: </strong>
geeksgeeks =&gt; geeksg 
geeksquiz =&gt; geeksq 
geeksforgeeks =&gt; geeksf</span></pre>
<div><span style="font-size: 18px;"><strong>Your task:</strong></span></div>
<div><span style="font-size: 18px;">You don't have to read input or print anything. Your task is to complete the function <strong>findPrefixes()</strong> which takes the array of strings and it's size N as input and returns a list of shortest unique prefix for each word </span></div>
<div>&nbsp;</div>
<div><span style="font-size: 18px;"><strong>Expected Time Complexity:</strong> O(N*length of each word)</span></div>
<div><span style="font-size: 18px;"><strong>Expected Auxiliary Space:&nbsp;</strong>O(N*length of each word)</span></div>
<div>&nbsp;</div>
<div><span style="font-size: 18px;"><strong>Constraints:</strong></span></div>
<div><span style="font-size: 18px;">1 ≤ N, Length of each word ≤ 1000</span></div></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Microsoft</code>&nbsp;<code>Google</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Trie</code>&nbsp;<code>Advanced Data Structure</code>&nbsp;