//map.cpp

#include "GameOfLife.h"

Map::Map(int r,int c){//makes the map
  int** a = new int*[r];
  for(int i = 0; i < rowCount; ++i){
    a[i] = new int[c];
  }
}

Map::Map(int r,int c, string text){//make a map from a file
  int** grid = new int*[r];
  for(int i = 0; i < c; ++i){
    a[i] = new int[c];
  }
}

Map::~Map(){
  for(int i = 0; i < c; ++i) {
      delete [] grid[i];
  }
  delete [] grid;
}

void Map::MapFromString(){//make a map from a user inputed file

}

void Map::RandomMap(int r,int c){
  cout<<"What initial population density would you like? (0,1]"<<endl;
  float popDensity = 0;
  cin>>popDensity;
  int numCells = (int)(popDensity*r*c);
  if(numCells == 0){
    numCells = 1;
  }

  srand (time(NULL));//generates a random seed for rand()
  while(numCells != 0){
      int row = rand() % r;
      int col = rand() % c;
      if(/*2DArray[r][c] != 'X'*/){
        //2DArray[r][c]='X';
        numCells--;
      }
  }
}
