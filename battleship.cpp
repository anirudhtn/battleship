#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<graphics.h>
#include<fstream.h>
#include"accept_N.cpp"
#include<ctype.h>
#include"bs_01.cpp"
char user[2][8][8], pc[2][8][8], na[2];
int cs = 0;
char username[20];
int maxpos = 0;
void create_user()
{
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			user[0][i][j] = 'x';
}
void bg()
{
	char	a[2] = {'A'};
	char 	b[2] = {'1'};
	int 	driver = VGA, mode = VGAHI;
	initgraph(&driver, &mode, "C:\\TURBOC3\\BGI");
	for (int i = 0, x = 120; i < 8; i++)
	{
		for (int j = 0, y = 150; j < 8; j++)
		{
			rectangle(x, y, x + 20, y + 20);
			rectangle(x + 200, y, x + 220, y + 20);
			if (i == 0)
			{
				outtextxy(x - 10, y + 5, a);
				outtextxy(x + 190, y + 5, a);
				a[0]++;
			}
			y += 20;
		}
		outtextxy(x + 5, 140, b);
		outtextxy(x + 205, 140, b);
		b[0]++;
		x += 20;
	}
	setcolor(CYAN);
	outtextxy(170, 110, "USER");
	outtextxy(380, 110, "PC");
	settextstyle(7, 0, 8);
	outtextxy(70, 0, "BATTLESHIP") ;
}
char* ctos(char a)
{
	na[0] = a;
	na[1] = '\0';
	return na;
}
void user_disp()
{
	for (int j = 0, x = 120; j < 8; j++)
	{
		for (int i = 0, y = 150; i < 8; i++)
		{
			if (user[0][i][j] != 'x')
			{
				if (user[0][i][j] == user[1][i][j])
				{
					setcolor(RED);
					outtextxy(x + 5, y + 5, ctos(user[0][i][j]));
				}
				else
				{
					setcolor(GREEN);
					outtextxy(x + 5, y + 5, ctos(user[0][i][j]));
				}
			}
			else if (user[0][i][j] == user[1][i][j])
			{
				setcolor(GREEN);
				outtextxy(x + 5, y + 5, ".");
			}
			y += 20;
		}
		x += 20;
	}
}

