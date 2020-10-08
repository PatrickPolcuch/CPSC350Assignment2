//runGame.cpp

#include "GameOfLife.h"

runGame::runGame(){
  //dont need a contructor
}

runGame::~runGame(){

}

void runGame::run(){
  Map* myMap;

  cout<<"What type of map would you like, Doughnut, Mirror, or Classic? (enter as 'D', 'M', or 'C')"<<endl;
  string usermap ="";
  cin>>usermap;

  cout<<"Would you like to like to start from a file, or generate a random map? (file/rand)"<<endl;
  string userfile = "";
  cin>>userfile;

  int rows;
  int cols;
  string text = "empty";
  if(userfile.compare("file")==0||userfile.compare("File")==0){
    cout<<"What is the name of the file?"<<endl;
    string fileName;
    cin>>fileName;

    ifstream myFile;
    myFile.open(fileName);

    string curLine;
    getline(myFile,curLine);

    stringstream intRow(curLine);
    intRow>>rows;

    getline(myFile,curLine);
    stringstream intCol(curLine);
    intCol>>cols;

    text = "";
    while(getline(myFile,curLine)){
      text +=curLine+'\n';
    }
  }else{
    cout<<"How many rows?"<<endl;
    cin>>rows;

    cout<<"How many colums?"<<endl;
    cin>>cols;
  }

    if(usermap.compare("D")==0||usermap.compare("d")==0){
      myMap = new DoughnutMap(rows, cols);
    }else if(usermap.compare("M")==0||usermap.compare("m")==0){
      myMap = new MirrorMap(rows, cols);
    }else if(usermap.compare("C")==0||usermap.compare("c")==0){
      myMap = new ClassicMap(rows, cols);
    } else{
      cout<<"Incorrect input for map type"<<endl;
    }

    if(text.compare("empty")==0){
      myMap->RandomMap();
    }else{
      myMap->MapFromString(text);
    }

  int a = myMap->NumNeighbors(0,0);
  cout<<a<<endl;
  delete myMap;
}
