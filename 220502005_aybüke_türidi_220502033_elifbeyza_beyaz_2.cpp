#include "geometri.h"
#include <sstream>
#include <cmath>
#include <iostream>
#include <sstream>




//NOKTA

// Parametresiz yap�c�
Nokta::Nokta() : x(0.0), y(0.0) {}

// Tek parametreli yap�c�
Nokta::Nokta(double value) : x(value), y(value) {}

// �ki parametreli yap�c�
Nokta::Nokta(double x, double y) : x(x), y(y) {}

// Kopyalama yap�c�
Nokta::Nokta(const Nokta& other) : x(other.x), y(other.y) {}

// Ofsetli yap�c�
Nokta::Nokta(const Nokta& other, double ofset_x, double ofset_y) : x(other.x + ofset_x), y(other.y + ofset_y) {}

// Y�k�c�
Nokta::~Nokta() {}

// Getter ve Setter metotlar�
double Nokta::getX() const {
    return x;
}

double Nokta::getY() const {
    return y;
}

void Nokta::setX(double x) {
    this->x = x;
}

void Nokta::setY(double y) {
    this->y = y;
}

void Nokta::setC(double x, double y) {
    this->x = x;
    this->y = y;
}

// string 
std::string Nokta::toString() const {
    return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
}
// yazdir
void Nokta::yazdir() const {
    std::cout << toString() << std::endl;
}





//DOGRU PARCASI

// �ki u� noktay� Nokta nesnesi olarak alan yap�c�
DogruParcasi::DogruParcasi(const Nokta& baslangic, const Nokta& bitis)
    : baslangicNoktasi(baslangic), bitisNoktasi(bitis) {}

// Ba�ka bir DogruParcasi nesnesi al�p kopyas�n� olu�turan yap�c�
DogruParcasi::DogruParcasi(const DogruParcasi& otherLine)
    : baslangicNoktasi(otherLine.getBaslangicNoktasi()), bitisNoktasi(otherLine.getBitisNoktasi()) {}

// Bir Nokta nesnesi, par�an�n uzunlu�u ve e�imi de�erlerini alarak
// do�ru par�as�n�n u� noktalar�n� hesaplayan yap�c�
DogruParcasi::DogruParcasi(const Nokta& ortaNokta, double uzunluk, double egim) {
    // Uzunlu�u ve e�imi kullanarak biti� noktas�n� hesapla
    double deltaX = uzunluk * std::cos(egim);
    double deltaY = uzunluk * std::sin(egim);

    // Ba�lang�� noktas� sabit, biti� noktas�n� hesapla
    bitisNoktasi.setX(ortaNokta.getX() + deltaX);
    bitisNoktasi.setY(ortaNokta.getY() + deltaY);

    // Ba�lang�� noktas� direkt olarak orta nokta
    baslangicNoktasi = ortaNokta;
}

// Getter ve Setter metotlar�
Nokta DogruParcasi::getBaslangicNoktasi() const {
    return baslangicNoktasi;
}

void DogruParcasi::setBaslangicNoktasi(const Nokta& baslangic) {
    baslangicNoktasi = baslangic;
}

Nokta DogruParcasi::getBitisNoktasi() const {
    return bitisNoktasi;
}

void DogruParcasi::setBitisNoktasi(const Nokta& bitis) {
    bitisNoktasi = bitis;
}

void DogruParcasi::setP1(const Nokta& p1) {
    baslangicNoktasi = p1;
}

// Uzunluk hesaplama metodu
double DogruParcasi::uzunluk() const {
    double deltaX = bitisNoktasi.getX() - baslangicNoktasi.getX();
    double deltaY = bitisNoktasi.getY() - baslangicNoktasi.getY();

    // Uzunlu�u do�rudan hesapla
    return std::sqrt(deltaX * deltaX + deltaY * deltaY);
}


Nokta DogruParcasi::kesisimNoktasi(const Nokta& nokta) const {
    // Kesi�im noktas�n�n x koordinat�, do�ru par�as�n�n ba�lang�� noktas�n�n x koordinat�na e�ittir.
    double xKesisim = baslangicNoktasi.getX();

    // Kesi�im noktas�n�n y koordinat�n� hesapla, dik do�ru par�as�n�n e�imi kullan�larak.
    double yKesisim = baslangicNoktasi.getY() + ((nokta.getX() - baslangicNoktasi.getX()) * std::tan(std::atan2(bitisNoktasi.getY() - baslangicNoktasi.getY(), bitisNoktasi.getX() - baslangicNoktasi.getX())));

    return Nokta(xKesisim, yKesisim);
}

