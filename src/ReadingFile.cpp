//
// Created by hp on 14.11.2020.
//

#include "ReadingFile.h"
#include <iostream>
#include <string>
#include "Iteration.h"
#include "Methods.h"
using namespace std;
ReadingFile::ReadingFile()  {

}
Methods methods;
Iteration iteration;
void ReadingFile::Read(string cards[],string path) {
    fstream file(path);
    if(!file) {
        printf("file does not exist");
    }
    else{
        for(int i = 51 ; i >=0 ; i--) {
            string card;
            file>>card;
            cards[i]=card;
        }

    }

}
string ReadingFile::Read2(string path,int i) {
    fstream file(path);
    string command;
    if(!file) {
        printf("file does not exist");
    }
    else{
        while(file&&i>0) {
            getline(file, command);
            i -= 1;
        }
    }
    return command;
}
