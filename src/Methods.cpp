//
// Created by hp on 14.11.2020.
//

#include "Methods.h"
#include <iostream>
#include <string>
#include "Writing.h"


using namespace std;
 Methods::Methods() {}
void Methods::fill_the_arrs(string a[], string b[]) { // this method was writen to fill the pile arrays which have "@@@"
     string c;
     for(int i = 0 ; i<13;i++) {
         if(a[i].compare(c)!=0) {
             if(a[i+1].compare(c)!=0) {
                 b[i]="@@@";
             }
             else {
                 b[i]=a[i];
                 break;
             }
         }
         else {
             break;
         }
     }

 }
void Methods::fill_the_arrs(string path) { //// this method was writen to fill the stock and foundation and other pile arrays which dont have "@@@"
     string cards[52];
     ReadingFile read;
     read.Read(cards,path);
     int a=0;
     int b=0;
     for(int i = 0 ; i<7 ; i++) {
         *Methods::mystack[i]=cards[a];
         a++;

         if(i==6) {
             b++;
             i=b-1;
             for(int j = i ; j<7 ; j++) {
                 *Methods::mystack[j]++;
             }
         }
     }
    for(int i = 28,j=0 ; i<52 ; i++ , j++) {
        Methods::stock[j]=cards[i];
    }
    fill_the_arrs(pile_1,pile1);
    fill_the_arrs(pile_2,pile2);
    fill_the_arrs(pile_3,pile3);
    fill_the_arrs(pile_4,pile4);
    fill_the_arrs(pile_5,pile5);
    fill_the_arrs(pile_6,pile6);
    fill_the_arrs(pile_0,pile0);

 }
Writing write;

void Methods::Print(string n) { // this method ıterate in arrays and give output
        //write.writefile("\n");
        write.writefile(n);
        string a,b,c,d,e,f,g,h;
        bool control2=false;
        if(control==0) {
            write.writefile("@@@ ___ ___ ___         ");

        }
        else {
            for(int i = control; i<24 ; i++) {
                if(stock[i].compare(slotcontrol)!=0)
                    control2=true;
            }
            if(control2) {
                write.writefile("@@@ ");
                if(slot1.compare(slotcontrol)==0) {
                    slot1="___";
                }
                if(slot2.compare(slotcontrol)==0) {
                    slot2="___";
                }
                if(slot3.compare(slotcontrol)==0) {
                    slot3="___";
                }
                write.writefile(slot1+" "+slot2+" "+slot3+"         ");
            }
            else {
                write.writefile("___ ");
                control=27;
                if(slot1.compare(slotcontrol)==0) {
                    slot1="___";
                }
                if(slot2.compare(slotcontrol)==0) {
                    slot2="___";
                }
                if(slot3.compare(slotcontrol)==0) {
                    slot3="___";
                }
                write.writefile(slot1+" "+slot2+" "+slot3+"         ");
            }
            }
        if(foundation_1[0].compare(foundationcontrol)==0) {
            foundation1="___";
        }
        else{
            for(int i = 12 ; i>=0; i--) {
                if(foundation_1[i]!="") {
                    foundation1 = foundation_1[i];
                    break;
                }
            }
        }
        if(foundation_2[0].compare(foundationcontrol)==0) {
            foundation2="___";
        }
        else{
            for(int i = 12 ; i>=0; i--) {
                if(foundation_2[i]!="") {
                    foundation2 = foundation_2[i];
                    break;
                }
                }
        }
        if(foundation_3[0].compare(foundationcontrol)==0) {
            foundation3="___";
        }
        else{
            for(int i = 12 ; i>=0; i--) {
                if(foundation_3[i]!="") {
                    foundation3 = foundation_3[i];
                    break;
                }
                }
        }
        if(foundation_4[0].compare(foundationcontrol)==0) {
            foundation4="___";
        }
        else{
            for(int i = 12 ; i>=0; i--) {
                if(foundation_4[i]!="") {
                    foundation4 = foundation_4[i];
                    break;
                }
                }
        }
    write.writefile(foundation1+" "+foundation2+" "+foundation3+" "+foundation4+"\n\n");


        for(int i = 0 ; i < 13 ; i++) {
            if(pile0[i].compare(a)==0)
                b="   ";
            if(pile1[i].compare(a)==0)
                c="   ";
            if(pile2[i].compare(a)==0)
                d="   ";
            if(pile3[i].compare(a)==0)
                e="   ";
            if(pile4[i].compare(a)==0)
                f="   ";
            if(pile5[i].compare(a)==0)
                g="   ";
            if(pile6[i].compare(a)==0)
                h="   ";
            if(pile6[i].compare(a)==0&pile5[i].compare(a)==0&pile4[i].compare(a)==0&pile3[i].compare(a)==0&pile2[i].compare(a)==0&pile1[i].compare(a)==0&pile0[i].compare(a)==0){
                break;
            }
            write.writefile(b+Methods::pile0[i]+"   "+c+Methods::pile1[i]+"   "+d+Methods::pile2[i]+"   "+e+Methods::pile3[i]+"   "+f+Methods::pile4[i]+"   "+g+Methods::pile5[i]+"   "+h+Methods::pile6[i]+"\n");
           // cout<<s+Methods::pile_0[i]+"  "+Methods::pile_1[i]+"  "+Methods::pile_2[i]+"  "+Methods::pile_3[i]+"  "+Methods::pile_4[i]+"  "+Methods::pile_5[i]+"  "+Methods::pile_6[i]<<endl;
        }
        write.writefile("\n");

}
void Methods::open(string input)  { // this method travels in stock arrays and change the slot cards
     string slot_1=slot1;
     string slot_2=slot2;
     string slot_3=slot3;
        int number1=0;
        int lastindex=0;
        for(int i = 23 ; i>= 0 ; i--) {
            if(!(stock[i]=="")||!(stock[i]=="___")) {
                lastindex=i;
                break;
            }
        }
        if(control>lastindex) {
            control=0;
            Print("****************************************\n\n");
            return;
        }
        for(; control<24; control++) {

            if(stock[control]==""||stock[control]=="___") {
                continue;
            }

            else {
                if(number1==0) {
                    slot1=stock[control];
                    number1++;
                }
                else if(number1==1) {
                    slot2=stock[control];
                    number1++;
                }
                else {
                    slot3=stock[control];
                    number1++;
                    control++;
                    break;
                }
            }
        }
        int number2=0;
    for(int i =0 ; i < 24 ; i++) {
        if(!(stock[i]==""||stock[i]=="___")) {
            number2++;
        }
    }
    if(number2>3) {
        if (slot_1 == slot1) {
            slot1 = "";
        }
        if (slot_2 == slot2) {
            slot2 = "";
        }
        if (slot_3 == slot3) {
            slot3 = "";
        }
    }
        Print("****************************************\n\n");

}
void Methods::open_method_helper(string arr_1[],string arr_2[]) {
     bool a = true;
    for(int i = 0 ; i < 13 ; i++) {
        if(arr_2[i+1].compare("")==0&arr_2[i].compare("@@@")==0) {
            arr_2[i]=arr_1[i];
            a=false;
        }
    }
    if(a) {
        write.writefile("invalid move\n");

        Print("****************************************\n\n");
    }
    else {
        Print("****************************************\n\n");
    }
}
void Methods::open(int number) { // this method open the closed cards
     if(number==0) {
         open_method_helper(pile_0,pile0);
     }
     else if(number==1) {
         open_method_helper(pile_1,pile1);
     }
     else if(number==2) {
         open_method_helper(pile_2,pile2);
     }
     else if(number==3) {
         open_method_helper(pile_3,pile3);
     }
     else if(number==4) {
         open_method_helper(pile_4,pile4);
     }
     else if(number==5) {
         open_method_helper(pile_5,pile5);
     }
     else {
         open_method_helper(pile_6,pile6);
     }

 }
 bool Methods::card_control_method(string card1, string card2) { // I compare the cards by using this method
     string card1copy=card1;
     if(card2=="") {
         if((card1copy.erase(0,1)=="13")) {
             return true;
         }
         else {
             return false;
         }
     }
     if(card2=="@@@") {
         return false;
     }
     char card_type1 =card1.at(0);
     card1.erase(0,1);
     int card_number1=stoi(card1);
     char card_type2 =card2.at(0);
     card2.erase(0,1);
     int card_number2=stoi(card2);
     if((card_type1=='H'|| card_type1=='D') &(card_type2=='C' || card_type2=='S')) {
         if(card_number2-card_number1==1) {
             return true;
         }
     }
     else if((card_type1=='C' || card_type1=='S') &(card_type2=='H' || card_type2=='D')){
         if(card_number2-card_number1==1) {
             return true;
         }
     }
     return false;

 }

