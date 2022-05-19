#include "Writing.h"


Writing::Writing() {

}
void Writing::writefile(string output){

    ofstream outfile;
    outfile.open("output.txt", ios_base::app);		
    outfile << output;				

    if(output=="Game Over!\n"){
        outfile.close();
    }
}
