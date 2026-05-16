#include "../Header/jatekmester.hpp"
#include "graphics.hpp"


#include <iostream>

#include "../Header/Grafikai/kivalaszto.hpp"

using namespace genv;

void Grafika::pont(Score a, Score b)
{
    gout << color (0,0,255) << move_to (200,285) << font("PixelifySans.ttf", 50)
                 << text(a.name);
    gout << color (255,0,0) << move_to (200,135) << text(b.name);
}

int Grafika::eredmeny(Score a, Score b,vector<Kartyak> va, vector<Kartyak> vb)
{
    bool jobb = va[0].value > vb[0].value && va[0].value > vb[1].value;
    bool jobbko = va[1].value > vb[0].value && va[1].value > vb[1].value;
    bool balko = vb[0].value > va[0].value && vb[0].value > va[1].value;
    bool bal = vb[1].value > va[0].value && vb[1].value > va[1].value;

    int won = 0;

    gout << move_to(125,200) << color(0,0,0) << box_to(500,300);
    gout << move_to(125,210) << color(255,255,0);
    if (a.value > b.value)
    {

        gout << text("The Player Won!");
        won = 1;
    }
    else if (a.value < b.value)
    {
       gout << text("The Enemy Won!");
    }
    else if (a.value == b.value)
    {
        if (jobb or jobbko)
        {
           gout << text("The Player Won!");
            won = 1;
        }
        else if (bal or balko)
        {
            gout  << text("The Enemy Won!");
        }
        else {
            if (va[0].value + va[1].value > vb[0].value + vb[1].value)
            {
                gout << text("The Player Won!");
                won = 1;
            }
            else if (va[0].value + va[1].value < vb[0].value + vb[1].value)
            {
                gout << text("The Player Won!");
                won = 1;
            }
            else
            {
                gout << text("    Tie     ");
                won = 2;
            }

        }
    }
    return won;
}

Jatekmester::Jatekmester()
{
    gout.open(600,600);
    filled();
    scores();
    _ymax = 10000;
    _hmax = 10000;
    _blind = 200;
    _bet = 0;
    _choices = {"Fold", "Call", "Bet"};

    _k2 = new Kivalaszto(5,424,150,175,50,3,_choices);

    _s3 = new Szambeallito(349,474,250,125,50,2000,_blind + _bet);

    _b1 = new Button(175,500,100,75,0,"Action");


    _choice = "";

}


