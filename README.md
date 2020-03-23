# Ultimate Tic Tac Toe

This is an implementation of Ultimate Tic Tac Toe game in command line. I created this game as a part of High School (Class 12) Project in 2017. The project required us to use modular programming concepts to build maintainable and modifiable applications. 

Rules of the game can be found on [Wikipedia](https://en.wikipedia.org/wiki/Ultimate_tic-tac-toe):

>Each small 3 × 3 tic-tac-toe board is referred to as a local board, and the larger 3 × 3 board is referred to as the global board.
>
>The game starts with X playing wherever they want in any of the 81 empty spots. This move "sends" their opponent to its relative location. >For example, if X played in the top right square of their local board, then O needs to play next in the local board at the top right of >the global board. O can then play in any one of the nine available spots in that local board, each move sending X to a different local >board.
>
>If a move is played so that it is to win a local board by the rules of normal tic-tac-toe, then the entire local board is marked as a >victory for the player in the global board.
>
>Once a local board is won by a player or it is filled completely, no more moves may be played in that board. If a player is sent to such a >board, then that player may play in any other board.
>
>Game play ends when either a player wins the global board or there are no legal moves remaining, in which case the game is a draw.
>

This version of the game does not implement the global board victory, so when a player wins in one of the local boards, they win the game.
