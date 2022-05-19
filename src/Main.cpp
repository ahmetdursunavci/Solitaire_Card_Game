/*Hocam eğer kodumu okursanız bir şey izah etmek istiyorum,
 * hocam ben ödevi tam gününde tamamlamıştım aslında.
 * ancak çok fazla error aldım ve bir türlü errorleri düzeltemedim saatlerce uğraştım ama olmadı.
 * sonrasında komple silip tekrar yazdım ödevi. Kısaltmak için çaba gösteremedim çünkü şu an saat 22:06 ve ödev
 * zaten geciktiği için acilen göndermem lazım çok üzgünüm. yorum satırı da yazamadım caktim olmadığı için
 * affedin.
 */
#include <iostream>
#include "Methods.h"
#include <string>
#include <cstring>
#include "Iteration.h"
#include "ReadingFile.h"

using namespace std;
void func(string a) {
    a.erase(0,1);
    cout<<a<<endl;
}
int main(int argc, char *argv[]) {
    string path1=argv[1];
    string path2=argv[2];
    string path3=argv[3];
    Iteration iteration;
    iteration.iteration(path1,path2,path3);














}
