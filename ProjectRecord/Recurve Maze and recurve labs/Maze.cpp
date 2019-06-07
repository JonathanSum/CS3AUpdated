
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <cstring>
#include <vector>
#include <string>
/*********************************************
*   Author         : Jonathan Sum
*   Assignment     : Lab 14 - Recursion
*   SECTION        : CS 003A
*   Due Date       : 4/28/19
*   ________________________________________________
*   Goal: write a maze
***********************************************/


using namespace std;

/***************************************************
*
*   FUNCTION void drawCross(int minX, int maxX, int minY, int maxY,vector<vector<string> > &maze);
________________________________________________
*   This function builds a maze recursively.
________________________________________________
*   PRE-CONDITIONS
*   empty maze with only borders of walls
*   POST-CONDITIONS
*   a complete maze
*****************************************************/
const int ROW = 10,         //IN - row of the maze
        COL = 12;         //IN - column of the maze

void drawCross(int minX      //IN - left edge of the maze
        , int maxX      //IN - right edge of the maze
        , int minY      //IN - upper edge of the maze
        , int maxY      //IN - lower edge of the maze
        ,vector<vector<string> > &maze      //IN - maze
        );


int main(){
    const string b = "\u25A0";      //IN shape of the wall

    //set up the randam seed
    srand(static_cast<unsigned int>(time(nullptr)));



    //IN & PROCESSING build a default maze
    vector<vector<string> > mazeMap
            {{b, b,    b,    b,    b,    b,    b,    b,    b,    b,    b,    b,    b},  //0
             {b, "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", b},  //1
             {b, "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", b},  //2
             {b, "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", b},  //3
             {b, "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", b},  //4
             {b, "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", b},  //5
             {b, "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", b},  //6
             {b, "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", b},  //7
             {b, "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", b},  //8
             {b, "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", b},  //9
             {b, b,    b,    b,    b,    b,    b,    b,    b,    b,    b,    b,    b},};//10
          //  0   1    2     3     4     5     6     7     8     9     10    11   12

    //Processing build all the walls in the maze
    drawCross(1,COL-1,1,ROW-1,mazeMap);

    //OUT  - print out the whole maze
    for (int i = 0; i < 11; i++) {

        for (int j = 0; j < 13; j++) {
            cout << mazeMap[i][j];

        }
        cout << endl;
    }

    return 0;

}






//drawCross(1,11,1,9,mazeMap);
void drawCross(int minX, int maxX, int minY, int maxY,vector<vector<string> > &maze) {

    //Processing - base cause that if width of walls are less than one space.
    if(( minX==maxX)||(minY==maxY)){

        return;
    }else {

        int ranVerX,           //PROCESSING set up the horizontal position of the cross shape wall
        ranVerY;                //PROCESSING set up the vertical position of the cross shape wall
        const string b = "\u25A0";           //IN - the shape of wall

        //PROCESSING set up the horizontal and vertical position
        // of the cross shape wall

        //Processing - base cause that if width of walls are than one space.
        if((minX+1)==maxX){
            return;
        }else{
           ranVerX = (minX + 1) + rand() % (((maxX - 1) + 1) - (minX + 1));


        }
        if((minY+1)==maxY){

            return;
        }else{
             ranVerY = (minY + 1) + rand() % (((maxY - 1) + 1) - (minY + 1));
        }



        int left            //PROCESSING - hole at the left of the cross shape wall
        , right            //PROCESSING - hole right of the cross shape wall
        , up            //PROCESSING - hole of right the cross shape wall
        , down;            //PROCESSING - holeof right the cross shape wall

        //PROCESSING & IN set up the location of three holes of two walls
        if ((maxX - 1) == (ranVerX + 1)) {
            right =( maxX - 1);
        } else {
            right = (ranVerX + 1) + rand() % ((maxX - 1) - (ranVerX + 1));
        }
        if ((maxY - 1) == (ranVerY + 1)) {
            down = maxY - 1;
        } else {
            down = (ranVerY + 1) + rand() % (maxY - 1 - (ranVerY + 1));
        }
        if((ranVerX  == minY)==0){

        }
        left = minX + rand() % (((ranVerX + 1) - 1) - minX);

        up = minY + rand() % ((ranVerY + 1) - 1 - minY);




        //PROCESSING - build a horizontal line
        for (int j = minX; j <= maxX; j++) {

            maze[ranVerY][j] = b;
        }
        //PROCESSING - build a vertical line
        for (int i = minY; i <= maxY; i++) {

            maze[i][ranVerX] = b;
        }

        //randomly choice holes are left wall, right wall and upper wall
        //or down wall, left wall and upper wall
        int half = 1 + rand() % ((2 + 1) - 1);

        //PROCESSING - build three holes
        if (half == 1) {

            maze[ranVerY][left] = "  ";
            maze[ranVerY][right] = "  ";
            maze[up][ranVerX] = "  ";
        } else {

            maze[down][ranVerX] = "  ";
            maze[ranVerY][left] = "  ";
            maze[up][ranVerX] = "  ";
        }
        //PROCESSING - build an exit and entry
        if(maxX==11&&maxY==9&&minX==1&&minY==1){
            maze[0][ranVerX]="  ";
            maze[1][ranVerX]="  ";
            maze[9][ranVerX]="  ";
            maze[10][ranVerX]="  ";
        }
    //PROCESSING - Recursion any upper right corners of four corners in the square maze

    drawCross(minX, ranVerX - 1, minY, ranVerY - 1, maze);
        //PROCESSING - Recursion any lower right corners of four corners in the square maze
    drawCross( minX, ranVerX-1, ranVerY+1,  maxY,maze);
        //PROCESSING - Recursion any upper left corners of four corners in the square maze
    drawCross(ranVerX+1,  maxX,  minY, ranVerY-1,maze);
        //PROCESSING - Recursion any lower left corners of four corners in the square maze
    drawCross(ranVerX+1,  maxX, ranVerY+1,  maxY,maze);
    }

}
