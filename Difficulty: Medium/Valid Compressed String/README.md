<h2><a href="https://www.geeksforgeeks.org/problems/valid-compressed-string--170647/1?page=8&category=Strings&sortBy=submissions">Valid Compressed String</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">A special compression mechanism can arbitrarily&nbsp;delete 0 or more characters and replace them with the deleted character count.<br>
Given two strings,&nbsp;<strong>S</strong>&nbsp;and <strong>T</strong> where&nbsp;S is a normal string and T is a compressed&nbsp;string,&nbsp;determine if the compressed string &nbsp;T is valid for the plaintext string S.&nbsp;<br>
<strong>Note:&nbsp;</strong>If T consists of multiple integers adjacently, consider all of them at a single number. For example T="12B32", consider T as "12" + "B" + "32".&nbsp;&nbsp;</span></p>

<p><br>
<span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:
</strong>S = "GEEKSFORGEEKS"
T = "G7G3S"
<strong>Output:
</strong>1
<strong>Explanation:</strong>
We can clearly see that T is a valid 
compressed string for S.</span>
</pre>

<p><br>
<span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:
</strong>S = "DFS"
T = "D1D"
<strong>Output :</strong>
0
<strong>Explanation:</strong>
T is not a valid compressed string.
</span></pre>

<p><br>
<span style="font-size:18px"><strong>Your Task:&nbsp;&nbsp;</strong><br>
You don't need to read input or print anything. Your task is to complete the function&nbsp;<strong>checkCompressed()</strong>&nbsp;which takes 2&nbsp;strings S&nbsp;and T as input parameters and returns integer 1 if T is a valid compression of S and&nbsp;0 otherwise.</span></p>

<p><br>
<span style="font-size:18px"><strong>Expected Time Complexity:</strong>&nbsp;O(|T|)<br>
<strong>Expected Auxiliary Space:</strong>&nbsp;O(1)</span></p>

<p><br>
<span style="font-size:18px"><strong>Constraints:</strong><br>
1 ≤ |S|&nbsp;≤ 10<sup>6</sup><br>
1 ≤ |T| ≤&nbsp;10<sup>6</sup><br>
All characters are either capital or numeric.</span></p>
</div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Facebook</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Strings</code>&nbsp;<code>Greedy</code>&nbsp;<code>Data Structures</code>&nbsp;<code>Algorithms</code>&nbsp;