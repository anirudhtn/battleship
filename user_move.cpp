void user_move()
{
	char	 a[50];
	setcolor(CYAN);
	setfillstyle(1, BLACK);
	do
	{	bar(10, 340, 470, 380); //fill coordinates in later
		outtextxy(20, 350, "ENTER POSITION TO ATTACK:");
		strcpy(a, accept1(400, 350));
	} while (!(strlen(a) == 2 && tolower(a[0]) <= 'h' && tolower(a[0]) >= 'a' && a[      1] <= '8' && a[1] >= '1' && pc[1][tolower(a[0]) - 'a'][a[1] - '1'] == '\0'));
	int j = tolower(a[0] - 97);
	int i = a[1] - 49;
	pc[1][j][i] = pc[0][j][i];
	bar(10, 340, 470, 380);
	if (pc[0][j][i] != 'x') outtextxy(100, 350, "YOU HAVE HIT A SHIP");
	else outtextxy(100, 350, "YOU HAVEN'T HIT ANY SHIPS");
	switch (pc[0][j][i])
	{
	case 's': p.s--; break;
	case 'd': p.d--; break;
	case 'b': p.b--; break;
	case 'c': p.c--; break;
	default: break;
	}
	getch();
	pc_disp();
	bar(10, 340, 470, 380);
	if (pc[0][j][i] == 's' && p.s == 0) outtextxy(100, 350, "SCAVENGER SUNK");
	else if (pc[0][j][i] == 'd' && p.d == 0) outtextxy(100, 350, "DESTROYER SUNK");
	else if (pc[0][j][i] == 'c' && p.c == 0) outtextxy(100, 350, "CARRIER SUNK");
	else if (pc[0][j][i] == 'b' && p.b == 0) outtextxy(100, 350, "BATTLESHIPSUNK");
	getch();
}
int gimmenames(char a)
{
	switch (a)
	{
	case 's': if (u.s == 0) jambu = 0; else jambu = 1; break;
	case 'b': if (u.b == 0) jambu = 0; else jambu = 1; break;
	case 'd': if (u.d == 0) jambu = 0; else jambu = 1; break;
	case 'c': if (u.c == 0) jambu = 0; else jambu = 1; break;
	}
	return jambu;
}
void scan(int &x, int& y)
{	int flag = 0;
	for (int i = 0; i < 8 && flag == 0; i++)
	{
		for (int j = 0; j < 8 && flag == 0; j++)
		{
			if (user[1][i][j] != '\0' && tolower(user[1][i][j]) != 'x')
				if (gimmenames(user[1][i][j])) { x = i; y = j; flag = 1;}
		}
	}

}