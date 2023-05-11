# ASSIGNMENT QUESTION 1
# Tic Tac Toe board
"""
Given a positions of coins of player1 and player2 in a 3X3 Tic Tac Toc board,
write a program to determine if the board position is a solution and
if so identify the winner of the game. In a Tic Tac Toc problem,
if the coins in a row or column or along a diagonal is of the same
player then he has won the game. Assume that player1 uses ‘1’ as his coin
and player2 uses '2' as his coin. '0' in the board represent empty cell.
"""
tictactoe = [[1, 0, 0],
             [0, 1, 0],
             [0, 0, 1]]
if tictactoe[0][0] == tictactoe[0][1] == tictactoe[0][2] != 0 or \
        tictactoe[1][0] == tictactoe[1][1] == tictactoe[1][2] != 0 or \
        tictactoe[2][0] == tictactoe[2][1] == tictactoe[2][2] != 0 or \
        tictactoe[0][0] == tictactoe[1][0] == tictactoe[2][0] != 0 or \
        tictactoe[0][1] == tictactoe[1][1] == tictactoe[2][1] != 0 or \
        tictactoe[0][2] == tictactoe[1][2] == tictactoe[2][2] != 0 or \
        tictactoe[0][0] == tictactoe[1][1] == tictactoe[2][2] != 0 or \
        tictactoe[0][2] == tictactoe[1][1] == tictactoe[2][0] != 0:
    print("You Won")
else:
    print("Please try again!!!")
