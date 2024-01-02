#include "geometri.h"
#include <sstream>
#include <cmath>
#include <iostream>
#include <sstream>




//NOKTA

// Parametresiz yapýcý
Nokta::Nokta() : x(0.0), y(0.0) {}

// Tek parametreli yapýcý
Nokta::Nokta(double value) : x(value), y(value) {}

// Ýki parametreli yapýcý
Nokta::Nokta(double x, double y) : x(x), y(y) {}

// Kopyalama yapýcý
Nokta::Nokta(const Nokta& other) : x(other.x), y(other.y) {}

// Ofsetli yapýcý
Nokta::Nokta(const Nokta& other, double ofset_x, double ofset_y) : x(other.x + ofset_x), y(other.y + ofset_y) {}

// Yýkýcý
Nokta::~Nokta() {}

// Getter ve Setter metotlarý
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

// Ýki uç noktayý Nokta nesnesi olarak alan yapýcý
DogruParcasi::DogruParcasi(const Nokta& baslangic, const Nokta& bitis)
    : baslangicNoktasi(baslangic), bitisNoktasi(bitis) {}

// Baþka bir DogruParcasi nesnesi alýp kopyasýný oluþturan yapýcý
DogruParcasi::DogruParcasi(const DogruParcasi& otherLine)
    : baslangicNoktasi(otherLine.getBaslangicNoktasi()), bitisNoktasi(otherLine.getBitisNoktasi()) {}

// Bir Nokta nesnesi, parçanýn uzunluðu ve eðimi deðerlerini alarak
// doðru parçasýnýn uç noktalarýný hesaplayan yapýcý
DogruParcasi::DogruParcasi(const Nokta& ortaNokta, double uzunluk, double egim) {
    // Uzunluðu ve eðimi kullanarak bitiþ noktasýný hesapla
    double deltaX = uzunluk * std::cos(egim);
    double deltaY = uzunluk * std::sin(egim);

    // Baþlangýç noktasý sabit, bitiþ noktasýný hesapla
    bitisNoktasi.setX(ortaNokta.getX() + deltaX);
    bitisNoktasi.setY(ortaNokta.getY() + deltaY);

    // Baþlangýç noktasý direkt olarak orta nokta
    baslangicNoktasi = ortaNokta;
}

// Getter ve Setter metotlarý
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

    // Uzunluðu doðrudan hesapla
    return std::sqrt(deltaX * deltaX + deltaY * deltaY);
}


Nokta DogruParcasi::kesisimNoktasi(const Nokta& nokta) const {
    // Kesiþim noktasýnýn x koordinatý, doðru parçasýnýn baþlangýç noktasýnýn x koordinatýna eþittir.
    double xKesisim = baslangicNoktasi.getX();

    // Kesiþim noktasýnýn y koordinatýný hesapla, dik doðru parçasýnýn eðimi kullanýlarak.
    double yKesisim = baslangicNoktasi.getY() + ((nokta.getX() - baslangicNoktasi.getX()) * std::tan(std::atan2(bitisNoktasi.getY() - baslangicNoktasi.getY(), bitisNoktasi.getX() - baslangicNoktasi.getX())));

    return Nokta(xKesisim, yKesisim);
}

// Doðru parçasýnýn orta noktasýný hesaplayan ve bir Nokta nesnesi olarak döndüren metot
Nokta DogruParcasi::ortaNokta() const {
    double xOrta = (baslangicNoktasi.getX() + bitisNoktasi.getX()) / 2.0;
    double yOrta = (baslangicNoktasi.getY() + bitisNoktasi.getY()) / 2.0;
    return Nokta(xOrta, yOrta);
}

// toString metodu
std::string DogruParcasi::toString() const {
    return "Baslangic: " + baslangicNoktasi.toString() + ", Bitis: " + bitisNoktasi.toString();
}


// ekrana yazdýrma metodu
void DogruParcasi::yazdir() const {
    std::cout << toString() << std::endl;
}





//DAÝRE SINIFI

// Merkez ve yarýçapý parametre olarak alan yapýcý
Daire::Daire(const Nokta& merkez, double yaricap) : merkez(merkez), yaricap(yaricap) {}

// Baþka bir Daire nesnesi alýp kopyasýný yeni bir Daire nesnesi olarak oluþturan yapýcý
Daire::Daire(const Daire& otherCircle) : merkez(otherCircle.merkez), yaricap(otherCircle.yaricap) {}

// Baþka bir Daire nesnesi ve reel bir pozitif x deðeri alarak, parametre olarak alýnan Daire nesnesini yarýçapý x ile çarpýlmýþ olarak kopyalayan yapýcý
Daire::Daire(const Daire& otherCircle, double x) : merkez(otherCircle.merkez), yaricap(otherCircle.yaricap* x) {}

// Alaný hesaplayan metot
double Daire::alan() const {
    return std::acos(-1.0) * yaricap * yaricap;
}

// Çevreyi hesaplayan metot
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
    ss << "Merkez: " << merkez.toString() << ", Yarýçap: " << yaricap;
    return ss.str();
}

// Yazdýr metodu
void Daire::yazdir() const {
    std::cout << toString() << std::endl;
}




//UCGEN

// Üç tane Nokta nesnesi alan yapýcý
Ucgen::Ucgen(const Nokta& nokta1, const Nokta& nokta2, const Nokta& nokta3)
    : nokta1(nokta1), nokta2(nokta2), nokta3(nokta3) {}

// Getter ve Setter metotlarý
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
    ss << "Üçgen; " << nokta1.toString() << ", " << nokta2.toString() << ", " << nokta3.toString();
    return ss.str();
}

// Alaný hesaplayan metot
double Ucgen::alan() const {
    // Üç noktanýn oluþturduðu üçgenin alanýný hesapla
    return 0.5 * std::abs((nokta1.getX() * (nokta2.getY() - nokta3.getY()) +
        nokta2.getX() * (nokta3.getY() - nokta1.getY()) +
        nokta3.getX() * (nokta1.getY() - nokta2.getY())));
}



// Çevreyi hesaplayan metot
double Ucgen::cevre() const {
    return DogruParcasi(nokta1, nokta2).uzunluk() +
        DogruParcasi(nokta2, nokta3).uzunluk() +
        DogruParcasi(nokta3, nokta1).uzunluk();
}






