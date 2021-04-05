void gameplay()
{
	do
	{
		user_move();
		if (p.s + p.c + p.d + p.b > 0) pc_move();
	} while ((u.s + u.c + u.b + u.d) > 0 && (p.s + p.c + p.d + p.b) > 0);
	getch();
	int result;
	bar(10, 340, 470, 380);
	setcolor(CYAN);
	if ((u.s + u.c + u.b + u.d) > 0) { outtextxy(100, 350, "YOU WIN!"); result = 0;}
	else { outtextxy(100, 350, "YOU LOSE!"); result = 1;}
	fstream f;
	f.open("pc_form.DAT", ios::out | ios::in | ios::binary);
	f.seekg(maxpos * sizeof(jeeru), ios::beg);
	f.read((char*)&jeeru, sizeof(jeeru));
	if (result)
	{
		jeeru.win();
		f.seekp(maxpos * sizeof(jeeru), ios::beg);
		f.write((char*)&jeeru, sizeof(jeeru));
	}
	else
	{
		jeeru.lose();
		f.seekp(maxpos * sizeof(jeeru), ios::beg);
		f.write((char*)&jeeru, sizeof(jeeru));
		f.close();
		f.open("pc_form.DAT", ios::app | ios::binary);
		form ani;
		strcpy(ani.name, username);
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				ani.a[i][j] = user[0][i][j];
			}
		}
		f.write((char*)&ani, sizeof(ani));
	}
	f.close();
	getch();
	bar(10, 340, 470, 380);
}
void battleshiprox()
{
	u.s = p.s = 2;
	u.d = p.d = 3;
	u.b = p.b = 4;
	u.c = p.c = 5;
	part1();
	gameplay();
	pc_disp();
	getch();
	cleardevice();
	closegraph();
}


