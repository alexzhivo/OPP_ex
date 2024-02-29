oop1_project
=====================================================================
					  Cat and Mouse Project
=====================================================================

			  Authors: Thai Ben Hamo , Alex Zhivotovsky.
		      ID: Thai - 315218396 , Alex - 319257903.

=====================================================================
                           Description
===================================================================== 	 

	In the project we will again implement the "cat and mouse" 
	game that we implemented in exercise 2. This time we will use 
	inheritance and polymorphism and we will also use the SFML 
	graphic library and its options, such as : clock, time limit, 
	collisions, sounds, different types of gifts, using the menu, 
	information display, movement speed and a different design for 
	objects.

=====================================================================
                         Included files
=====================================================================

the files added inside include directory:

	- Controller.h
	- Menu.h
	- Board.h
	- HUD.h
	- SoundManager.h
	- GraphicManager.h
	- GameObject.h
	- StaticObject.h
	- Cheese.h
	- Wall.h
	- Key.h
	- Door.h
	- Gift.h
	- LifeGift.h
	- FreezeGift.h
	- TimeGift.h
	- EnemyRemoveGift.h
	- MovingObject.h
	- Cat.h
	- Mouse.h

the files added inside resources directory:

	LEVELS:
	- Board1.txt
	- Board2.txt
	- Board3.txt

	IMAGES:
	- cat.png
	- cheese.png
	- door.png
	- exitbutton.png
	- game-logo.png
	- gift.png
	- heart.png
	- helpbutton.png
	- help-image.png
	- HUDimage.png
	- key.png
	- losescreen.png
	- menu-background.png
	- mouse-left.png
	- mouse-front.png
	- mouse-back.png
	- mouse-right.png
	- startgamebutton.png
	- wall.png
	- winscreen.png

	SOUNDS:
	- clicksound.wav
	- losesound.wav
	- levelmusic.wav
	- levelup.wav
	- loselife.wav
	- menumusic.wav
	- opendoor.wav
	- pickupcheese.wav
	- pickupenemyremove.wav
	- pickupfreeze.wav
	- pickupkey.wav
	- pickuplife.wav
	- pickuptime.wav
	- winsound.wav


the files added inside src directory:

	- main.cpp
	- Controller.cpp
	- Menu.cpp
	- Board.cpp
	- HUD.cpp
	- SoundManager.cpp
	- GraphicManager.cpp
	- GameObject.cpp
	- StaticObject.cpp
	- Cheese.cpp
	- Wall.cpp
	- Key.cpp
	- Door.cpp
	- Gift.cpp
	- LifeGift.cpp
	- FreezeGift.cpp
	- TimeGift.cpp
	- EnemyRemoveGift.cpp
	- MovingObject.cpp
	- Cat.cpp
	- Mouse.cpp

=====================================================================
                          Data Structures
=====================================================================

	We used a vector as the main data structure to store the 
	objects of the board. 

=====================================================================
                     Algorithms worth mention
=====================================================================
	
	Due to time considerations, we mainly used randomness in 
	choosing the gifts and moving the cats.

=====================================================================
                              Design
=====================================================================
	
	CONTROLLER - class responsible for game modes.
	BOARD - class responsible for the game board.
	MENU - the main menu class.
	HUD - the data presentation class (found in BOARD)
	SOUNDMANAGER - responsible for playing the sounds.
	GRAPHICMANAGER - responsible for graphic printing.
	GAMEOBJECT - base class for al the game objects in game.
	STATICOBJECT - for GIFTS,WALL,KEY,CHEESE,DOOR.
	MOVINGOBJECT - for CAT and MOUSE.
	GIFT - for FREEZEGIFT, LIFEGIFT, ENEMYREMOVEGIFT, TIMEGIFT.

=====================================================================
                            Known bugs
=====================================================================

=====================================================================
                             Comments
=====================================================================

	THINGS WE CHANGED:

	- When the phase resets because time is up, life does not return 
	to the initial state of the phase.
	The number of keys resets, the time and points return to the 
	initial state.

	- you can only get up to 3 keys.