int Jatekmester::alap(float ind) {

    bool e = true;

    if (ind - int(ind) == 0) {
        _blind = 200*ind;
    }
    else {
        ind -= 0.5;
    }
    vector<Kepbetolto *> _v = {_w[0],_w[1]};

    int ij = 1;


    vector <Kartyak> _te = _kozos;
    for (int i = 0; i < _tied.size(); i++) {
        _te.push_back(_tied[i]);
    }
    vector <Kartyak> _o = _kozos;
    for (int i = 0; i < _ove.size(); i++) {
        _o.push_back(_ove[i]);
    }

    while(gin >> ev) {

        //fő grafika
        gout << move_to(0,0) <<color(0,100,25) << box(600,600);


        for (Kepbetolto * wg: _v) {
            wg->rajzol();
        }

        if (ij < 6) {

            //Kiválasztó
            _k2->rajzol();
            _k2->handle(ev);

            //Számbeállító
            _s3->rajzol();
            _s3->handle(ev);

            //Gomb
            _b1->rajzol();
            _b1->handle(ev);

            //döntések
            if (_b1->is_clicked() or _skip)
            {
                _b1->erase_clicked();
                _choice = _k2->gettext();
                _bet = _s3->returnint();
                if (_choice == "Bet" or _choice == "Raise")
                {
                    _ymax -= _bet + _blind;
                    _pot += _bet;


                }
                if (_choice == "Call")
                {
                    _ymax -= _blind;
                    _blind = 0;
                }
                if (_choice == "Fold")
                {
                    _skip = true;
                }
                else {
                    _skip = false;
                    _choice = "";
                    _bet = 0;
                }

                cout << _ymax << " " << _pot <<endl;
                cout << _hmax << endl;

                if (ij == 1)
                {
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
            _skip = false;
            cout << " " << _skip << endl;
            for (int i = 1; i < _ove.size() + 1; i++) {
                _v.push_back(_w[_w.size()-i]);
            }
            szabalyok(_te, _you);
            szabalyok(_o, _it);

            e = false;
        }

        if (!e)
        {
            _g.pont(_you,_it);
            if (ev.type == ev_mouse && ev.button == btn_left)
            {
                ij ++;
                if (ij > 7)
                {
                    e = true;
                }

            }
        }



        if (ij > 7) {
            int result = _g.eredmeny(_you,_it,_tied,_ove);
            if (result == 1) {
                _ymax += _pot;
            }
            else if (result == 2)
            {
                _ymax += _pot/2;
                _hmax += _pot/2;
            }
            else
            {
                _hmax += _pot;
            }
            _pot = 0;

            if (ev.type == ev_mouse && ev.button == btn_left) {
                ij ++;
            }
        }

        if (ij > 9)
        {
            filled();
            return 0;
        }
        if (_ymax == 0 or _hmax == 0) {
            _res;
        }
        if (ev.type == ev_key && ev.keycode > 0 && ev.keycode == key_escape)
        {
            _res = true;
            return 0;
        }

        gout << refresh;

    }
}

void Jatekmester::szabalyok(vector<Kartyak> v, Score &a) {

    int same = 0;
    int max = 0;
    int count = 0;
    int ind = 0;
    int ano = 0;

    vector<int> same_list;
    vector<string> cl;
    vector<string> di;
    vector<string> he;
    vector<string> sp;
    vector <Kartyak> _g = v;
    vector<Kartyak> straight;

    bool is_flush = false;
    bool is_straight = false;

    // sorrend miatt kell még extra bool hogy flush jöjjön ha van
    // straight is (aminek a kártyái nem ugyanolyan a suit-je)
    bool true_flush = false;

    //Párok,hármasok,négyesek és házak
    for (int i = 2; i < 15; i++) {
        for (int j = 0; j < v.size(); j++) {
            if (v[j].value == i) {
                same_list.push_back(i);
            }
        }
        if (same_list.size() > 1) {
            same += same_list.size();
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

    is_flush = cl.size() > 5 or di.size() >= 5 or
        he.size() >= 5 or sp.size() >= 5;

    if (is_flush)
    {
        true_flush = true;
        cl.clear();
        di.clear();
        he.clear();
        sp.clear();
    }
    else
    {
        cl.clear();
        di.clear();
        he.clear();
        sp.clear();
    }

    //Straight
    for (int j = 0; j < v.size(); j++) {
        for (int i = 0; i < _g.size(); i++) {
            if (_g[i].value > max) {
                max = _g[i].value;
                ind = i;
            }
        }
        straight.push_back(_g[ind]);
        max = 0;
        _g.erase(_g.begin() + ind);
    }
    for (int i = 0; i < straight.size(); i++) {
        int ig = i;
        if (straight[i].value == straight[ig+1].value) {
            ig ++;
        }
        else if (straight[i].value == straight[ig+1].value + 1) {
            count ++;
            if (count >= 4) {
                is_straight = true;
            }
        }
        else
        {
            count = 0;
        }
        //Straight Flush
        if (straight[i].suit == "C") {
            cl.push_back(straight[i].suit);
        }
        else if (straight[i].suit == "D") {
            di.push_back(straight[i].suit);
        }
        else if (straight[i].suit == "H") {
            he.push_back(straight[i].suit);
        }
        else if (straight[i].suit == "S") {
            sp.push_back(straight[i].suit);
        }
    }

    //Minden egybe
    if (true_flush && !is_straight)
    {
        a = _rank[5];
    }
    else if (is_straight) {
        if (is_flush && straight[0].value < 14 ) {
            a = _rank[8];
        }
        else if (is_flush && straight[0].value == 14 && straight[4].value == 10) {
            a = _rank[9];
        }
        else {
            a = _rank[4];
        }

    }
    else if (same == 2) {
        a = _rank[1];
    }
    else if (same == 3) {
        a = _rank[3];
    }
    else if (same == 4) {
        if (ano == 1) {
            a =  _rank[7];
        }
        else {
            a = _rank[2];
        }
    }

    else if (same == 5) {
         a = _rank[6];
    }
    else if (same == 6) {
        if (ano == 3) {
            a = _rank[2];
        }else {
            a =  _rank[3];
        }

    }
    else {
        a = _rank[0];
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
    _k.clear();
    _tied.clear();
    _ove.clear();
    _kozos.clear();
    _w.clear();
    fill("H");
    fill("D");
    fill("S");
    fill("C");
}
void Jatekmester::scores(){
    Score s;

    for (int i = 1; i < 11; i++) {
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
    _rank[9].name = "Royal Flush";

}
void Jatekmester::choose()
{

}

bool Jatekmester::is_over()
{
    return _res;
}
