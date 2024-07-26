<h2><a href="https://www.geeksforgeeks.org/problems/validate-an-ip-address-1587115621/1?page=6&sortBy=submissions">Validate an IP Address</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Write a program to Validate an IPv4 Address.<br><em>According to Wikipedia,&nbsp;<a href="http://en.wikipedia.org/wiki/IP_address">IPv4 addresses&nbsp;</a>are canonically represented in dot-decimal notation, which consists of four decimal numbers, each ranging from 0 to 255, separated by dots, e.g., 172.16.254.1 .</em><br>A<strong> valid IPv4 Address</strong> is of the form <strong>x1.x2.x3.x4</strong> where <strong>0 &lt;= (x1, x2, x3, x4) &lt;= 255</strong>.<br>Thus, we can write the generalized form of an IPv4 address as (0-255).(0-255).(0-255).(0-255).<br><strong>Note:</strong> Here we are considering numbers only from 0 to 255 and any additional <a href="https://en.wikipedia.org/wiki/Leading_zero#:~:text=A%20leading%20zero%20is%20any,for%20the%20same%20numeric%20value."><em>leading</em> <em>zeroes</em></a> will be considered invalid.</span></p>
<p><span style="font-size: 18px;">Your task is to complete the function<strong> isValid </strong>which returns 1&nbsp;if the given IPv4 address is valid else returns 0. The function takes the IPv4 address as the only argument&nbsp;in the form of string.</span></p>
<p><span style="font-size: 18px;"><strong>Examples :</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input:
</strong>IPv4 address = 222.111.111.111
<strong>Output: true</strong>
Explanation: Here, the IPv4 address is as
per the criteria mentioned and also all
four decimal numbers lies in the mentioned
range.
</span>
</pre>
<pre><span style="font-size: 18px;"><strong>Input:
</strong>IPv4 address = 5555..555
<strong>Output: false</strong><strong>
Explanation: </strong>5555..555 is not a valid
IPv4 address, as the middle two portions
are missing.</span></pre>
<p><span style="font-size: 18px;"><strong>Expected Time Complexity:</strong> O(n), n = length of the string.<br><strong>Expected Auxiliary Space:</strong>&nbsp;O(1)<br><br><strong>Constraints:</strong><br>1&lt;=length of string &lt;=20</span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Zoho</code>&nbsp;<code>Amazon</code>&nbsp;<code>Microsoft</code>&nbsp;<code>Qualcomm</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Strings</code>&nbsp;<code>Data Structures</code>&nbsp;