#ifndef SERVICELAYER_H
#define SERVICELAYER_H

#include "persons.h"
#include <vector>

using namespace std;


class ServiceLayer
{
    vector<Persons> people;
public:
    ServiceLayer();
    vector<Persons> list();
};

#endif // SERVICELAYER_H
