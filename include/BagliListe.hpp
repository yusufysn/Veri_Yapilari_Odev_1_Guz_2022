#ifndef BagliListe_hpp
#define BagliListe_hpp
#include <exception>
#include <iomanip>
#include "Dugum.hpp"

class BagliListe
{
public:
    BagliListe();
    ~BagliListe();
    int& ilkGetir();
    int& getir(int sira);
    void ekle(int sira,const int& veri);
    void ekle(const  int& veri);
    void cikar();
    void cikar(int sira);
    int dugumSayisiGetir() const;
    float ortalamaHesapla();
    Dugum* dugumGetir(int sira);
private:
    Dugum* sondanBirOncekiGetir()
    {
        if(ilk==0)
            return 0;
        if(ilk->sonraki==0)
            return ilk;
        
        Dugum* gec= ilk;
        while(gec->sonraki->sonraki!=0)
            gec=gec->sonraki;

        return gec;
    }
    
    Dugum* ilk;
    int dugumSayisi;
};

#endif