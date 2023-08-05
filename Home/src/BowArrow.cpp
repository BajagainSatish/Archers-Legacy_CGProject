#include <graphics.h>
void Bow(int, int, int, int, int, int);
void Arrow(int, int, int, int);
void ArrowTipTriangle(int, int, int);
int main()
{
    int a = 650, b = 550;
    bool shootArrow = false;
    initwindow(1800, 1000, "ShootArrow", 100, 20);
    while (1)
    {
        cleardevice();
        Bow(550, 650, 50, -45, 135, 80);
        Arrow(a, b, 50, 10);
        if (GetAsyncKeyState(VK_RIGHT))
        {
            shootArrow = true;
        }
        if (shootArrow)
        {
            a += 2;
            b -= 2;
        }
        delay(10);
    }

    getch();
    return 0;
}
void Bow(int centerX, int centerY, int difference, int startAngle, int endAngle, int bowRadius)
{
    line(centerX - difference, centerY - difference, centerX + difference, centerY + difference);
    arc(centerX, centerY, startAngle, endAngle, bowRadius);
}
void Arrow(int centerX, int centerY, int difference, int tipDifference)
{
    line(centerX - difference, centerY + difference, centerX + difference, centerY - difference);
    ArrowTipTriangle(centerX + difference, centerY - difference, tipDifference);
}
void ArrowTipTriangle(int arrowBaseX, int arrowBaseY, int tipDifference)
{
    line(arrowBaseX - tipDifference, arrowBaseY - tipDifference, arrowBaseX + tipDifference, arrowBaseY + tipDifference);
    line(arrowBaseX - tipDifference, arrowBaseY - tipDifference, arrowBaseX + tipDifference, arrowBaseY - tipDifference);
    line(arrowBaseX + tipDifference, arrowBaseY - tipDifference, arrowBaseX + tipDifference, arrowBaseY + tipDifference);
}