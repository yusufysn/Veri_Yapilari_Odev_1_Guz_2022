/**
 * @file            Ekran.cpp
 * @description     Ekrana istenen formatta yazma islemelirini yapar
 * @assingnment     1. Odev
 * @date            13.11.2022
 * @author          Yusuf Yesin
 */
#include "Ekran.hpp"
#include<iomanip>
using namespace std;

Ekran::Ekran()
{
    sira = 0;
    sonrakiDugumler = 0;
    yazdirilanDugumSayisi = 0;
    harf = "";
    d = new DosyaOku();
    
    Ciz();
}
void Ekran::ilkveson()
{
    if(sonrakiDugumler == 0) cout<<"ilk           ";
    else cout<<"<---          ";
    if (d->yoneticiListe->dugumSayisi<8)
    {
        for (int i = 1; i < d->yoneticiListe->dugumSayisi-1; i++)
        {
            cout<<"              ";
        }
    }
    else {
        for (int i = 1; i < 7; i++)
        {
            if (i+sonrakiDugumler+1>=d->yoneticiListe->dugumSayisi) break;
            cout<<"              ";
        }
    }
    if (sonrakiDugumler+8 > d->yoneticiListe->dugumSayisi-1)
    {
        cout<<"      son"<<endl;
    }
    else
        cout<<"      --->"<<endl;
}
void Ekran::cizgiCiz()
{
    if (d->yoneticiListe->dugumSayisi<8)
    {
        for (int i = 0; i < d->yoneticiListe->dugumSayisi; i++)
        {
            cout<<"-----------   ";
        }
        cout<<endl;
    }
    else {
        for (int i = 0; i < 8; i++)
        {
            cout<<"-----------   ";
            if (i+sonrakiDugumler+1>=d->yoneticiListe->dugumSayisi) break;
        }
        cout<<endl;
    }
}
void Ekran::dugumAdres()
{
    if (d->yoneticiListe->dugumSayisi<8 && harf!="p")
    {
        for (int i = 0; i < d->yoneticiListe->dugumSayisi; i++)
        {
            cout<<" "<<setw(9)<<d->yoneticiListe->dugumGetir(i+sonrakiDugumler)<<"    ";
            yazdirilanDugumSayisi++;
        }
        cout<<endl;
    }
    else {
        for (int i = 0; i < 8; i++)
        {
            cout<<" "<<setw(9)<<d->yoneticiListe->dugumGetir(i+sonrakiDugumler)<<"    ";
            if (i+sonrakiDugumler+1>=d->yoneticiListe->dugumSayisi) break;
            yazdirilanDugumSayisi++;
            
        }
        cout<<endl;
    }
}
void Ekran::oncekiAdres()
{
    if (d->yoneticiListe->dugumSayisi<8){
        for (int i = 0; i < d->yoneticiListe->dugumSayisi; i++)
        {
            if(d->yoneticiListe->dugumGetir(i+sonrakiDugumler)->onceki == 0) cout<<"|000000000|   ";
            else cout<<"|"<<setw(9)<<right<<d->yoneticiListe->dugumGetir(i+sonrakiDugumler)->onceki<<"|   ";
        }
        cout<<endl;
    }
    else{
        for (int i = 0; i < 8; i++)
        {
            if(d->yoneticiListe->dugumGetir(i+sonrakiDugumler)->onceki == 0) cout<<"|000000000|   ";
            else cout<<"|"<<setw(9)<<right<<d->yoneticiListe->dugumGetir(i+sonrakiDugumler)->onceki<<"|   ";
            if (i+sonrakiDugumler+1>=d->yoneticiListe->dugumSayisi) break;
        }
        cout<<endl;
    }
}
void Ekran::ortalamaYaz()
{
    if (d->yoneticiListe->dugumSayisi<8)
    {
        for (int i = 0; i < d->yoneticiListe->dugumSayisi; i++)
        {
            cout << fixed << setprecision(2);
            cout<<"|"<<setw(9)<<right<<d->yoneticiListe->dugumGetir(i+sonrakiDugumler)->ortalama<<"|   ";
        }
        cout<<endl;
    }
    else{
        for (int i = 0; i < 8; i++)
        {
            cout << fixed << setprecision(2);
            cout<<"|"<<setw(9)<<right<<d->yoneticiListe->dugumGetir(i+sonrakiDugumler)->ortalama<<"|   ";
            if (i+sonrakiDugumler+1>=d->yoneticiListe->dugumSayisi) break;
        }
        cout<<endl;
    }
}
void Ekran::sonrakiAdres()
{
    if (d->yoneticiListe->dugumSayisi<8)
    {
        for (int i = 0; i < d->yoneticiListe->dugumSayisi; i++)
        {
            if(d->yoneticiListe->dugumGetir(i+sonrakiDugumler)->sonraki == NULL) cout<<"|000000000|   ";
            else cout<<"|"<<setw(9)<<right<<d->yoneticiListe->dugumGetir(i+sonrakiDugumler)->sonraki<<"|   ";
        }
        cout<<endl;
    }
    else
    {
        for (int i = 0; i < 8; i++)
        {
            if(d->yoneticiListe->dugumGetir(i+sonrakiDugumler)->sonraki == NULL) cout<<"|000000000|   ";
            else cout<<"|"<<setw(9)<<right<<d->yoneticiListe->dugumGetir(i+sonrakiDugumler)->sonraki<<"|   ";
            if (i+sonrakiDugumler+1>=d->yoneticiListe->dugumSayisi) break;
        }
        cout<<endl;
    }
}
void Ekran::yoneticiListeCiz()
{
    dugumAdres();
    cizgiCiz();
    oncekiAdres();
    cizgiCiz();
    ortalamaYaz();
    cizgiCiz();
    sonrakiAdres();
    cizgiCiz();
}
void Ekran::boslukBirak()
{
    cout<<setw(14*sira)<<"";
}
void Ekran::satirListesiCiz(int random)
{
    boslukBirak();cout<<"^^^^^^^^^^^"<<endl;
    for (int i = 0; i < d->yoneticiListe->dugumGetir(sira+sonrakiDugumler)->SatirListesi->dugumSayisiGetir(); i++)
    {
        boslukBirak();cout<<setw(10)<<right<<d->yoneticiListe->dugumGetir(sira+sonrakiDugumler)->SatirListesi->dugumGetir(i)<<" "<<endl;
        boslukBirak();cout<<"-----------"<<endl;
        boslukBirak();cout<<"|"<<setw(9)<<right<<d->yoneticiListe->dugumGetir(sira+sonrakiDugumler)->SatirListesi->dugumGetir(i)->veri<<"|"<<endl;
        boslukBirak();cout<<"-----------";
        if(random == i ) cout<<"    <--- silinecek secili";
        cout<<endl;
        if (d->yoneticiListe->dugumGetir(sira+sonrakiDugumler)->SatirListesi->dugumGetir(i)->sonraki == NULL)
        {boslukBirak();cout<<"|000000000|"<<endl;}
        else
        {boslukBirak();cout<<"|"<<setw(9)<<right<<d->yoneticiListe->dugumGetir(sira+sonrakiDugumler)->SatirListesi->dugumGetir(i)->sonraki<<"|"<<endl;}
        cout<<endl;
    }   
}
void Ekran::Ciz()
{
    harf = "";
    int sayac = 1;
    while (true)
    {
        system("cls");
        ilkveson();
        yoneticiListeCiz();
        cout<<endl;
        satirListesiCiz();
        cin>>harf;
        if(harf == "c" && sira == 7 && (d->yoneticiListe->dugumSayisi-1)!=(sira+sonrakiDugumler)){sira-=7; sonrakiDugumler+=8;}
        else if(harf == "c") 
        {
            sira++;
            if(sira == d->yoneticiListe->dugumSayisi%8 && sonrakiDugumler == d->yoneticiListe->dugumSayisi-(d->yoneticiListe->dugumSayisi%8)) sira--;
        }
        else if(harf == "c" && sayac < d->yoneticiListe->dugumSayisi%8) {sira++; sayac++; }
        if(harf == "z" && sira>0) {sira--;if(sayac>1)sayac--;}
        else if(harf == "z" && sonrakiDugumler>0){sira+=7; sonrakiDugumler-=8;if(sayac>1)sayac--; }
        if(harf == "a" && sonrakiDugumler>7) {yazdirilanDugumSayisi-=8; sonrakiDugumler-=8; sayac=1;}
        if(harf == "d" && (sira+sonrakiDugumler)<(d->yoneticiListe->dugumSayisi-8)) 
        {
            sonrakiDugumler+=8;
            if(sira >= d->yoneticiListe->dugumSayisi%8 && sonrakiDugumler == d->yoneticiListe->dugumSayisi-(d->yoneticiListe->dugumSayisi%8)) sonrakiDugumler-=8;
        }
        if(harf == "p") {
            d->yoneticiListe->cikar(sira+sonrakiDugumler);
            if(sira==0 && sonrakiDugumler!=0){
                sira+=7;
                sonrakiDugumler-=8;
            }
            if(sira+sonrakiDugumler==d->yoneticiListe->dugumSayisi){
                sira--;
            }
        }
        if(harf == "k")
        {
            int random = rand()%d->yoneticiListe->dugumGetir(sira+sonrakiDugumler)->SatirListesi->dugumSayisiGetir();
            system("cls");
            ilkveson();
            yoneticiListeCiz();
            cout<<endl;
            satirListesiCiz(random);
            cin>>harf;
            if(harf=="k"){
                //satir listesinde bir dugum var ise yonetici dugumu siler
                if(d->yoneticiListe->dugumGetir(sira+sonrakiDugumler)->SatirListesi->dugumSayisiGetir()==1) {
                    d->yoneticiListe->cikar(sira+sonrakiDugumler);
                    if(sira==0 && (sira+sonrakiDugumler)==d->yoneticiListe->dugumSayisi){sira+=7; sonrakiDugumler-=8;}
                    else if((sira+sonrakiDugumler)==d->yoneticiListe->dugumSayisi) sira--;
                }
                else {
                    float oncekiOrt = d->yoneticiListe->dugumGetir(sira+sonrakiDugumler)->ortalama;
                    d->yoneticiListe->dugumGetir(sira+sonrakiDugumler)->SatirListesi->cikar(random);
                    d->yoneticiListe->dugumGetir(sira+sonrakiDugumler)->ortalama = d->yoneticiListe->dugumGetir(sira+sonrakiDugumler)->SatirListesi->ortalamaHesapla();
                    
                    YoneticiDugum* gecici = d->yoneticiListe->dugumGetir(sira+sonrakiDugumler);
                    YoneticiDugum* yeni = new YoneticiDugum();
                    yeni->ortalama     = d->yoneticiListe->dugumGetir(sira+sonrakiDugumler)->ortalama;
                    yeni->SatirListesi = d->yoneticiListe->dugumGetir(sira+sonrakiDugumler)->SatirListesi;
                    int s = 0;
                    //ortalama arttiğinda sağa oteler
                    if(oncekiOrt < d->yoneticiListe->dugumGetir(sira+sonrakiDugumler)->ortalama && gecici->sonraki != 0)
                    {
                        //son dugume ulasana kadar sonraki dugumler ile yeni ortalamayi karsilastirir
                        while(true)
                        {
                            if(d->yoneticiListe->dugumGetir(sira+sonrakiDugumler)->ortalama < gecici->sonraki->ortalama) break;
                            if(gecici->sonraki==0) break;
                            gecici = gecici->sonraki;
                            s++;
                        }
                        d->yoneticiListe->cikar(sira+sonrakiDugumler);
                        if ((sira+sonrakiDugumler+s)>=d->yoneticiListe->dugumSayisi)
                        {
                            d->yoneticiListe->ekle(yeni->SatirListesi);
                        }
                        else
                        d->yoneticiListe->ekle((sira+sonrakiDugumler+s), yeni->SatirListesi);
                    }
                    //ortalama azaldiğinda sola oteler
                    else if(oncekiOrt > d->yoneticiListe->dugumGetir(sira+sonrakiDugumler)->ortalama)
                    {
                        //ilk dugume ulasana kadar onceki dugumler ile yeni ortalamayi karsilastirir
                        while(gecici->onceki != 0)
                        {
                            if(d->yoneticiListe->dugumGetir(sira+sonrakiDugumler)->ortalama > gecici->onceki->ortalama) break;
                            gecici = gecici->onceki;
                            s--;
                        }
                        d->yoneticiListe->cikar(sira+sonrakiDugumler);
                        if ((sira+sonrakiDugumler+s)>=d->yoneticiListe->dugumSayisi)
                        {
                            d->yoneticiListe->ekle(yeni->SatirListesi);
                        }
                        else
                        d->yoneticiListe->ekle((sira+sonrakiDugumler+s), yeni->SatirListesi);
                    }
                }
                d->yoneticiListe->dugumGetir(sira+sonrakiDugumler)->ortalama = d->yoneticiListe->dugumGetir(sira+sonrakiDugumler)->SatirListesi->ortalamaHesapla();
            }
        }
    }
}
Ekran::~Ekran()
{
    delete d;
}
