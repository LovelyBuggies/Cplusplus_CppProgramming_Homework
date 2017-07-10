# [STL]Maze (eden)

## Descrption
You are provided a maze(迷宫), and you need to program to find the least steps
to walk from the start to the end.And you can only walk in four directions:up,
down,left, right.



There will only be 5 kinds of characters in the maze.The meaning of each is as
followed.



"#" is for rock, which you can not walk through.



"S" is for start.



"E" is for end.



"." is for road.



"!" is for magma(岩浆),which you can not walk through.



Input

n,m represent the maze is a nxm maze.(n rows, m columnsm,0 <n,m <= 21).



Then is the maze.



e.g.

55

\#\#\#\#\#

\#S..\#

\#.!.\#

\#.\#E\#

\#\#\#\#\#







Output



You need to give the least steps to walk from start to the end.If it doesn't
exist, then output -1.

e.g.(for the example in input)

4



## Hint
(1)Use queue in STL.

(2)Use Breadth-first Search(广度优先搜索)



