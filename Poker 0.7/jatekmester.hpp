#ifndef CLIONGRAPHICSKIT_JATEKMESTER_HPP
#define CLIONGRAPHICSKIT_JATEKMESTER_HPP

#include "graphics.hpp"
#include "Grafikai/kepbetolto.hpp"

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
    void eredmeny(Score a, Score b,vector<Kartyak> va, vector<Kartyak> vb);
};

class Jatekmester {
    void fill(string name);
    void filled();
    void scores();
public:
    Jatekmester();
    void szabalyok(vector <Kartyak>v, Score &a);
    int alap();
    bool is_over();
protected:
    bool _res = false;
    Grafika _g;
    Score _you, _it;
    genv::event ev;
    vector<Score> _rank;
    vector<Kartyak> _tied;
    vector<Kartyak> _kozos;
    vector<Kartyak> _ove;
    vector<Kepbetolto*> _w;
    vector<Kartyak> _k;
};

#endif //CLIONGRAPHICSKIT_JATEKMESTER_HPP