#include "zbior.h"
#include <algorithm>
#include <new>
#include <random>

void Zbior::alokuj(size_t n)
{
    if (n > 0)
    {
        m_elementy = new(std::nothrow) double[n];
        m_liczbaElementow = n;
    }
}

void Zbior::zwolnij()
{
    if (m_elementy != nullptr)
    {
        delete[] m_elementy;
        m_elementy = nullptr;
    }
}

Zbior::Zbior(size_t liczElem, double dGran, double gGran)
{
    alokuj(liczElem);
    std::uniform_real_distribution<double> zakres(dGran, gGran);
    std::random_device generator;
    for (size_t elem = 0; elem < liczElem; elem++)
        m_elementy[elem] = zakres(generator);
}

Zbior::~Zbior()
{
    zwolnij();
}

// Konstruktor kopiuj¹cy
Zbior::Zbior(const Zbior& other)
{
    alokuj(other.m_liczbaElementow);
    std::copy(other.m_elementy, other.m_elementy + m_liczbaElementow, m_elementy);
    m_dolnaGranica = other.m_dolnaGranica;
    m_gornaGranica = other.m_gornaGranica;
}

// Operator przypisania kopiuj¹cy
Zbior& Zbior::operator=(const Zbior& other)
{
    if (this != &other)
    {
        zwolnij();
        alokuj(other.m_liczbaElementow);
        std::copy(other.m_elementy, other.m_elementy + m_liczbaElementow, m_elementy);
        m_dolnaGranica = other.m_dolnaGranica;
        m_gornaGranica = other.m_gornaGranica;
    }
    return *this;
}
