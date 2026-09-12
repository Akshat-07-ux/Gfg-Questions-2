<h2><a href="https://www.geeksforgeeks.org/problems/mapped-string0501/1">Mapped String</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO" style="--text-color: var(--problem-text-color);"><p><span style="font-size: 18px;">Given <strong>n</strong> unique characters (in infinite supply), find the number of possible mapped strings of length <strong>n</strong>. </span><span style="font-size: 18px;">A mapped string follows following properties:</span></p>
<ul>
<li><span style="font-size: 18px;">Both left and right halves of the string contains same set of characters. </span></li>
<li><span style="font-size: 18px;">Each half contains <strong>&nbsp;n / 2 </strong>unique characters.</span></li>
<li><span style="font-size: 18px;">n is always even.</span></li>
</ul>
<p><span style="font-size: 18px;">For example: “abccba” is mapped string since the left and right halves contain unique characters and both halves contain same set of characters but "abcbcd" is not.<strong> &nbsp;</strong>As the answer can be very large, find it modulo 10<sup>9</sup> + 7.</span></p>
<p><span style="font-size: 18px;"><strong>Examples:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input</strong>: n = 2
<strong>Output:</strong>&nbsp;2&nbsp;
<strong>Explanation</strong>: Suppose two unique characters are 'a' and 'b', then there will be two mapped strings - 'aa' and 'bb'.
</span></pre>
<pre><span style="font-size: 18px;"><strong>Input: </strong>n = 4
<strong>Output:&nbsp;</strong>24
<strong>Explanation</strong>: Suppose four unique characters are 'a', 'b', 'c' and 'd' and for each pair of them there will be four mapped strings. Hence, there are total 6 pairs so 6 * 4 = 24 total mapped strings.</span></pre></div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Strings</code>&nbsp;<code>Combinatorial</code>&nbsp;