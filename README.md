# battleship
    Battleship is an application built based on the actual battleship game(   https://en.wikipedia.org/wiki/Battleship_(game)  ), but with a few tweaks of my own! 
    The game is implemented as follows : 
    • A class form has been declared and functions have been declared as member functions. This class type has data members that hold the name of a formation, a 2D array to hold the formation and another data member ‘count’ that counts the number of wins and losses the computer has had with that formation.
    • accept 1( ) and accept2( ) are functions that have been incorporated in the program to enable the end user to input the positions of their ships and the positions they wish to attack.
    • createuser() is a function that initialises all the contents of the array user[0] (user is a 2d array) with ‘x’.
    • bg() is a function that displays the background on the output screen
    • ctos() is a function that converts a char data type into a string data type
    • user_disp() prints the user’s formation on the first gird. If a position has been picked by the computer it appears red, or else it will be green.
    • check() ensures that a position entered by the user is in accordance with a set of constraints
    • input(), input1() and input2() allow the user to place their ships on their grid
    • Before the ship is placed save_check() checks if the ship does not cross the borders of the grid or does not lie on top of another ship and then saves the positions in user[0] array
    • pc_store() reads the file pc_form.DAT to find the formation that has the most number of wins. It stores this formation in pc[0 (pc is a 3D array).
    • part1() repeatedly calls input(),input1(),input2() and save_check() for each ship. It also calls pc_store()
    • “lives” is a structure that holds the number of lives each ship has. This life value of a ship of one user is reduced each time the opponent picks a position that contains that ship.
    • pc_disp() constantly displays those positions the user has attacked on the second grid
    • user_move() asks the user to attack a position on the computer’s grid. It also gives the required output the user successfully hit a ship or not.
    • pc_move(), scan() and gimmeames() help the computer to make a decision on which position it would like to attack
    • gameplay() constantly calls user_move() and pc_move() until either the player or the computer has won. The result of the game is displayed and also the count value of the formation the computer used is changed.

