#include <graphics.h>

// hover effect

int main()

{

    int bk_color = 15, x, y;

    initwindow(700, 600, "Hover", 150, 50);

    while (1)

    {

        POINT cursor;

        GetCursorPos(&cursor);

        setfillstyle(SOLID_FILL, bk_color);

        bar(300, 250, 400, 350);

        if ((cursor.x >= 300 + 150 && cursor.x <= 400 + 150) && (cursor.y >= 250 + 50 && cursor.y <= 350 + 50))

        {

            bk_color = 14;
            if (ismouseclick(WM_LBUTTONDOWN))
            {
                getmouseclick(WM_LBUTTONDOWN, x, y);
                printf("Left click at coordinates: (%d, %d)\n", x, y);
            }
        }

        else

            bk_color = 15;
    }

    getch();

    closegraph();
}