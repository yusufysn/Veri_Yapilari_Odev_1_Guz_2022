/**
 * @file            DosyaOku.cpp
 * @description     dosyadan okuma islemlerini yapar
 * @assingnment     1. Odev
 * @date            13.11.2022
 * @author          Yusuf Yesin
 */
#include "DosyaOku.hpp"
#include "BagliListe.hpp"
#include "Ekran.hpp"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

DosyaOku::DosyaOku() {
    SatirListesi = new BagliListe*[satirSayisi()];
    for (int i = 0; i < satirSayisi(); i++)
    {
        SatirListesi[i] = new BagliListe();
    }
    string satir = "";
    string sayi = "";
    int j = 0; //satir sayaci
    ifstream dosyaoku("./veriler.txt");
    if ( dosyaoku.is_open() ){
        while (getline(dosyaoku, satir) ){
            int i = 0; //karakter sayaci
            while(true){
                if (satir[i] == ' ' && i != satir.length()-1) {
                    SatirListesi[j]->ekle(stoi(sayi));
                    i++;
                    sayi = "";
                    continue;
                }
                sayi += satir[i];
                i++;
                if (satir[i-1]=='\0') {
                    SatirListesi[j]->ekle(stoi(sayi));
                    sayi = "";
                    break;
                }
            }
            j++;
        }
        dosyaoku.close();
    }
    int s = 0, i = 0;
    
    yoneticiListe = new YoneticiListe();
    
    yoneticiListe->ekle(SatirListesi[0]);
    for (int i = 1; i < j; i++)//satir sayisi
    {
        int indis = yoneticiListe->buyukOrtalamaninIndexi(SatirListesi[i]->ortalamaHesapla());
        if(yoneticiListe->dugumSayisiGetir() == indis) yoneticiListe->ekle(SatirListesi[i]);
        else yoneticiListe->ekle(indis, SatirListesi[i]);
    }
}
int DosyaOku::satirSayisi(){
    // Satir sayisini bulur.
    string satir = "";
    int satirSayisi = 0;
    ifstream dosyaoku("./veriler.txt");
    if ( dosyaoku.is_open() ){
        while (getline(dosyaoku, satir) ){
            satirSayisi++;
        }
        dosyaoku.close();
    }
    return satirSayisi;
}
DosyaOku::~DosyaOku(){
    delete[] SatirListesi;
    delete yoneticiListe;
}