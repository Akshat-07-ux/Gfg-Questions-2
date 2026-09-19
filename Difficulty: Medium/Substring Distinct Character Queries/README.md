<h2><a href="https://www.geeksforgeeks.org/problems/queries-on-strings5636/1">Substring Distinct Character Queries</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO" style="--text-color: var(--problem-text-color);"><p><span style="font-size: 18px;">Given a string <strong>s</strong> consisting of lowercase English letters and a 2D array <strong>queries[][]</strong>, where each query is represented as <strong>{l, r}</strong>, find</span><span style="font-size: 18px;">&nbsp;the number of distinct characters present in the substring <strong>s[l...r]</strong> (inclusive).</span></p>
<p><span style="font-size: 18px;">The indices l and r are 1-based.&nbsp;</span></p>
<p><span style="font-size: 18px;"><strong>Examples:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input: </strong>s = "abcbaed", queries[][] = [[1, 4], [2, 4], [1, 7]]
<strong>Output: </strong>[3, 2, 5]
<strong>Explanation: </strong></span><span style="font-size: 18px;">Query [1,4] -&gt; Substring = "abcb" -&gt; Distinct characters = [a, b, c] -&gt; 3
Query [2,4] -&gt; Substring = "bcb" -&gt; Distinct characters = [b, c] -&gt; 2
Query [1,7] -&gt; Substring = "abcbaed" -&gt; Distinct characters = [a, b, c, d, e] -&gt; 5</span></pre>
<pre><span style="font-size: 18px;"><strong>Input: </strong>s = "programming", queries[][] = [[1, 6], [3, 9], [1, 11]]<strong>
Output:</strong> [5, 5, 8]<strong>
Explanation: </strong>Query [1,6] -&gt; Substring = "progra" -&gt; Distinct characters = [p, r, o, g, a] -&gt; 5
Query [3,9] -&gt; Substring = "ogrammi" -&gt; Distinct characters = [o, g, r, a, m, i] -&gt; 6
Query [1,11] -&gt; Substring = "programming" -&gt; Distinct characters = [p, r, o, g, a, m, i, n] -&gt; 8</span></pre>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 ≤ |s| ≤ 10<sup>5</sup><br>1 ≤ No of Queries ≤ 10<sup>4</sup><br>1 ≤ l ≤ r ≤ |s|</span></p></div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Strings</code>&nbsp;<code>Prefix Sum</code>&nbsp;<code>Hash</code>&nbsp;