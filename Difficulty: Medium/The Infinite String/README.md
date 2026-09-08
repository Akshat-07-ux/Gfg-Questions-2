<h2><a href="https://www.geeksforgeeks.org/problems/the-infinite-string1049/1">The Infinite String</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO" style="--text-color: var(--problem-text-color);"><p class="PDq2pG_selectionAnchorContainer" data-start="113" data-end="457"><span style="font-size: 18.6667px;">Given a string <strong>str</strong> and an integer <strong>pos</strong>, construct an infinite string by repeatedly applying the following operation.</span></p>
<p class="PDq2pG_selectionAnchorContainer" data-start="113" data-end="457"><span style="font-size: 18.6667px;">In the i-th step, the current string str is concatenated with i consecutive $ characters, followed by the reverse of the current string.</span></p>
<p class="PDq2pG_selectionAnchorContainer" data-start="113" data-end="457"><span style="font-size: 18.6667px;">Formally, if the current string is str, update it as:</span></p>
<ul>
<li class="PDq2pG_selectionAnchorContainer" data-start="113" data-end="457"><span style="font-size: 18.6667px;">str = str + ('$' repeated i times) + reverse(str)</span></li>
<li class="PDq2pG_selectionAnchorContainer" data-start="113" data-end="457"><span style="font-size: 18.6667px;">The process continues indefinitely.</span></li>
</ul>
<p class="PDq2pG_selectionAnchorContainer" data-start="113" data-end="457"><span style="font-size: 18.6667px;">Find and return the character present at the 1-based position pos in the resulting infinite string.</span></p>
<p><span style="font-size: 18px;"><strong>Examples :</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input</strong>: str = "12345", pos = 3
<strong>Output: </strong>3
<strong>Explanation</strong>: A = "12345", then A[pos] is 3.
</span></pre>
<pre><span style="font-size: 18px;"><strong>Input: </strong>str = "12345", pos = 10
<strong>Output:&nbsp;</strong>2
<strong>Explanation</strong>: A = "12345$54321", then A[pos] is 2.
</span></pre>
<pre><span style="font-size: 18px;"><strong>Input: </strong>str = "abc", pos = 7
<strong>Output: </strong>a
<strong>Explanation</strong>: After the first operation: str = "abc$cba". The character at position 7 is a.</span></pre></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>National Instruments</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Mathematics</code>&nbsp;<code>Strings</code>&nbsp;<code>Recursion</code>&nbsp;