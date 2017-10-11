#include <iostream>
#include <fstream>

#include <stdlib.h>

#include "Sor.h"
using namespace std;

void menu(){
    int hossz;
    cerr << "Adja meg a a sor hosszat! (<=0 eseten default 128 hossz):";
    cin >> hossz;
    if (hossz<=0){hossz=128;}
    Sor teszt(hossz);
    char opcio;
    while (opcio!='q'){
        cerr << "Valasszon egy opciot a kovetkezok kozul:\n 'a' - a sor vegere fuzes \n 'p' - a sor elso elemenek kiirasa es kivetele \n 'f' - a sor elso elemenek kiirasa \n 'q' - kilepes" << endl;
        cin >> opcio;
        switch(opcio){
        int temp;
        case 'a':
            cerr << "Adjon meg egy erteket: ";
            cin >> temp;
            if (!teszt.Tele()){
                teszt.Berak(temp);
            }else{cerr<<"A sor tele van!\n";}
            break;
        case 'p':
            if (!teszt.Ures()){
                teszt.Kivesz(temp);
                cerr << "A kivett elem a " << temp << " volt."<< endl;
            }else{cerr << "A sor ures!\n";}
            break;
        case 'f':
            if (!teszt.Ures()){
                teszt.Elso(temp);
                cerr << "A sor elso eleme a: " << temp << endl;
            }else{cerr << "A sor ures!\n";}
            break;
        case 'q':
            break;
        default:
            cerr << "Nem valid parancs!\n";
        }
        cerr << teszt << endl;
    }
}

int main()
{
    const string fileName = "inp.txt";
        ifstream in(fileName.c_str());
        if(in.fail()){
            cout << "Fajlnyitasi hiba!" << endl;
            exit(1);
        }
    int temp;
    Sor a(3);
    in>>a;
    cerr << "a sor: ";
    a.Kivesz(temp);
    cerr << temp;
    a.Kivesz(temp);
    cerr << temp;
    a.Kivesz(temp);
    cerr << temp << endl;
    Sor b(2);
    in>>b;
    cerr << "b sor: ";
    b.Kivesz(temp);
    cerr << temp;
    b.Kivesz(temp);
    cerr << temp <<endl;
    cerr << "c sor: ";
    Sor c(1);
    in>>c;
    cerr << c;
    c.Kivesz(temp);
    cerr << temp;
    //menu();
    return 0;
}
