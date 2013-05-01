Game Design Document
====================

Objective
--------------------
The objective of the game is to stay alive by avoiding the enemies.

Objects
--------------------
My game will include the following "objects":
- Yoshi (playable character) - moves by the player's command
![Yoshi](/img/yoshiw2.png)
	
- Goomba (enemy) - sinks right and left
![Goomba](/img/goombaw1.png)
	
- Koopa (enemy) - sinks right and left
![Koopa](/img/koopaw1.png)
	
- Bullet Bill (enemy) - shoots from right to left or left to right
![Bullet Bill](/img/rbill.png)
	
- Kamek (enemy) - appears at a random location and shoots magic
![Kamek](/img/kamek1.png)
	
- Magic (enemy ammo) - moves at a sine motion
![magic](/img/magic.png)
	
- Coin (item) - sinks straight down
![coin](/img/coin.png)

- Heart (item) - appears at a random location
![heart](/img/heart.png)

Controls
--------------------
WASD keys are used to move up, left, down, and right respectively.

Score
--------------------
The scoring is as follows:

- 10 points for every second that passes
	
- 50 points for every coin collected
	
Life
--------------------
The player starts with three lives. He or she 
can obtain more lives by collecting five coins or a heart.
If the player touches an enemy or magic, he or she
loses a life. When a player loses all of his or her
lives, its game over.

Layout
--------------------
On the game screen, the lives, coins, and score will be
displayed on the bottom. The game will be displayed on top.
During the game, the player can press the pause button to pause.
