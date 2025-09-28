<h2><a href="https://www.geeksforgeeks.org/problems/lexicographical-smallest-string/1?page=6&category=Graph&sortBy=submissions">Lexicographical Smallest String</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given a string<strong>&nbsp;s </strong>of length <strong>N</strong>, the task is to find the lexicographically smallest string&nbsp;of minimum characters that do not exist as a substring&nbsp;in <strong>s</strong>.</span></p>
<p><strong><span style="font-size: 18px;">Example 1:</span></strong></p>
<pre><span style="font-size: 18px;"><strong>Input:</strong></span>
<span style="font-size: 18px;">s = "aabacdefghijklmnopqrstuvwxyz"</span>
<span style="font-size: 18px;"><strong>Output:</strong></span>
<span style="font-size: 18px;">ad</span>
<span style="font-size: 18px;"><strong>Explanation:</strong></span>
<span style="font-size: 18px;">All the single digit strings from [a-z] occur in the 
given string and in two character strings, strings 
{aa, ab, ac} occur but ad is not present in the given 
string.</span></pre>
<p><strong><span style="font-size: 18px;">Example 2:</span></strong></p>
<pre><span style="font-size: 18px;"><strong>Input:</strong></span>
<span style="font-size: 18px;">s = "geeksforgeeks"</span>
<span style="font-size: 18px;"><strong>Output:</strong></span>
<span style="font-size: 18px;">a</span>
<span style="font-size: 18px;"><strong>Explanation:</strong></span>
<span style="font-size: 18px;">Single digit string "a" is not present in the given 
string.</span></pre>
<p><strong><span style="font-size: 18px;">Your Task:</span></strong></p>
<p><span style="font-size: 18px;">Your task is to complete the function <strong>lexicographicalSmallestString()</strong> which takes a string <strong>s</strong> as the only argument and returns the lexicographically smallest string which is not present as the substring in the string <strong>s</strong>.</span></p>
<p><span style="font-size: 18px;"><strong>Expected Time Complexity:</strong> O(N<sup>2</sup>&nbsp;* log(N))</span></p>
<p><span style="font-size: 18px;"><strong>Expected Space Complexity:</strong> O(N<sup>2</sup>)</span></p>
<p><strong><span style="font-size: 18px;">Constraints:</span></strong></p>
<ul>
<li><span style="font-size: 18px;">1 &lt;= N &lt;= 10<sup>3</sup></span></li>
<li><span style="font-size: 18px;">String s consists of lowercase English alphabets.</span></li>
</ul></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Google</code>&nbsp;<code>Uber</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Graph</code>&nbsp;<code>BFS</code>&nbsp;<code>Data Structures</code>&nbsp;<code>Algorithms</code>&nbsp;