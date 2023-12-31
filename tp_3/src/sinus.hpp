#ifndef _SINUS
#define _SINUS

#include <puissance.hpp>
#include <factorielle.hpp>

template <unsigned long K>
struct Sinus {
    static const double valeur(const long double &x) {
        return Sinus<K - 1>::valeur(x) + (Puissance<K>::valeur(-1) * (Puissance<2 * K + 1>::valeur(x) / Factorielle<2 * K + 1>::valeur));
    }
};

template <>
struct Sinus<0> {
    static const double valeur(const long double &x) {
        return x;
    }
};

#endif