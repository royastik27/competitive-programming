/**
* UVA 10267 - Graphical Editor
* AUTHOR: Eng. Astik Roy
**/

#include <iostream>

using namespace std;

#define LIMIT 250

int row, col;
char pic[LIMIT][LIMIT], preColor;

void clearPic(){
    int i, j;
    for(i = 0; i<row; ++i)
        for(j = 0; j<col; ++j)
            pic[i][j] = 'O';
}

void displayPic(){
    int i, j;
    for(i = 0; i<row; ++i){
        for(j = 0; j<col; ++j){
            cout << pic[i][j];
        }

        cout << '\n';
    }
}

void fill(int x, int y, char color){ //call using y-1 x-1

    if(x < 0 || y < 0 || x >= row || y >=col || pic[x][y] == color)
        return;

    if(pic[x][y] == preColor)
        pic[x][y] = color;
    else
        return;

    fill(x, y-1, color);
    fill(x, y+1, color);

    fill(x-1, y, color);
    fill(x-1, y-1, color);
    fill(x-1, y+1, color);

    fill(x+1, y, color);
    fill(x+1, y-1, color);
    fill(x+1, y+1, color);
}

int main(){

    int x1, x2, y1, y2, i, j;
    char option, color, name[31];

    while(1){

        cin >> option;

        switch(option){
        case 'I':
            //create the pic
            cin >> col >> row;
            clearPic();
            break;
        case 'C':
            //clear the pic
            clearPic();
            break;
        case 'L':
            //colors the pixels with coordinates (x, y) in color C
            cin >> x1 >> y1 >> color;
            pic[y1-1][x1-1] = color;
            break;
        case 'V':
            //vertical Segment
            cin >> x1 >> y1 >> y2 >> color;

            if(y1 > y2){
                y2 = y1 + y2;
                y1 = y2 - y1;
                y2 = y2 - y1;
            }

            for(i = y1-1; i < y2; ++i){
                pic[i][x1-1] = color;
            }
            break;
        case 'H':
            //horizontal segment
            cin >> x1 >> x2 >> y1 >> color;

            if(x1 > x2){
                x1 = x1 + x2;
                x2 = x1 - x2;
                x1 = x1 - x2;
            }

            for(i = x1-1; i < x2; ++i){
                pic[y1-1][i] = color;
            }
            break;
        case 'K':
            //draw rectangle
            cin >> x1 >> y1 >> x2 >> y2 >> color;

            if(x1 > x2){
                x1 = x1 + x2;
                x2 = x1 - x2;
                x1 = x1 - x2;
            }

            if(y1 > y2){
                y2 = y1 + y2;
                y1 = y2 - y1;
                y2 = y2 - y1;
            }

            for(i = y1-1; i < y2; ++i)
                for(j = x1-1; j < x2; ++j)
                    pic[i][j] = color;
            break;
        case 'F':
            cin >> x1 >> y1 >> color;
            preColor = pic[y1-1][x1-1];

            fill(y1-1, x1-1, color);

            break;
        case 'S':
            //save and display
            cin >> name;
            cout << name << '\n';
            displayPic();
            break;
        case 'X':
            return 0;
        }
    }

    return 0;
}
