<h2><a href="https://www.geeksforgeeks.org/problems/save-your-life4601/1?page=7&category=Strings&sortBy=submissions">Maximum ASCII Sum Substring</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO" style="--text-color: var(--problem-text-color);"><p><span style="font-size: large;">Given a string <strong>s</strong>, a character array <strong>a[]</strong>, and an integer array <strong>b[]</strong>, find the substring of <strong>s</strong> having the maximum sum of ASCII values of its characters.</span></p>
<p><span style="font-size: large;">For some characters, their standard ASCII values are redefined. For each index i, the character a[i] has a redefined ASCII value b[i]. For all other characters, use their standard ASCII values.</span></p>
<p><span style="font-size: 18px;"><strong>Examples:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input: </strong>s = "abcde", a[] = ['c'], b[] = [-1000]
<strong>Output: </strong>"de"
<strong>Explanation: </strong>Substring "de" has the maximum sum of ASCII value, including c decreases the sum value</span>
</pre>
<pre><span style="font-size: 18px;"><strong>Input: </strong>s = "dbfbsdbf", a[] = ['b','s'], b[] = [-100, 45]
<strong>Output: </strong>"dbfbsdbf"</span><span style="font-size: 18px;">
<strong>Explanation: </strong>Substring "dbfbsdbf</span><span style="font-size: 18px;">" has the maximum sum of ASCII value.</span></pre></div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Kadane</code>&nbsp;<code>Strings</code>&nbsp;<code>Arrays</code>&nbsp;