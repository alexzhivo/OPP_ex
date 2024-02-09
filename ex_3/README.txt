oop1_ex03
=====================================================================
			          LEVEL EDITOR
=====================================================================

	    	     Authors: Thai Ben Hamo , Alex Zhivotovsky.
		      ID: Thai - 315218396 , Alex - 319257903.

=====================================================================
                                                             Description
===================================================================== 	 

	In this exercise we were asked to build a level editor for the game we 
	built "cat and mouse". The editor can load a level through the files and 
	if there is no existing file then it asks the user for values to prepare one 
	himself. (width and height). The program is built with the help of SFML 
	and thus allows a convenient graphical interface for the user to build the 
	levels he wants. The editor has ten buttons. One button per object that 
	can be drawn on the board, delete button, a save button and a new button 
	(for requesting new input from the user and restarting the editor).

=====================================================================
                                                           Included files
=====================================================================

the files added inside include directory:

	- Board.h
	- Button.h
	- Editor.h
	- Menu.h
	- Row.h
	- Tile.h

the files added inside resources directory:

	- cat.png
	- cheese.png
	- delete.png
	- door.png
	- gift.png
	- key.png
	- mouse.png
	- new.png
	- save.png
	- wall.png

the files added inside src directory:

	- Board.cpp
	- Button.cpp
	- Editor.cpp
	- Menu.cpp
	- Row.cpp
	- Tile.cpp
	- main.cpp

=====================================================================
                                                        Data Structures
=====================================================================

	As indicated in the instructions, we used a data structure that simulates
	a two-dimensional array with the help of the Row class that resembles 
	a vector that holds the rows in Board. Inside each Row there are n Tile 
	objects that hold a Char member that symbolizes an object in the game.

=====================================================================
                                                Algorithms worth mention
=====================================================================
	

=====================================================================
                                                             Design
=====================================================================
	
	Our program is built on the basis of the main class Editor which is 
	responsible for the Board, the Textures and the Menu. Each class
	takes care of drawing itself on the board with the help of SFML. 
	The Board holds the current level using our Row & Tile data structure. 
	The Menu holds our buttons for writing operations on the board.

=====================================================================
                                                         Known bugs
=====================================================================


=====================================================================
                                                          Comments
=====================================================================



