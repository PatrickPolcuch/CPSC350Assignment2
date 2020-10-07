//my .h file
#include <iostream>
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
  Map();
  ~Map();
  void ReadFile();
  void RandomMap(int r,int c);
  void MapFromString();
};

class ClassicMap: public Map{
public:
  //functions
};

class MirrorMap:public Map{
public:
  //functions
};

class DoughnutMap:public Map{
public:
  //functions
};
