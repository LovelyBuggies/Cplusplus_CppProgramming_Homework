//
// Maze Game
// C++
// Created by Nino on 2017/4/28.
// Copyright © Nino 2017. All rights reserved.
// 

#include <iostream>  
#include <queue>  
using namespace std;



// Maze properties
#define MAX_N 100
#define MAX_M 100
#define INF 10000

int N, M;
char maze[MAX_N][MAX_M];
int d[MAX_N][MAX_M];

enum Direction {up, down, left, right};
struct Coordinate {
    Coordinate() {}
    Coordinate(int _x, int _y) : x(_x), y(_y) {}
    int x;
    int y;
} start, goal;




// Draw maze map.
void drawMaze() {
    cin >> N >> M;   
    for (int i = 0; i < N; i++)  
        for (int j = 0; j < M; j++) {
            cin >> maze[i][j];
            if (maze[i][j] == 'S') {  
                start = Coordinate(i,j);
            }  
            if (maze[i][j] == 'E') {  
                goal = Coordinate(i,j);
            }  
        }
    // initial all distance to be INF 
    for (int i = 0; i < N; i++)  
        for (int j = 0; j < M; j++)  
            d[i][j] = INF;  
}




// BFS find the nearest
int bfs() {
    queue<Coordinate> q;
    // tourist preparation  
    q.push(start);  
    d[start.x][start.y] = 0;   
    while (true)
    {  
        // where is it now
        Coordinate current = q.front();
        q.pop();
        // where we can go
        for (int i = 0; i < 4; i++)  
        {  
          
            // push all reachable place if possible
            Coordinate reachable;
            reachable.x = current.x;
            reachable.y = current.y;

            switch(i) {
                case 0: reachable.x -= 1;
                case 1: reachable.x += 1;
                case 2: reachable.y -= 1;
                case 3: reachable.y += 1;
                default: break;
            }

            // limitation: 
            // not a magma and wall
            // within the bound
            // haven't been yet
            if (0 <= reachable.x&&reachable.x < N  && 0 <= reachable.y&&reachable.y < M)
                if(maze[reachable.x][reachable.y] != '#' && maze[reachable.x][reachable.y] != '!')
                    if(d[reachable.x][reachable.y] == INF) 
                    {
                    q.push(Coordinate(reachable.x, reachable.y));
                    d[reachable.x][reachable.y] = d[current.x][current.y] + 1;
                    // if goal is reached, return distance  
                    if(reachable.x == goal.x && reachable.y == goal.y) 
                        return d[goal.x][goal.y];  
                    } 
        }
      
        // if drived into a corner (no way to go)
        if(q.size() == 0)
            return -1;
    }
}  



// test maze
void test() {
    drawMaze(); 
    cout << bfs() << endl;  
}



int main() {
    test();
}  