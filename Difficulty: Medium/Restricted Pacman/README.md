<h2><a href="https://www.geeksforgeeks.org/problems/restricted-pacman--141631/1?page=8&category=Hash&sortBy=submissions">Restricted Pacman</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 14pt;">In the game of Restricted Pacman, an infinite linear path is given. Pacman has to start at position 0 and eat as many candies as possible. In one move he can only jump a distance of either <strong>m</strong> or <strong>n</strong>. &nbsp;If <strong>m</strong> and <strong>n</strong> are coprime numbers, find how many candies will be left on the board after the game is over.<br><strong>Note:</strong> The result is always finite as after a point <strong>x</strong>&nbsp;every index in the infinite path can be visited.&nbsp;</span></p>
<p><span style="font-size: 14pt;"><strong>Examples:</strong></span></p>
<pre><span style="font-size: 14pt;"><strong>Input: </strong>m= 2, n= 5
<strong>Output:</strong> 2
<strong>Explanation:</strong> From index 0, the indices that can be visited are<br>0 + 2 = 2
0 + 2 + 2 = 4
0 + 5 = 5
0 + 2 + 2 + 2 = 6
0 + 2 + 5 = 7
0 + 2 + 2 + 2 + 2 = 8
0 + 2 + 2 + 5 = 9
0 + 5 + 5 = 10
and so on.
1 and 3 are the only indices that cannot be visited. Therefore the candies at these two positions will be left on the board. </span></pre>
<pre><span style="font-size: 14pt;"><strong>Input: </strong>m = 2, n = 7
<strong>Output:</strong> 3 <br><span style="font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Roboto, Oxygen, Ubuntu, Cantarell, 'Open Sans', 'Helvetica Neue', sans-serif;"><strong>Explanation </strong>: From index 0,the indices that can be visited are <br>0 + 2 = 2<br>0 + 2 + 2 = 4<br>0 + 2 + 2 + 2 =6<br>0 + 7 = 7<br>0 + 2 + 2 + 2 + 2 = 8<br>0 + 2 + 7 = 9<br>and so on.<br>1 ,3 and 5 are the only indices that cannot be visited .Therefore the candies at these two postions will be left on the board </span></span></pre>
<p><span style="font-size: 14pt;"><strong>Constraints:</strong><br>1 &lt; m, n ≤ 500</span></p></div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Hash</code>&nbsp;<code>Mathematical</code>&nbsp;<code>Queue</code>&nbsp;<code>Data Structures</code>&nbsp;<code>Algorithms</code>&nbsp;