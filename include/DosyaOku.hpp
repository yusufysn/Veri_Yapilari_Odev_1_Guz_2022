#ifndef DOSYAOKU_HPP
#define DOSYAOKU_HPP

#include "BagliListe.hpp"
#include "YoneticiListe.hpp"
#include <iostream>

using namespace std;

class DosyaOku {
public:
    DosyaOku();
    int satirSayisi();//verilen veri.txt dosyasindaki satir sayisini bulur
    BagliListe** SatirListesi;
    YoneticiListe* yoneticiListe;
    ~DosyaOku();
};
#endif 
