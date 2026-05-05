#include "jatekmester.hpp"
#include <iostream>

using namespace genv;

Jatekmester::Jatekmester()
{
    gout.open(600,600);
    filled();
    scores();
}


void Jatekmester::alap() {
    event ev;
    bool e = true;
    vector<Kepbetolto *> _v = {_w[0],_w[1]};
    int ij = 1;

    vector <Kartyak> _te = _kozos;
    for (int i = 0; i < _tied.size(); i++) {
        _te.push_back(_tied[i]);
    }

    while(gin >> ev) {
        //fő grafika
        gout << move_to(0,0) <<color(0,100,25) << box(600,600);
        if (ij < 6) {
            if (ev.type == ev_mouse && ev.button == btn_left) {
                if (ij == 1) {
                    for (int i = 1; i < 4; i++) {
                        _v.push_back(_w[i]);
                        ij++;
                    }
                }else {
                    ij ++;
                }
                _v.push_back(_w[ij]);
            }
        }
        //szabályok kezdete
        if (ij == 6 && e) {
            szabalyok(_te);
            e = false;
        }
        //rajzol
        for (Kepbetolto * wg: _v) {
           wg->rajzol();
       }
        gout << refresh;

    }
}
void Jatekmester::szabalyok(vector<Kartyak> v) {
    int same = 0;
    int count = 0;
    int ano = 0;
    vector<int> same_list;
    vector<string> cl;
    vector<string> di;
    vector<string> he;
    vector<string> sp;
    bool is_flush =
        cl.size() >= 5 or di.size() >= 5 or
        he.size() >= 5 or sp.size() >= 5;
    //Párok,hármasok,négyesek és házak
    for (int i = 2; i < 15; i++) {
        for (int j = 0; j < v.size(); j++) {
            if (v[j].value == i) {
                same_list.push_back(i);
            }
        }
        if (same_list.size() > 1) {
            cout<<same_list[0]<<endl;
            same += same_list.size();
            cout << same<<endl;
            ano ++;
            same_list.clear();
        }else {
            same_list.clear();
        }
    }

    //Flush
    for (int i = 0; i < v.size(); i++) {
        if (v[i].suit == "C") {
            cl.push_back(v[i].suit);
        }
        else if (v[i].suit == "D") {
            di.push_back(v[i].suit);
        }
        else if (v[i].suit == "H") {
            he.push_back(v[i].suit);
        }
        else if (v[i].suit == "S") {
            sp.push_back(v[i].suit);
        }
    }
    //Straight
    //Straight Flush
    //Minden egybe
    if (same == 2) {
        cout << _rank[1].name << endl;
    }
    else if (same == 3) {
        cout << _rank[3].name <<endl;
    }
    else if (same == 4) {
        if (ano == 1) {
            cout<< _rank[7].name << endl;
        }
        else {
            cout << _rank[2].name << endl;
        }
    }

    else if (same == 5) {
        cout << _rank[6].name << endl;
    }
    else if (same == 6) {
        if (ano == 3) {
            cout << _rank[2].name << endl;
        }else {
            cout << _rank[3].name << endl;
        }

    }
    else if (is_flush)
    {
        cout << _rank[5].name << endl;
    }
    else {
        cout << _rank[0].name << endl;
    }
    cl.clear();
    di.clear();
    he.clear();
    sp.clear();
}
void Jatekmester::fill(string name)
{
    string hk;
    Kartyak k1;
    k1.suit = name;
    for (int i = 2; i < 15; i++) {
        k1.value = i;
        if (i == 11) {
            hk = "j";
        }
        else if (i == 12) {
            hk = "q";
        }
        else if (i == 13) {
            hk = "k";
        }
        else if (i == 14) {
            hk = "a";
        }
        else {
            hk = to_string(i);
        }
        k1.id = name + hk;
        _k.push_back(k1);
    }
}
void Jatekmester::filled() {
    fill("H");
    fill("D");
    fill("S");
    fill("C");
}
void Jatekmester::scores(){
    Score s;

    for (int i = 1; i < 10; i++) {
        s.value = i;
        _rank.push_back(s);
    }

    _rank[0].name = "High Card";
    _rank[1].name = "Pair";
    _rank[2].name = "Two Pair";
    _rank[3].name = "Three of a Kind";
    _rank[4].name = "Straight";
    _rank[5].name = "Flush";
    _rank[6].name = "Full House";
    _rank[7].name = "Four of a Kind";
    _rank[8].name = "Straight Flush";

}
