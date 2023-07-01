# Ultimate Tic Tac Toe

![screenshot](screenshot.png)

Rules of the game can be found on [Wikipedia](https://en.wikipedia.org/wiki/Ultimate_tic-tac-toe) and also on this nicely illustrated website: [Math with Bad Drawings](https://mathwithbaddrawings.com/2013/06/16/ultimate-tic-tac-toe/).

This version of the game does not implement the global board victory, so when a player wins in one of the local boards, they win the game.
Also this implementation uses `system(cls)` to *clear* the screen, which only works on Windows. So unfortunately the clearing function will not work properly on other OSes.
