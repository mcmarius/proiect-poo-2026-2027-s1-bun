#include <iostream>
#include <array>
#include <cmath>
#include <ostream>
#include <utility>
#include <vector>

#include "Example.h"

class Student
{
    int m_an;
    int m_grupa;
    std::string m_nume;

public:
    Student(int an, int grupa, const std::string& nume)
        : m_an(an),
          m_grupa(grupa),
          m_nume(nume)
    {
        std::cout << "constr student " << nume << "\n";
    }

    ~Student()
    {
        std::cout << "destr student " << m_nume << "\n";
    }

    Student(const Student& other)
        : m_an(other.m_an),
          m_grupa(other.m_grupa),
          m_nume(other.m_nume)
    {
    }

    Student& operator=(const Student& other)
    {
        if (this == &other)
            return *this;
        m_an = other.m_an;
        m_grupa = other.m_grupa;
        m_nume = other.m_nume;
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const Student& obj)
    {
        return os
            << "m_an: " << obj.m_an
            << " m_grupa: " << obj.m_grupa
            << " m_nume: " << obj.m_nume;
    }
};

class Facultate
{
    std::string m_nume;
    std::vector<Student> m_studenti;

public:
    Facultate(const std::string& m_nume, const std::vector<Student>& m_studenti)
        : m_nume(m_nume),
          m_studenti(m_studenti)
    {
    }

    int scor() { return m_studenti.size(); }
};

class Oras
{
    Facultate m_facultate;
    int nr_locuitori;

public:
    Oras(const Facultate& m_facultate, int nr_locuitori)
        : m_facultate(m_facultate),
          nr_locuitori(nr_locuitori)
    {
        std::cout << "constr oras " << nr_locuitori << "\n";
    }
};

class AnalizaDate
{
    std::string m_nume;
    int nr;

public:
    AnalizaDate(std::string m_nume, int nr)
        : m_nume(std::move(m_nume)),
          nr(nr)
    {
    }

    virtual double rezultat(Facultate f)
    {
        // multe calcule complicate
        return 5 * f.scor() + nr;
    }
};

class AnalizaTest : public AnalizaDate
{
    float precizie;

public:
    AnalizaTest(const std::string& m_nume, int nr, float precizie)
        : AnalizaDate(m_nume, nr),
          precizie(precizie)
    {
    }

    double rezultat([[maybe_unused]] Facultate f) override
    {
        // calculăm cu o formulă aproximativă
        return std::round(7);
    }
};


int main() {
    Student st1{2, 264, "Icsulescu"};
    Student st2{2, 264, "Icsuleanu"};
    std::cout << st1 << st2;
    operator<<(std::cout, "hello\n");

    Facultate fac1{"FMI", {st1, st2}};
    AnalizaTest test{"a1", 2, 3};
    std::cout << test.rezultat(fac1);

    std::cout << "Hello, world!\n";
    Example e1;
    e1.add(3);
    e1.g();
    std::array<int, 100> v{};
    int nr;
    std::cout << "Introduceți nr: ";
    /////////////////////////////////////////////////////////////////////////
    /// Observație: dacă aveți nevoie să citiți date de intrare de la tastatură,
    /// dați exemple de date de intrare folosind fișierul tastatura.txt
    /// Trebuie să aveți în fișierul tastatura.txt suficiente date de intrare
    /// (în formatul impus de voi) astfel încât execuția programului să se încheie.
    /// De asemenea, trebuie să adăugați în acest fișier date de intrare
    /// pentru cât mai multe ramuri de execuție.
    /// Dorim să facem acest lucru pentru a automatiza testarea codului, fără să
    /// mai pierdem timp de fiecare dată să introducem de la zero aceleași date de intrare.
    ///
    /// Pe GitHub Actions (bife), fișierul tastatura.txt este folosit
    /// pentru a simula date introduse de la tastatură.
    /// Bifele verifică dacă programul are erori de compilare, erori de memorie și memory leaks.
    ///
    /// Dacă nu puneți în tastatura.txt suficiente date de intrare, îmi rezerv dreptul să vă
    /// testez codul cu ce date de intrare am chef și să nu pun notă dacă găsesc vreun bug.
    /// Impun această cerință ca să învățați să faceți un demo și să arătați părțile din
    /// program care merg (și să le evitați pe cele care nu merg).
    ///
    /////////////////////////////////////////////////////////////////////////
    std::cin >> nr;
    /////////////////////////////////////////////////////////////////////////
    for(int i = 0; i < nr; ++i) {
        std::cout << "v[" << i << "] = ";
        std::cin >> v[i];
    }
    std::cout << "\n\n";
    std::cout << "Am citit de la tastatură " << nr << " elemente:\n";
    for(int i = 0; i < nr; ++i) {
        std::cout << "- " << v[i] << "\n";
    }
    ///////////////////////////////////////////////////////////////////////////
    /// Pentru date citite din fișier, NU folosiți tastatura.txt. Creați-vă voi
    /// alt fișier propriu cu ce alt nume doriți.
    /// Exemplu:
    /// std::ifstream fis("date.txt");
    /// for(int i = 0; i < nr2; ++i)
    ///     fis >> v2[i];
    ///
    ///////////////////////////////////////////////////////////////////////////
    return 0;
}
