//
// Created by hp on 14.11.2020.
//

#ifndef ASSIGNMENT1_READINGFILE_H
#define ASSIGNMENT1_READINGFILE_H
#include <iostream>
#include <fstream>
using namespace std;

class ReadingFile {
public:
    ReadingFile();
    void Read(string a[],string path);
    string Read2(string path,int i);
};






#endif //ASSIGNMENT1_READINGFILE_H
