#include "szambeallito.hpp"
#include <iostream>


using namespace genv;

Szambeallito::Szambeallito(int x, int y, int sx, int sy, int fs,int max, int min) :
    Widget2(x,y,sx,sy), _font_size(fs), _min(min), _max(max)
{
}
void Szambeallito::rajzol() {
    _text = std::to_string(_szam);
    canvas b(_size_x,_size_y);
    b << color(100,100,100) << move_to(0,0) << box(_size_x, _size_y);
    b << color (75,75,75) << move_to(5,ny) << box(nx - 10, ny + ny);
    b << move_to(nx,ny/4) << color(255,255,255) << box_to(_size_x - nx/4,_size_y - ny/4);
    for (int i=0;i<nx -20;i++) {
        b << color (255,255,255)
          << move_to(nx/2 - 1, ny + 10)
            << line_to(10 + i, ny + ny/2 + 5);
    }
    for (int i=0;i<nx -20;i++) {
        b << color (255,255,255)
          << move_to(nx/2 - 1, fy + ny/2 + 5)
            << line_to(10 + i, fy + 10);
    }
    b << color(0,0,0) << move_to(nx + 10,fy - ny) <<font("LiberationSans-Regular.ttf", _font_size) << text(_text);
    gout << stamp(b,_x,_y);

}
void Szambeallito::handle(genv::event ev)
{
    if (ev.type == ev_mouse && ev.button == btn_left)
    {
        if (ev.pos_x - _x> 5 && ev.pos_x - _x<5+nx-10
            && ev.pos_y - _y>ny && ev.pos_y-_y<fy)
        {
            _szam += 10;

        }else if (ev.pos_x - _x> 5 && ev.pos_x - _x<5+nx-10
            && ev.pos_y - _y>fy && ev.pos_y-_y<ny+fy)
        {
            _szam -= 10;
        }
    }
    if (ev.type == ev_key && ev.keycode > 0)
    {
        if (ev.keycode == key_up)
        {
            _szam ++;
        }
        if (ev.keycode == key_down)
        {
            _szam --;
        }
        if (ev.keycode == key_pgup)
        {
            _szam += 10;
        }
        if (ev.keycode == key_pgdn)
        {
            _szam -= 10;
        }
    }
    if (_szam > _max)
    {
        _szam = _max;
    }
    if (_szam < _min)
    {
        _szam = _min;
    }
}
void Szambeallito::returnvalue()
{
    std::cout << _szam << std::endl;
}

void Szambeallito::erase_value()
{
    _szam = 0;
}

int Szambeallito::returnint() {
    return _szam;
}
