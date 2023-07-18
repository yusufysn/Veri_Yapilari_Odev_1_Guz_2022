/**
 * @file            Dugum.cpp
 * @description     Bagli listenin dugumlerini olusturur
 * @assingnment     1. Odev
 * @date            13.11.2022
 * @author          Yusuf Yesin
 */
#include "Dugum.hpp"
#include <iostream>

Dugum::Dugum(const int& veri)
{
    this->veri = veri;
    sonraki = onceki = 0;
}