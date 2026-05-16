#ifndef CLIONGRAPHICSKIT_SZAMBEALLITO_HPP
#define CLIONGRAPHICSKIT_SZAMBEALLITO_HPP

#include "../Grafikai/widgetbe2.hpp"

class Szambeallito : public Widget2{
public:
    Szambeallito(int x, int y, int sx, int sy, int fs, int max, int min);
    void rajzol() override;
    void handle(genv::event ev) override;
    void returnvalue() override;
    int returnint();
private:
    int _szam = 0;
    int nx = _size_x/4;
    int ny = _size_y/4;
    int fy = _size_y/2;
    int _min, _max, _font_size;
    std::string _text;
};


#endif