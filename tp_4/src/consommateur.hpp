#ifndef _CONSOMMATEUR_
#define _CONSOMMATEUR_

#include <memory>
#include <ressource.hpp>

class Consommateur
{
private:
    int _besoin = 0;
    std::shared_ptr<Ressource> _ressource = nullptr;

public:
    Consommateur(){};
    Consommateur(int besoin, std::shared_ptr<Ressource> ressource) : _besoin{besoin}, _ressource{ressource} {}
    void puiser()
    {
        if (_ressource != nullptr)
        {
            _ressource->consommer(_besoin);
            if (_ressource->getStock() <= 0)
            {
                _ressource.reset();
                _ressource = nullptr;
            }
        }
    }
};

#endif