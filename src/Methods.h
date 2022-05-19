//
// Created by hp on 14.11.2020.
//

#ifndef ASSIGNMENT1_METHODS_H
#define ASSIGNMENT1_METHODS_H

#include <iostream>
#include "ReadingFile.h"
#include "Writing.h"
using namespace std;
class Methods {
public:
    string pile_0[20],pile_1[20],pile_2[20],pile_3[20],pile_4[20],pile_5[20],pile_6[20];
    string pile0[20],pile1[20],pile2[20],pile3[20],pile4[20],pile5[20],pile6[20];
    string stock[24];
    string foundation_1[13],foundation_2[13],foundation_3[13],foundation_4[13];
    string *mystack[7] = {pile_0,pile_1,pile_2,pile_3,pile_4,pile_5,pile_6};
    string foundation1,foundation2,foundation3,foundation4,foundationcontrol;
    string slot1="___";
    string slot2="___";
    string slot3="___";
    string slotcontrol;
    int control=0;
    Methods();
    void fill_the_arrs(string a[],string b[]);
    void fill_the_arrs(string path);
    void open(string input);
    void open(int number);
    void open_method_helper(string arr_1[],string arr_2[]);
    void movepile(string pile_type1,string pile_type2,int number_of_cards);
    string Finding_card1(string type,int cardsnumber);
    string Finding_card2(string type);
    void Changing_cards(string pile_type1,string pile_type2,string card1,string card2,string cards[]);
    void Print(string n);
    bool card_control_method(string card1,string card2);
    bool card_control_method_foundation(string card1,string card2);
    void Move_Waste(string pile_type);
    string card_Finding(string pile_type);
    void Move_to_foundation_pile(string pile_type);
    void Move_to_foundation_waste();
    bool Win();



};


#endif //ASSIGNMENT1_METHODS_H
