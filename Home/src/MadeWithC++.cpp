// Made paila nai for oop project

#include <graphics.h>
#include <stdlib.h>
#include <iostream>
#define width 1280
#define height 700

int i, X[100], Y[100], M[100], N[100], s = 16, l, d = 2;
// VERY VERY IMP NOTE: PRESS Ctrl + Shift + B to build the file. Then right click on exe file, press Run executable then it executes.
void nice_intro();
void moveCode(int startX, int startY, int endX, int endY, const char *direction, int boxPatt, int boxCol, int textPatt, int textCol);

int main()
{
    initwindow(width, height);
    nice_intro();
    getch();
    closegraph();
    return 0;
}

void moveCode(int startX, int startY, int endX, int endY, const char *direction, int boxPatt, int boxCol, int textPatt, int textCol)
{
    if (boxPatt == 2 || boxPatt == 3 || boxPatt == 5 || boxPatt == 7)
    {
        std::cout << "Incorrect choice for box pattern." << std::endl
                  << "THE PATTERN OF BOX MUST BE 1,4,6,8,9,10 or 11, maybe you used 2,3,5,or 7" << std::endl
                  << " TERMINATED UNEXPECTEDLY. " << std::endl
                  << "return -1 lol" << std::endl;
        closegraph();
    }
    X[0] = s * (startX / s);
    Y[0] = s * (startY / s);
    bar(X[0] - s / 2, Y[0] - s / 2, X[0] + s / 2, Y[0] + s / 2);

    M[0] = s * (endX / s);
    N[0] = s * (endY / s);
    setfillstyle(boxPatt, boxCol);
    bar(M[0] - s / 2, N[0] - s / 2, M[0] + s / 2, N[0] + s / 2);

    l = 1;

    while (1)
    {
        // displaying the text
        setfillstyle(textPatt, textCol);
        for (i = 0; i < l; i++)
            bar(X[i] - s / 2, Y[i] - s / 2, X[i] + s / 2, Y[i] + s / 2);
        delay(1); // delay between display of one bar and next bar(small box 16 px)

        for (i = l - 1; i > 0; i--)
        {
            X[i] = X[i - 1];
            Y[i] = Y[i - 1];
        }
        if (!strcmp(direction, "up"))
        {
            Y[0] = Y[0] - s;
        }
        else if (!strcmp(direction, "down"))
        {
            Y[0] = Y[0] + s;
        }
        else if (!strcmp(direction, "right"))
        {
            X[0] = X[0] + s;
        }
        else if (!strcmp(direction, "left"))
        {
            X[0] = X[0] - s;
        }
        else if (!strcmp(direction, "bottomright"))
        {
            X[0] = X[0] + s;
            Y[0] = Y[0] + s;
        }
        else if (!strcmp(direction, "upright"))
        {
            X[0] = X[0] + s;
            Y[0] = Y[0] - s;
        }
        else if (!strcmp(direction, "upleft"))
        {
            X[0] = X[0] - s;
            Y[0] = Y[0] - s;
        }

        if (getpixel(X[0], Y[0]) == boxCol)
        {
            return;
        }
    }
    // IMPORTANT NOTE:
    // FOR GETPIXEL TO WORK, THE PATTERN OF BOX MUST BE 1,4,6,8,9,10 or 11 and maybe others more also
    // for getpixel, pattern 2,3,5 and 7 won't work. maybe not enough matter to be detected by getpixel function
}
void nice_intro()
{
    /*
    // S, 710,760 x 300 400
    moveCode(560, 100, 510, 100, "left", 1, 1, 2, 2);
    moveCode(510, 100, 510, 150, "down", 1, 1, 2, 2);
    moveCode(510, 150, 560, 150, "right", 1, 1, 2, 2);
    */

    // M
    moveCode(400, 300, 400, 200, "up", 1, 1, 2, 2);
    moveCode(400, 200, 450, 240, "bottomright", 1, 1, 2, 2);
    moveCode(450, 240, 500, 200, "upright", 1, 1, 2, 2);
    moveCode(500, 200, 500, 300, "down", 1, 1, 2, 2);

    // A
    moveCode(550, 300, 550, 200, "up", 4, 3, 4, 4);
    moveCode(550, 200, 600, 200, "right", 4, 3, 4, 4);
    moveCode(600, 200, 600, 300, "down", 4, 3, 4, 4);
    moveCode(600, 250, 550, 250, "left", 4, 3, 4, 4);

    // D
    moveCode(650, 300, 650, 200, "up", 4, 3, 4, 4);
    moveCode(650, 200, 700, 200, "right", 4, 3, 4, 4);
    moveCode(700, 200, 700, 300, "down", 4, 3, 4, 4);
    moveCode(700, 300, 650, 300, "left", 4, 3, 4, 4);

    // E
    moveCode(750, 300, 750, 200, "up", 4, 3, 4, 4);
    moveCode(750, 200, 800, 200, "right", 4, 3, 4, 4);
    moveCode(750, 250, 800, 250, "right", 4, 3, 4, 4);
    moveCode(750, 300, 800, 300, "right", 4, 3, 4, 4);

    // W
    moveCode(400, 350, 400, 450, "down", 1, 1, 2, 2);
    moveCode(400, 450, 450, 410, "upright", 1, 1, 2, 2);
    moveCode(450, 410, 500, 450, "bottomright", 1, 1, 2, 2);
    moveCode(500, 450, 500, 350, "up", 1, 1, 2, 2);

    // I
    moveCode(550, 350, 550, 450, "down", 8, 7, 7, 7);

    // T
    moveCode(600, 350, 660, 350, "right", 6, 5, 6, 6);
    moveCode(630, 350, 630, 450, "down", 6, 5, 6, 6);

    // H
    moveCode(690, 400, 690, 350, "up", 10, 10, 11, 11);
    moveCode(690, 400, 690, 450, "down", 10, 10, 11, 11);
    moveCode(690, 400, 740, 400, "right", 10, 10, 11, 11);
    moveCode(740, 400, 740, 350, "up", 10, 10, 11, 11);
    moveCode(740, 400, 740, 450, "down", 10, 10, 11, 11);

    // C
    moveCode(500, 500, 400, 500, "left", 10, 10, 11, 11);
    moveCode(400, 500, 400, 600, "down", 10, 10, 11, 11);
    moveCode(400, 600, 500, 600, "right", 10, 10, 11, 11);

    //+
    moveCode(600, 500, 600, 600, "down", 8, 7, 7, 7);
    moveCode(650, 550, 550, 550, "left", 8, 7, 7, 7);

    //+
    moveCode(750, 500, 750, 600, "down", 8, 7, 7, 7);
    moveCode(780, 550, 700, 550, "left", 8, 7, 7, 7);
}