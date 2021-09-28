#define VARIABLE_H_INCLUDED

int dx = 280;
int dy = 570;

int x = 0;
int y = 0;
int i = 0;
int score = 0;
char bc[4][20] = { "images\\Green_B.bmp", "images\\Red_B.bmp" };
char b[2][20] = { "images\\Aim_B.bmp", "images\\Blast.bmp" };
char converted_score[20];
int bcIndex = 0;
int bIndex = 0;

void object_move()
{
	if (dy != 0 && dy>0)
	{
		dy -= 3;
	}
	else if (dy == 0 || dy<0)
	{
		dy--;
		i = 1;
	}
}
