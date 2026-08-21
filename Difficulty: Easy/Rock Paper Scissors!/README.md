<h2><a href="https://www.geeksforgeeks.org/problems/rock-paper-scissors2830/1">Rock Paper Scissors!</a></h2><h3>Difficulty Level : Difficulty: Easy</h3><hr><div class="problems_problem_content__Xm_eO" style="--text-color: var(--problem-text-color);"><p><span style="font-size: 18px;">Two players, <strong>a</strong> and <strong>b</strong>, are playing a series of Rock-Paper-Scissors games. </span></p>
<ul>
<li><span style="font-size: 18px;">Player a's and b's moves are given by strings <strong>a</strong> and <strong>b </strong>respectively. </span></li>
<li><span style="font-size: 18px;">Each character in the strings is one of 'R', 'P', or 'S', representing Rock, Paper, and Scissors respectively.</span></li>
<li><span style="font-size: 18px;">A total of <strong>k</strong> games are played. In the <strong>i-th</strong> game, each player uses the next character from their respective string. </span></li>
<li><span style="font-size: 18px;">If a player reaches the end of their string, they continue again from the beginning of the same string.</span></li>
</ul>
<p><span style="font-size: 18px;">The winner of a game is determined using the standard Rock-Paper-Scissors rules:</span></p>
<ul>
<li><span style="font-size: 18px;">Rock defeats Scissors.</span></li>
<li><span style="font-size: 18px;">Scissors defeats Paper.</span></li>
<li><span style="font-size: 18px;">Paper defeats Rock.</span></li>
</ul>
<p><span style="font-size: 18px;">If both players choose the same move, the game is considered a <strong>draw</strong>.</span></p>
<p><span style="font-size: 18px;">Given the strings <strong>a</strong>, <strong>b</strong>, and an integer <strong>k</strong>, find the number of games won by each player after <strong>exactly k</strong>&nbsp;games have been played.</span></p>
<p><span style="font-size: 18px;"><strong>Examples:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input: </strong>a = "RPS", b = "SR", k = 7
<strong>Output:</strong> [3, 2]
<strong>Explanation</strong>: Since the strings are used cyclically, the sequence of moves played is (R,S), (P,R), (S,S), (R,R), (P,S), (S,R), and (R,S). Player A wins the 1st, 2nd, and 7th games, while Player B wins the 5th and 6th games. <br>The 3rd and 4th games end in a draw. Hence, Player A wins 3 games and Player B wins 2 games.</span>
</pre>
<pre><span style="font-size: 18px;"><strong>Input</strong>: a = "RP", b = "SRS", k = 8
<strong>Output:</strong> [5, 2]
<strong>Explanation</strong>: The strings repeat after reaching their ends, producing the sequence of games (R,S), (P,R), (R,S), (P,S), (R,R), (P,S), (R,S), and (P,R). <br>Player A wins the 1st, 2nd, 3rd, 7th, and 8th games, while Player B wins the 4th and 6th games. <br>The 5th game is a draw. Therefore, Player A wins 5 games and Player B wins 2 games.</span>
</pre>
<p><span style="font-size: 18px;"><strong style="font-size: 18px;">Constraints:</strong><br><span style="font-size: 18px;">1 ≤ |a|, |b| ≤ 10<sup>3</sup></span><br><span style="font-size: 18px;">1&nbsp;</span></span><span style="font-size: 18px;">≤ </span><span style="font-size: 18px;">k </span><span style="font-size: 18px;">≤ 10<sup>9</sup></span></p></div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Strings</code>&nbsp;