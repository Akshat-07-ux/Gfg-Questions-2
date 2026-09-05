<h2><a href="https://www.geeksforgeeks.org/problems/comment-removal2017/1">Comment Removal</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO" style="--text-color: var(--problem-text-color);"><p><span style="font-size: 14pt;">Given a string <strong>s</strong> representing a piece of code, remove all comments from the code and return the modified string. The code can contain two types of comments:</span></p>
<ul>
<li><span style="font-size: 14pt;">Single-line comments: Begin with // and continue until the end of the line (\n).</span></li>
<li><span style="font-size: 14pt;">Multi-line comments: Begin with /* and end with */.</span></li>
</ul>
<p><span style="font-size: 14pt;"><strong>Note:</strong> Comments cannot be nested. The remaining code should preserve the original order of characters after removing all comments.</span></p>
<p><span style="font-size: 18px;"><strong>Examples:</strong></span></p>
<pre><span style="font-size: 18px;"><strong style="font-size: 18px;">Input: </strong><span style="font-size: 18px;">s = "#include int main(int *argc,char **argv){ // First line of code\\nprintf(\"Hello World!!! \"); return 0; }"
</span><strong style="font-size: 18px;">Output: "</strong><span style="font-size: 18px;">#include int main(int *argc,char **argv){ printf("Hello World!!! "); return 0; }"
</span><strong style="font-size: 18px;">Explanation</strong><span style="font-size: 18px;">: The comment starting with // and ending at the newline character is removed.</span></span>
</pre>
<pre><span style="font-size: 18px;"><strong>Input</strong>: s <strong>= </strong></span><span style="font-size: 18px;">"#include int main(int *argc,char **argv){ /* First line of code Printing Hello World */printf(\"Hello World!!! \"); return 0; }"</span><span style="font-size: 18px;">
<strong>Output: "</strong>#include int main(int *argc,char **argv){ printf("Hello World!!! "); return 0; }"
<strong>Explanation</strong>: Removed the commented area starting with /*<strong> </strong>and ending with */.</span>
</pre></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>BrowserStack</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Strings</code>&nbsp;