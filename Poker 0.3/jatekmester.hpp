#ifndef CLIONGRAPHICSKIT_JATEKMESTER_HPP
#define CLIONGRAPHICSKIT_JATEKMESTER_HPP

#include "graphics.hpp"
#include "kepbetolto.hpp"

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
class Jatekmester {
    void fill(string name);
    void filled();
    void scores();
public:
    Jatekmester();
    void szabalyok(vector <Kartyak>v);
    void alap();
protected:
    vector<Score> _rank;
    vector<Kartyak> _tied;
    vector<Kartyak> _kozos;
    vector<Kepbetolto*> _w;
    vector<Kartyak> _k;
};

#endif //CLIONGRAPHICSKIT_JATEKMESTER_HPP
