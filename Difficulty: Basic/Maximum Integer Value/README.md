<h2><a href="https://www.geeksforgeeks.org/problems/maximum-integer-value1434/1">Maximum Integer Value</a></h2><h3>Difficulty Level : Difficulty: Basic</h3><hr><div class="problems_problem_content__Xm_eO" style="--text-color: var(--problem-text-color);"><p class="PDq2pG_selectionAnchorContainer" data-start="33" data-end="327"><span style="font-size: 18.6667px;">Given a string s consisting of digits (<strong>0–9</strong>), insert either the '<strong>+</strong>' or '<strong>*</strong>' operator between every pair of adjacent digits. The expression is evaluated strictly from left to right, and each digit must be used exactly once in the given order.</span></p>
<p class="PDq2pG_selectionAnchorContainer" data-start="33" data-end="327"><span style="font-size: 18.6667px;">Determine the maximum possible value that can be obtained by choosing the operators optimally.</span></p>
<p><span style="font-size: 18px;"><strong>Examples :</strong></span></p>
<pre><span style="font-size: 18px;"><strong style="font-size: 18px;">Input: </strong><span style="font-size: 18px;">s</span><strong style="font-size: 18px;"> </strong><span style="font-size: 18px;">= "01230"
</span><strong style="font-size: 18px;">Output: </strong><span style="font-size: 18px;">9
</span><strong style="font-size: 18px;">Explanation: 
</strong><span style="font-size: 18px;">One optimal expression is: 0 + 1 + 2 * 3 + 0
Since the expression is evaluated strictly from left to right:
0 + 1 = 1
1 + 2 = 3
3 * 3 = 9
9 + 0 = 9
Hence, the maximum possible value is 9.</span></span></pre>
<pre><span style="font-size: 18px;"><strong style="font-size: 18px;">Input:</strong><span style="font-size: 18px;"> s = "891"
</span><strong style="font-size: 18px;">Output:</strong><span style="font-size: 18px;"> 73
</span><strong style="font-size: 18px;">Explanation:
</strong><span style="font-size: 18px;">One optimal expression is: 8 * 9 + 1
Evaluating from left to right:
8 * 9 = 72
72 + 1 = 73
Thus, the maximum possible value is 73.</span></span>
</pre>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1&nbsp;</span><span style="font-size: 18px;">≤</span><span style="font-size: 18px;"> |s|&nbsp;</span><span style="font-size: 18px;">≤</span><span style="font-size: 18px;"> 9<br></span><span style="font-size: 18px;">s contains only digits from 0 to 9<br>Leading 0's maybe present.</span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Facebook</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Strings</code>&nbsp;<code>Mathematics</code>&nbsp;