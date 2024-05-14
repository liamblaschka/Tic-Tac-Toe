# Tic-Tac-Toe

## Description
C++ SFML 2 player tic tac toe game. Features include the scoreboard, the ability to play again and alternating who goes first each time, and the ability to see the previous moves using the arrow keys.

### Skills demonstrated:
- C++
- Object Oriented Programming
- SFML
- Friendly user interface design

## Instructions
### To use:
- After running, it starts as X's turn, simply click a square to make a move.
- With each move the turn will alternate.
- If you get three of your pieces in a row horizontally, vertically, or diagonally, you win.
- If all squares have been filled and no one has won, it is a draw.
- When the game is over the outcome is added to the scoreboard, the option is then presented whether to play again or exit.
- When play again is chosen, the player who goes first is alternated (if X went first last game, now O goes first).

### To build:
- Make a build directory and within it run 'cmake ..' , then when it is finished, run 'make'.
- Navigate to the bin directory within build.
- Run the 'tictactoe' executable.

## Preview
<div align="center">
  <img src="https://github.com/liamblaschka/image-repo/blob/main/Tic-Tac-Toe/X_win.png" width="332" height="350">
  <img src="https://github.com/liamblaschka/image-repo/blob/main/Tic-Tac-Toe/O_win.png" width="332" height="350">
  <img src="https://github.com/liamblaschka/image-repo/blob/main/Tic-Tac-Toe/Draw.png" width="332" height="350">
  <p>
    The three possible outcomes of a game, X wins, O wins, and draw.<br>
    The scoreboard updates with each outcome in format (X wins, Draws, O wins).<br>
    When the game is over, the user is presented with the option to play again or exit the game.
  </p>
  <br>
  <img src="https://github.com/liamblaschka/image-repo/blob/main/Tic-Tac-Toe/X_first.png" width="332" height="350">
  <img src="https://github.com/liamblaschka/image-repo/blob/main/Tic-Tac-Toe/O_first.png" width="332" height="350">
  <p>
    The turn is shown in the scoreboard where it is the underlined player's turn.<br>
    After every game, the player with the first turn alternates.
  </p>
  <br>
  <img src="https://github.com/liamblaschka/image-repo/blob/main/Tic-Tac-Toe/move_history1.png" width="332" height="350">
  <img src="https://github.com/liamblaschka/image-repo/blob/main/Tic-Tac-Toe/move_history2.png" width="332" height="350">
  <img src="https://github.com/liamblaschka/image-repo/blob/main/Tic-Tac-Toe/move_history3.png" width="332" height="350">
  <p>
    The arrow keys can be used to view the previous moves,<br>
    (left goes back one move, right goes forward, up goes to the start, down goes back to the last move).<br>
    The board is slightly faded to indicate that it is showing the previous moves.
  </p>
</div>
