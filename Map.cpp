//map.cpp

#include "GameOfLife.h"

Map::Map(int r,int c){//makes the map
  rows = r;
  cols = c;
  maptype = 

  /*char** grid = new char*[rows];
  for(int i = 0; i < rows; ++i){
    grid[i] = new char[cols];
  }
  */
  char grid[100][100];
}

Map::~Map(){
  /*for(int i = 0; i < cols; ++i) {
      delete [] grid[i];
  }
  delete [] grid;
  cout<<"map deleted"<<endl;*/
}

void Map::MapFromString(string str){//make a map from a user inputed file
  char c;
  int curRow = 0;
  int curCol = 0;

  for(int i = 0; i<str.size(); ++i){
    c = str.at(i);
    if(c == '\n'){
      curRow++;
      curCol = 0;
    }else if(c == 'X'){
      grid[curRow][curCol] = 'X';
      curCol++;
    }else if(c =='-'){
      grid[curRow][curCol] = '-';
      curCol++;
    }else if(c == char(10)||c == (char)(13)||c == ' '){//I dont know why these chars are in a text file
      continue;
    }else{
      cout<<"Something went wrong in Map::MapFromString(string str)"<<endl;
      cout<<(int)c<<endl;
      break;
    }
  }
  cout<<MapToString()<<endl;
}

void Map::RandomMap(){
  cout<<"What initial population density would you like? (0,1]"<<endl;
  float popDensity = 0;
  cin>>popDensity;
  int numCells = (int)(popDensity*rows*cols);
  if(numCells == 0){
    numCells = 1;
  }

  for(int i =0; i<rows; ++i){
    for(int j = 0; j<cols; ++j){
      grid[i][j] = '-';
    }
  }

  srand (time(NULL));//generates a random seed for rand()
  while(numCells != 0){
      int row = rand() % rows;
      int col = rand() % cols;
      if(grid[rows][cols] != 'X'){
        grid[row][col]='X';
        numCells--;
      }
  }

  cout<<MapToString()<<endl;
}

string Map::MapToString(){
  string ret = "";//return string

  for(int i =0; i<rows; ++i){
    for(int j = 0; j<cols; j++){
      ret += grid[i][j];
    }
    ret += '\n';
  }


  return ret;
}

int Map::NumNeighbors(int r,int c){
  cout<<"executing Map::Numneighbors"<<endl;
  //subNumNeighbors(r, c);
}

/*int Map::subNumNeighbors(int r, int c){
  cout<<"executing Math::subNumNeighbors"<<endl;
}*/