// Do�ru par�as�n�n orta noktas�n� hesaplayan ve bir Nokta nesnesi olarak d�nd�ren metot
Nokta DogruParcasi::ortaNokta() const {
    double xOrta = (baslangicNoktasi.getX() + bitisNoktasi.getX()) / 2.0;
    double yOrta = (baslangicNoktasi.getY() + bitisNoktasi.getY()) / 2.0;
    return Nokta(xOrta, yOrta);
}

// toString metodu
std::string DogruParcasi::toString() const {
    return "Baslangic: " + baslangicNoktasi.toString() + ", Bitis: " + bitisNoktasi.toString();
}


// ekrana yazd�rma metodu
void DogruParcasi::yazdir() const {
    std::cout << toString() << std::endl;
}





//DA�RE SINIFI

// Merkez ve yar��ap� parametre olarak alan yap�c�
Daire::Daire(const Nokta& merkez, double yaricap) : merkez(merkez), yaricap(yaricap) {}

// Ba�ka bir Daire nesnesi al�p kopyas�n� yeni bir Daire nesnesi olarak olu�turan yap�c�
Daire::Daire(const Daire& otherCircle) : merkez(otherCircle.merkez), yaricap(otherCircle.yaricap) {}

// Ba�ka bir Daire nesnesi ve reel bir pozitif x de�eri alarak, parametre olarak al�nan Daire nesnesini yar��ap� x ile �arp�lm�� olarak kopyalayan yap�c�
Daire::Daire(const Daire& otherCircle, double x) : merkez(otherCircle.merkez), yaricap(otherCircle.yaricap* x) {}

// Alan� hesaplayan metot
double Daire::alan() const {
    return std::acos(-1.0) * yaricap * yaricap;
}

// �evreyi hesaplayan metot
double Daire::cevre() const {
    return 2 * std::acos(-1.0) * yaricap;
}

int Daire::kesisim(const Daire& digerDaire) const {
    double merkezMesafe = sqrt(pow(merkez.getX() - digerDaire.merkez.getX(), 2) + pow(merkez.getY() - digerDaire.merkez.getY(), 2));

    return (merkezMesafe > yaricap + digerDaire.yaricap) ? 2 :
        (merkezMesafe + digerDaire.yaricap < yaricap) ? 0 :
        1;
}


// toString metodu
std::string Daire::toString() const {
    std::ostringstream ss;
    ss << "Merkez: " << merkez.toString() << ", Yar��ap: " << yaricap;
    return ss.str();
}

// Yazd�r metodu
void Daire::yazdir() const {
    std::cout << toString() << std::endl;
}




//UCGEN

// �� tane Nokta nesnesi alan yap�c�
Ucgen::Ucgen(const Nokta& nokta1, const Nokta& nokta2, const Nokta& nokta3)
    : nokta1(nokta1), nokta2(nokta2), nokta3(nokta3) {}

// Getter ve Setter metotlar�
Nokta Ucgen::getNokta1() const {
    return nokta1;
}

void Ucgen::setNokta1(const Nokta& nokta) {
    nokta1 = nokta;
}

Nokta Ucgen::getNokta2() const {
    return nokta2;
}

void Ucgen::setNokta2(const Nokta& nokta) {
    nokta2 = nokta;
}

Nokta Ucgen::getNokta3() const {
    return nokta3;
}

void Ucgen::setNokta3(const Nokta& nokta) {
    nokta3 = nokta;
}

// toString metodu
std::string Ucgen::toString() const {
    std::ostringstream ss;
    ss << "��gen; " << nokta1.toString() << ", " << nokta2.toString() << ", " << nokta3.toString();
    return ss.str();
}

// Alan� hesaplayan metot
double Ucgen::alan() const {
    // �� noktan�n olu�turdu�u ��genin alan�n� hesapla
    return 0.5 * std::abs((nokta1.getX() * (nokta2.getY() - nokta3.getY()) +
        nokta2.getX() * (nokta3.getY() - nokta1.getY()) +
        nokta3.getX() * (nokta1.getY() - nokta2.getY())));
}



// �evreyi hesaplayan metot
double Ucgen::cevre() const {
    return DogruParcasi(nokta1, nokta2).uzunluk() +
        DogruParcasi(nokta2, nokta3).uzunluk() +
        DogruParcasi(nokta3, nokta1).uzunluk();
}






