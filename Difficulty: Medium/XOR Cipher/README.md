<h2><a href="https://www.geeksforgeeks.org/problems/xor-cipher3009/1">XOR Cipher</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO" style="--text-color: var(--problem-text-color);"><p class="PDq2pG_selectionAnchorContainer" data-start="146" data-end="317"><span style="font-size: 14pt;">A hexadecimal string has been encrypted using the following XOR-based cipher. Let the original string be of length <strong>n</strong>. The encrypted string is constructed as follows:</span></p>
<ul data-start="322" data-end="678">
<li data-section-id="wrzbzm" data-start="322" data-end="426"><span style="font-size: 14pt;"> The first character of the encrypted string is the same as the first character of the original string. </span></li>
<li data-section-id="m1258l" data-start="429" data-end="676"><span style="font-size: 14pt;"> For every index i (1&nbsp;<span style="font-size: 18px;">≤</span>&nbsp;i &lt; n), the i<sup>th</sup> character of the encrypted string is obtained by performing the XOR operation on the hexadecimal values of the (i - 1)<sup>th</sup> and i<sup>th</sup> characters of the original string. </span></li>
</ul>
<p data-start="681" data-end="764"><span style="font-size: 14pt;">Given the encrypted hexadecimal string <strong>s</strong>, return the original hexadecimal string.</span></p>
<p class="PDq2pG_selectionAnchorContainer" data-start="273" data-end="350"><span style="font-size: 14pt;"> </span></p>
<p data-start="769" data-end="821" data-is-last-node=""><span style="font-size: 14pt;"><strong data-start="769" data-end="778">Note:</strong> Hexadecimal letters are uppercase (A-F).</span></p>
<p data-start="769" data-end="821" data-is-last-node=""><span style="font-size: 14pt;"><img src="https://media.geeksforgeeks.org/img-practice/prod/addEditProblem/930985/Web/Other/blobid1_1786017336.jpg" width="296" height="210"></span></p>
<p data-start="699" data-end="751">&nbsp;<span style="font-size: 18px;"><strong>Examples :</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input: </strong>s = "A171"
<strong>Output: "</strong>ABCD"
<strong>Explanation: </strong>The encrypted string is decrypted as follows:
S[0] = A
S[1] = A XOR 1 = B
S[2] = B XOR 7 = C
S[3] = C XOR 1 = D
Hence, the original hexadecimal string is "ABCD".</span></pre>
<pre><span style="font-size: 18px;"><strong>Input: </strong>s = "653CA5"
<strong>Output: "</strong>636F61"</span>
<span style="font-size: 18px;"><strong style="font-size: 18px;">Explanation: </strong><span style="font-size: 18px;">The encrypted string is decrypted as follows:
S[0] = 6
S[1] = 6 XOR 5 = 3
S[2] = 3 XOR 3 = 6
S[3] = 6 XOR C = F
S[4] = F XOR A = 6
S[5] = 6 XOR 5 = 1
Hence, the original hexadecimal string is "636F61".</span></span></pre>
<p><span style="font-size: 18px;"><strong>Constraints:<br></strong></span><span style="font-size: 18px;">1 ≤ |s| ≤ 1001<br></span><span style="font-size: 18px;">s consists of uppercase hexadecimal characters (0-9, A-F)</span></p></div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Strings</code>&nbsp;<code>Bit Magic</code>&nbsp;<code>Binary Representation</code>&nbsp;