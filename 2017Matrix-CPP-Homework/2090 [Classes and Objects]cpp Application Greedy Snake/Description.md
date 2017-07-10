# [Classes and Objects]cpp Application Greedy Snake

# Greedy Snake Game

## Introduction

You must have finished a project last semaster in SE-121(An Introduction to Software Engineering). That project is called greedy snake which is a c language project.

This time we are going to rewrite the game using OOP(object oriented programming) using c++ to finish it.

## Snake Game

Snake is a game where the player maneuvers a line which grows in length, with the line itself being a primary obstacle. There is no standard version of the game. The concept originated in the 1976 arcade game Blockade, and its simplicity has led to many implementations (some of which have the word snake or worm in the title). After a variant was preloaded on Nokia mobile phones in 1998, there was a resurgence of interest in the Snake concept as it found a larger audience.

The player controls a dot, square, or object on a bordered plane. As it moves forward, it leaves a trail behind, resembling a moving snake. In some games, the end of the trail is in a fixed position, so the snake continually gets longer as it moves. In another common scheme, the snake has a specific length, so there is a moving tail a fixed number of units away from the head. The player loses when the snake runs into the screen border, a trail, or another obstacle.

The Snake concept comes in two major variants:

In the first, which is most often a two-player game, there are multiple snakes on the playfield. Each player attempts to block the other so he or she runs into an existing trail and loses. Surround for the Atari 2600 is an example of this type. The Light Cycles segment of the Tron arcade game is a single-player version, where the other "snakes" are AI controlled.

In the second variant, a sole player attempts to eat apples by running into them with the head of the snake. Each object eaten makes the snake longer, so maneuvering is progressively more difficult. Examples: Nibbler, Snake Byte.


 
## Game Rules

Players can move up, down, left and right when playing. If the snake hit the border of the map, game over. Also, it the snake's head hit its body, it will also game over.

If the snake eat a food, it will grow up 1 of length.

You must have known this.

MAX_HEIGHT = 15

MAX_WIDTH = 15

 

## Instructions

Due to the limits of our online judge system, so we are just going to complete the main logic of the game.

Firstly, please download a executable binary file to your computer and then run the program locally. Make sure to run the program in a terminal, or it might flash out because there is isn't a "system pause" line in the code.

You will see some tips for you which is a request of your input operation.

You should first input two integers which inidicates the width and height of the map. Then you are supposed to input two integers which indicates the initial position for the snake head.

Next, you should input serval "foods". Fisrtly, input the number of foods you want to have. Then input the positions. Each position has two integers, say x and y. Note that these positions cannot be repeated and also it can not be the same position of head.

Once you finish the initialization, you can start the game by input chars 'w' for up, 's' for down, 'a' for left, 'd' for right and 'q' for quit.

 

## Requirement for coding

You are required to finish the class by yourself. There is some interfaces that are use in class GameUI, please pay attention to it.

Your first job is to analyze the GameUI code as will as the executable program. And then, start to design your classes.

 

## More

If you are interested in this game, you can improve it.

You can have a continuous operation version. You may have two snakes together as a 2P game. You may have obstacles in the map. You may have a GUI using Qt or other tools. .....

Have fun!

Source Author: *叶嘉祺*