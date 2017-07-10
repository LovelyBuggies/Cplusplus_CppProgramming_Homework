# [Inheritance] Game Object

## Descrption
In this problem, you should complete some classes.  
You can see more details in sample input / output and main.cpp  
Each gameobject will have position,speed, and 10HP.  
When you select a gameobject, we will hear it's voice.You should print this
voice.  
When you select a worker, you will hear "Scv good to go, sir!"  
When you select a zealot, you will hear "My life for Aiur!"  
When you select a tower, you will hear nothing, and you can replace it by a
"~"  
We describe the speed as a vector  (dx, dy)  
For the three gameobjects, they are (1, 1) (2, 2) and (0, 0). (Tower cannot
move.)  
When a object moves, you should print where he moves to.  
Zealot and tower can attack other objects and their damages are 1.  
Worker can repair an object.  
When worker build a building, you should print a triangle by '*' with
different height.  
For example, if the worker build a building with 3 you should print  
```
  *
 ***
*****
```

## Sample Input
```
1 1  
2 2  
3 3  
4
```

## Sample Output  
```
test for select:  
Scv good to go, sir!  
My life for Aiur  
~

test for move:  
Worker moves to (2, 2)  
Zealot moves to (4, 4)  
Tower cannot move

test for attack:  
Zealot's hp is 9  
Tower's hp is 9

test for repair:  
Zealot's hp is 10

test for build:  
   *
  ***
 *****
*******
```
## Hint
高度为3的三角形，第一层为2个空格和一个*，第二层为1个空格和三个*，第三层为5个*。（行末无空格）

 关于move函数，对于原本在(x,y)的对象，移动到(x+dx, y+dy)

`repair`和`attack`参数为`gameobject*`    

*出题人：王毅峰*