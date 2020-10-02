//my .h file
#include <iostream>

using namespace std;

class runGame{
public:
  static void runGame(Map m);
};

class map{
public:
  Map();
  ~Map();
  void ReadFile();
};

class ClassicMap:public map{
public:
  //functions
};

class MirrorMap:public map{
public:
  //functions
};

class DoughnutMap:public map{
public:
  //functions
};
