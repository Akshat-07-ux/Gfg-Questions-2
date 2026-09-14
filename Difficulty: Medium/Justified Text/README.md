<h2><a href="https://www.geeksforgeeks.org/problems/justified-text/1">Justified Text</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO" style="--text-color: var(--problem-text-color);"><p><span style="font-size: 14pt;">Given an array of words <strong>words[]</strong> and a line width <strong>l</strong>, format the words such that each line has <strong>exactly</strong> l characters and is fully justified (both left and right).</span></p>
<ul>
<li><span style="font-size: 14pt;">Pack as many words as possible into each line greedily.</span></li>
<li><span style="font-size: 14pt;">Distribute extra spaces as evenly as possible between words on each line.</span></li>
<li><span style="font-size: 14pt;">If spaces cannot be distributed evenly, the left gaps get one more space than the right.</span></li>
<li><span style="font-size: 18.6667px;">The last line is <strong>left-justified</strong>, with single spaces between words and any remaining spaces added at the end.</span></li>
</ul>
<p><span style="font-size: 14pt;">Return a list of strings where each string represents one formatted line.</span></p>
<p><strong><span style="font-size: 14pt;">Examples:</span></strong></p>
<pre><span style="font-size: 14pt;"><strong>Input:</strong> words[] = ["geeksforgeeks", "is", "the", "best", "computer", "science", "portal", "for", "geeks"], l = 16
<strong>Output:</strong> ["geeksforgeeks is", "the         best", "computer science", "portal for geeks"]</span><br><span style="font-size: 14pt;"><strong>Explanation:</strong>
"geeksforgeeks is": contains 13 and 2 characters separated by 1 space.<br>"the         best": contains two words and 9 extra spaces.<br>"computer science": contains 8 and 7 characters and 1 extra space.<br>"portal for geeks":  is left-justified with single spaces.</span></pre>
<pre><span style="font-size: 14pt;"><strong>Input:</strong> words[] = ["geeks", "for", "geeks"], l = 8
<strong>Output:</strong> ["geeks   ", "for     ", "geeks   "]
<strong>Explanation:</strong> Each line contains a single word, so the remaining positions are filled with trailing spaces.</span></pre>
<p><span style="font-size: 14pt;"><strong>Constraints:</strong></span><br><span style="font-size: 14pt;">1 ≤ words.size() ≤ 10<sup>3</sup></span><br><span style="font-size: 14pt;">1 ≤ length of each word ≤ 20</span><br><span style="font-size: 14pt;">minimum word length ≤ l ≤ 100</span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Google</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Arrays</code>&nbsp;<code>Strings</code>&nbsp;<code>implementation</code>&nbsp;