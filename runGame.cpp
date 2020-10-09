//runGame.cpp

#include "GameOfLife.h"

runGame::runGame(){
  //dont need a contructor
}

runGame::~runGame(){

}

void runGame::run(){

  cout<<"What type of map would you like, Doughnut, Mirror, or Classic? (enter as 'D', 'M', or 'C')"<<endl;
  string usermapStr ="";
  cin>>usermapStr;

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

  char usermapChar = 'C';
  if(usermapStr.compare("D")==0||usermapStr.compare("d")==0){
    usermapChar = 'D';
  }else if(usermapStr.compare("M")==0||usermapStr.compare("m")==0){
    usermapChar = 'M';
  }else if(usermapStr.compare("C")==0||usermapStr.compare("c")==0){
    usermapChar = 'C';
  } else{
    cout<<"Incorrect input for map type, defaulting to Classic map"<<endl;
  }

  Map* myMap = new Map(rows, cols, usermapChar);

  if(text.compare("empty")==0){
    myMap->RandomMap();
  }else{
    myMap->MapFromString(text);
  }

  char delivery;
  cout<<"Would you like to hit enter before each generation, have a brief pause between generations, of output all generations to a file? ('E','P','F')"<<endl;
  cin>>delivery;

  string fileContents = "";

  int generation = 0;
  string gen0 = "gen0";
  string gen1 = "gen1";
  string gen2 = "gen2";

  cout<<"Generation "<<generation<<'\n'<<myMap->MapToString()<<endl;
  while(true){
    string next = myMap->NextGen();
    generation++;

    if(generation%3==0){
      gen0=next;
    }else if(generation%3==1){
      gen1 =next;
    }else if(generation%3==2){
      gen2 = next;
    }
    if(gen0.compare(gen1)==0||gen0.compare(gen2) == 0||gen1.compare(gen2) == 0){
      cout<<"Stabelized"<<endl;
      break;
    }
    cout<<"Generation "<<generation<<'\n'<<next<<endl;
  }

  delete myMap;
}
