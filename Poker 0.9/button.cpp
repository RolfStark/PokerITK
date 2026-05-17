#include "button.hpp"
#include <iostream>


using namespace genv;
using namespace std;

Button::Button(int x, int y, int sx, int sy,int i,string text):
    Widget2(x, y, sx, sy), _i(i), _text(text)
{
    r = 0;
    g = 255;
    b = 0;
}

void Button::rajzol()
{
    canvas c(_size_x,_size_y);
    c << move_to(0,0) << color (r,g,b) << box(_size_x,_size_y);
    c << move_to(10,_size_y/4) << color(0,0,0) << font("LiberationSans-Regular.ttf", 30)
    << text(_text);
    gout << stamp(c,_x,_y);
    gout << refresh;
}

void Button::handle(genv::event ev)
{
    if (ev.type == ev_mouse && is_selected(ev.pos_x,ev.pos_y))
    {
        if (ev.button == btn_left)
        {
            g = 0;
            b = 255;
        }
        else if (ev.button == -btn_left)
        {
            clicked = true;
            g = 255;
            b = 0;


        }
        else {
            clicked = false;
        }
    }


}
void Button::returnvalue()
{

}
bool Button::is_clicked()
{
    return clicked;
}

void Button::erase_clicked()
{
    clicked = false;
}


int Button::returnint()
{
    return _i;
}
