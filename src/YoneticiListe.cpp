/**
 * @file            YoneticiListe.cpp
 * @description     satir listelerini yoneten bagli listeyi olusturur
 * @assingnment     1. Odev
 * @date            13.11.2022
 * @author          Yusuf Yesin
 */
#include "YoneticiListe.hpp"
#include "YoneticiDugum.hpp"
YoneticiListe::YoneticiListe()
{
    ilk = NULL;
    dugumSayisi = 0;
}
YoneticiListe::~YoneticiListe()
{
    YoneticiDugum* gecici = ilk;

    for(int i=0;i<dugumSayisi;i++)
    {
        YoneticiDugum* silinecek = gecici;

        gecici= gecici->sonraki;
        delete silinecek;
    }
}
void YoneticiListe::ekle(int sira, BagliListe* liste)
{
    //sira 0 ise ve ilk düğüm yoksa
    if(sira==0&&ilk==NULL)
    {
        ilk = new YoneticiDugum(liste, liste->ortalamaHesapla());
    }
    else
    {
        YoneticiDugum* aktifDugum = dugumGetir(sira);

        if(aktifDugum==NULL) return;

        YoneticiDugum* yeni = new YoneticiDugum(liste, liste->ortalamaHesapla());

        YoneticiDugum* onceki = aktifDugum->onceki;

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
void YoneticiListe::ekle(BagliListe* liste)
{
    
    YoneticiDugum* yeni = new YoneticiDugum(liste, liste->ortalamaHesapla());

    if(ilk==0)
    {
        ilk = yeni;
    }
    else
    {
        YoneticiDugum* gec = ilk;
        
        while(gec->sonraki!=0)
            gec=gec->sonraki;
        
        gec->sonraki=yeni;
        yeni->onceki=gec;
    }
    dugumSayisi++;
}
void YoneticiListe::cikar(int sira)
{
    YoneticiDugum* silinecek = dugumGetir(sira);
    
    if(silinecek==0) return;

    YoneticiDugum* onceki = silinecek->onceki;
    YoneticiDugum* sonraki = silinecek->sonraki;

    delete silinecek;

    if(sonraki)
        sonraki->onceki = onceki;
    if(onceki)
        onceki->sonraki = sonraki;
    else
        ilk = sonraki;
    dugumSayisi--;
}
void YoneticiListe::cikar()
{
    if(ilk==0)  return;

    if(ilk->sonraki==0)
    {
        delete ilk;
        ilk=0;
    }
    else
    {
        YoneticiDugum* gecici = sondanBirOncekiGetir();
        delete gecici->sonraki;
        gecici->sonraki = 0;
    }
    dugumSayisi--;
}
int YoneticiListe::dugumSayisiGetir() const
{
    return dugumSayisi;
}
int YoneticiListe::buyukOrtalamaninIndexi(float ort)
{
    YoneticiDugum* gecici = ilk;
    int index = 0;
    if(ilk->sonraki == NULL && ort > ilk->ortalama) {
        index = 1;
        return index;
    }
    while (gecici != NULL)
    {   
        if (ort < gecici->ortalama) return index;
        
        gecici = gecici->sonraki;
        index++;
    } 
    return index;
}
YoneticiDugum* YoneticiListe::dugumGetir(int sira)
{
    if(sira<0||sira>=dugumSayisi)
        return 0;
    
    YoneticiDugum* gec= ilk;
    
    for(int i=0;i<sira;i++)
    {
        gec=gec->sonraki;
    }
    return gec;
}
YoneticiDugum* YoneticiListe::sondanBirOncekiGetir()
{
    if(ilk==0)
        return 0;
    if(ilk->sonraki==0)
        return ilk;
    
    YoneticiDugum* gec= ilk;
    while(gec->sonraki->sonraki!=0)
        gec=gec->sonraki;

    return gec;
}