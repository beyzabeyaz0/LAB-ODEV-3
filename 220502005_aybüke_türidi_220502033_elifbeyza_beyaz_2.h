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
    Nokta(); // Parametresiz yapýcý
    Nokta(double value); // Tek parametreli yapýcý
    Nokta(double x, double y); // Ýki parametreli yapýcý
    Nokta(const Nokta& other); // Kopyalama yapýcý
    Nokta(const Nokta& other, double ofset_x, double ofset_y); // Ofsetli yapýcý
    ~Nokta(); // Yýkýcý

    // Getter ve Setter metotlarý
    double getX() const;
    double getY() const;
    void setX(double x);
    void setY(double y);
    void setC(double x, double y);

    // Diðer iþlevler
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
    // Ýki uç noktayý Nokta nesnesi olarak alan yapýcý
    DogruParcasi(const Nokta& baslangic, const Nokta& bitis);

    // Baþka bir DogruParcasi nesnesi alýp kopyasýný oluþturan yapýcý
    DogruParcasi(const DogruParcasi& otherLine);

    // Bir Nokta nesnesi, parçanýn uzunluðu ve eðimi deðerlerini alarak
    // doðru parçasýnýn uç noktalarýný hesaplayan yapýcý
    DogruParcasi(const Nokta& ortaNokta, double uzunluk, double egim);

    // Getter ve Setter metotlarý
    Nokta getBaslangicNoktasi() const;
    void setBaslangicNoktasi(const Nokta& baslangic);

    Nokta getBitisNoktasi() const;
    void setBitisNoktasi(const Nokta& bitis);

    // Uzunluk hesaplama metodu
    double uzunluk() const;

    // Bir Nokta nesnesini parametre olarak alýr, çizilecek dik doðru parçasýnýn kesiþme noktasýný hesaplar
    // ve bir Nokta nesnesi olarak döndürür.
    Nokta kesisimNoktasi(const Nokta& nokta) const;

    // Doðru parçasýnýn orta noktasýný hesaplayan ve bir Nokta nesnesi olarak döndüren metot
    Nokta ortaNokta() const;

    void setP1(const Nokta& p1);

    // toString metodu
    std::string toString() const;

    // ekrana yazdýrma metodu
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
    // Merkez ve yarýçapý parametre olarak alan yapýcý
    Daire(const Nokta& merkez, double yaricap);

    // Baþka bir Daire nesnesi alýp kopyasýný yeni bir Daire nesnesi olarak oluþturan yapýcý
    Daire(const Daire& otherCircle);

    // Baþka bir Daire nesnesi ve reel bir pozitif x deðeri alarak, parametre olarak alýnan Daire nesnesini yarýçapý x ile çarpýlmýþ olarak kopyalayan yapýcý
    Daire(const Daire& otherCircle, double x);

    // Alaný hesaplayan metot
    double alan() const;

    // Çevreyi hesaplayan metot
    double cevre() const;

    // Kesiþim durumunu kontrol eden metot
    int kesisim(const Daire& digerDaire) const;

    // toString metodu
    std::string toString() const;

    // Yazdýr metodu
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

    double* acilar; // Açýlar için dinamik dizi

public:
    // Üç tane Nokta nesnesi alan yapýcý
    Ucgen(const Nokta& nokta1, const Nokta& nokta2, const Nokta& nokta3);

    // Getter ve Setter metotlarý
    Nokta getNokta1() const;
    void setNokta1(const Nokta& nokta);
    Nokta getNokta2() const;
    void setNokta2(const Nokta& nokta);
    Nokta getNokta3() const;
    void setNokta3(const Nokta& nokta);

    // toString metodu
    std::string toString() const;

    // Alaný hesaplayan metot
    double alan() const;

    // Çevreyi hesaplayan metot
    double cevre() const;


};

#endif // UCGEN_H

