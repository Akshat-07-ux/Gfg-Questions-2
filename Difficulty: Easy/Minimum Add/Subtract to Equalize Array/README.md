<h2><a href="https://www.geeksforgeeks.org/problems/equalize-an-array3405/1?page=9&category=Sorting&sortBy=submissions">Minimum Add/Subtract to Equalize Array</a></h2><h3>Difficulty Level : Difficulty: Easy</h3><hr><div class="problems_problem_content__Xm_eO" style="--text-color: var(--problem-text-color);"><p><span style="font-size: 18.6667px;">Given an array <strong>arr[]</strong> of integers and an integer <strong>k</strong>, find the <strong>minimum</strong> number of operations required to make every element of the array equal. In one operation, you may pick any single element and either add k to it or subtract k from it.</span></p>
<p><span style="font-size: 18.6667px;">If it is possible to make all elements equal, return the minimum number of operations. If it is not possible, return <strong>-1</strong>.</span></p>
<p><span style="font-size: 18.6667px;"><strong>Note</strong>: The minimum number of operations will always fit in a 32-bit signed integer.</span></p>
<p><strong><span style="font-size: 18.6667px;">Examples:</span></strong></p>
<pre><span style="font-size: 14pt;"><strong style="font-size: 14pt;">Input:</strong><span style="font-size: 14pt;"> arr[] = [7, 5, 21, 17], k = 2</span><strong style="font-size: 14pt;">
Output: </strong><span style="font-size: 14pt;">13</span><strong style="font-size: 14pt;">
Explanation:<br></strong><span style="font-size: 18.6667px;">Add k to arr[1] once, changing it from 5 to 7.
Subtract k from arr[2] seven times, changing it from 21 to 7.
Subtract k from arr[3] five times, changing it from 17 to 7.
The array becomes [7, 7, 7, 7] after 1 + 7 + 5 = 13 operations, and no fewer operations can achieve this.</span></span></pre>
<pre><span style="font-size: 14pt;"><strong>Input: </strong>arr[] = [7, 5, 21, 17], k = 3<strong>
Output: </strong>-1<strong>
Explanation: </strong>It is impossible to make all elements equal.</span></pre>
<p><span style="font-size: 14pt;"><strong>Constraints:<br></strong></span><span style="font-size: 18.6667px;">1 ≤ arr.size() ≤ 10<sup>5</sup><br></span><span style="font-size: 18.6667px;">1 ≤ k, arr[i] ≤ 10<sup>4</sup></span></p></div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Mathematical</code>&nbsp;<code>Sorting</code>&nbsp;