<h2><a href="https://www.geeksforgeeks.org/problems/remove-leading-zeros-from-an-ip-address3530/1">Leading Zeros in IP Address Style String</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO" style="--text-color: var(--problem-text-color);"><p><span style="font-size: 18px;">Given a IP address style string string <strong>s</strong>, remove all leading <strong>zeros </strong>from each numeric segment. </span><span style="font-size: 18px;">Unlike a standard IP address, the segments in s:</span></p>
<ul>
<li><span style="font-size: 18px;">may contain values greater than <strong>255</strong></span></li>
<li><span style="font-size: 18px;">may be fewer or more than <strong>4</strong> in number</span></li>
</ul>
<p><span style="font-size: 18px;">Return the <strong>normalized </strong>IP address after removing leading zeros from every segment.</span></p>
<p><span style="font-size: 18px;"><strong>Example :</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input: </strong>s = "100.020.003.400"
<strong>Output:</strong> 100.20.3.400</span><span style="font-size: 18px;">
<strong>Explanation:</strong> The leading zeros are removed from 20 and 3.</span>
</pre>
<pre><span style="font-size: 18px;"><strong>Input:</strong> s = "100.000.010.0999"
<strong>Output:</strong> 100.0.10.999
<strong>Explanation:</strong> The leading zeros are removed from 0, 10 and 999.</span>
</pre>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 ≤ |s| ≤ 10<sup>5</sup></span></p></div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Strings</code>&nbsp;