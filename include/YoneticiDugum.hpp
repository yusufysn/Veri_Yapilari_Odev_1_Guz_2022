#ifndef YONETICIDUGUM_HPP
#define YONETICIDUGUM_HPP
#include<iostream>
#include"BagliListe.hpp"
using namespace std;

class YoneticiDugum
{
public:
    YoneticiDugum(BagliListe* liste = NULL, const float& ort = 0);
    ~YoneticiDugum();
    float ortalama;
    BagliListe* SatirListesi;
    YoneticiDugum* sonraki;
    YoneticiDugum* onceki;
};

#endif