bool Methods::card_control_method_foundation(string card1,string card2) {
    char card_type1 =card1.at(0);
    card1.erase(0,1);
    int card_number1=stoi(card1);
    if(card2==""&&card_number1==1) {
        return true;
    }
    else if( card2==""&&card_number1!=1) {
        return false;
    }
    char card_type2 =card2.at(0);
    card2.erase(0,1);
    int card_number2=stoi(card2);
    if((card_type1=='S' & card_type2=='S') ||(card_type1=='C'& card_type2=='C' )||(card_type1=='H' & card_type2=='H' )||(card_type1=='D' & card_type2=='D' )){
        if(card_number1-card_number2==1) {
            return true;
        }
    }
     return false;
 }

string Methods::Finding_card1(string type,int cardsnumber) {//I find the cards which are expected to move
     string card;
     if(type=="0") {
         for(int i = 19 ; i>=0 ; i--) {
             if(!(pile0[i]=="")) {
                 if(cardsnumber>0) {
                     card = pile0[i];
                     cardsnumber-=1;
                 }
             }
         }
         if(card==""||card=="@@@"||(cardsnumber>0)) {
             write.writefile("invalid move\n");
             Print("****************************************\n\n");
             return "";
         }
         else {
             return card;
         }

     }
     else if(type=="1") {
         for(int i = 19 ; i>=0 ; i--) {
             if(!(pile1[i]=="")) {
                 if(cardsnumber>0) {
                     card = pile1[i];
                     cardsnumber-=1;
                 }
             }
         }
         if(card==""||card=="@@@"||(cardsnumber>0)) {
             write.writefile("invalid move\n");
             Print("****************************************\n\n");
             return "";
         }
         else {
             return card;
         }

     }
     else if(type=="2") {
         for(int i = 19 ; i>=0 ; i--) {
             if(!(pile2[i]=="")) {
                 if(cardsnumber>0) {
                     card = pile2[i];
                     cardsnumber-=1;
                 }
             }
         }
         if(card==""||card=="@@@"||(cardsnumber>0)) {
             write.writefile("invalid move\n");

             Print("****************************************\n\n");
             return "";
         }
         else {
             return card;
         }

     }
     else if(type=="3") {
         for(int i = 19 ; i>=0 ; i--) {
             if(!(pile3[i]=="")) {
                 if(cardsnumber>0) {
                     card = pile3[i];
                     cardsnumber-=1;
                 }
             }
         }
         if(card==""||card=="@@@"||(cardsnumber>0)) {
             write.writefile("invalid move\n");
             Print("****************************************\n\n");
             return "";
         }
         else {
             return card;
         }

     }
    if(type=="4") {
        for(int i = 19 ; i>=0 ; i--) {
            if(!(pile4[i]=="")) {
                if(cardsnumber>0) {
                    card = pile4[i];
                    cardsnumber-=1;
                }
            }
        }
        if(card==""||card=="@@@"||(cardsnumber>0)) {
            write.writefile("invalid move\n");

            Print("****************************************\n\n");
            return "";
        }
        else {
            return card;
        }

    }
    if(type=="5") {
        for(int i = 19 ; i>=0 ; i--) {
            if(!(pile5[i]=="")) {
                if(cardsnumber>0) {
                    card = pile5[i];
                    cardsnumber-=1;
                }
            }
        }
        if(card==""||card=="@@@"||(cardsnumber>0)) {
            write.writefile("invalid move\n");
            Print("****************************************\n\n");
            return "";
        }
        else {
            return card;
        }

    }
    else {
        for(int i = 19 ; i>=0 ; i--) {
            if(!(pile6[i]=="")) {
                if(cardsnumber>0) {
                    card = pile6[i];
                    cardsnumber-=1;
                }
            }
        }
        if(card==""||card=="@@@"||(cardsnumber>0)) {
            write.writefile("invalid move\n");
            Print("****************************************\n\n");
            return "";
        }
        else {
            return card;
        }
    }
 }
string Methods::Finding_card2(string type) { // I find host cards by using this method
     string card2;
     if(type=="0") {
         for(int i =19 ; i>=0 ; i--) {
             if(!(pile0[i]=="")) {
                 card2=pile0[i];
                 return card2;
                 }
             }
         }
     else if(type=="1") {
         for(int i =19 ; i>=0 ; i--) {
             if(!(pile1[i]=="")) {
                 card2=pile1[i];
                 return card2;
             }
         }
     }
     else if(type=="2") {
         for(int i =19 ; i>=0 ; i--) {
             if(!(pile2[i]=="")) {
                 card2=pile2[i];
                 return card2;
             }
         }
     }
     else if(type=="3") {
         for(int i =19 ; i>=0 ; i--) {
             if(!(pile3[i]=="")) {
                 card2=pile3[i];
                 return card2;
             }
         }
     }
     else if(type=="4") {
         for(int i =19 ; i>=0 ; i--) {
             if(!(pile4[i]=="")) {
                 card2=pile4[i];
                 return card2;
             }
         }
     }
     else if(type=="5") {
         for(int i =19 ; i>=0 ; i--) {
             if(!(pile5[i]=="")) {
                 card2=pile5[i];
                 return card2;
             }
         }
     }
     else {
         for(int i =19 ; i>=0 ; i--) {
             if(!(pile6[i]=="")) {
                 card2=pile6[i];
                 return card2;
             }
         }
     }
     return "";
 }

