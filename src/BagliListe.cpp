/**
 * @file            BagliListe.cpp
 * @description     satir listelerini olusturur
 * @assingnment     1. Odev
 * @date            13.11.2022
 * @author          Yusuf Yesin
 */
#include "BagliListe.hpp"

BagliListe::BagliListe()
{
    ilk=0;
    dugumSayisi = 0;
}
BagliListe::~BagliListe()
{
    Dugum* gecici = ilk;

    for(int i=0;i<dugumSayisi;i++)
    {
        Dugum* silinecek = gecici;

        gecici= gecici->sonraki;
        delete silinecek;
    }
}
int& BagliListe::ilkGetir()
{
    if(ilk)
        return ilk->veri;
    throw std::out_of_range("BagliListe::ilkGetir(): dugum yok hatasi");
}
int& BagliListe::getir(int sira)
{
    Dugum* gec= dugumGetir(sira);

    if(gec!=0)
        return gec->veri;
    throw std::out_of_range("BagliListe::getir(): sira hatali");     
}
void BagliListe::ekle(int sira, const int& veri)
{
    //sira 0 ise ve ilk düğüm yoksa
    if(sira==0&&ilk==0)
    {
        ilk = new Dugum(veri);
    }
    else
    {
        Dugum* aktifDugum = dugumGetir(sira);

        if(aktifDugum==0) return;

        Dugum* yeni = new Dugum(veri);

        Dugum* onceki = aktifDugum->onceki;

        aktifDugum->onceki = yeni;
        yeni->sonraki = aktifDugum;
        yeni->onceki = onceki;

        if(onceki)
            onceki->sonraki = yeni;
        else
            ilk = yeni;
    }

    dugumSayisi++;
}
void BagliListe::ekle(const int& veri)
{
    Dugum* yeni = new Dugum(veri);

    if(ilk==0)
    {
        ilk = yeni;
    }
    else
    {
        Dugum* gec = ilk;
        
        while(gec->sonraki!=0)
            gec=gec->sonraki;
        
        gec->sonraki=yeni;
        yeni->onceki=gec;
    }
    dugumSayisi++;
}
void BagliListe::cikar()
{
    if(ilk==0)  return;

    if(ilk->sonraki==0)
    {
        delete ilk;
        ilk=0;
    }
    else
    {
        Dugum* gecici = sondanBirOncekiGetir();
        delete gecici->sonraki;
        gecici->sonraki = 0;
    }
    dugumSayisi--;
}
void BagliListe::cikar(int sira)
{
    Dugum* silinecek = dugumGetir(sira);
    
    if(silinecek==0) return;
    //sirayı daha önce kontrol ettiğimiz için
    //fonksiyonun var olan bir düğümü getirdiğinden eminiz

    Dugum* onceki = silinecek->onceki;
    Dugum* sonraki = silinecek->sonraki;

    delete silinecek;

    if(sonraki)
        sonraki->onceki = onceki;
    if(onceki)
        onceki->sonraki = sonraki;
    else
        ilk = sonraki;
    dugumSayisi--;
}
int BagliListe::dugumSayisiGetir() const
{
    return dugumSayisi;
}
float BagliListe::ortalamaHesapla()
{
    Dugum* gecici = ilk;
    float toplam = ilk->veri;
    while (gecici->sonraki != NULL)
    {
        gecici = gecici->sonraki;
        toplam += gecici->veri;
    }
    return toplam/(float)dugumSayisiGetir();
}
Dugum* BagliListe::dugumGetir(int sira)
{
    if(sira<0||sira>=dugumSayisi)
        return 0;
    
    Dugum* gec= ilk;
    
    for(int i=0;i<sira;i++)
    {
        gec=gec->sonraki;
    }
    return gec;
}
