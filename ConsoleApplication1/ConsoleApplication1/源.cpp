#include<graphics.h>
#include<conio.h>

class Self
{
private:
	int x, y,speed;
	IMAGE selfimage[3];
	IMAGE State;
	int w, h;
public:
	Self() 
	{
		loadimage(&selfimage[0], _T("E:\\newtest\\picture\\left.jpg"));
		loadimage(&selfimage[2], _T("E:\\newtest\\picture\\right.jpg"));
		loadimage(&selfimage[1], _T("E:\\newtest\\picture\\stop.jpg"));
		w = selfimage[1].getwidth();
		h = selfimage[1].getheight();
	};
	void Selfimage()//����������
	{
		
	}
	void Drawself()
	{
		setfillcolor(WHITE);
		putimage(450, 450, &selfimage[1]);
		x = 450;
		y = 450;
		speed = 5;
	}
	void Moveself()
	{
		setlinecolor(BLACK);
		setfillcolor(BLACK);
		fillrectangle(x, y, (x + w), (y + h));
		State = selfimage[1];
		if (GetAsyncKeyState(VK_SHIFT) & 0x8000) speed = 2;else speed = 5;
		if (GetAsyncKeyState(VK_LEFT) & 0x8000) { x = x - speed; State = selfimage[0]; }
		if (GetAsyncKeyState(VK_RIGHT) & 0x8000) { x = x + speed; State = selfimage[2]; }
		if (GetAsyncKeyState(VK_UP) & 0x8000)y = y - speed;
		if (GetAsyncKeyState(VK_DOWN) & 0x8000)	y = y + speed;
		putimage(x, y, &State);
		Sleep(10);
	}
	int ValueofX()
	{
		return x;
	}
	int ValueofY()
	{
		return y;
	}
	int SelfpointX()
	{
		return (x + w / 2);
	}
	int SelfpointY()
	{
		return(y + h / 2);
	}
}me;


class Bullet
{
public:
	Bullet(){}
}selfbullet;

class Enemy
{
private:
	int Ex1, Ey1, Ex2, Ey2;
public:
	Enemy() {}
	void Drawenemy()
	{
		setfillcolor(WHITE);
		fillcircle(100, 100, 30);
		fillcircle(800, 100, 30);
		Ex1 = Ey1 = 100;
		Ex2 = 800;Ey2 = 100;
	}
	void Moveenemy()
	{
		setlinecolor(BLACK);
		setfillcolor(BLACK);
		fillcircle(Ex1, Ey1, 30);
		fillcircle(Ex2, Ey2, 30);
		if (me.ValueofX() > Ex1)
			Ex1++;
		else if (me.ValueofX() < Ex1)
			Ex1--;
		if (me.ValueofY()> Ey1)
			Ey1++;
		else if (me.ValueofY() < Ey1)
			Ey1--;
		if (me.ValueofX() > Ex2)
			Ex2++;
		else if (me.ValueofX() < Ex2)
			Ex2--;
		if (me.ValueofY() > Ey2)
			Ey2++;
		else if (me.ValueofY() < Ey2)
			Ey2--;
		setlinecolor(WHITE);
		setfillcolor(WHITE);
		fillcircle(Ex1, Ey1, 30);
		fillcircle(Ex2, Ey2, 30);
	}
}enemy;
void UI()
{
	initgraph(900, 900);
};
void move()
{
	me.Drawself();
	enemy.Drawenemy();
	while (true)
	{
		BeginBatchDraw();
		me.Moveself();
		enemy.Moveenemy();
		FlushBatchDraw();
	}
}
void testit()
{
	IMAGE test_;
	loadimage(&test_,_T("E:\\newtest\\picture\\test.gif"));
	putimage(0, 0, &test_);
}
void main()
{
	UI();
	testit();
	move();
}