<h2><a href="https://www.geeksforgeeks.org/problems/unusual-string-sort0405/1?page=9&category=Sorting&sortBy=submissions">Unusual String Sort</a></h2><h3>Difficulty Level : Difficulty: Easy</h3><hr><div class="problems_problem_content__Xm_eO" style="--text-color: var(--problem-text-color);"><p><span style="font-size: 18px;">Given a string <strong>s</strong> consisting of uppercase and lowercase English letters, <strong>rearrange</strong> its characters according to the following rules:</span></p>
<ul>
<li><span style="font-size: 18px;">All uppercase letters must appear in sorted (ascending lexicographical) order among themselves.</span></li>
<li><span style="font-size: 18px;">All lowercase letters must appear in sorted (ascending lexicographical) order among themselves.</span></li>
<li><span style="font-size: 18px;">The output string should alternate between uppercase and lowercase letters whenever both are available.</span></li>
<li><span style="font-size: 18px;">If one category (uppercase or lowercase) is exhausted before the other, append all remaining characters of the other category to the end of the string in sorted order.</span></li>
</ul>
<p><span style="font-size: 18px;">Return the resulting string.</span></p>
<p><span style="font-size: 18px;"><strong>Examples:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input: </strong>s = "bAwutndekWEdkd"
<strong>Output:</strong> "AbEdWddekkntuw"
<strong>Explanation</strong>: <br>The uppercase letters are A, E, W, which sort to A, E, W.
The lowercase letters are b, d, d, d, e, k, k, n, t, u, w, which are already in sorted order.
Alternating between uppercase and lowercase while both are available produces: A b E d W d.
After all uppercase letters are used, the remaining lowercase letters d e k k n t u w are appended in sorted order, resulting in: "AbEdWddekkntuw".
</span></pre>
<pre><span style="font-size: 18px;"><strong>Input</strong>: s = "AiBFR"
<strong>Output:</strong> "AiBFR"
<strong>Explanation</strong>: Letters A, B, F, R and sorted as well as letter i. </span>
</pre>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 ≤ |s| ≤ 1000</span></p></div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Strings</code>&nbsp;<code>Sorting</code>&nbsp;