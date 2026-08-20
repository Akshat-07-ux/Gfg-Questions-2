<h2><a href="https://www.geeksforgeeks.org/problems/print-kth-character-in-sorted-concatenated-substrings-of-a-string0302/1">Print kth Character</a></h2><h3>Difficulty Level : Difficulty: Hard</h3><hr><div class="problems_problem_content__Xm_eO" style="--text-color: var(--problem-text-color);"><p><span style="font-size: 18px;">Given a string <strong>s</strong> consisting of lowercase alphabetic characters, consider all <strong>unique</strong> substrings of s (i.e., no substring value is repeated, even if it occurs at multiple positions in s). Arrange these unique substrings in lexicographically sorted order, then concatenate them into a single string.</span></p>
<p><span style="font-size: 18px;">Find the<strong> k-th</strong> character (1-indexed) of this concatenated string.</span></p>
<p><span style="font-size: 18px;"><strong>Examples:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input:</strong> s = "banana", k = 10
<strong>Output:</strong> n
<strong>Explanation:</strong> The unique substrings of "banana", sorted lexicographically, are:
a, an, ana, anan, anana, b, ba, ban, bana, banan, banana, n, na, nan, nana
Concatenating them gives:
"a" + "an" + "ana" + "anan" + "anana" + "b" + "ba" + "ban" + "bana" + "banan" + "banana" + "n" + "na" + "nan" + "nana"
Tracking cumulative length as we concatenate:
"a"     -&gt; length 1  (cumulative: 1)
"an"    -&gt; length 2  (cumulative: 3)
"ana"   -&gt; length 3  (cumulative: 6)
"anan"  -&gt; length 4  (cumulative: 10)
The 10th character falls at the end of "anan", which is 'n'.
Hence, the answer is 'n'.</span></pre>
<pre><span style="font-size: 18px;"><strong>Input:</strong> s = "abcdefg", k = 10
<strong>Output:</strong> d
<strong>Explanation: </strong>Since all characters in "abcdefg" are distinct, every substring is already unique.
Sorted lexicographically, the substrings starting with 'a' come first:
a, ab, abc, abcd, abcde, abcdef, abcdefg, ...
Tracking cumulative length as we concatenate:
"a"     -&gt; length 1  (cumulative: 1)
"ab"    -&gt; length 2  (cumulative: 3)
"abc"   -&gt; length 3  (cumulative: 6)
"abcd"  -&gt; length 4  (cumulative: 10)
The 10th character falls at the end of "abcd", which is 'd'.
Hence, the answer is 'd'.</span>
</pre>
<p><strong><span style="font-size: 18px;">Constraints:</span></strong><br><span style="font-size: 18px;">1 ≤ |s| ≤ 1000<br>1 ≤ k ≤ Length of concatenated string</span></p></div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Strings</code>&nbsp;