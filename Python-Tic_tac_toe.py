
def print_board(board): 
    print(f"{board['top-l']}|{board['top-m']}|{board['top-r']} ")   #print a nice board
    print("-+--+-")
    print(f"{board['mid-l']}|{board['mid-m']}|{board['mid-r']} ")
    print("-+--+-")
    print(f"{board['low-l']}|{board['low-m']}|{board['low-r']} ")

def check_winner(br, turn):
  if (br['top-r'] ==turn and br['top-m'] == turn and br['top-r']== turn) or \
  (br['mid-r'] ==turn and br['mid-m'] == turn and br['low-r']== turn) or \
  (br['low-r'] ==turn and br['low-m'] == turn and br['low-r']== turn) or \
  (br['top-r'] ==turn and br['mid-r'] == turn and br['low-r']== turn) or \
  (br['top-m'] ==turn and br['mid-m'] == turn and br['low-m']== turn) or \
  (br['top-l'] ==turn and br['mid-l'] == turn and br['low-l']== turn) or \
  (br['top-l'] ==turn and br['mid-m'] == turn and br['low-r']== turn) or \
  (br['top-l'] ==turn and br['mid-m'] == turn and br['low-r']== turn):
    print("\n****** YOU WIN *******")
    return True


the_board = {'top-l': '?', 'top-m': '?', 'top-r': '?', 
'mid-l': '?', 'mid-m': '?', 'mid-r': '?', 
'low-l': '?', 'low-m': '?', 'low-r': '?'}

print("******TIC TAC TOE *******\n")

turn = 'X'
for i in range(10):      #repeat 9 times
    print_board(the_board)
    print(f"\nNow is {turn}'s turn. What's your move? (Example: top-l , mid-m, low-r ")
    print("Press 'q' to quit at any time.")
    move = input().lower().rstrip()     #turn lowercase and erase spaces 

    if move == 'q': 
        break
    if move not in the_board.keys():     #validate user's input. 
      print("***That's not a valid move***. Try again.\n")
      continue
    the_board[move] = turn
    win = check_winner(the_board, turn)  #check if there's a winner
    if win == True: 
      break
  
    if turn == 'X':      #change turn
        turn = 'O'
    else: 
        turn ='X'


print_board(the_board)


