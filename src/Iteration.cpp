//
// Created by hp on 15.11.2020.
//

#include "Iteration.h"
#include <iostream>
#include <string>
#include "Methods.h"
#include <cstring>
#include "ReadingFile.h"
using namespace std;
void Iteration::iteration(string path1 , string path2,string path3) {
    ReadingFile read;
    Methods method;
    Writing write;
    method.fill_the_arrs(path1);
    method.Print("\n");
    int number=0;
    while(true) {
        number++;
        string a=read.Read2(path2,number);
        string array[20];
        write.writefile(a+"\n\n");
        char commandarray[a.length()];
        strcpy(commandarray, a.c_str());
        char split[] = " ";
        char *str = strtok(commandarray, " ");

        int i = 0;
        while (str) {
            array[i] = str;
            str = strtok(NULL, split);
            i++;
        }


          if(array[0]=="exit") {
              write.writefile("exit\n\n");
              write.writefile("****************************************\n\n");
              write.writefile("Game Over!");
              break;
          }
          if(array[0]== "open") {


              if(array[1]=="from") { //from stock
                  string c="open from stock";
                  method.open(c);
              }
              else { //from pile
                  int sayi=stoi(array[1]);
                  method.open(sayi);
              }
          }
          else {
              if(array[1]=="pile") { // for pile
                  int numbercards=stoi(array[3]);
                  if(array[2]==array[4]) {
                      cout<<"Invalid Move"<<endl;
                  }
                  else {
                      method.movepile(array[2], array[4], numbercards);
                  }
              }
              else if(array[1]=="waste") { //move waste
                    method.Move_Waste(array[2]);
              }
              else if(array[2]=="foundation"&array[3]=="pile") {
                  method.Move_to_foundation_pile(array[4]);
              }
              else if(array[2]=="foundation"&array[3]=="waste") {
                  method.Move_to_foundation_waste();
              }

          }
          if(method.Win()) {
            write.writefile("****************************************\n\n");
            write.writefile("You Win!\n\n");
            write.writefile("Game Over!");
            break;
          }




      }



}