int check(char* na)
{
	if (strlen(na) == 2 && na[0] >= 'A' && na[0] <= 'H' && na[1] >= '1' && na[1] <= '8') return 1;
	else return 0;
}
char* input(char* a)
{
	char na[20];
	if (cs == 0)
	{
		settextstyle(0, 0, 0);
		outtextxy(100, 350, "Enter username:");
		strcpy(username, accept1(420, 350));
		bar(10, 340, 470, 380);
		cs = 1;
	}
	setcolor(CYAN);
	do
	{
		setfillstyle(1, BLACK);
		bar(10, 340, 470, 380);
		settextstyle(0, 0, 0);
		outtextxy(100, 350, "Enter starting position of ");
		outtextxy(320, 350, a);
		strcpy(na, accept1(420, 350));
		na[0] = toupper(na[0]);
		if (check(na)) break;
		setfillstyle(1, BLACK);
		bar(10, 340, 470, 380);
		outtextxy(100, 350, "Invalid Position");
		getch();
	} while (7);
	return na;
}
char* input1()
{
	char *a = NULL;
	setcolor(CYAN);
	do
	{
		setfillstyle(1, BLACK);
		bar(10, 340, 470, 380);
		outtextxy(100, 350, "Horizontal or Vertical");
		strcpy(a, accept1(370, 350));
		if ((strcmpi(a, "v") == 0) || (strcmpi(a, "H") == 0)) break;
		bar(10, 340, 470, 380);
		outtextxy(100, 350, "Invalid Instruction");
		getch();
	} while (7);
	return a;
}
char* input2(char* na)
{
	int i = 0;
	char a[20];
	setcolor(CYAN);
	do
	{
		setfillstyle(1, BLACK);
		bar(10, 340, 470, 380);
		if (strcmpi(na, "H") == 0)
		{
			outtextxy(100, 350, "Left or Right");
			strcpy(a, accept1(420, 350));
			if ((strcmpi(a, "L") == 0) || (strcmpi(a, "R") == 0)) i = 1;
		}
		else
		{
			outtextxy(100, 350, "Up or Down");
			strcpy(a, accept1(420, 350));
			if ((strcmpi(a, "U") == 0) || (strcmpi(a, "D") == 0)) i = 1;
		}
		if (i == 1) break;
		bar(10, 340, 470, 380);
		outtextxy(100, 350, "Invalid Instruction");
		getch();
	} while (7);
	return a;
}
int save_check(char* pos, char* dir, int size, char* d)
{
	int flag = 1;
	if (strcmpi(dir, "l") == 0)
	{
		for (int i = pos[1] - 49, k = 0; k < size && flag == 1; i--, k++)
		{
			if (i < 0) flag = 0;
			else if (user[0][toupper(pos[0]) - 65][i] != 'x')flag = 0;
		}
		if (flag)
		{
			for (i = pos[1] - 49, k = 0; k < size; i--, k++)
			{
				user[0][toupper(pos[0]) - 65][i] = tolower(d[0]);
			}
		}
	}
	else if (strcmpi(dir, "r") == 0)
	{
		for (int i = pos[1] - 49, k = 0; k < size && flag == 1; i++, k++)
		{
			if (i > 7) flag = 0;
			else if (user[0][toupper(pos[0]) - 65][i] != 'x')flag = 0;
		}
		if (flag)
		{
			for (i = pos[1] - 49, k = 0; k < size; i++, k++)
			{
				user[0][toupper(pos[0]) - 65][i] = tolower(d[0]);
			}
		}
	}
	else if (strcmpi(dir, "u") == 0)
	{
		for (int i = pos[0] - 65, k = 0; k < size && flag == 1; i--, k++)
		{
			if (i < 0) flag = 0;
			else if (user[0][i][pos[1] - 49] != 'x')  flag = 0;
		}
		if (flag)
		{
			for (i = pos[0] - 65, k = 0; k < size; i--, k++)
				user[0][i][pos[1] - 49] = tolower(d[0]);
		}
	}
	else if (strcmpi(dir, "d") == 0)
	{
		for (int i = pos[0] - 65, k = 0; k < size && flag == 1; i++, k++)
		{
			if (i > 7) flag = 0;
			else if (user[0][i][pos[1] - 49] != 'x')  flag = 0;
		}
		if (flag)
		{
			for (i = pos[0] - 65, k = 0; k < size; i++, k++)
				user[0][i][pos[1] - 49] = tolower(d[0]);
		}
	}
	return flag;
}
void pc_store()
{
	ifstream	f;
	int	i = 0, max;
	f.open("pc_form.DAT", ios::in | ios::binary);
	f.read((char*)&jeeru, sizeof(jeeru));
	max = jeeru.return_count();
	while (!f.eof())
	{

		f.read((char*)&jeeru, sizeof(jeeru));
		if (jeeru.return_count() > max)
		{
			max = jeeru.return_count();
			maxpos = i;
		}
		i++;
	}
	f.seekg(maxpos * sizeof(jeeru), ios::beg);
	f.read((char*)&jeeru, sizeof(jeeru));
	for (int m = 0; m < 8; m++)
		for (int n = 0; n < 8; n++)
			pc[0][m][n] = jeeru.a[m][n];
	f.close();


}

void part1()
{
	clrscr();
	bg();
	create_user();
	char pos[20], dis[20], dir1[20], dir2[20], m;
	for (int i = 2; i <= 5;)
	{
		switch (i)
		{
		case 2: strcpy(dis, "Scavenger"); break;
		case 3: strcpy(dis, "Destroyer"); break;
		case 4: strcpy(dis, "Battleship"); break;
		case 5: strcpy(dis, "Carrier"); break;
		}
		strcpy(pos, input(dis));
		strcpy(dir1, input1());
		strcpy(dir2, input2(dir1));
		if (save_check(pos, dir2, i, dis))
		{
			i++;
			user_disp();
		}
		else
		{
			setcolor(CYAN);
			setfillstyle(1, BLACK);
			bar(10, 340, 470, 380);
			outtextxy(100, 350, "Invalid Instruction");
			getch();
		}
		getch();

	}
	getch();
	pc_store();
}