void Methods::Changing_cards(string pile_type1,string pile_type2,string card1,string card2,string cards[]) { // this method change the cards.
     string card1copy=card1;
    if(pile_type1=="0") {
        int number = 0 ;
        for(int i = 0 ; i< 19 ; i++) {
            if(pile0[i]==card1) {
                for(int j = i ; j<20 ; j++ ) {
                    if(!(pile0[j]=="")) {
                        cards[number]=pile0[j];
                        pile0[j]="";
                        pile_0[j]="";
                        number++;
                    }
                }
                break;
            }
        }
        if(pile_type2=="6") {
            for(int i = 0 ; i<19 ; i++) {
                if(pile6[i]==card2) {
                    for(int j = 0 ; j < number;j++) {
                        if(i==0) {
                            if(card2=="") {
                                pile6[i] = cards[j];
                                pile_6[i] = cards[j];
                                i++;
                            }
                            else {
                                pile6[i+1] = cards[j];
                                pile_6[i+1] = cards[j];
                                i++;
                            }
                        }
                        else {
                            pile6[i + 1] = cards[j];
                            pile_6[i + 1] = cards[j];
                            i++;
                        }
                    }
                    break;
                }
            }
        }
        else if(pile_type2=="2") {
            for(int i = 0 ; i<19 ; i++) {
                if(pile2[i]==card2) {
                    for(int j = 0 ; j < number;j++) {
                        if(i==0) {
                            if(card2=="") {
                                pile2[i] = cards[j];
                                pile_2[i] = cards[j];
                                i++;
                            }
                            else {
                                pile2[i+1] = cards[j];
                                pile_2[i+1] = cards[j];
                                i++;
                            }
                        }
                        else {
                            pile2[i + 1] = cards[j];
                            pile_2[i + 1] = cards[j];
                            i++;
                        }
                    }
                    break;
                }
            }
        }
        else if(pile_type2=="3") {
            for(int i = 0 ; i<19 ; i++) {
                if(pile3[i]==card2) {
                    for(int j = 0 ; j < number;j++) {
                        if(i==0) {
                            if(card2=="") {
                                pile3[i] = cards[j];
                                pile_3[i] = cards[j];
                                i++;
                            }
                            else {
                                pile3[i+1] = cards[j];
                                pile_3[i+1] = cards[j];
                                i++;
                            };
                        }
                        else {
                            pile3[i + 1] = cards[j];
                            pile_3[i + 1] = cards[j];
                            i++;
                        }
                    }
                    break;
                }
            }
        }
        else if(pile_type2=="4") {
            for(int i = 0 ; i<19 ; i++) {
                if(pile4[i]==card2) {
                    for(int j = 0 ; j < number;j++) {
                        if(i==0) {
                            if(card2=="") {
                                pile4[i] = cards[j];
                                pile_4[i] = cards[j];
                                i++;
                            }
                            else {
                                pile4[i+1] = cards[j];
                                pile_4[i+1] = cards[j];
                                i++;
                            }
                        }
                        else {
                            pile4[i + 1] = cards[j];
                            pile_4[i + 1] = cards[j];
                            i++;
                        }
                    }
                    break;
                }
            }
        }
        else if(pile_type2=="5") {
            for(int i = 0 ; i<19 ; i++) {
                if(pile5[i]==card2) {
                    for(int j = 0 ; j < number;j++) {
                        if(i==0) {
                            if(card2=="") {
                                pile5[i] = cards[j];
                                pile_5[i] = cards[j];
                                i++;
                            }
                            else {
                                pile5[i+1] = cards[j];
                                pile_5[i+1] = cards[j];
                                i++;
                            }
                        }
                        else {
                            pile5[i + 1] = cards[j];
                            pile_5[i + 1] = cards[j];
                            i++;
                        }
                    }
                    break;
                }
            }
        }
        else if(pile_type2=="1") {
            for(int i = 0 ; i<19 ; i++) {
                if(pile1[i]==card2) {
                    for(int j = 0 ; j < number;j++) {
                        if(i==0) {
                            if(card2=="") {
                                pile1[i] = cards[j];
                                pile_1[i] = cards[j];
                                i++;
                            }
                            else {
                                pile1[i+1] = cards[j];
                                pile_1[i+1] = cards[j];
                                i++;
                            }
                        }
                        else {
                            pile1[i + 1] = cards[j];
                            pile_1[i + 1] = cards[j];
                            i++;
                        }
                    }
                    break;
                }
            }
        }
    }
     else if(pile_type1=="1") {
         int number = 0 ;
         for(int i = 0 ; i< 19 ; i++) {
             if(pile1[i]==card1) {
                 for(int j = i ; j<20 ; j++ ) {
                     if(!(pile1[j]=="")) {
                         cards[number]=pile1[j];
                         pile1[j]="";
                         pile_1[j]="";
                         number++;
                     }
                 }
                 break;
             }
         }
         if(pile_type2=="0") {
             for(int i = 0 ; i<19 ; i++) {
                 if(pile0[i]==card2) {
                     for(int j = 0 ; j < number;j++) {
                         if(i==0) {
                             if(card2=="") {
                                 pile0[i] = cards[j];
                                 pile_0[i] = cards[j];
                                 i++;
                             }
                             else {
                                 pile0[i+1] = cards[j];
                                 pile_0[i+1] = cards[j];
                                 i++;
                             }
                         }
                         else {
                             pile0[i + 1] = cards[j];
                             pile_0[i + 1] = cards[j];
                             i++;
                         }
                     }
                     break;
                 }
             }
         }
         else if(pile_type2=="2") {
             for(int i = 0 ; i<19 ; i++) {
                 if(pile2[i]==card2) {
                     for(int j = 0 ; j < number;j++) {
                         if(i==0) {
                             if(card2=="") {
                                 pile2[i] = cards[j];
                                 pile_2[i] = cards[j];
                                 i++;
                             }
                             else {
                                 pile2[i+1] = cards[j];
                                 pile_2[i+1] = cards[j];
                                 i++;
                             }
                         }
                         else {
                             pile2[i + 1] = cards[j];
                             pile_2[i + 1] = cards[j];
                             i++;
                         }
                     }
                     break;
                 }
             }
         }
         else if(pile_type2=="3") {
             for(int i = 0 ; i<19 ; i++) {
                 if(pile3[i]==card2) {
                     for(int j = 0 ; j < number;j++) {
                         if(i==0) {
                             if(card2=="") {
                                 pile3[i] = cards[j];
                                 pile_3[i] = cards[j];
                                 i++;
                             }
                             else {
                                 pile3[i+1] = cards[j];
                                 pile_3[i+1] = cards[j];
                                 i++;
                             }
                         }
                         else {
                             pile3[i + 1] = cards[j];
                             pile_3[i + 1] = cards[j];
                             i++;
                         }
                     }
                     break;
                 }
             }
         }
         else if(pile_type2=="4") {
             for(int i = 0 ; i<19 ; i++) {
                 if(pile4[i]==card2) {
                     for(int j = 0 ; j < number;j++) {
                         if(i==0) {
                             if(card2=="") {
                                 pile4[i] = cards[j];
                                 pile_4[i] = cards[j];
                                 i++;
                             }
                             else {
                                 pile4[i+1] = cards[j];
                                 pile_4[i+1] = cards[j];
                                 i++;
                             }
                         }
                         else {
                             pile4[i + 1] = cards[j];
                             pile_4[i + 1] = cards[j];
                             i++;
                         }
                     }
                     break;
                 }
             }
         }
         else if(pile_type2=="5") {
             for(int i = 0 ; i<19 ; i++) {
                 if(pile5[i]==card2) {
                     for(int j = 0 ; j < number;j++) {
                         if(i==0) {
                             if(card2=="") {
                                 pile5[i] = cards[j];
                                 pile_5[i] = cards[j];
                                 i++;
                             }
                             else {
                                 pile5[i+1] = cards[j];
                                 pile_5[i+1] = cards[j];
                                 i++;
                             }
                         }
                         else {
                             pile5[i + 1] = cards[j];
                             pile_5[i + 1] = cards[j];
                             i++;
                         }
                     }
                     break;
                 }
             }
         }
         else if(pile_type2=="6") {
             for(int i = 0 ; i<19 ; i++) {
                 if(pile6[i]==card2) {
                     for(int j = 0 ; j < number;j++) {
                         if(i==0) {
                             if(card2=="") {
                                 pile6[i] = cards[j];
                                 pile_6[i] = cards[j];
                                 i++;
                             }
                             else {
                                 pile6[i+1] = cards[j];
                                 pile_6[i+1] = cards[j];
                                 i++;
                             }
                         }
                         else {
                             pile6[i + 1] = cards[j];
                             pile_6[i + 1] = cards[j];
                             i++;
                         }
                     }
                     break;
                 }
             }
         }
     }
     else if(pile_type1=="2") {
         int number = 0 ;
         for(int i = 0 ; i< 19 ; i++) {
             if(pile2[i]==card1) {
                 for(int j = i ; j<20 ; j++ ) {
                     if(!(pile2[j]=="")) {
                         cards[number]=pile2[j];
                         pile2[j]="";
                         pile_2[j]="";
                         number++;
                     }
                 }
                 break;
             }
         }
         if(pile_type2=="0") {
             for(int i = 0 ; i<19 ; i++) {
                 if(pile0[i]==card2) {
                     for(int j = 0 ; j < number;j++) {
                         if(i==0) {
                             if(card2=="") {
                                 pile0[i] = cards[j];
                                 pile_0[i] = cards[j];
                                 i++;
                             }
                             else {
                                 pile0[i+1] = cards[j];
                                 pile_0[i+1] = cards[j];
                                 i++;
                             }
                         }
                         else {
                             pile0[i + 1] = cards[j];
                             pile_0[i + 1] = cards[j];
                             i++;
                         }
                     }
                     break;
                 }
             }
         }
         else if(pile_type2=="6") {
             for(int i = 0 ; i<19 ; i++) {
                 if(pile6[i]==card2) {
                     for(int j = 0 ; j < number;j++) {
                         if(i==0) {
                             if(card2=="") {
                                 pile6[i] = cards[j];
                                 pile_6[i] = cards[j];
                                 i++;
                             }
                             else {
                                 pile6[i+1] = cards[j];
                                 pile_6[i+1] = cards[j];
                                 i++;
                             }
                         }
                         else {
                             pile6[i + 1] = cards[j];
                             pile_6[i + 1] = cards[j];
                             i++;
                         }
                     }
                     break;
                 }
             }
         }
         else if(pile_type2=="3") {
             for(int i = 0 ; i<19 ; i++) {
                 if(pile3[i]==card2) {
                     for(int j = 0 ; j < number;j++) {
                         if(i==0) {
                             if(card2=="") {
                                 pile3[i] = cards[j];
                                 pile_3[i] = cards[j];
                                 i++;
                             }
                             else {
                                 pile3[i+1] = cards[j];
                                 pile_3[i+1] = cards[j];
                                 i++;
                             }
                         }
                         else {
                             pile3[i + 1] = cards[j];
                             pile_3[i + 1] = cards[j];
                             i++;
                         }
                     }
                     break;
                 }
             }
         }
         else if(pile_type2=="4") {
             for(int i = 0 ; i<19 ; i++) {
                 if(pile4[i]==card2) {
                     for(int j = 0 ; j < number;j++) {
                         if(i==0) {
                             if(card2=="") {
                                 pile4[i] = cards[j];
                                 pile_4[i] = cards[j];
                                 i++;
                             }
                             else {
                                 pile4[i+1] = cards[j];
                                 pile_4[i+1] = cards[j];
                                 i++;
                             }
                         }
                         else {
                             pile4[i + 1] = cards[j];
                             pile_4[i + 1] = cards[j];
                             i++;
                         }
                     }
                     break;
                 }
             }
         }
         else if(pile_type2=="5") {
             for(int i = 0 ; i<19 ; i++) {
                 if(pile5[i]==card2) {
                     for(int j = 0 ; j < number;j++) {
                         if(i==0) {
                             if(card2=="") {
                                 pile5[i] = cards[j];
                                 pile_5[i] = cards[j];
                                 i++;
                             }
                             else {
                                 pile5[i+1] = cards[j];
                                 pile_5[i+1] = cards[j];
                                 i++;
                             }
                         }
                         else {
                             pile5[i + 1] = cards[j];
                             pile_5[i + 1] = cards[j];
                             i++;
                         }
                     }
                     break;
                 }
             }
         }
         else if(pile_type2=="1") {
             for(int i = 0 ; i<19 ; i++) {
                 if(pile1[i]==card2) {
                     for(int j = 0 ; j < number;j++) {
                         if(i==0) {
                             if(card2=="") {
                                 pile1[i] = cards[j];
                                 pile_1[i] = cards[j];
                                 i++;
                             }
                             else {
                                 pile1[i+1] = cards[j];
                                 pile_1[i+1] = cards[j];
                                 i++;
                             };
                         }
                         else {
                             pile1[i + 1] = cards[j];
                             pile_1[i + 1] = cards[j];
                             i++;
                         }
                     }
                     break;
                 }
             }
         }
     }
     else if(pile_type1=="3") {
         int number = 0 ;
         for(int i = 0 ; i< 19 ; i++) {
             if(pile3[i]==card1) {
                 for(int j = i ; j<20 ; j++ ) {
                     if(!(pile3[j]=="")) {
                         cards[number]=pile3[j];
                         pile3[j]="";
                         pile_3[j]="";
                         number++;
                     }
                 }
                 break;
             }
         }
         if(pile_type2=="0") {
             for(int i = 0 ; i<19 ; i++) {
                 if(pile0[i]==card2) {
                     for(int j = 0 ; j < number;j++) {
                         if(i==0) {
                             if(card2=="") {
                                 pile0[i] = cards[j];
                                 pile_0[i] = cards[j];
                                 i++;
                             }
                             else {
                                 pile0[i+1] = cards[j];
                                 pile_0[i+1] = cards[j];
                                 i++;
                             }
                         }
                         else {
                             pile0[i + 1] = cards[j];
                             pile_0[i + 1] = cards[j];
                             i++;
                         }
                     }
                     break;
                 }
             }
         }
         else if(pile_type2=="2") {
             for(int i = 0 ; i<19 ; i++) {
                 if(pile2[i]==card2) {
                     for(int j = 0 ; j < number;j++) {
                         if(i==0) {
                             if(card2=="") {
                                 pile2[i] = cards[j];
                                 pile_2[i] = cards[j];
                                 i++;
                             }
                             else {
                                 pile2[i+1] = cards[j];
                                 pile_2[i+1] = cards[j];
                                 i++;
                             }
                         }
                         else {
                             pile2[i + 1] = cards[j];
                             pile_2[i + 1] = cards[j];
                             i++;
                         }
                     }
                     break;
                 }
             }
         }
         else if(pile_type2=="6") {
             for(int i = 0 ; i<19 ; i++) {
                 if(pile6[i]==card2) {
                     for(int j = 0 ; j < number;j++) {
                         if(i==0) {
                             if(card2=="") {
                                 pile6[i] = cards[j];
                                 pile_6[i] = cards[j];
                                 i++;
                             }
                             else {
                                 pile6[i+1] = cards[j];
                                 pile_6[i+1] = cards[j];
                                 i++;
                             }
                         }
                         else {
                             pile6[i + 1] = cards[j];
                             pile_6[i + 1] = cards[j];
                             i++;
                         }
                     }
                     break;
                 }
             }
         }
         else if(pile_type2=="4") {
             for(int i = 0 ; i<19 ; i++) {
                 if(pile4[i]==card2) {
                     for(int j = 0 ; j < number;j++) {
                         if(i==0) {
                             if(card2=="") {
                                 pile4[i] = cards[j];
                                 pile_4[i] = cards[j];
                                 i++;
                             }
                             else {
                                 pile4[i+1] = cards[j];
                                 pile_4[i+1] = cards[j];
                                 i++;
                             }
                         }
                         else {
                             pile4[i + 1] = cards[j];
                             pile_4[i + 1] = cards[j];
                             i++;
                         }
                     }
                     break;
                 }
             }
         }
         else if(pile_type2=="5") {
             for(int i = 0 ; i<19 ; i++) {
                 if(pile5[i]==card2) {
                     for(int j = 0 ; j < number;j++) {
                         if(i==0) {
                             if(card2=="") {
                                 pile5[i] = cards[j];
                                 pile_5[i] = cards[j];
                                 i++;
                             }
                             else {
                                 pile5[i+1] = cards[j];
                                 pile_5[i+1] = cards[j];
                                 i++;
                             }
                         }
                         else {
                             pile5[i + 1] = cards[j];
                             pile_5[i + 1] = cards[j];
                             i++;
                         }
                     }
                     break;
                 }
             }
         }
         else if(pile_type2=="1") {
             for(int i = 0 ; i<19 ; i++) {
                 if(pile1[i]==card2) {
                     for(int j = 0 ; j < number;j++) {
                         if(i==0) {
                             if(card2=="") {
                                 pile1[i] = cards[j];
                                 pile_1[i] = cards[j];
                                 i++;
                             }
                             else {
                                 pile1[i+1] = cards[j];
                                 pile_1[i+1] = cards[j];
                                 i++;
                             }
                         }
                         else {
                             pile1[i + 1] = cards[j];
                             pile_1[i + 1] = cards[j];
                             i++;
                         }
                     }
                     break;
                 }
             }
         }
     }
     else if(pile_type1=="4") {
         int number = 0 ;
         for(int i = 0 ; i< 19 ; i++) {
             if(pile4[i]==card1) {
                 for(int j = i ; j<20 ; j++ ) {
                     if(!(pile4[j]=="")) {
                         cards[number]=pile4[j];
                         pile4[j]="";
                         pile_4[j]="";
                         number++;
                     }
                 }
                 break;
             }
         }
         if(pile_type2=="0") {
             for(int i = 0 ; i<19 ; i++) {
                 if(pile0[i]==card2) {
                     for(int j = 0 ; j < number;j++) {
                         if(i==0) {
                             if(card2=="") {
                                 pile0[i] = cards[j];
                                 pile_0[i] = cards[j];
                                 i++;
                             }
                             else {
                                 pile0[i+1] = cards[j];
                                 pile_0[i+1] = cards[j];
                                 i++;
                             }
                         }
                         else {
                             pile0[i + 1] = cards[j];
                             pile_0[i + 1] = cards[j];
                             i++;
                         }
                     }
                     break;
                 }
             }
         }
         else if(pile_type2=="2") {
             for(int i = 0 ; i<19 ; i++) {
                 if(pile2[i]==card2) {
                     for(int j = 0 ; j < number;j++) {
                         if(i==0) {
                             if(card2=="") {
                                 pile2[i] = cards[j];
                                 pile_2[i] = cards[j];
                                 i++;
                             }
                             else {
                                 pile2[i+1] = cards[j];
                                 pile_2[i+1] = cards[j];
                                 i++;
                             }
                         }
                         else {
                             pile2[i + 1] = cards[j];
                             pile_2[i + 1] = cards[j];
                             i++;
                         }
                     }
                     break;
                 }
             }
         }
         else if(pile_type2=="3") {
             for(int i = 0 ; i<19 ; i++) {
                 if(pile3[i]==card2) {
                     for(int j = 0 ; j < number;j++) {
                         if(i==0) {
                             if(card2=="") {
                                 pile3[i] = cards[j];
                                 pile_3[i] = cards[j];
                                 i++;
                             }
                             else {
                                 pile3[i+1] = cards[j];
                                 pile_3[i+1] = cards[j];
                                 i++;
                             }
                         }
                         else {
                             pile3[i + 1] = cards[j];
                             pile_3[i + 1] = cards[j];
                             i++;
                         }
                     }
                     break;
                 }
             }
         }
         else if(pile_type2=="6") {
             for(int i = 0 ; i<19 ; i++) {
                 if(pile6[i]==card2) {
                     for(int j = 0 ; j < number;j++) {
                         if(i==0) {
                             if(card2=="") {
                                 pile6[i] = cards[j];
                                 pile_6[i] = cards[j];
                                 i++;
                             }
                             else {
                                 pile6[i+1] = cards[j];
                                 pile_6[i+1] = cards[j];
                                 i++;
                             }
                         }
                         else {
                             pile6[i + 1] = cards[j];
                             pile_6[i + 1] = cards[j];
                             i++;
                         }
                     }
                     break;
                 }
             }
         }
         else if(pile_type2=="5") {
             for(int i = 0 ; i<19 ; i++) {
                 if(pile5[i]==card2) {
                     for(int j = 0 ; j < number;j++) {
                         if(i==0) {
                             if(card2=="") {
                                 pile5[i] = cards[j];
                                 pile_5[i] = cards[j];
                                 i++;
                             }
                             else {
                                 pile5[i+1] = cards[j];
                                 pile_5[i+1] = cards[j];
                                 i++;
                             }
                         }
                         else {
                             pile5[i + 1] = cards[j];
                             pile_5[i + 1] = cards[j];
                             i++;
                         }
                     }
                     break;
                 }
             }
         }
         else if(pile_type2=="1") {
             for(int i = 0 ; i<19 ; i++) {
                 if(pile1[i]==card2) {
                     for(int j = 0 ; j < number;j++) {
                         if(i==0) {
                             if(card2=="") {
                                 pile1[i] = cards[j];
                                 pile_1[i] = cards[j];
                                 i++;
                             }
                             else {
                                 pile1[i+1] = cards[j];
                                 pile_1[i+1] = cards[j];
                                 i++;
                             }
                         }
                         else {
                             pile1[i + 1] = cards[j];
                             pile_1[i + 1] = cards[j];
                             i++;
                         }
                     }
                     break;
                 }
             }
         }
     }
    else if(pile_type1=="5") {
        int number = 0 ;
        for(int i = 0 ; i< 19 ; i++) {
            if(pile5[i]==card1) {
                for(int j = i ; j<20 ; j++ ) {
                    if(!(pile5[j]=="")) {
                        cards[number]=pile5[j];
                        pile5[j]="";
                        pile_5[j]="";
                        number++;
                    }
                }
                break;
            }
        }
        if(pile_type2=="0") {
            for(int i = 0 ; i<19 ; i++) {
                if(pile0[i]==card2) {
                    for(int j = 0 ; j < number;j++) {
                        if(i==0) {
                            if(card2=="") {
                                pile0[i] = cards[j];
                                pile_0[i] = cards[j];
                                i++;
                            }
                            else {
                                pile0[i+1] = cards[j];
                                pile_0[i+1] = cards[j];
                                i++;
                            };
                        }
                        else {
                            pile0[i + 1] = cards[j];
                            pile_0[i + 1] = cards[j];
                            i++;
                        }
                    }
                    break;
                }
            }
        }
        else if(pile_type2=="2") {
            for(int i = 0 ; i<19 ; i++) {
                if(pile2[i]==card2) {
                    for(int j = 0 ; j < number;j++) {
                        if(i==0) {
                            if(card2=="") {
                                pile2[i] = cards[j];
                                pile_2[i] = cards[j];
                                i++;
                            }
                            else {
                                pile2[i+1] = cards[j];
                                pile_2[i+1] = cards[j];
                                i++;
                            }
                        }
                        else {
                            pile2[i + 1] = cards[j];
                            pile_2[i + 1] = cards[j];
                            i++;
                        }
                    }
                    break;
                }
            }
        }
        else if(pile_type2=="3") {
            for(int i = 0 ; i<19 ; i++) {
                if(pile3[i]==card2) {
                    for(int j = 0 ; j < number;j++) {
                        if(i==0) {
                            if(card2=="") {
                                pile3[i] = cards[j];
                                pile_3[i] = cards[j];
                                i++;
                            }
                            else {
                                pile3[i+1] = cards[j];
                                pile_3[i+1] = cards[j];
                                i++;
                            }
                        }
                        else {
                            pile3[i + 1] = cards[j];
                            pile_3[i + 1] = cards[j];
                            i++;
                        }
                    }
                    break;
                }
            }
        }
        else if(pile_type2=="4") {
            for(int i = 0 ; i<19 ; i++) {
                if(pile4[i]==card2) {
                    for(int j = 0 ; j < number;j++) {
                        if(i==0) {
                            if(card2=="") {
                                pile4[i] = cards[j];
                                pile_4[i] = cards[j];
                                i++;
                            }
                            else {
                                pile4[i+1] = cards[j];
                                pile_4[i+1] = cards[j];
                                i++;
                            }
                        }
                        else {
                            pile4[i + 1] = cards[j];
                            pile_4[i + 1] = cards[j];
                            i++;
                        }
                    }
                    break;
                }
            }
        }
        else if(pile_type2=="6") {
            for(int i = 0 ; i<19 ; i++) {
                if(pile6[i]==card2) {
                    for(int j = 0 ; j < number;j++) {
                        if(i==0) {
                            if(card2=="") {
                                pile6[i] = cards[j];
                                pile_6[i] = cards[j];
                                i++;
                            }
                            else {
                                pile6[i+1] = cards[j];
                                pile_6[i+1] = cards[j];
                                i++;
                            }
                        }
                        else {
                            pile6[i + 1] = cards[j];
                            pile_6[i + 1] = cards[j];
                            i++;
                        }
                    }
                    break;
                }
            }
        }
        else if(pile_type2=="1") {
            for(int i = 0 ; i<19 ; i++) {
                if(pile1[i]==card2) {
                    for(int j = 0 ; j < number;j++) {
                        if(i==0) {
                            if(card2=="") {
                                pile1[i] = cards[j];
                                pile_1[i] = cards[j];
                                i++;
                            }
                            else {
                                pile1[i+1] = cards[j];
                                pile_1[i+1] = cards[j];
                                i++;
                            }
                        }
                        else {
                            pile1[i + 1] = cards[j];
                            pile_1[i + 1] = cards[j];
                            i++;
                        }
                    }
                    break;
                }
            }
        }
    }
   else if(pile_type1=="6") {
        int number = 0 ;
        for(int i = 0 ; i< 19 ; i++) {
            if(pile6[i]==card1) {
                for(int j = i ; j<20 ; j++ ) {
                    if(!(pile6[j]=="")) {
                        cards[number]=pile6[j];
                        pile6[j]="";
                        pile_6[j]="";
                        number++;
                    }
                }
                break;
            }
        }
        if(pile_type2=="0") {
            for(int i = 0 ; i<19 ; i++) {
                if(pile0[i]==card2) {
                    for(int j = 0 ; j < number;j++) {
                        if(i==0) {
                            if(card2=="") {
                                pile0[i] = cards[j];
                                pile_0[i] = cards[j];
                                i++;
                            }
                            else {
                                pile0[i+1] = cards[j];
                                pile_0[i+1] = cards[j];
                                i++;
                            }
                        }
                        else {
                            pile0[i + 1] = cards[j];
                            pile_0[i + 1] = cards[j];
                            i++;
                        }
                    }
                    break;
                }
            }
        }
        else if(pile_type2=="2") {
            for(int i = 0 ; i<19 ; i++) {
                if(pile2[i]==card2) {
                    for(int j = 0 ; j < number;j++) {
                        if(i==0) {
                            if(card2=="") {
                                pile2[i] = cards[j];
                                pile_2[i] = cards[j];
                                i++;
                            }
                            else {
                                pile2[i+1] = cards[j];
                                pile_2[i+1] = cards[j];
                                i++;
                            }
                        }
                        else {
                            pile2[i + 1] = cards[j];
                            pile_2[i + 1] = cards[j];
                            i++;
                        }
                    }
                    break;
                }
            }
        }
        else if(pile_type2=="3") {
            for(int i = 0 ; i<19 ; i++) {
                if(pile3[i]==card2) {
                    for(int j = 0 ; j < number;j++) {
                        if(i==0) {
                            if(card2=="") {
                                pile3[i] = cards[j];
                                pile_3[i] = cards[j];
                                i++;
                            }
                            else {
                                pile3[i+1] = cards[j];
                                pile_3[i+1] = cards[j];
                                i++;
                            }
                        }
                        else {
                            pile3[i + 1] = cards[j];
                            pile_3[i + 1] = cards[j];
                            i++;
                        }
                    }
                    break;
                }
            }
        }
        else if(pile_type2=="4") {
            for(int i = 0 ; i<19 ; i++) {
                if(pile4[i]==card2) {
                    for(int j = 0 ; j < number;j++) {
                        if(i==0) {
                            if(card2=="") {
                                pile4[i] = cards[j];
                                pile_4[i] = cards[j];
                                i++;
                            }
                            else {
                                pile4[i+1] = cards[j];
                                pile_4[i+1] = cards[j];
                                i++;
                            }
                        }
                        else {
                            pile4[i + 1] = cards[j];
                            pile_4[i + 1] = cards[j];
                            i++;
                        }
                    }
                    break;
                }
            }
        }
        else if(pile_type2=="5") {
            for(int i = 0 ; i<19 ; i++) {
                if(pile5[i]==card2) {
                    for(int j = 0 ; j < number;j++) {
                        if(i==0) {
                            if(card2=="") {
                                pile5[i] = cards[j];
                                pile_5[i] = cards[j];
                                i++;
                            }
                            else {
                                pile5[i+1] = cards[j];
                                pile_5[i+1] = cards[j];
                                i++;
                            }
                        }
                        else {
                            pile5[i + 1] = cards[j];
                            pile_5[i + 1] = cards[j];
                            i++;
                        }
                    }
                    break;
                }
            }
        }
        else if(pile_type2=="1") {
            for(int i = 0 ; i<19 ; i++) {
                if(pile1[i]==card2) {
                    for(int j = 0 ; j < number;j++) {
                        if(i==0) {
                            if(card2=="") {
                                pile1[i] = cards[j];
                                pile_1[i] = cards[j];
                                i++;
                            }
                            else {
                                pile1[i+1] = cards[j];
                                pile_1[i+1] = cards[j];
                                i++;
                            }
                        }
                        else {
                            pile1[i + 1] = cards[j];
                            pile_1[i + 1] = cards[j];
                            i++;
                        }
                    }
                    break;
                }
            }
        }
    }
 }
