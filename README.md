Ilyas Sefiani
s0244917

Explanation for every class

AbstactFactory:

-Calling the right Concrete Factory for making entities.
-Pure Virtual

Concrete Factory:

-The implemented functions for Abstract Factory.

Camera:

-Changing the world coordinates to pixel coordinates
and the reverse.

EntityModel:

-Keeps the logic parts that all the entities need.
-Getters and setters for all the entities.

Entityview:

-All the functionality to change the game representation.
-Derived class of Observer.

Game:

-Setting up the sfml window.
-The main game loop.

Highscore:

-Holds the highscores, updates them and overwrites them.

Level:

-Holds the levelMapping with every {coordinate,character}

Mapreader:

-Reads the .txt file of a map and gives the levelMapping to the Level Class.

Observer:

-Pure Virtual so we can ensure that the right view is called.
-Struct Event is made here. We use this struct to give the right
event with the correct entity causing it.


Random:

-Makes the functions to do all the random choices for the AI.

Score:

-Adds the right amount of points based on what you eat.
-Derived class of Observer.

State:

-All the different states with their corresponding implementation.
-State is a pure virtual

StateManager:

-Ensures that the right state is called in the main game loop.

Stopwatch:

-Makes the functions for getting the right deltaTime.

Subject:

-Ensures that the right entity sends the correct change for the view.
-Pure Virtual

World:

-Makes all the functions that are used to change the game from a logic
perspective. Ghost AI, PacMan movement, Eating, colliding, losing lives
and reseting the level.
