#include "graphics.hpp"
#include "elemek.hpp"
#include <iostream>

using namespace genv;

Elemek::Elemek(int x ,int y ,int sx, int sy,int fs , int t, int hx, int hy,std::string s) :
    Widget2(x,y,sx,sy), _font_size(fs), _hx(hx),_hy(hy),_s(s), _t(t)
{
}
void Elemek::rajzol() {
    canvas cb(_size_x,_ty-10);
    cb << color(r,g,b) << move_to(0,0) << box(_size_x,_ty-10);
    cb << move_to(0, 0) << color(0,0,0) << font("LiberationSans-Regular.ttf",_font_size) << text(_s);
    gout << stamp(cb,_hx,_hy);
}
void Elemek::handle(event ev) {

    if (ev.type == ev_mouse && ev.button == btn_left) {
        r = 75;
        g = 75;
        b = 75;
        bo = false;
        if (ev.pos_x - _x> 0 && ev.pos_x - _x< _size_x && ev.pos_y >_hy && ev.pos_y<_hy + _ty - 10) {
            r = 0;
            g = 0;
            b = 255;
            _text = _s;
            bo = true;
        }
    }

}
void Elemek::returnvalue() {
    if (bo) {
        std::cout << _s << std::endl;
    }
}

std::string Elemek::gettext() {
    return _text;
}
void Elemek::erase()
{
    _text = "";
}
