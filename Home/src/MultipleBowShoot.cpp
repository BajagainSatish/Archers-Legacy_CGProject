#include <graphics.h>
void BowArrow(int, int, int, int, int, int);
void Arrow(int, int, int, int, int);
int main()
{
    bool shootArrow = false;
    int arrow1X = 100, arrow1Y = 500;
    int arrow2X = 500, arrow2Y = 500;
    int arrow3X = 900, arrow3Y = 500;
    int arrow4X = 1300, arrow4Y = 500;
    int arrow5X = 1700, arrow5Y = 500;

    initwindow(1800, 1000, "ShootArrow", 50, 0);

    while (1)
    {
        cleardevice();
        BowArrow(100, 500, 50, -90, 90, 80);
        Arrow(arrow1X, arrow1Y, 50, -90, 90);

        BowArrow(500, 500, 50, -45, 135, 80);
        Arrow(arrow2X, arrow2Y, 50, -45, 135);

        BowArrow(900, 500, 50, 0, 180, 80);
        Arrow(arrow3X, arrow3Y, 50, 0, 180);

        BowArrow(1300, 500, 50, 45, 225, 80);
        Arrow(arrow4X, arrow4Y, 50, 45, 225);

        BowArrow(1700, 500, 50, 90, 270, 80);
        Arrow(arrow5X, arrow5Y, 50, 90, 270);

        if (GetAsyncKeyState(VK_SPACE))
        {
            shootArrow = true;
        }
        if (shootArrow)
        {
            arrow1X += 15;

            arrow2X += 15;
            arrow2Y -= 15;

            arrow3Y -= 15;

            arrow4X -= 15;
            arrow4Y -= 15;

            arrow5X -= 15;
        }
        delay(10);
    }

    getch();
    closegraph();
    return 0;
}
void BowArrow(int centerX, int centerY, int difference, int startAngle, int endAngle, int bowRadius)
{
    // Arc Part
    arc(centerX, centerY, startAngle, endAngle, bowRadius);
    // Bow Line
    if (startAngle == -90 && endAngle == 90)
    {
        line(centerX, centerY - difference, centerX, centerY + difference); // Bow Line
    }
    if (startAngle == -45 && endAngle == 135)
    {
        line(centerX - difference, centerY - difference, centerX + difference, centerY + difference); // Bow Line
    }
    if (startAngle == 0 && endAngle == 180)
    {
        line(centerX - difference, centerY, centerX + difference, centerY); // Bow Line
    }
    if (startAngle == 45 && endAngle == 225)
    {
        line(centerX + difference, centerY - difference, centerX - difference, centerY + difference); // Bow Line
    }
    if (startAngle == 90 && endAngle == 270)
    {
        line(centerX, centerY - difference, centerX, centerY + difference); // Bow Line
    }
}

void Arrow(int centerX, int centerY, int difference, int startAngle, int endAngle)
{
    int arrowBaseX, arrowBaseY;
    int tipDifference = 10;
    if (startAngle == -90 && endAngle == 90)
    {
        line(centerX - difference, centerY, centerX + difference, centerY); // Arrow Line

        // ArrowHead
        arrowBaseX = centerX + difference;
        arrowBaseY = centerY;
        line(arrowBaseX, arrowBaseY - tipDifference, arrowBaseX, arrowBaseY + tipDifference);
        line(arrowBaseX, arrowBaseY - tipDifference, arrowBaseX + tipDifference, arrowBaseY);
        line(arrowBaseX, arrowBaseY + tipDifference, arrowBaseX + tipDifference, arrowBaseY);
    }
    if (startAngle == -45 && endAngle == 135)
    {
        line(centerX - difference, centerY + difference, centerX + difference, centerY - difference); // Arrow Line

        // ArrowHead
        arrowBaseX = centerX + difference;
        arrowBaseY = centerY - difference;
        line(arrowBaseX - tipDifference, arrowBaseY - tipDifference, arrowBaseX + tipDifference, arrowBaseY + tipDifference);
        line(arrowBaseX - tipDifference, arrowBaseY - tipDifference, arrowBaseX + tipDifference, arrowBaseY - tipDifference);
        line(arrowBaseX + tipDifference, arrowBaseY - tipDifference, arrowBaseX + tipDifference, arrowBaseY + tipDifference);
    }
    if (startAngle == 0 && endAngle == 180)
    {
        line(centerX, centerY - difference, centerX, centerY + difference); // Arrow Line

        // ArrowHead
        arrowBaseX = centerX;
        arrowBaseY = centerY - difference;
        line(arrowBaseX - tipDifference, arrowBaseY, arrowBaseX + tipDifference, arrowBaseY);
        line(arrowBaseX - tipDifference, arrowBaseY, arrowBaseX, arrowBaseY - tipDifference);
        line(arrowBaseX, arrowBaseY - tipDifference, arrowBaseX + tipDifference, arrowBaseY);
    }
    if (startAngle == 45 && endAngle == 225)
    {
        line(centerX + difference, centerY + difference, centerX - difference, centerY - difference); // Arrow Line

        // ArrowHead
        arrowBaseX = centerX - difference;
        arrowBaseY = centerY - difference;
        line(arrowBaseX - tipDifference, arrowBaseY + tipDifference, arrowBaseX + tipDifference, arrowBaseY - tipDifference);
        line(arrowBaseX - tipDifference, arrowBaseY + tipDifference, arrowBaseX - tipDifference, arrowBaseY - tipDifference);
        line(arrowBaseX + tipDifference, arrowBaseY - tipDifference, arrowBaseX - tipDifference, arrowBaseY - tipDifference);
    }
    if (startAngle == 90 && endAngle == 270)
    {
        line(centerX + difference, centerY, centerX - difference, centerY); // Arrow Line

        // ArrowHead
        arrowBaseX = centerX - difference;
        arrowBaseY = centerY;
        line(arrowBaseX, arrowBaseY - tipDifference, arrowBaseX, arrowBaseY + tipDifference);
        line(arrowBaseX, arrowBaseY - tipDifference, arrowBaseX - tipDifference, arrowBaseY);
        line(arrowBaseX, arrowBaseY + tipDifference, arrowBaseX - tipDifference, arrowBaseY);
    }
}