<h2><a href="https://www.geeksforgeeks.org/problems/frequency-of-a-substring-in-a-string/1">Frequency of a Substring in a String</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO" style="--text-color: var(--problem-text-color);"><p><span style="font-size: 18.6667px;">Given two strings <strong>s1</strong> and <strong>s2</strong>, consisting of lowercase English letters, find the number of occurrences of s2 as a substring in s1. Overlapping occurrences should also be counted.</span></p>
<p><span style="font-size: 18px;"><strong style="font-size: 18px;">Examples:</strong></span></p>
<pre><span style="font-size: 14pt;"><strong>Input: </strong>s1 = "gfggfg", s2 = "gfg"<strong>
Output: </strong>2<strong>
Explanation: </strong></span><span style="font-size: 18.6667px;">The substring "gfg" occurs in "gfggfg" starting at indices 0 and 3. Therefore, the frequency of s2 in s1 is 2.</span></pre>
<pre><span style="font-size: 14pt;"><strong>Input: </strong>s1 = "banana", s2 = "nn"<strong>
Output:</strong> 0<strong>
Explanation: </strong></span><span style="font-size: 18.6667px;">The substring "nn" does not occur anywhere in "banana". Therefore, the frequency is 0.</span></pre>
<pre><span style="font-size: 14pt;"><strong>Input:</strong> s1 = "aaaaa", s2 = "aa"<strong>
Output:</strong> 4
<strong>Explanation: </strong></span><span style="font-size: 18.6667px;">The substring "aa" occurs starting at indices 0, 1, 2, and 3. Since overlapping occurrences are also counted, the frequency is 4.</span></pre>
<p><span style="font-size: 14pt;"><strong>Constraints:</strong><br>1 ≤|s2|</span><span style="font-size: 18.6667px;">≤</span><span style="font-size: 14pt;"> |s1|≤ 10</span><sup>5</sup></p></div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Hash</code>&nbsp;<code>Strings</code>&nbsp;