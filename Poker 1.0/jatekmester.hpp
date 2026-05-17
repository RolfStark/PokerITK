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
    void menu();
    void victory();
    void defeat();
    void pont(Score a, Score b);
    void score (int a, int b);
    void choose(int a, string b);
    int eredmeny(Score a, Score b,vector<Kartyak> va, vector<Kartyak> vb, int d);
};

class Jatekmester {

    void fill(string name);
    void filled();
    void scores();
    void cpu(bool &a, bool &c,int b);
    void szabalyok(vector <Kartyak>v, Score &a);

public:

    Jatekmester();

    int alap(float ind);
    int menu(float &ind);
    bool game_over();
    bool is_over();

protected:

    //PÉNZ
    int _blind;
    int _yblind;
    int _hblind;
    int _bet;
    int _rbet;
    int _ymax;
    int _hmax;
    int who_won = 0;
    int _pot = 0;
    int _you_won = 0;

    //cselekvések
    int _dec;
    string _choice = " ";
    string _shesh;

    bool _is_over = false;
    bool _great = false;
    bool _chosen = true;
    bool _raised = false;
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