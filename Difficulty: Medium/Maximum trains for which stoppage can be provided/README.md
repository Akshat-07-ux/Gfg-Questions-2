<h2><a href="https://www.geeksforgeeks.org/problems/maximum-trains-for-which-stoppage-can-be-provided/1?page=7&category=Hash&sortBy=submissions">Maximum trains for which stoppage can be provided</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;"><span style="font-size: 18px;">You are given a railway station with <strong>m platforms</strong> and <strong>two main tracks</strong> for <strong>non-stopping</strong> trains. You are also given a 2D array&nbsp;</span></span><strong><span style="font-size: 18px;">trains</span></strong><span style="font-size: 18px;"> of size <strong>n × 3</strong>, where <strong>train[i][0] </strong>represents the <strong>arrival </strong>time, <strong>train[i][1]</strong>&nbsp;the <strong>departure</strong> time, and <strong>train[i][2]</strong> the required platform number for the <strong>i<sup>th</sup></strong> train. </span></p>
<p><span style="font-size: 18px;">A platform can serve only one train at a time, but if a train departs at time <strong>T</strong> and another arrives at the same time <strong>T</strong>, the platform can be reused. </span><span style="font-size: 14pt;">Also note that the arrival and departure times of a train should not be the same there must be at least one unit of time during which the train actually halts at a platform.</span></p>
<p><span style="font-size: 18px;">Your have to find the maximum number of trains that can be scheduled to stop at the station without any platform conflicts.</span></p>
<p><span style="font-size: 18px;"><strong>Note: </strong>Trains&nbsp;are&nbsp;given in the&nbsp;form of {arrival time, departure time, platform Number} and the&nbsp;arrival time and departure time are represented by a 4-digit integer as 1030 will represent 10:30 and 912 will represent 09:12 (24 hour Clock).</span></p>
<p><strong><span style="font-size: 18px;">Examples:</span></strong></p>
<pre><span style="font-size: 18px;"><strong>Input</strong> : n = 6, m = 3 
Train no.|  Arrival Time |Dept. Time | Platform No.
    1    |   10:00       |  10:30    |    1
    2    |   10:10       |  10:30    |    1
    3    |   10:00       |  10:20    |    2
    4    |   10:30       |  12:30    |    2
    5    |   12:00       |  12:30    |    3
    6    |   09:00       |  10:05    |    1
<strong>Output</strong> : 5
<strong>Explanation</strong> : If train no. 1 will left to go without stoppage then 2 and 6 can easily be accommodated on platform 1. And 3 and 4 on platform 2 and 5 on platform 3.</span></pre>
<p><span style="font-size: 18px;"><strong>Constraints:<br></strong></span><span style="font-size: 18px;">1 ≤ n ≤ 10<sup>4<br></sup></span><span style="font-size: 18px;">1 ≤ m ≤ 100</span>&nbsp;</p></div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Sorting</code>&nbsp;<code>Greedy</code>&nbsp;<code>Hash</code>&nbsp;