#ifndef CLIONGRAPHICSKIT_JATEKMESTER_HPP
#define CLIONGRAPHICSKIT_JATEKMESTER_HPP

#include "graphics.hpp"
#include "Grafikai/kepbetolto.hpp"
#include "Grafikai/button.hpp"
#include "Grafikai/szambeallito.hpp"
#include "Grafikai/kivalaszto.hpp"

using namespace std;


struct Kartyak {
    string id;
    string suit;
    int value;
};
struct Score {
    string name;
    int value;
};
class Grafika {
public:
    void pont(Score a, Score b);
    int eredmeny(Score a, Score b,vector<Kartyak> va, vector<Kartyak> vb);
};

class Jatekmester {

    void fill(string name);
    void filled();
    void scores();

public:

    Jatekmester();
    void szabalyok(vector <Kartyak>v, Score &a);
    int alap(float ind);
    void choose();
    bool is_over();

protected:

    //basics
    int _blind;
    int _bet;
    int _rbet;
    int _ymax;
    int _hmax;
    int _pot = 0;
    string _choice = " ";
    bool _res = false;
    bool _skip = false;

    //special types
    Grafika _g;
    Score _you, _it;
    genv::event ev;
    Button * _b1;
    Kivalaszto * _k2;
    Szambeallito * _s3;


    //lists
    vector<Score> _rank;
    vector<Kartyak> _tied;
    vector<Kartyak> _kozos;
    vector<Kartyak> _ove;
    vector<Kepbetolto*> _w;
    vector<Kartyak> _k;
    vector<string> _choices;

};

#endif //CLIONGRAPHICSKIT_JATEKMESTER_HPP