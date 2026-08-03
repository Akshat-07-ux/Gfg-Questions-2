<h2><a href="https://www.geeksforgeeks.org/problems/cba-subsequence--170645/1?page=10&category=Sorting&sortBy=submissions">Smallest Rearrangement with No "cba" Subsequence</a></h2><h3>Difficulty Level : Difficulty: Easy</h3><hr><div class="problems_problem_content__Xm_eO" style="--text-color: var(--problem-text-color);"><p><span style="font-size: 18px;">Given a string <strong>s </strong>of lowercase English letters, rearrange the characters of <strong>s </strong>such that it does not contain <strong>"cba"</strong> as a subsequence . </span></p>
<p><span style="font-size: 18px;">Among all valid rearrangements, return the lexicographically smallest one.</span></p>
<p><span style="font-size: 18px;"><strong>Examples:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input: </strong>s = "aaaaab"<strong>
Output: </strong>"aaaaab"<strong>
Explanation:</strong> The string has no subsequence "cba" and is the lexicographically smallest such arrangement.</span></pre>
<pre><span style="font-size: 18px;"><strong>Input: </strong>s = "cba"<strong>
Output: </strong>"abc"<strong>
Explanation:</strong> Rearranging as "abc" removes the "cba" subsequence, and it is the lexicographically smallest valid arrangement.</span></pre>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 ≤ n ≤ 10<sup>5</sup><br>s contains only lowercase English alphabets.</span></p></div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Strings</code>&nbsp;<code>Sorting</code>&nbsp;