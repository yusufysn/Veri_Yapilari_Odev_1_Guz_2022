#ifndef YONETICILISTE_hpp
#define YONETICILISTE_hpp
#include "YoneticiDugum.hpp"
#include "BagliListe.hpp"

class YoneticiListe 
{
public:
    YoneticiListe();
    ~YoneticiListe();
    void ekle(int sira,BagliListe* liste);
    void ekle(BagliListe* liste);
    YoneticiDugum* dugumGetir(int sira);
    int dugumSayisiGetir() const;
    int buyukOrtalamaninIndexi(float ort);
    void cikar(int sira);
    void cikar();
    YoneticiDugum* sondanBirOncekiGetir();
    YoneticiDugum* ilk;
    int dugumSayisi;
};

#endif