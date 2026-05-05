#ifndef CLIONGRAPHICSKIT_WIDGETBE2_HPP
#define CLIONGRAPHICSKIT_WIDGETBE2_HPP

#include "graphics.hpp"

class Widget2 {
protected:
    int _x, _y, _size_x, _size_y;


public:
    Widget2(int x, int y, int sx, int sy);
    bool is_selected(int mouse_x, int mouse_y);
    virtual void rajzol() = 0;
    virtual void handle(genv::event ev) = 0;
    virtual void returnvalue() = 0;
};


#endif