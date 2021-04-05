#include<bios.h>
#include<dos.h>
#include<process.h>
#include"battlesh.cpp"
#include"mouse.cpp"
#include<stdlib.h>
#include"checkSquare.cpp"
int jambu, rememberx = -1, remembery = -1, x, y;
struct lives
{
	int 	s;
	int 	d;
	int 	b;
	int 	c;
} u, p;

void pc_disp()
{
	for (int j = 0, x = 320; j < 8; j++)
	{
		for (int i = 0, y = 150; i < 8; i++)
		{
			if (pc[1][i][j] == 'x')  setcolor(GREEN);
			else setcolor(RED);
			outtextxy(x + 5, y + 5, ctos(pc[1][i][j]));
			y += 20;
		}
		x += 20;
	}
}

void pc_move()
{
	randomize();
	int sathu;
	if (((u.s == 0) || (u.s == 2)) && ((u.c == 0) || (u.c == 5)) && ((u.d == 0) || (u.d == 3
	                                                                               )) && ((u.b == 0) || (u.b == 4)))
	{
		do
		{
			sathu = random(64);
		} while (user[1][0][sathu] != '\0');
		x = sathu / 8;
		y = sathu % 8;
	}
	else
	{
		scan(x, y);
		if (x == 0 && y == 0)
		{
			if (user[1][1][0] == '\0' && user[1][0][1] == '\0')
			{
				if (random(2)) { x = 1; y = 0;}
				else {x = 0; y = 1;}
			}
			else if (user[1][1][0] == '\0' && user[1][0][1] != user[1][0][0])
			{
				x += 1;
			}
			else if (user[1][0][1] == '\0' && user[1][1][0] != user[1][0][0])
			{
				y += 1;
			}
			else if (user[1][1][0] == user[1][0][0])
			{
				do
				{
					x += 1;
				} while (user[1][x][y] == user[1][0][0]);
			}
			else if (user[1][0][1] == user[1][0][0])
			{
				do
				{
					y += 1;
				} while (user[1][x][y] == user[1][0][0]);
			}
		}
		else if (x == 7 && y == 0)
		{
			if (user[1][6][0] == '\0' && user[1][7][1] == '\0')
			{
				if (random(2)) { x = 6; y = 0;}
				else {x = 7; y = 1;}
			}
			else if (user[1][6][0] == '\0' && user[1][7][1] != user[1][7][0])
			{
				x -= 1;
			}
			else if (user[1][7][1] == '\0' && user[1][6][0] != user[1][7][0])
			{
				y += 1;
			}
			else if (user[1][6][0] == user[1][7][0])
			{
				do
				{
					x -= 1;
				} while (user[1][x][y] == user[1][7][0]);
			}
			else if (user[1][7][1] == user[1][7][0])
			{
				do
				{
					y += 1;
				} while (user[1][x][y] == user[1][7][0]);
			}
		}
		else if (x == 0 && y == 7)
		{
			if (user[1][1][7] == '\0' && user[1][0][6] == '\0')
			{
				if (random(2)) { x = 1; y = 7;}
				else {x = 0; y = 6;}
			}
			else if (user[1][1][7] == '\0' && user[1][0][6] != user[1][0][7])
			{
				x += 1;
			}
			else if (user[1][0][6] == '\0' && user[1][1][7] != user[1][0][7])
			{
				y -= 1;
			}
			else if (user[1][1][7] == user[1][0][7])
			{
				do
				{
					x += 1;
				} while (user[1][x][y] == user[1][0][7]);
			}
			else if (user[1][0][6] == user[1][0][7])
			{
				do
				{
					y -= 1;
				} while (user[1][x][y] == user[1][0][7]);
			}
		}
		else if (x == 7 && y == 7)
		{
			if (user[1][6][7] == '\0' && user[1][7][6] == '\0')
			{
				if (random(2)) { x = 6; y = 7;}
				else {x = 7; y = 6;}
			}
			else if (user[1][6][7] == '\0' && user[1][7][6] != user[1][7][7])
			{
				x -= 1;
			}
			else if (user[1][7][6] == '\0' && user[1][6][7] != user[1][7][7])
			{
				y -= 1;
			}
			else if (user[1][6][7] == user[1][7][7])
			{
				do
				{
					x -= 1;
				} while (user[1][x][y] == user[1][7][7]);
			}
			else if (user[1][7][6] == user[1][7][7])
			{
				do
				{
					y -= 1;
				} while (user[1][x][y] == user[1][7][7]);
			}
		}
		else if (x == 0)
		{
			if (user[1][x + 1][y] == '\0' && user[1][x][y + 1] == '\0' && user[1][x][y - 1] == '\0')
			{
				sathu = random(3);
				if (sathu == 2) { x += 1;}
				else if (sathu == 1) { y += 1;}
				else y -= 1;
			}
			else if (user[1][x + 1][y] == '\0' && user[1][x][y + 1] == '\0' && user[1][x][y - 1] != user[1][x][y])
			{
				if (random(2)) {x += 1;}
				else y += 1;
			}
			else if (user[1][x + 1][y] == '\0' && user[1][x][y - 1] == '\0' && user[1][x][y + 1] != user[1][x][y])
			{
				if (random(2)) x += 1;
				else y -= 1;
			}
			else if (user[1][x][y + 1] == '\0' && user[1][x][y - 1] == '\0' && user[1][x + 1][y] != user[1][x][y])
			{
				if (random(2)) y += 1;
				else y -= 1;
			}
			else if (user[1][x + 1][y] == '\0' && user[1][x][y + 1] != user[1][x][y] && user[1][x][y - 1] != user[1][x][y])
			{
				x += 1;
			}
			else if (user[1][x][y - 1] == '\0' && user[1][x][y + 1] != user[1][x][y] && user[1][x + 1][y] != user[1][x][y])
			{
				y -= 1;
			}
			else if (user[1][x][y + 1] == '\0' && user[1][x + 1][y] != user[1][x][y] && user[1][x][y - 1] != user[1][x][y])
			{
				y += 1;
			}
			else if (user[1][x + 1][y] == user[1][x][y])
			{
				do
				{
					x += 1;
				} while (user[1][x][y] == user[1][x - 1][y]);
			}
			else if (user[1][x][y - 1] != user[1][x][y] && user[1][x][y + 1] == user[1][x][y])
			{
				if (user[1][x][y - 1] == '\0') {rememberx = x; remembery = y - 1;}
				do
				{
					y += 1;
				} while (user[1][x][y] == user[1][x][y - 1] && y < 7);
				if (user[1][x][y] != '\0') { x = rememberx; y = remembery;}
			}
			else if (user[1][x][y + 1] != user[1][x][y] && user[1][x][y - 1] == user[1][x][y])
			{
				if (user[1][x][y + 1] == '\0') {rememberx = x; remembery = y + 1;}
				do
				{
					y -= 1;
				} while (user[1][x][y] == user[1][x][y + 1] && y > 0);
				if (user[1][x][y] != '\0') { x = rememberx; y = remembery;}

			}
		}
		else if (x == 7)
		{
			if (user[1][x - 1][y] == '\0' && user[1][x][y + 1] == '\0' && user[1][x][y - 1] == '\0')
			{
				sathu = random(3);
				if (sathu == 2) { x -= 1;}
				else if (sathu == 1) { y += 1;}
				else y -= 1;
			}
			else if (user[1][x - 1][y] == '\0' && user[1][x][y + 1] == '\0' && user[1][x][y - 1] != user[1][x][y])
			{
				if (random(2)) {x -= 1;}
				else y += 1;
			}
			else if (user[1][x - 1][y] == '\0' && user[1][x][y - 1] == '\0' && user[1][x][y + 1] != user[1][x][y])
			{
				if (random(2)) x -= 1;
				else y -= 1;
			}
			else if (user[1][x][y + 1] == '\0' && user[1][x][y - 1] == '\0' && user[1][x - 1][y] != user[1][x][y])
			{
				if (random(2)) y += 1;
				else y -= 1;
			}
			else if (user[1][x - 1][y] == '\0' && user[1][x][y + 1] != user[1][x][y] && user[1][x][y - 1] != user[1][x][y])
			{
				x -= 1;
			}
			else if (user[1][x][y - 1] == '\0' && user[1][x][y + 1] != user[1][x][y] && user[1][x - 1][y] != user[1][x][y])
			{
				y -= 1;
			}
			else if (user[1][x][y + 1] == '\0' && user[1][x - 1][y] != user[1][x][y] && user[1][x][y - 1] != user[1][x][y])
			{
				y += 1;
			}
			else if (user[1][x - 1][y] == user[1][x][y])
			{
				do
				{
					x -= 1;
				} while (user[1][x][y] == user[1][x + 1][y]);
			}
			else if (user[1][x][y - 1] != user[1][x][y] && user[1][x][y + 1] == user[1][x][y])
			{
				if (user[1][x][y - 1] == '\0') {rememberx = x; remembery = y - 1;}
				do
				{
					y += 1;
				} while (user[1][x][y] == user[1][x][y - 1] && y < 7);
				if (user[1][x][y] != '\0') { x = rememberx; y = remembery;}
			}
			else if (user[1][x][y + 1] != user[1][x][y] && user[1][x][y - 1] == user[1][x][y])
			{
				if (user[1][x][y + 1] == '\0') {rememberx = x; remembery = y + 1;}
				do
				{
					y -= 1;
				} while (user[1][x][y] == user[1][x][y + 1] && y > 0);
				if (user[1][x][y] != '\0') { x = rememberx; y = remembery;}

			}
		}
		else if (y == 0)
		{
			if (user[1][x][y + 1] == '\0' && user[1][x + 1][y] == '\0' && user[1][x - 1][y] == '\0')
			{
				sathu = random(3);
				if (sathu == 2) { y += 1;}
				else if (sathu == 1) { x += 1;}
				else x -= 1;
			}
			else if (user[1][x][y + 1] == '\0' && user[1][x + 1][y] == '\0' && user[1][x - 1][y] != user[1][x][y])
			{
				if (random(2)) {y += 1;}
				else x += 1;
			}
			else if (user[1][x][y + 1] == '\0' && user[1][x - 1][y] == '\0' && user[1][x + 1][y] != user[1][x][y])
			{
				if (random(2)) y += 1;
				else x -= 1;
			}
			else if (user[1][x + 1][y] == '\0' && user[1][x - 1][y] == '\0' && user[1][x][y + 1] != user[1][x][y])
			{
				if (random(2)) x += 1;
				else x -= 1;
			}
			else if (user[1][x][y + 1] == '\0' && user[1][x + 1][y] != user[1][x][y] && user[1][x - 1][y] != user[1][x][y])
			{
				y += 1;
			}
			else if (user[1][x - 1][y] == '\0' && user[1][x + 1][y] != user[1][x][y] && user[1][x][y + 1] != user[1][x][y])
			{
				x -= 1;
			}
			else if (user[1][x + 1][y] == '\0' && user[1][x][y + 1] != user[1][x][y] && user[1][x - 1][y] != user[1][x][y])
			{
				x += 1;
			}
			else if (user[1][x][y + 1] == user[1][x][y])
			{
				do
				{
					y += 1;
				} while (user[1][x][y] == user[1][x][y - 1]);
			}
			else if (user[1][x - 1][y] != user[1][x][y] && user[1][x + 1][y] == user[1][x][y])
			{
				if (user[1][x - 1][y] == '\0') {rememberx = x - 1; remembery = y;}
				do
				{
					x += 1;
				} while (user[1][x][y] == user[1][x - 1][y] && x < 7);
				if (user[1][x][y] != '\0') { x = rememberx; y = remembery;}
			}
			else if (user[1][x + 1][y] != user[1][x][y] && user[1][x - 1][y] == user[1][x][y])
			{
				if (user[1][x + 1][y] == '\0') {rememberx = x + 1; remembery = y;}
				do
				{
					x -= 1;
				} while (user[1][x][y] == user[1][x + 1][y] && x > 0);
				if (user[1][x][y] != '\0') { x = rememberx; y = remembery;}

			}
		}
		else if (y == 7)
		{
			if (user[1][x][y - 1] == '\0' && user[1][x + 1][y] == '\0' && user[1][x - 1][y] == '\0')
			{
				sathu = random(3);
				if (sathu == 2) { y -= 1;}
				else if (sathu == 1) { x += 1;}
				else x -= 1;
			}
			else if (user[1][x][y - 1] == '\0' && user[1][x + 1][y] == '\0' && user[1][x - 1][y] != user[1][x][y])
			{
				if (random(2)) {y -= 1;}
				else x += 1;
			}
			else if (user[1][x][y - 1] == '\0' && user[1][x - 1][y] == '\0' && user[1][x + 1][y] != user[1][x][y])
			{
				if (random(2)) y -= 1;
				else x -= 1;
			}
			else if (user[1][x + 1][y] == '\0' && user[1][x - 1][y] == '\0' && user[1][x][y - 1] != user[1][x][y])
			{
				if (random(2)) x += 1;
				else x -= 1;
			}
			else if (user[1][x][y - 1] == '\0' && user[1][x + 1][y] != user[1][x][y] && user[1][x - 1][y] != user[1][x][y])
			{
				y -= 1;
			}
			else if (user[1][x - 1][y] == '\0' && user[1][x + 1][y] != user[1][x][y] && user[1][x][y - 1] != user[1][x][y])
			{
				x -= 1;
			}
			else if (user[1][x + 1][y] == '\0' && user[1][x][y - 1] != user[1][x][y] && user[1][x - 1][y] != user[1][x][y])
			{
				x += 1;
			}
			else if (user[1][x][y - 1] == user[1][x][y])
			{
				do
				{
					y -= 1;
				} while (user[1][x][y] == user[1][x + 1][y]);
			}
			else if (user[1][x - 1][y] != user[1][x][y] && user[1][x + 1][y] == user[1][x][y])
			{
				if (user[1][x - 1][y] == '\0') {rememberx = x - 1; remembery = y;}
				do
				{
					x += 1;
				} while (user[1][x][y] == user[1][x - 1][y] && x < 7);
				if (user[1][x][y] != '\0') { x = rememberx; y = remembery;}
			}
			else if (user[1][x + 1][y] != user[1][x][y] && user[1][x - 1][y] == user[1][x][y])
			{
				if (user[1][x + 1][y] == '\0') {rememberx = x + 1; remembery = y;}
				do
				{
					x -= 1;
				} while (user[1][x][y] == user[1][x + 1][y] && x > 0);
				if (user[1][x][y] != '\0') { x = rememberx; y = remembery;}

			}
		}
		else
		{
			if (user[1][x + 1][y] == '\0' && user[1][x -          1][y] == '\0' && user[1][x][y + 1] == '\0' && user[1][x][y - 1] == '\0')
			{
				sathu = random(4);
				if (sathu == 3) x += 1;
				else if (sathu == 2) x -= 1;
				else if (sathu == 1) y += 1;
				else y -= 1;
			}
			else if (user[1][x + 1][y] == '\0' && user[1][x - 1][y] == '\0' && user[1][x][y + 1] == '\0' && user[1][x][y - 1] != user[1][x][y])
			{
				sathu = random(3);
				if (sathu == 2) x += 1;
				else if (sathu == 1) x -= 1;
				else y += 1;
			}
			else if (user[1][x + 1][y] == '\0' && user[1][x - 1][y] == '\0' && user[1][x][y - 1] == '\0' && user[1][x][y + 1] != user[1][x][y])
			{
				sathu = random(3);
				if (sathu == 2) x += 1;
				else if (sathu == 1) x -= 1;
				else y -= 1;
			}
			else if (user[1][x + 1][y] == '\0' && user[1][x][y + 1] == '\0' && user[1][x][y - 1] == '\0' && user[1][x - 1][y] != user[1][x][y])
			{
				sathu = random(3);
				if (sathu == 2) x += 1;
				else if (sathu == 1) y += 1;
				else y -= 1;
			}
			else if (user[1][x - 1][y] == '\0' && user[1][x][y + 1] == '\0' && user[1][x][y - 1] == '\0' && user[1][x + 1][y] != user[1][x][y])
			{
				sathu = random(3);
				if (sathu == 2) x -= 1;
				else if (sathu == 1) y += 1;
				else y -= 1;
			}
			else if (user[1][x + 1][y] == '\0' && user[1][x - 1][y] == '\0' && user[1][x][y + 1] != user[1][x][y] && user[1][x][y - 1] != user[1][x][y])
			{
				if (random(2)) x += 1;
				else x -= 1;
			}
			else if (user[1][x + 1][y] == '\0' && user[1][x][y + 1] == '\0' && user[1][x - 1][y] != user[1][x][y] && user[1][x][y - 1] != user[1][x][y])
			{
				if (random(2)) x += 1;
				else y += 1;
			}
			else if (user[1][x + 1][y] == '\0' && user[1][x][y - 1] == '\0' && user[1][x][y + 1] != user[1][x][y] && user[1][x - 1][y] != user[1][x][y])
			{
				if (random(2)) x += 1;
				else y -= 1;
			}
			else if (user[1][x][y + 1] == '\0' && user[1][x - 1][y] == '\0' && user[1][x + 1][y] != user[1][x][y] && user[1][x][y - 1] != user[1][x][y])
			{
				if (random(2)) y += 1;
				else x -= 1;
			}
			else if (user[1][x][y - 1] == '\0' && user[1][x - 1][y] == '\0' && user[1][x][y + 1] != user[1][x][y] && user[1][x + 1][y] != user[1][x][y])
			{
				if (random(2)) x -= 1;
				else y -= 1;
			}
			else if (user[1][x][y + 1] == '\0' && user[1][x][y - 1] == '\0' && user[1][x + 1][y] != user[1][x - 1][y] && user[1][x][y - 1] != user[1][x][y])
			{
				if (random(2)) y += 1;
				else y -= 1;
			}
			else if (user[1][x + 1][y] == '\0' && user[1][x - 1][y] != user[1][x][y] && user[1][x][y + 1] != user[1][x][y] && user[1][x][y - 1] != user[1][x][y])
			{
				x += 1;
			}
			else if (user[1][x - 1][y] == '\0' && user[1][x + 1][y] != user[1][x][y] && user[1][x][y + 1] != user[1][x][y] && user[1][x][y - 1] != user[1][x][y])
			{
				x -= 1;
			}
			else if (user[1][x][y - 1] == '\0' && user[1][x + 1][y] != user[1][x][y] && user[1][x][y + 1] != user[1][x][y] && user[1][x - 1][y] != user[1][x][y])
			{
				y -= 1;
			}
			else if (user[1][x][y + 1] == '\0' && user[1][x + 1][y] != user[1][x][y] && user[1][x - 1][y] != user[1][x][y] && user[1][x][y - 1] != user[1][x][y])
			{
				y += 1;
			}
			else if (user[1][x][y - 1] != user[1][x][y] && user[1][x][y + 1] == user[1][x][y])
			{
				if (user[1][x][y - 1] == '\0') {rememberx = x; remembery = y - 1;}
				do
				{
					y += 1;
				} while (user[1][x][y] == user[1][x][y - 1] && y < 7);
				if (user[1][x][y] != '\0') { x = rememberx; y = remembery;}
			}
			else if (user[1][x][y + 1] != user[1][x][y] && user[1][x][y - 1] == user[1][x][y])
			{
				if (user[1][x][y + 1] == '\0') {rememberx = x; remembery = y + 1;}
				do
				{
					y -= 1;
				} while (user[1][x][y] == user[1][x][y + 1] && y > 0);
				if (user[1][x][y] != '\0') { x = rememberx; y = remembery;}

			}

			else if (user[1][x - 1][y] != user[1][x][y] && user[1][x + 1][y] == user[1][x][y])
			{
				if (user[1][x - 1][y] == '\0') {rememberx = x - 1; remembery = y;}
				do
				{
					x += 1;
				} while (user[1][x][y] == user[1][x - 1][y] && x < 7);
				if (user[1][x][y] != '\0') { x = rememberx; y = remembery;}
			}
			else if (user[1][x + 1][y] != user[1][x][y] && user[1][x - 1][y] == user[1][x][y])
			{
				if (user[1][x + 1][y] == '\0') {rememberx = x + 1; remembery = y;}
				do
				{
					x -= 1;
				} while (user[1][x][y] == user[1][x + 1][y] && x > 0);
				if (user[1][x][y] != '\0') { x = rememberx; y = remembery;}

			}
		}
	}
	bar(10, 340, 470, 380);
	user[1][x][y] = user[0][x][y];
	if (user[0][x][y] == 's') outtextxy(100, 350, "SCAVENGER HIT");
	else if (user[0][x][y] == 'd')outtextxy(100, 350, "DESTROYER HIT");
	else if (user[0][x][y] == 'b')outtextxy(100, 350, "BATTLESHIP HIT");
	else if (user[0][x][y] == 'c')outtextxy(100, 350, "CARRIER HIT");
	else outtextxy(100, 350, "SHOT MISSED");
	switch (user[0][x][y])
	{
	case 's': u.s--; break;
	case 'd': u.d--; break;
	case 'b': u.b--; break;
	case 'c': u.c--; break;
	default: break;
	}
	getch();
	user_disp();
	bar(10, 340, 470, 380);
	if (user[0][x][y] == 's' && u.s == 0) outtextxy(100, 350, "SCAVENGER SUNK");
	else if (user[0][x][y] == 'd' && u.d == 0) outtextxy(100, 350, "DESTROYER SUNK");
	else if (user[0][x][y] == 'c' && u.c == 0) outtextxy(100, 350, "CARRIER SUNK");
	else if (user[0][x][y] == 'b' && u.b == 0) outtextxy(100, 350, "BATTLESHIP SUNK");
	getch();

}




