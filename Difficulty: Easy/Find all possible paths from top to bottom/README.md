<h2><a href="https://www.geeksforgeeks.org/problems/find-all-possible-paths-from-top-to-bottom/1?page=2&category=Backtracking&sortBy=submissions">Find all possible paths from top to bottom</a></h2><h3>Difficulty Level : Difficulty: Easy</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 14pt;">Given a n x m matrix <strong>mat[][]</strong>. <span style="font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Roboto, Oxygen, Ubuntu, Cantarell, 'Open Sans', 'Helvetica Neue', sans-serif;">Your task is to find and return all possible paths from the top-left cell (0, 0) </span><span style="font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Roboto, Oxygen, Ubuntu, Cantarell, 'Open Sans', 'Helvetica Neue', sans-serif;">to the bottom-right cell (n-1, m-1)</span><span style="font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Roboto, Oxygen, Ubuntu, Cantarell, 'Open Sans', 'Helvetica Neue', sans-serif;">.</span></span></p>
<p data-start="543" data-end="609"><span style="font-size: 14pt;">From each cell, you can move only in the following two directions:</span></p>
<ul data-start="611" data-end="651">
<li data-start="611" data-end="631"><span style="font-size: 14pt;"> </span>
<p data-start="613" data-end="631"><span style="font-size: 14pt;">Right → (i, j+1)</span></p>
<span style="font-size: 14pt;"> </span></li>
<li data-start="632" data-end="651"><span style="font-size: 14pt;"> </span>
<p data-start="634" data-end="651"><span style="font-size: 14pt;">Down → (i+1, j)</span></p>
<span style="font-size: 14pt;"> </span></li>
</ul>
<p data-start="653" data-end="767"><span style="font-size: 14pt;">Return all possible paths, where each path is represented as a list of matrix elements encountered along the path.</span></p>
<p><span style="font-size: 18px;"><strong>Examples:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input: </strong>mat[][] = [[</span><span style="font-size: 18px;">1, 2, 3],</span>
<span style="font-size: 18px;">                [4, 5, 6]]</span>
<span style="font-size: 18px;"><strong>Output: </strong>[[</span><span style="font-size: 18px;">1, 4, 5, 6],</span>
<span style="font-size: 18px;">        [1, 2, 5, 6], </span>
<span style="font-size: 18px;">        [1, 2, 3, 6]]</span>
<span style="font-size: 18px;"><strong>Explanation: </strong>We can see that there are 3 </span>
<span style="font-size: 18px;">paths from the cell (0,0) to (1,2).</span></pre>
<pre><span style="font-size: 18px;"><strong>Input: </strong>mat[][] = [[</span><span style="font-size: 18px;">1, 2],</span>
<span style="font-size: 18px;">                [3, 4]]</span>
<span style="font-size: 18px;"><strong>Output: </strong>[[</span><span style="font-size: 18px;">1, 2, 4],</span>
<span style="font-size: 18px;">        [1, 3, 4]]<br></span><span style="font-size: 14pt;"><strong>Explanation: </strong>There are 2 possible paths from cell (0, 0)<span style="font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Roboto, Oxygen, Ubuntu, Cantarell, 'Open Sans', 'Helvetica Neue', sans-serif;"> to (1, 1)</span><span style="font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Roboto, Oxygen, Ubuntu, Cantarell, 'Open Sans', 'Helvetica Neue', sans-serif;">.</span></span></pre>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 &lt;= n, m &lt;= 10<sup>&nbsp;</sup><br>1 &lt;= mat[i][j] &lt;= n*m<br>n * m &lt; 20</span></p></div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Matrix</code>&nbsp;<code>Backtracking</code>&nbsp;<code>Data Structures</code>&nbsp;<code>Algorithms</code>&nbsp;