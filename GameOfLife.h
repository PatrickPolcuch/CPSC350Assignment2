//my .h file
#include <iostream>
#include <fstream>
#include <sstream>
#include <math.h>

using namespace std;

class runGame{
public:
  runGame();
  ~runGame();
  static void run();
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
