#ifndef PERSONS_H
#define PERSONS_H

#include <iostream>

using namespace std;

class Persons
{
private:
    int ID;
    string name;
    int birthYear;
    int deathYear;
    char gender;
    bool alive;

    //These are for making sure that we get valid information when using the >> operator.
    /*bool validName(const string& s);
    bool genderCheck(char& gender);
    bool validYear(const string& s, int& year);
    bool birthChecks(int birthYear, int deathYear);*/

public:
    Persons();
    Persons(int id, string n, char g, int bY, int dY); //Constructor which takes in Name, gender, birthyear and deathyear (with 0 for living persons).

    string getName() const;
    int getBirthYear() const;
    int getDeathYear() const;
    char getGender() const;
    bool getAlive() const;

    void operator = (const Persons& p);
    bool operator == (const Persons& p);
    bool operator != (const Persons& p);
    friend ostream& operator << (ostream& out, const Persons& p);
    //friend istream& operator >> (istream& in, Persons& p);
};

#endif // PERSONS_H
