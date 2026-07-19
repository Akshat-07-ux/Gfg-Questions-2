<h2><a href="https://www.geeksforgeeks.org/problems/maximum-number-of-partitions-that-can-be-sorted-individually-to-make-sorted2926/1?page=9&category=Sorting&sortBy=submissions">Maximum Partitions to Make a Permutation Sorted</a></h2><h3>Difficulty Level : Difficulty: Easy</h3><hr><div class="problems_problem_content__Xm_eO" style="--text-color: var(--problem-text-color);"><p><span style="font-size: 18px;">Given an array <strong>arr[]</strong> of size <strong>n</strong> containing a <strong>permutation</strong> of integers from <strong>0</strong> to <strong>n - 1</strong>. Divide the array into contiguous partitions such that after sorting each partition individually and concatenating them in the original order, the entire array becomes sorted.</span></p>
<p><span style="font-size: 18px;">Return the <strong>maximum</strong> number of partitions that can be formed.</span></p>
<p><span style="font-size: 18px;"><strong>Examples:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input:</strong> arr[] = [2, 1, 0, 3]
<strong>Output:</strong> 2
<strong>Explanation: </strong>The array can be partitioned into [2, 1, 0] and [3]. After sorting each partition, we get [0, 1, 2] and [3]. Concatenating them results in [0, 1, 2, 3], which is sorted.
</span></pre>
<pre><span style="font-size: 18px;"><strong>Input:</strong> arr[] = [2, 1, 0, 3, 4, 5] <strong>
Output:</strong> 4 <br><strong>Explanation: </strong></span><span style="font-size: 18.6667px;">The array can be partitioned into [2, 1, 0], [3], [4], and [5]. Sorting each partition individually and concatenating them produces the sorted array [0, 1, 2, 3, 4, 5].</span></pre>
<pre><span style="font-size: 18px;"><strong>Input:</strong> arr[] = [2, 1, 0] <strong>
Output:</strong> 1<br><strong>Explanation: </strong>The entire array must be treated as a single partition. After sorting it, we obtain [0, 1, 2].</span></pre>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 ≤ arr.size() ≤ 10<sup>5</sup><sup><br></sup>0 ≤ arr[i] ≤ arr.size()-1<sup><br></sup></span></p></div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Arrays</code>&nbsp;<code>Sorting</code>&nbsp;