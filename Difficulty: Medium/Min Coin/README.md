<h2><a href="https://www.geeksforgeeks.org/problems/min-coin5549/1?page=3&category=Greedy&sortBy=submissions">Min Coin</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given a list of coins of <strong>distinct denominations arr</strong> and the <strong>total amount of money</strong>. Find the<strong> minimum number of coins</strong> required to make up that amount. Output<strong> -1</strong> if that money cannot be made up using given coins.<br>You may assume that there are<strong> infinite </strong>numbers of coins of each type.</span><br>&nbsp;</p>
<p><span style="font-size: 18px;"><strong>Example 1:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input: </strong>arr = [1, 2, 5], amount = 11
<strong>Output: </strong>3
<strong>Explanation: </strong>2*5 + 1 = 11. So taking 2 
denominations of 5 and 1 denomination of  
1, </span><span style="font-size: 18px;">one can make 11.</span>
</pre>
<p><span style="font-size: 18px;"><strong>Example 2:</strong></span></p>
<pre><strong><span style="font-size: 18px;">Input: </span></strong><span style="font-size: 18px;">arr = [2, 6], amount = 7
<strong>Output: </strong>-1
<strong>Explanation: </strong>Not possible to make 7 using 
denominations 2 and 6.</span>
</pre>
<p>&nbsp;</p>
<p><span style="font-size: 18px;"><strong>Your Task:</strong><br>You don't need to read or print anything. Your task is to complete the function&nbsp;<strong>MinCoin()</strong> which takes a list of denominations and amounts as input parameters and returns a minimum number of coins to make up the amount. If not possible returns -1.</span><br>&nbsp;</p>
<p><span style="font-size: 18px;"><strong>Expected Time Complexity:&nbsp;</strong>O(n*amount)<br><strong>Expected Space Complexity:&nbsp;</strong>O(amount)</span><br>&nbsp;</p>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 &lt;= number of distinct denominations&nbsp;&lt;= 100</span><br><span style="font-size: 18px;">1 &lt;= amount,<strong>arri</strong> &lt;= 10<sup>4</sup></span></p></div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Dynamic Programming</code>&nbsp;<code>Greedy</code>&nbsp;<code>Algorithms</code>&nbsp;