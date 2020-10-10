/*Patrick Polcuch
2348668
CPSC350Assignment2
my .h file
*/

#include <iostream>
#include <fstream>
#include <sstream>//used to get integers from a file
#include <chrono>//for the sleep_for() function
#include <thread>//for the sleep_for() function

using namespace std;
using namespace std::this_thread;//for the sleep_for() function
using namespace std::chrono;//for the sleep_for() function

class runGame{
public:
  runGame();
  ~runGame();
  static void run();
  static void pause(char type);
};

class Map{
public:
  Map(int r,int c, char type);
  ~Map();
  void ReadFile();
  void RandomMap();
  void MapFromString(string str);
  string MapToString();
  int NumNeighbors(int r,int c);
  int NumNeighborsClassic(int r,int c);
  int NumNeighborsDoughnut(int r,int c);
  int NumNeighborsMirror(int r,int c);
  string NextGen();

  int grid[100][100];
  int rows;
  int cols;
  char maptype;

};
