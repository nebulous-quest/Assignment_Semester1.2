#include "iGraphics.h"
#include "Variable.h"



void iDraw()
{
	//place your drawing codes here
	iClear();
	iShowBMP(dx, dy, bc[bcIndex]);
	
	if (bIndex == 1)
	{
		iShowBMP2(x, y, b[bIndex], 0);
		bIndex = 0;
	}
	if (bIndex == 0)
	{
		iShowBMP2(x, y, b[bIndex], 0);
		bIndex = 0;
	}
	if (i == 1)
	{
		iText(400, 300, "Game Over");
	}

	iSetColor(0, 255, 0);
	iText(650, 570, "Player Name : Sajid", GLUT_BITMAP_HELVETICA_10);
	iText(650, 550, "Score : ", GLUT_BITMAP_HELVETICA_10);
	iText(690, 550, converted_score, GLUT_BITMAP_HELVETICA_10);
	iText(200, 10, "Press p for pause and r for resume");
}

void iMouseMove(int mx, int my)
{

}

void iPassiveMouse(int mx, int my)
{
	printf("(x,y):%d,%d \n", mx, my);
	x = mx - 23;
	y = my - 23;
}


void iMouse(int button, int state, int mx, int my)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		

		if (x <= (dx +30) && x >= dx && y <= (dy+40) && y >= dy && bcIndex == 1)
		{
			bIndex = 1;
			dy = 570;
			dx = 320;
			bcIndex = 0;
			score = score + 10;
			sprintf(converted_score, "%d", score);
		}

		else if (x <= (dx + 30) && x >= dx && y <= (dy + 40) && y >= dy && bcIndex == 0)
		{
			bIndex = 1;
			dy = 570;
			dx = 280;
			bcIndex = 1;
			score = score + 20;
			sprintf(converted_score, "%d", score);
		}

		else
		{
			bIndex = 0;
		}
	}
}


void iKeyboard(unsigned char key)
{
	if (key == 'p')
	{
		iPauseTimer(0);
	}
	
	if (key == 'r')
	{
		iResumeTimer(0);
	}
}

void iSpecialKeyboard(unsigned char key)
{

	if (key == GLUT_KEY_END)
	{
		exit(0);
	}

}

int main()
{
	
	iSetTimer(20, object_move);

	iInitialize(800, 600, "Balloon Shoot");

	iStart(); 

	return 0;
}

