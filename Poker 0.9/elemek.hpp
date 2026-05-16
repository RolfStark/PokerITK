#ifndef CLIONGRAPHICSKIT_SZAMELEMEK_HPP
#define CLIONGRAPHICSKIT_SZAMELEMEK_HPP

#include "graphics.hpp"
#include "widgetbe2.hpp"

class Elemek : public Widget2{
    std::string _s;
    std::string _text;
    int _hx, _hy, _t, _font_size;
    int _ty = _size_y/_t;
    bool bo = false;
    int r = 75;
    int g = 75;
    int b = 75;
    public:
    Elemek(int x,int y,int sx,int sy, int fs,int t, int hx, int hy,std::string s);
    void rajzol() override;
    void handle(genv::event ev) override;
    void returnvalue() override;
    void erase();
    std::string gettext();
};


#endif //CLIONGRAPHICSKIT_SZAMELEMEK_HPP