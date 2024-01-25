oop1_ex02
=====================================================================
			        CAT AND MOUSE
=====================================================================

	    	     Authors: Thai Ben Hamo , Alex Zhivotovsky.
		      ID: Thai - 315218396 , Alex - 319257903.

=====================================================================
                                                             Description
===================================================================== 	 

In this exercise we were asked to create a terminal game simulating the "cat and mouse" game. 
the user plays with the arrow keys on the keyboard and thus controls the mouse character.
the goal of the game is to collect all the cheese in each stage and thus pass all the stages 
and finish with the highest score.
in the various stages, cats can appear that will hinder the mouse from carrying out its task.
some of the maps have gifts that when taken by the mouse will kill one of the cats on the map.
sometimes the way will be blocked by a door that can only be opened and passed through 
with a key found in map.

=====================================================================
                                                           Included files
=====================================================================

the files added inside include directory:

	- Board.h
	- Cats.h
	- Controller.h
	- io.h
	- Location.h
	- Mouse.h

the files added inside resources directory:

	- Board1.txt
	- Board2.txt
	- Board3.txt
	
	these file hold the board and the elements for each level.
	
	to add a level a "Board#.txt" #-next lvl should be added to the directory.
	and add a line: configure_file ("BoardX.txt" ${CMAKE_BINARY_DIR} COPYONLY)
	to the CMakeList.txt file inside the directory.

the files added inside src directory:

	- Main.cpp (main file for running the game)
	- Controller.cpp (controlling the game, holds the game entites,score and level controlls)
	- Board.cpp (board class holds the level with all the walls and items with utility functions)
	- Cats.cpp (cats class holding cats movements and positions on screen)
	- io.cpp (file for handle key press and cursor on screen)
	- Location.cpp (struct for position on board)
	- Mouse.cpp (mouse class is handling all the mouse movements and functions)

=====================================================================
                                                        Data Structures
=====================================================================

	all the elements that store position in game we stored inside a vector.
	each vector represents a entity position on board (cats , cheese, keys, presents).
	with the use of vectors we could easily know the current amount of entities on board,
	get position and remove/add entities to vector.

=====================================================================
                                                Algorithms worth mention
=====================================================================

Cats Movement:
	we used a random option due to due to lack of time after the mouse's turn, 
	if there are cats on the map, the cats move randomly on the map one step in a 
	possible direction. If a cat tries to move to a blocked place, its turn passes.

Cats Removal with Present:
	Here too we used a random mechanism. 
	When a mouse takes a gift a random cat disappears from the map.	

=====================================================================
                                                         Known bugs
=====================================================================

	- when Mouse Steps on Mouse He doesn't get eaten.
	- after a mouse gets eaten the cats doesn't go back to initial position.

=====================================================================
                                                          Comments
=====================================================================



