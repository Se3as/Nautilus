Nautilus - Battleship Game (C++/FLTK)

Basic knowledge:

Nautilus is a modern take on the classic Battleship game, implemented in C++ using the FLTK (Fast Light Toolkit) library for graphical interface. 
This project combines strategic naval combat using search, insert and delete algorithms with an immersive underwater theme.

Features:

- Two-player turn-based gameplay

- Multiple vessel types with unique characteristics(search algoriths as weapons)

- Interactive game board with FLTK widgets

- Background music and sound effects

- Dynamic HUD showing player stats

Requirements:

- C++

- FLTK 1.3

- SDL2

- SDL2_mixer(for the rock&roll to work)

To  install the graphics libraries run these:

- sudo apt install libsdl2-dev libsdl2-mixer-dev libfltk1.3-dev

Then give permission to the compilation script with:

- chmod +x build.sh  

Now you can run the program with:

- ./build.sh

Game Controls:

Everything is based on a clickable HUD display

- START button for beggining the game

- QUIT button for exiting

- X (inside a box) button at the rights side of theboard for exiting midway


(BUTTONS FOR BOTH PLAYERS):

- MONEY: shows currenty owned money, 3 credits will be added at the beggining of each players turn

- HEALTH: when clicked, then click a vessel to show its remaining health

- DECOY: when clicked, click on the terrain to add a decoy vessel with no atack power that will be destroyed by any atack (decoys are unmovable)

- UPGRADE: when clicked, click ally vessel to upgrade atack power efficency by 30%

- SPIES: when clicked, click an enemy vessel to debuff their atack power efficency by 30%

- MOVE: when clicked, click a diferent empty terrain node on your side of the map to move the vessel to a new position

(INTERNAL PLAYING FIELD):

- GIRD OF BUTTONS: each player has a 8x6 grid in the center of the map where they can place vessels and decoys. as well as move them and click theris respective vessels on that terrain to atack

- IF ATACKED DURING OPOSITE PLAYER TURN: the atacked player vessel location will be revealed for the remaining of the enemys turn

(VESSELS DESPLAYED):

- Venture: Vessel corresponding to Linked List, value: 3 credits, click to buy.

- Typhon: Vessel corresponding to Array List, value: 4 credits, click to buy.

- Dugong: Vessel corresponding to Set, value: 5 credits, click to buy.

- Camel: Vessel corresponding to Red Black Tree, value: 6 credits, click to buy.

- Remora: Vessel corresponding to Binary Tree, value: 7 credits, click to buy.

- Winterhalter: Vessel corresponding to Splay Tree, value: 8 credits, click to buy.


Gameplay loop:

1. The game begins when PLAY is clicked
2. Player1 always moves first, each player is automatically given 12 credits and 3 actions at the beggining with 3 more credits and 3 actions being added each turn.
3. Players are free to use the interface to place vessels, decoys, upgrade, atack the enemy or themselves, or move their vessels.
4. Game ends when past turn 2 any player is left without vessels on their side of the map, or the cube X button for exiting the game is clicked.
5. when finished a postgame screen will show winning player and the QUIT button to exit entirely.

Contributors:

Juan Sebastian Loaiza Ospina
Luis Alfredo Arias
Alexander Wang Wu

Credits:

https://www.geeksforgeeks.org/
