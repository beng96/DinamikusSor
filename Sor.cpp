#include <iostream>
#include "Sor.h"
using namespace std;

Sor::Sor(int elemek) : maxMeret(elemek), sor(new int [maxMeret]), eleje(0), vege(0), darab(0) {}

Sor::Sor (const Sor &eredeti) : maxMeret(eredeti.maxMeret), 
								eleje(eredeti.eleje),
								vege(eredeti.vege), 
								darab(eredeti.darab), 
								sor(new int[maxMeret])
{
	for (int i = 0; i < maxMeret; i++) 
		sor[i] = eredeti.sor[i];
}


Sor::~Sor() { delete [] sor;}

void Sor::Berak(int v)
{
    if(Tele()) cout << "Tele van a sor." << endl;
    else
    {
        vege = (vege + 1) % maxMeret;
        sor[vege] = v;  darab++;
    }
}

void Sor::Kivesz(int &v)
{
    if(Ures()) 
		cout << "Ures a sor." << endl;
    else
    {
        v = sor[eleje];
        eleje = (eleje + 1) % maxMeret; darab--;
    }
}

void Sor::Elso(int &v) const
{
    if(Ures()) 
		cout << "Ures a sor." << endl;
    else
		v = sor[eleje];
}

bool Sor::Ures() const { return (darab == 0); }

bool Sor::Tele() const { return (darab == maxMeret); }

int Sor::Hossz() const { return darab; }

ostream& operator<<(ostream& s, Sor& a)
{
    for(int i=0; i<a.Hossz(); i++)
	{
        int x;
        a.Kivesz(x);
        s << x << ' ';
        a.Berak(x);
    }
    return s;
}

istream& operator>>(istream& s, Sor& a)
{
    for(int i=0; i<a.maxMeret; i++) 
	{
        int temp;
        s >> temp;
        a.Berak(temp);
    }
    return s;
}
