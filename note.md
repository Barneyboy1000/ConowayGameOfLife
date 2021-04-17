# Notes on how I created a solution
Firstly, Looking at the GameOfLife class I realised that it is called by application, which is run by main.

## Implementing evolve functionality
Some nested for loop needed to be created to check each cell and make sure that cell needs to be born or dies.
If the counted neighbour cells == 3 then another cell is born.
If the counted neighbour cells is neither 3 and 2 then it is killed.

## Impleting the Cellular Grid function
Needed to make the constructor for the class, so I made three private variables. Two to represent the height and Width and the other to represent charaters to store the cells.
Implemented the getters by just returning the private variables.
To check if a cell is alive, I added X and Y, multiplyed it by the width of the grid and checked if that cell contained a '*' which represents an alive cell.
To kill a cell we just assign a '-' at the cell location depending on the parameters
To recieve a cell we just do the same as the kill cell its just use '*' instead

## Implementing the count neighbour code
Finally, to count the number of neighbouring cells. Well we can take the width of the whole arena and add it to the passed value, and by adding it to the value in a for loop we can get its general position.
So, we use the for loop to represent the neigbouring cells from -1 representing the lowest corner of the cell and 2 representing the highest corner.
By going through each value and modding each x and y coordinate with the total will give a remainder of how much into the matrix we are and therefore the position of the surrounding cell.
But, now we have the new x and y coordinates and do a check to see if there is something there. 0s and 1s can be added to a total value and returned to represent the number of surrounding cells.

## Upon first run
Errors occured saying "'CellularGrid::~CellularGrid': cannot define a compiler-generated special member function (must be declared in the class first)".
Must mean I forgot to declare in in the header file.

## Upon second run
Run time error occured stating " The variable 'n' is being used without being initialized." in the countLivingCellNeighbours (int x, int y) function.
Changed the function so its shows n = 0 when initializing the the local variables

## Upon third run
The code ran but didnt do what I expected, also an exception occured at the end so I called the destructor at the end of the GameOfLife run function.
Even when I surround the program in an exception it still throws and exception. Not sure what is happening so I will move on.

## last run
I think the code runs well, so I will hand it in