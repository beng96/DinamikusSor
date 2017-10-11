#ifndef SOR_H_INCLUDED
#define SOR_H_INCLUDED

class Sor
{
   public:

      Sor(int elemek = 128);
      Sor (const Sor&);
      ~Sor();

      void Berak(int ); //Hatulra
      void Kivesz(int &); //Elore
      void Elso(int &) const; //Elolrol
      bool Ures() const;
      bool Tele() const;
      int Hossz() const;
      friend std::istream& operator>> (std::istream& s, Sor& a);
      friend std::ostream& operator<< (std::ostream& s, Sor& a);

   private:
      int eleje, vege, darab, maxMeret;
      int *sor;
};

#endif // SOR_H_INCLUDED
