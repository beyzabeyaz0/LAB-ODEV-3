#pragma once
#include <iostream>
#include <cmath>

#ifndef NOKTA_H
#define NOKTA_H


class Nokta {
private:
    double x;
    double y;

public:
    Nokta(); // Parametresiz yap�c�
    Nokta(double value); // Tek parametreli yap�c�
    Nokta(double x, double y); // �ki parametreli yap�c�
    Nokta(const Nokta& other); // Kopyalama yap�c�
    Nokta(const Nokta& other, double ofset_x, double ofset_y); // Ofsetli yap�c�
    ~Nokta(); // Y�k�c�

    // Getter ve Setter metotlar�
    double getX() const;
    double getY() const;
    void setX(double x);
    void setY(double y);
    void setC(double x, double y);

    // Di�er i�levler
    std::string toString() const;
    void yazdir() const;
};


#endif



#pragma once
#ifndef DOGRUPARCASI_H
#define DOGRUPARCASI_H



class DogruParcasi {
private:
    Nokta baslangicNoktasi;
    Nokta bitisNoktasi;

public:
    // �ki u� noktay� Nokta nesnesi olarak alan yap�c�
    DogruParcasi(const Nokta& baslangic, const Nokta& bitis);

    // Ba�ka bir DogruParcasi nesnesi al�p kopyas�n� olu�turan yap�c�
    DogruParcasi(const DogruParcasi& otherLine);

    // Bir Nokta nesnesi, par�an�n uzunlu�u ve e�imi de�erlerini alarak
    // do�ru par�as�n�n u� noktalar�n� hesaplayan yap�c�
    DogruParcasi(const Nokta& ortaNokta, double uzunluk, double egim);

    // Getter ve Setter metotlar�
    Nokta getBaslangicNoktasi() const;
    void setBaslangicNoktasi(const Nokta& baslangic);

    Nokta getBitisNoktasi() const;
    void setBitisNoktasi(const Nokta& bitis);

    // Uzunluk hesaplama metodu
    double uzunluk() const;

    // Bir Nokta nesnesini parametre olarak al�r, �izilecek dik do�ru par�as�n�n kesi�me noktas�n� hesaplar
    // ve bir Nokta nesnesi olarak d�nd�r�r.
    Nokta kesisimNoktasi(const Nokta& nokta) const;

    // Do�ru par�as�n�n orta noktas�n� hesaplayan ve bir Nokta nesnesi olarak d�nd�ren metot
    Nokta ortaNokta() const;

    void setP1(const Nokta& p1);

    // toString metodu
    std::string toString() const;

    // ekrana yazd�rma metodu
    void yazdir() const;
};

#endif



#ifndef DAIRE_H
#define DAIRE_H


class Daire {
private:
    Nokta merkez;
    double yaricap;

public:
    // Merkez ve yar��ap� parametre olarak alan yap�c�
    Daire(const Nokta& merkez, double yaricap);

    // Ba�ka bir Daire nesnesi al�p kopyas�n� yeni bir Daire nesnesi olarak olu�turan yap�c�
    Daire(const Daire& otherCircle);

    // Ba�ka bir Daire nesnesi ve reel bir pozitif x de�eri alarak, parametre olarak al�nan Daire nesnesini yar��ap� x ile �arp�lm�� olarak kopyalayan yap�c�
    Daire(const Daire& otherCircle, double x);

    // Alan� hesaplayan metot
    double alan() const;

    // �evreyi hesaplayan metot
    double cevre() const;

    // Kesi�im durumunu kontrol eden metot
    int kesisim(const Daire& digerDaire) const;

    // toString metodu
    std::string toString() const;

    // Yazd�r metodu
    void yazdir() const;
};

#endif


#ifndef UCGEN_H
#define UCGEN_H


class Ucgen {
private:
    Nokta nokta1;
    Nokta nokta2;
    Nokta nokta3;

    double* acilar; // A��lar i�in dinamik dizi

public:
    // �� tane Nokta nesnesi alan yap�c�
    Ucgen(const Nokta& nokta1, const Nokta& nokta2, const Nokta& nokta3);

    // Getter ve Setter metotlar�
    Nokta getNokta1() const;
    void setNokta1(const Nokta& nokta);
    Nokta getNokta2() const;
    void setNokta2(const Nokta& nokta);
    Nokta getNokta3() const;
    void setNokta3(const Nokta& nokta);

    // toString metodu
    std::string toString() const;

    // Alan� hesaplayan metot
    double alan() const;

    // �evreyi hesaplayan metot
    double cevre() const;


};

#endif // UCGEN_H

