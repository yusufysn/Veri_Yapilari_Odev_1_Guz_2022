#ifndef EKRAN_HPP
#define EKRAN_HPP

#include<iostream>
#include<iomanip>
#include "YoneticiListe.hpp"
#include "DosyaOku.hpp"
using namespace std;


class Ekran
{
public:
    int sira;
    int sonrakiDugumler;
    int yazdirilanDugumSayisi;
    string harf;
    DosyaOku* d;
    
    Ekran();
    ~Ekran();
    void ilkveson();//ekranin ustundeki ilk ve son isaretlerini yazar
    void cizgiCiz();//dugum aralarindaki cizgileri cizer
    void dugumAdres();//yonetici listedeki dugumlerin adreslerini yazar
    void oncekiAdres();//yonetici listedeki dugumlerin onceki adreslerini yazar
    void ortalamaYaz();//yonetici listedeki dugumlerin tutugu ortalama degerini yazar
    void sonrakiAdres();//yonetici listedeki dugumlerin sonraki adreslerini yazar
    void yoneticiListeCiz();//yonetici listeyi 8 dugum olarak cizer
    void boslukBirak();//dugumler arasindaki bosluklari cizer
    void satirListesiCiz(int random = -1);//yonetici dugumun icindeki satir listesini yazdirir
    void Ciz();
};


#endif