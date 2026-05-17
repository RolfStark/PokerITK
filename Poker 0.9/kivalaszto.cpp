#include "kivalaszto.hpp"
#include <iostream>
#include <vector>
#include "elemek.hpp"

using namespace genv;

Kivalaszto::Kivalaszto(int x, int y, int sx, int sy,int fs, int t, std::vector<std::string> v) :
    Widget2(x,y,sx,sy), _font_size(fs), _v(v), _t(t)
{
    max = v.size();
    refr(x,y,sx,sy,fs,t);
}
void Kivalaszto::rajzol() {

    c.open(_size_x,_size_y);
    c << color(100,100,100) << move_to(0,0) << box(_size_x,_size_y);

    gout << stamp(c,_x,_y);
    for (Elemek * eg : e) {
        eg->rajzol();
    }
}
void Kivalaszto::handle(event ev) {
    for (Elemek * eg : e) {
        eg->handle(ev);
    }
    if (ev.type == ev_mouse) {
        if (ev.button == btn_wheeldown && le < max - _t) {
            le ++;
            refr(_x,_y,_size_x,_size_y,_font_size, _t);
        }else if (ev.button == btn_wheelup && le > 0) {
            le --;
            refr(_x,_y,_size_x,_size_y,_font_size, _t);
        }
    }
}
void Kivalaszto::returnvalue() {
    for (Elemek * eg : e) {
        eg->returnvalue();
    }
}
std::string Kivalaszto::gettext() {
    for (Elemek * eg : e) {
        if (eg->gettext().size() > 0) {
            _text = eg->gettext();
            eg->erase();
        }
    }
    return _text;
}

void Kivalaszto::refr(int x, int y, int sx, int sy, int fs,int t){
    e.clear();
    for (int i = 0; i < _t; i++) {
        e.push_back(new Elemek(x,y,sx,sy,fs, t, _x,i*_ty + _y,_v[i+le]));
    }
}


