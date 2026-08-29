<h2><a href="https://www.geeksforgeeks.org/problems/combine-the-strings3459/1">Combine the strings</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO" style="--text-color: var(--problem-text-color);"><p><span style="font-size: 14pt;">Given an array <strong>s[]</strong> of <strong>n </strong>strings, find the maximum length of a string obtained by combining strings from the array, where two strings can be combined only if the last character of the first string equals the first character of the second string, and&nbsp; any number of strings can be combined in a chain.</span></p>
<p><span style="font-size: 14pt;"><strong>Note</strong>: All strings considered must be of the same length and if no two strings can be combined, return 0.</span></p>
<p><span style="font-size: 14pt;"><strong>Examples:</strong></span></p>
<pre><span style="font-size: 14pt;"><strong>Input: </strong>s[] = ["RBR", "BBR", "RRR"]<strong>
Output: </strong>9<strong>
Explanation: </strong>Combined string: "BBR" + "RBR" + "RRR" -&gt; length 9.</span></pre>
<pre><span style="font-size: 14pt;"><strong>Input:</strong> s[] = ["RRR", "BBB"]<strong>
Output: </strong>0<strong>
Explanation: </strong>No two strings satisfy the combining condition.</span></pre>
<p><span style="font-size: 14pt;"><strong>Constraints:</strong><br>2 ≤ n ≤ 10<sup>4</sup><br>1 ≤ |s[i]| ≤ 100<br>s[i] contains only characters 'R' and 'B'</span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Walmart</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Strings</code>&nbsp;