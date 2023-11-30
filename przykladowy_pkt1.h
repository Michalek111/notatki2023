#pragma once

class Zbior
{
    size_t m_liczbaElementow = 0;
    double* m_elementy = nullptr;
    double m_dolnaGranica = 0;
    double m_gornaGranica = 0;

    void alokuj(size_t);
    void zwolnij();

public:
    Zbior(size_t liczElem, double dGran, double gGran);
    ~Zbior();

    // Mechanizmy kopiowania
    Zbior(const Zbior& other);
    Zbior& operator=(const Zbior& other);

    // Mechanizmy przenoszenia (wykluczone)
    Zbior(Zbior&&) = delete;
    Zbior& operator=(Zbior&&) = delete;
};