void Methods::movepile(string pile_type1,string pile_type2,int number_of_cards) {//this method change the cards by using above methods
            string changing_cards[number_of_cards+1];
            string card_1=Finding_card1(pile_type1,(number_of_cards+1));
            string card_2=Finding_card2(pile_type2);
            if(card_1=="") {
                return;
            }
            else if(card_2=="@@@"||card_1=="@@@") {
                write.writefile("invalid move\n");

                Print("****************************************\n\n");
                return;
            }
            if(card_control_method(card_1,card_2)) {
                Changing_cards(pile_type1,pile_type2,card_1,card_2,changing_cards);
                Print("****************************************\n\n");
            }
            else {
                write.writefile("invalid move\n");

                Print("****************************************\n\n");
            }

 }
 void Methods::Move_Waste(string pile_type) { // this method transport the card from stock to pile
        string card;
        string card1;
        if(!(slot3=="___")) {
            card1=slot3;
        }
        else {
            if(!(slot2=="___")) {
                card1=slot2;
            }
            else {
                if(!(slot1=="___")) {
                    card1=slot1;
                }
                else {
                    write.writefile("invalid move\n");
                    Print("****************************************\n\n");
                    return;
                }
            }
        }
        int number=0;
        if(pile_type=="0") {
            for(int i = 0 ; i<20;i++) {
                if(pile0[0]=="") {
                    card="";
                    break;
                }
                if(!(pile0[i]=="@@@")) {
                    card=pile0[i];
                    number=i+1;
                    if(card=="") {
                        card="D50";
                        break;
                    }
                    if(pile0[i+1]=="") {
                        break;
                    }
                }
            }
        }
        else if(pile_type=="1") {
            for(int i = 0 ; i<20;i++) {
                if(pile1[0]=="") {
                    card="";
                    break;
                }
                if(!(pile1[i]=="@@@")) {
                    card=pile1[i];
                    number=i+1;
                    if(card=="") {
                        card="D50";
                        break;
                    }
                    if(pile1[i+1]=="") {
                        break;
                    }
                }
            }
        }
        else if(pile_type=="2") {
            for(int i = 0 ; i<20;i++) {
                if(pile2[0]=="") {
                    card="";
                    break;
                }
                if(!(pile2[i]=="@@@")) {
                    card=pile2[i];
                    number=i+1;
                    if(card=="") {
                        card="D50";
                        break;
                    }
                    if(pile2[i+1]=="") {
                        break;
                    }
                }
            }
        }
      else if(pile_type=="3") {
         for(int i = 0 ; i<20;i++) {
             if(pile3[0]=="") {
                 card="";
                 break;
             }
             if(!(pile3[i]=="@@@")) {
                 card=pile3[i];
                 number=i+1;
                 if(card=="") {
                     card="D50";
                     break;
                 }
                 if(pile3[i+1]=="") {
                     break;
                 }
             }
         }
     }
    else if(pile_type=="4") {
            for(int i = 0 ; i<20;i++) {
                if(pile4[0]=="") {
                    card="";
                    break;
                }
                if(!(pile4[i]=="@@@")) {
                    card=pile4[i];
                    number=i+1;
                    if(card=="") {
                        card="D50";
                        break;
                    }
                    if(pile4[i+1]=="") {
                        break;
                    }
                }
            }
        }
    else if(pile_type=="5") {
         for(int i = 0 ; i<20;i++) {
             if(pile5[0]=="") {
                 card="";
                 break;
             }
             if(!(pile5[i]=="@@@")) {
                 number=i+1;
                 card=pile5[i];
                 if(card=="") {
                     card="D50";
                     break;
                 }
                 if(pile5[i+1]=="") {
                     break;
                 }

             }
         }
     }
    else if(pile_type=="6") {
         for(int i = 0 ; i<20;i++) {
             if(pile6[0]=="") {
                 card="";
                 break;
             }
             if(!(pile6[i]=="@@@")) {
                 number=i+1;
                 card=pile6[i];
                 if(card=="") {
                     card="D50";
                     break;
                 }
                 if(pile6[i+1]=="") {
                     break;
                 }
             }
         }
     }
    if(card_control_method(card1,card)) {
        if(pile_type=="0") {
            if(card1==slot3) {
                slot3 = "___";
                pile0[number] = card1;
                pile_0[number]=card1;
                for (int i = 0; i < 24; i++) {
                    if (stock[i] == card1) {

                        stock[i] = "";
                    }
                }
            }
            else if(card1==slot2) {
                slot2 = "___";
                pile0[number] = card1;
                pile_0[number]=card1;
                for (int i = 0; i < 24; i++) {
                    if (stock[i] == card1) {
                        stock[i] = "";
                    }
                }
            }
            else if(card1==slot1) {
                slot1="___";
                pile0[number]=card1;
                pile_0[number]=card1;
                for(int i = 0 ; i<24;i++) {
                    if(stock[i]==card1) {
                        stock[i]="";
                        for(int j = i ; j>=0 ; j--) {
                            if(!(stock[j]=="")) {
                                slot1=stock[j];
                                Print("****************************************\n\n");
                                return;
                            }
                        }
                    }
                }
            }
        }
        if(pile_type=="1") {
            if(card1==slot3) {
                slot3 = "___";
                pile1[number] = card1;
                pile_1[number]=card1;
                for (int i = 0; i < 24; i++) {
                    if (stock[i] == card1) {
                        stock[i] = "";
                    }
                }
            }
            else if(card1==slot2) {
                slot2 = "___";
                pile1[number] = card1;
                pile_1[number]=card1;
                for (int i = 0; i < 24; i++) {
                    if (stock[i] == card1) {
                        stock[i] = "";
                    }
                }
            }
            else if(card1==slot1) {
                slot1="___";
                pile1[number]=card1;
                pile_1[number]=card1;
                for(int i = 0 ; i<24;i++) {
                    if(stock[i]==card1) {
                        stock[i] = "";
                        for(int j = i ; j>=0 ; j--) {
                            if(!(stock[j]=="")) {
                                slot1=stock[j];
                                Print("****************************************\n\n");
                                return;
                            }
                        }
                    }
                }
            }
        }
        if(pile_type=="2") {
            if(card1==slot3) {
                slot3 = "___";
                pile2[number]=card1;
                pile_2[number]=card1;
                for (int i = 0; i < 24; i++) {
                    if (stock[i] == card1) {
                        stock[i] = "";
                    }
                }
            }
            else if(card1==slot2) {
                slot2 = "___";
                pile2[number]=card1;
                pile_2[number]=card1;
                for (int i = 0; i < 24; i++) {
                    if (stock[i] == card1) {
                        stock[i] = "";
                    }
                }
            }
            else if(card1==slot1) {
                slot1="___";
                pile2[number]=card1;
                pile_2[number]=card1;
                for(int i = 0 ; i<24;i++) {
                    if(stock[i]==card1) {
                        stock[i] = "";
                        for(int j = i ; j>=0 ; j--) {
                            if(!(stock[j]=="")) {
                                slot1=stock[j];
                                Print("****************************************\n\n");
                                return;
                            }
                        }
                    }
                }
            }
        }
        if(pile_type=="3") {
            if(card1==slot3) {
                slot3 = "___";
                pile3[number]=card1;
                pile_3[number]=card1;
                for (int i = 0; i < 24; i++) {
                    if (stock[i] == card1) {
                        stock[i] = "";
                    }
                }
            }
            else if(card1==slot2) {
                slot2 = "___";
                pile3[number]=card1;
                pile_3[number]=card1;
                for (int i = 0; i < 24; i++) {
                    if (stock[i] == card1) {
                        stock[i] = "";
                    }
                }
            }
            else if(card1==slot1) {
                slot1="___";
                pile3[number]=card1;
                pile_3[number]=card1;
                for(int i = 0 ; i<24;i++) {
                    if(stock[i]==card1) {
                        stock[i] = "";
                        for(int j = i ; j>=0 ; j--) {
                            if(!(stock[j]=="")) {
                                slot1=stock[j];
                                Print("****************************************\n\n");
                                return;
                            }
                        }
                    }
                }
            }
        }
        if(pile_type=="4") {
            if(card1==slot3) {
                slot3 = "___";
                pile4[number]=card1;
                pile_4[number]=card1;
                for (int i = 0; i < 24; i++) {
                    if (stock[i] == card1) {
                        stock[i] = "";
                    }
                }
            }
            else if(card1==slot2) {
                slot2 = "___";
                pile4[number]=card1;
                pile_4[number]=card1;
                for (int i = 0; i < 24; i++) {
                    if (stock[i] == card1) {
                        stock[i] = "";
                    }
                }
            }
            else if(card1==slot1) {
                slot1="___";
                pile4[number]=card1;
                pile_4[number]=card1;
                for(int i = 0 ; i<24;i++) {
                    if(stock[i]==card1) {
                        stock[i] = "";
                        for(int j = i ; j>=0 ; j--) {
                            if(!(stock[j]=="")) {
                                slot1=stock[j];
                                Print("****************************************\n\n");
                                return;
                            }
                        }
                    }
                }
            }
        }
        if(pile_type=="5") {
            if(card1==slot3) {
                slot3 = "___";
                pile5[number]=card1;
                pile_5[number]=card1;
                for (int i = 0; i < 24; i++) {
                    if (stock[i] == card1) {
                        stock[i] = "";
                    }
                }
            }
            else if(card1==slot2) {
                slot2 = "___";
                pile5[number]=card1;
                pile_5[number]=card1;
                for (int i = 0; i < 24; i++) {
                    if (stock[i] == card1) {
                        stock[i] = "";
                    }
                }
            }
            else if(card1==slot1) {
                slot1="___";
                pile5[number]=card1;
                pile_5[number]=card1;
                for(int i = 0 ; i<24;i++) {
                    if(stock[i]==card1) {
                        stock[i] = "";
                        for(int j = i ; j>=0 ; j--) {
                            if(!(stock[j]=="")) {
                                slot1=stock[j];
                                Print("****************************************\n\n");
                                return;
                            }
                        }
                    }
                }
            }
        }
        if(pile_type=="6") {
            if(card1==slot3) {
                slot3 = "___";
                pile6[number]=card1;
                pile_6[number]=card1;
                for (int i = 0; i < 24; i++) {
                    if (stock[i] == card1) {
                        stock[i] = "";
                    }
                }
            }
            else if(card1==slot2) {
                slot2 = "___";
                pile6[number]=card1;
                pile_6[number]=card1;
                for (int i = 0; i < 24; i++) {
                    if (stock[i] == card1) {
                        stock[i] = "";
                    }
                }
            }
            else if(card1==slot1) {
                slot1="___";
                pile6[number]=card1;
                pile_6[number]=card1;
                for(int i = 0 ; i<24;i++) {
                    if(stock[i]==card1) {
                        stock[i]="";
                        for(int j = i ; j>=0 ; j--) {
                            if(!(stock[j]=="")) {
                                slot1=stock[j];
                                Print("****************************************\n\n");
                                return;
                            }
                        }
                    }
                }
            }
        }
    }
    else {
        write.writefile("invalid move\n");
        Print("****************************************\n\n");
    }
    Print("****************************************\n\n");

 }
 string Methods::card_Finding(string pile_type) {
     string card;
     if(pile_type == "0") {
         for(int i = 19; i >=0 ; i--) {
             if (!(pile0[i]==""||pile0[i]=="@@@")) {
                 card=pile0[i];
                 return card;
             }
         }
     }
     else if(pile_type == "1") {
         for (int i = 19; i >= 0; i--) {
             if (!(pile1[i] == "" || pile1[i] == "@@@")) {
                 card = pile1[i];
                 return card;
             }
         }
     }
     else if(pile_type == "2") {
         for (int i = 19; i >= 0; i--) {
             if (!(pile2[i] == "" || pile2[i] == "@@@")) {
                 card = pile2[i];
                 return card;
             }
         }
     }
     else if(pile_type == "3") {
         for (int i = 19; i >= 0; i--) {
             if (!(pile3[i] == "" || pile3[i] == "@@@")) {
                 card = pile3[i];
                 return card;
             }
         }
     }
     else if(pile_type == "4") {
         for (int i = 19; i >= 0; i--) {
             if (!(pile4[i] == "" || pile4[i] == "@@@")) {
                 card = pile4[i];
                 return card;
             }
         }
     }
     else if(pile_type == "5") {
         for (int i = 19; i >= 0; i--) {
             if (!(pile5[i] == "" || pile5[i] == "@@@")) {
                 card = pile5[i];
                 return card;
             }
         }
     }
     else if(pile_type == "6") {
         for (int i = 19; i >= 0; i--) {
             if (!(pile6[i] == "" || pile6[i] == "@@@")) {
                 card = pile6[i];
                 return card;
             }
         }
     }
     return "";
 }
 void Methods::Move_to_foundation_pile(string pile_type) { // this method transport the card from pile to foundation also from foundation to pile
     string card=card_Finding(pile_type);
     string card2;
     string cardcopy=card;
     if(card=="") {
         write.writefile("invalid move\n");

         Print("****************************************\n\n");
         return;
     }
     char cardtype=cardcopy.at(0);
     int number = 0;
     if(cardtype=='H') {
            for(int i = 12 ; i>=0 ; i--) {
                if (!(foundation_1[i]=="")) {
                    card2=foundation_1[i];
                    number=i+1;
                    break;
                }
            }
     }
     else if(cardtype=='D') {
         for(int i = 12 ; i>=0 ; i--) {
             if (!(foundation_2[i]=="")) {
                 card2=foundation_2[i];
                 number=i+1;
                 break;
             }
         }
     }
     else if(cardtype=='S') {
         for(int i = 12 ; i>=0 ; i--) {
             if (!(foundation_3[i]=="")) {
                 card2=foundation_3[i];
                 number=i+1;
                 break;
             }
         }
     }
     else if(cardtype=='C') {
         for(int i = 12 ; i>=0 ; i--) {
             if (!(foundation_4[i]=="")) {
                 card2=foundation_4[i];
                 number=i+1;
                 break;
             }
         }
     }
    if(card_control_method_foundation(card,card2)) {
        if(cardtype=='H') {
            foundation_1[number]=card;
            if(pile_type=="0") {
                for(int i = 0 ; i < 20 ; i++) {
                    if(pile0[i]==card) {
                        pile0[i]="";
                        pile_0[i]="";
                        break;
                    }
                }
            }
         else  if(pile_type=="1") {
                for(int i = 0 ; i < 20 ; i++) {
                    if(pile1[i]==card) {
                        pile1[i]="";
                        pile_1[i]="";
                        break;
                    }
                }
            }
            else if(pile_type=="2") {
                for(int i = 0 ; i < 20 ; i++) {
                    if(pile2[i]==card) {
                        pile2[i]="";
                        pile_2[i]="";
                        break;
                    }
                }
            }
           else if(pile_type=="3") {
                for(int i = 0 ; i < 20 ; i++) {
                    if(pile3[i]==card) {
                        pile3[i]="";
                        pile_3[i]="";
                        break;
                    }
                }
            }
           else if(pile_type=="4") {
                for(int i = 0 ; i < 20 ; i++) {
                    if(pile4[i]==card) {
                        pile4[i]="";
                        pile_4[i]="";
                        break;
                    }
                }
            }
          else if(pile_type=="5") {
                for(int i = 0 ; i < 20 ; i++) {
                    if(pile5[i]==card) {
                        pile5[i]="";
                        pile_5[i]="";
                        break;
                    }
                }
            }
         else  if(pile_type=="6") {
                for(int i = 0 ; i < 20 ; i++) {
                    if(pile6[i]==card) {
                        pile6[i]="";
                        pile_6[i]="";
                        break;
                    }
                }
            }
        }
        else if(cardtype=='D') {
            foundation_2[number]=card;
            if(pile_type=="0") {
                for(int i = 0 ; i < 20 ; i++) {
                    if(pile0[i]==card) {
                        pile0[i]="";
                        pile_0[i]="";
                        break;
                    }
                }
            }
            else  if(pile_type=="1") {
                for(int i = 0 ; i < 20 ; i++) {
                    if(pile1[i]==card) {
                        pile1[i]="";
                        pile_1[i]="";
                        break;
                    }
                }
            }
            else if(pile_type=="2") {
                for(int i = 0 ; i < 20 ; i++) {
                    if(pile2[i]==card) {
                        pile2[i]="";
                        pile_2[i]="";
                        break;
                    }
                }
            }
            else if(pile_type=="3") {
                for(int i = 0 ; i < 20 ; i++) {
                    if(pile3[i]==card) {
                        pile3[i]="";
                        pile_3[i]="";
                        break;
                    }
                }
            }
            else if(pile_type=="4") {
                for(int i = 0 ; i < 20 ; i++) {
                    if(pile4[i]==card) {
                        pile4[i]="";
                        pile_4[i]="";
                        break;
                    }
                }
            }
            else if(pile_type=="5") {
                for(int i = 0 ; i < 20 ; i++) {
                    if(pile5[i]==card) {
                        pile5[i]="";
                        pile_5[i]="";
                        break;
                    }
                }
            }
            else  if(pile_type=="6") {
                for(int i = 0 ; i < 20 ; i++) {
                    if(pile6[i]==card) {
                        pile6[i]="";
                        pile_6[i]="";
                        break;
                    }
                }
            }
        }
        if(cardtype=='S') {
            foundation_3[number]=card;
            if(pile_type=="0") {
                for(int i = 0 ; i < 20 ; i++) {
                    if(pile0[i]==card) {
                        pile0[i]="";
                        pile_0[i]="";
                        break;
                    }
                }
            }
            else  if(pile_type=="1") {
                for(int i = 0 ; i < 20 ; i++) {
                    if(pile1[i]==card) {
                        pile1[i]="";
                        pile_1[i]="";
                        break;
                    }
                }
            }
            else if(pile_type=="2") {
                for(int i = 0 ; i < 20 ; i++) {
                    if(pile2[i]==card) {
                        pile2[i]="";
                        pile_2[i]="";
                        break;
                    }
                }
            }
            else if(pile_type=="3") {
                for(int i = 0 ; i < 20 ; i++) {
                    if(pile3[i]==card) {
                        pile3[i]="";
                        pile_3[i]="";
                        break;
                    }
                }
            }
            else if(pile_type=="4") {
                for(int i = 0 ; i < 20 ; i++) {
                    if(pile4[i]==card) {
                        pile4[i]="";
                        pile_4[i]="";
                        break;
                    }
                }
            }
            else if(pile_type=="5") {
                for(int i = 0 ; i < 20 ; i++) {
                    if(pile5[i]==card) {
                        pile5[i]="";
                        pile_5[i]="";
                        break;
                    }
                }
            }
            else  if(pile_type=="6") {
                for(int i = 0 ; i < 20 ; i++) {
                    if(pile6[i]==card) {
                        pile6[i]="";
                        pile_6[i]="";
                        break;
                    }
                }
            }
        }
        if(cardtype=='C') {
            foundation_4[number]=card;
            if(pile_type=="0") {
                for(int i = 0 ; i < 20 ; i++) {
                    if(pile0[i]==card) {
                        pile0[i]="";
                        pile_0[i]="";
                        break;
                    }
                }
            }
            else  if(pile_type=="1") {
                for(int i = 0 ; i < 20 ; i++) {
                    if(pile1[i]==card) {
                        pile1[i]="";
                        pile_1[i]="";
                        break;
                    }
                }
            }
            else if(pile_type=="2") {
                for(int i = 0 ; i < 20 ; i++) {
                    if(pile2[i]==card) {
                        pile2[i]="";
                        pile_2[i]="";
                        break;
                    }
                }
            }
            else if(pile_type=="3") {
                for(int i = 0 ; i < 20 ; i++) {
                    if(pile3[i]==card) {
                        pile3[i]="";
                        pile_3[i]="";
                        break;
                    }
                }
            }
            else if(pile_type=="4") {
                for(int i = 0 ; i < 20 ; i++) {
                    if(pile4[i]==card) {
                        pile4[i]="";
                        pile_4[i]="";
                        break;
                    }
                }
            }
            else if(pile_type=="5") {
                for(int i = 0 ; i < 20 ; i++) {
                    if(pile5[i]==card) {
                        pile5[i]="";
                        pile_5[i]="";
                        break;
                    }
                }
            }
            else  if(pile_type=="6") {
                for(int i = 0 ; i < 20 ; i++) {
                    if(pile6[i]==card) {
                        pile6[i]="";
                        pile_6[i]="";
                        break;
                    }
                }
            }
        }
    }
    else {
        write.writefile("invalid move\n");
        Print("****************************************\n\n");
        return;
    }
     Print("****************************************\n\n");


 }
 void Methods::Move_to_foundation_waste() {// this method transport the card from stock to foundation
     string card1;
     if(!(slot3=="___")) {
         card1=slot3;
     }
     else {
         if(!(slot2=="___")) {
             card1=slot2;
         }
         else {
             if(!(slot1=="___")) {
                 card1=slot1;
             }
             else {
                 write.writefile("invalid move\n");
                 Print("****************************************\n");
                 return;
             }
         }
     }
     string card1copy=card1;
     char card1type=card1.at(0);
     int card1number=stoi(card1copy.erase(0,1));
     bool kontrol = false;   // open from stock move to foundation waste
         if(card1type=='H') {
             if(foundation_1[card1number-1]=="") {
                 if(card1number==1) {
                     foundation_1[0] = card1;
                     kontrol = true;
                 }
                 else {
                     if(foundation_1[card1number-2]!="") {
                         foundation_1[card1number-1] = card1;
                         kontrol = true;
                     }
                 }
             }
         }
         else if(card1type=='D') {
             if(foundation_2[card1number-1]=="") {
                 if(card1number==1) {
                     foundation_2[0] = card1;
                     kontrol = true;
                 }
                 else {
                     if(foundation_2[card1number-2]!="") {
                         foundation_2[card1number-1] = card1;
                         kontrol = true;
                     }
                 }
             }
         }
         else if(card1type=='S') {
             if(foundation_3[card1number-1]=="") {
                 if(card1number==1) {
                     foundation_3[0] = card1;
                     kontrol = true;
                 }
                 else {
                     if(foundation_3[card1number-2]!="") {
                         foundation_3[card1number-1] = card1;
                         kontrol = true;
                     }
                 }
             }
         }
         else {
             if(foundation_4[card1number-1]=="") {
                 if(card1number==1) {
                     foundation_4[0] = card1;
                     kontrol = true;
                 }
                 else {
                     if(foundation_4[card1number-2]!="") {
                         foundation_4[card1number-1] = card1;
                         kontrol = true;
                     }
                 }
             }
         }
         if(kontrol) {
             int number = 0;
             for (int i = 0; i < 24; i++) {
                 if (stock[i] == card1) {
                     stock[i] = "";
                     number = i;
                 }
             }
             if (card1 == slot3) {
                 slot3 = "___";
             } else if (card1 == slot2) {
                 slot2 = "___";
             } else {
                 string slot1card;
                 for (int i = number; i >= 0; i--) {
                     if (!(stock[i] == "")) {
                         slot1card = stock[i];
                         break;
                     }
                 }
                 if (slot1card == "") {
                     slot1 = "___";
                 } else {
                     slot1 = slot1card;
                 }
             }
         }
         else {
             write.writefile("invalid move\n");
             Print("****************************************\n\n");
             return;
         }
         Print("****************************************\n\n");

 }
 bool Methods::Win() { // İf foundation slots are full these method return true and game is over.
    if(foundation1=="H13"&&foundation2=="D13"&&foundation3=="S13"&&foundation4=="C13") {
        return true;
    }
    return false;
}
