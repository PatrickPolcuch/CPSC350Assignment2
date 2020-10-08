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
  Map(int r,int c);
  ~Map();
  void ReadFile();
  void RandomMap();
  void MapFromString(string str);
  string MapToString();
  int NumNeighbors(int r,int c);

  int grid[100][100];
  int rows;
  int cols;
//private:
//  int subNumNeighbors(int r,int c);
};

class ClassicMap: public Map{
public:
  ClassicMap(int r,int c);
  ~ClassicMap();
  int NumNeighbors(int r,int c);
  //int Method(int r,int c);
};

class MirrorMap:public Map{
public:
  MirrorMap(int r,int c);
  ~MirrorMap();


};

class DoughnutMap:public Map{
public:
  DoughnutMap(int r,int c);
  ~DoughnutMap();
};
