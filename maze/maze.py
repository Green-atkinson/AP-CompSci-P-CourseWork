# Option 2: Use python ncurses to create a maze. It must be at least 10x10.
# The edges of your maze should be 'x' and the movable piece an 'o'. WASD
# should move the cursor, all other buttons should do nothing. Moving into
# an 'x' should be prevented. When the 'o' reaches the end of the maze, a 'y',
# the screen should switch to a congratulatory message. One more key press
# should end the game. Submitted in a folder <lastname>maze.zip


#lets me use the curses module & sleep
import curses
import time

#initializes a screen, stored in variable stdscr
stdscr = curses.initscr()

#prompts that put curses into the appropriate operating settings
curses.noecho()
curses.cbreak()
stdscr.keypad(True)

#add an x to the screen
stdscr.addstr(1, 1, "XXXXXXXXXX")
stdscr.addstr(2, 1, "XX  X    X")
stdscr.addstr(3, 1, "XX XXXX XX")
stdscr.addstr(4, 1, "XX  XXX XX")
stdscr.addstr(5, 1, "XXX XX   X")
stdscr.addstr(6, 1, "XXX XXXX X")
stdscr.addstr(7, 1, "X   X    X")
stdscr.addstr(8, 1, "X XXX XXXX")
stdscr.addstr(9, 1, "X     X  X")
stdscr.addstr(10, 1, "XXXXXXXXXX")

stdscr.refresh()

#x- and y- coordinates of o & y
ox = 6
oy = 2
stdscr.addch(oy, ox, 'o')

yx = 4
yy = 2
stdscr.addch(yy, yx, 'y')
stdscr.refresh()

#start the maze
user_input = stdscr.getch()
while user_input != ord('q'):

    #move down
    if user_input == ord('s') and chr(stdscr.inch(oy + 1, ox)) != 'X' and oy + 1 < 11:
        stdscr.addch(oy, ox, ' ')
        oy += 1
        stdscr.addch(oy, ox, 'o')
        stdscr.refresh()

    #move up
    if user_input == ord('w') and chr(stdscr.inch(oy - 1, ox)) != 'X' and oy - 1 < 11:
        stdscr.addch(oy, ox, ' ')
        oy -= 1
        stdscr.addch(oy, ox, 'o')
        stdscr.refresh()

    #move left
    if user_input == ord('a') and chr(stdscr.inch(oy, ox - 1)) != 'X' and ox - 1 < 11:
        stdscr.addch(oy, ox, ' ')
        ox -= 1
        stdscr.addch(oy, ox, 'o')
        stdscr.refresh()

    #move right
    if user_input == ord('d') and chr(stdscr.inch(oy, ox + 1)) != 'X' and ox + 1 < 11:
        stdscr.addch(oy, ox, ' ')
        ox += 1
        stdscr.addch(oy, ox, 'o')
        stdscr.refresh()

    #win the game, get o to touch y
    if oy == yy and ox == yx:
        stdscr.clear()
        stdscr.refresh()
        print("CONGRADULATIONS, YOU WON!")

    #asks for the next move from user
    stdscr.refresh()
    user_input = stdscr.getch()

#end program
curses.endwin()