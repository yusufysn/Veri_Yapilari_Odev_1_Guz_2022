/**
 * @file            YoneticiDugum.cpp
 * @description     yonetici listenin dugumlerini olusturur
 * @assingnment     1. Odev
 * @date            13.11.2022
 * @author          Yusuf Yesin
 */
#include "YoneticiDugum.hpp"

YoneticiDugum::YoneticiDugum(BagliListe* liste, const float& ort)
{
    this->ortalama = ort;
    this->SatirListesi = liste;
    sonraki = onceki = 0;
}
YoneticiDugum::~YoneticiDugum()
{ 
}