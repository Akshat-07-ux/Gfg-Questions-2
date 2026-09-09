<h2><a href="https://www.geeksforgeeks.org/problems/archana-and-her-tricky-string2910/1">Longest Arithmetic Progression in a String</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO" style="--text-color: var(--problem-text-color);"><p><span style="font-size: 20px;">Given a string <strong>s </strong>of size <strong>n</strong>, find the longest string that can be formed by selecting characters from <strong>s</strong> such that:</span></p>
<ul>
<li><span style="font-size: 20px;">Their ASCII values are in strictly descending order and form an arithmetic progression, with a common difference of at least 1.</span></li>
<li><span style="font-size: 20px;">Among all strings achieving the maximum possible length, the one with the smallest common difference is preferred.</span></li>
<li><span style="font-size: 20px;">If multiple strings still tie after that, return the one with the highest ASCII value.</span></li>
</ul>
<p><span style="font-size: 20px;"><strong>Examples:</strong></span></p>
<pre><span style="font-size: 20px;"><strong>Input: </strong>s = "ABCPQR"<strong>
Output: </strong>"RQP"<strong>
Explanation: </strong>Both "CBA" and "RQP" are valid strings of maximum length 3, each with a common difference of 1. Since "RQP" has a higher ASCII value than "CBA", it is chosen as the answer.</span></pre>
<pre><span style="font-size: 20px;"><strong>Input: </strong>s = "ADGJPRT"<strong>
Output: </strong>"JGDA"<strong>
Explanation: </strong>"JGDA" (ASCII values of J, G, D, A form a descending arithmetic progression with common difference 3) is the longest such string that can be formed.</span></pre>
<p><span style="font-size: 20px;"><strong>Constraints:</strong><br>3&nbsp;&nbsp;≤ n&nbsp;&nbsp;≤ 10<sup>5</sup><br>A&nbsp; ≤ s[i]&nbsp; ≤ Z<br>The string contains minimum three&nbsp;different characters.</span></p></div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Strings</code>&nbsp;<code>Mathematics</code>&nbsp;<code>series</code>&nbsp;