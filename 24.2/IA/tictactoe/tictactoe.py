"""
Tic Tac Toe Player
"""

import math, copy

X = "X"
O = "O"
EMPTY = None


def initial_state():
    """
    Returns starting state of the board.
    """
    return [[EMPTY, EMPTY, EMPTY],
            [EMPTY, EMPTY, EMPTY],
            [EMPTY, EMPTY, EMPTY]]


def player(board):
    """
    Returns player who has the next turn on a board.
    """
    count = 0

    for row in range (len(board)):
        for colum in range (len(board[row])):
            if board[row][colum] != EMPTY:
                count+=1
                
    if count%2 == 0:
        return X
    
    return O

def actions(board):
    """
    Returns set of all possible actions (i, j) available on the board.
    """
    
    possibleActions = set()
    
    for row in range (len(board)):
        for colum in range (len(board[row])):
            if board[row][colum] == EMPTY:
                possibleActions.add((row, colum))
                
    return possibleActions


def result(board, action):
    """
    Returns the board that results from making move (i, j) on the board.
    """
    if action not in actions(board):
        raise Exception("Action error!")
    
    row, colum = action
    board_copy = copy.deepcopy(board)
    
    board_copy[row][colum] = player(board)
    
    return board_copy

def verifyRow(board, player):
    
    for row in range(len(board)):
        if board[row][0] == player and board[row][1] == player and board[row][2] == player:
            return True
    
    return False

def verifyColum(board, player):
    
    for colum in range(3):
        if board[0][colum] == player and board[1][colum] == player and board[2][colum] == player:
            return True
    
    return False

def verifyDiagonals(board, player):
    
    if board[0][0] == player and board[1][1] == player and board[2][2] == player:
        return True
    
    if board[0][2] == player and board[1][1] == player and board[2][0] == player:
        return True
    
    return False

def winner(board):
    """
    Returns the winner of the game, if there is one.
    """  
    
    if verifyRow(board, X) or verifyColum(board, X) or verifyDiagonals(board, X):
        return X
    
    if verifyRow(board, O) or verifyColum(board, O) or verifyDiagonals(board, O):
        return O
            
    return EMPTY

def terminal(board):
    """
    Returns True if game is over, False otherwise.
    """
    count = 0
    for row in range (len(board)):
        for colum in range (len(board[row])):
            if board[row][colum] != EMPTY:
                count+=1
    
    if winner(board) == X or winner(board) == O or count == 9:
        return True 

    return False

def utility(board):
    """
    Returns 1 if X has won the game, -1 if O has won, 0 otherwise.
    """
    
    if winner(board) == X:
        return 1
    if winner(board) == O:
        return -1
    return 0
    
def max_value(board):
    value = -math.inf
    if terminal(board):
        return utility(board)
    
    for action in actions(board):
        value = max(value, min_value(result(board, action)))
        
    return value

def min_value(board):
    value = math.inf
    if terminal(board):
        return utility(board)
    
    for action in actions(board):
        value = min(value, max_value(result(board, action)))
        
    return value

def minimax(board):
    """
    Returns the optimal action for the current player on the board.
    """
    if terminal(board):
        return EMPTY

    elif player(board) == X:
        plays = []
        for action in actions(board):
            value = min_value(result(board, action))
            if value == 1:
                return action

            best_play = [value, action]
            plays.append(best_play)

        return sorted(plays, key=lambda x: x[0], reverse=True)[0][1]
        
    elif player(board) == O:
        plays = []
        for action in actions(board):
            value = max_value(result(board, action))
            if value == -1:
                return action

            best_play = [value, action]
            plays.append(best_play)

        return sorted(plays, key=lambda x: x[0])[0][1]

   
