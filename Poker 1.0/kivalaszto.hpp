#ifndef CLIONGRAPHICSKIT_KIVALASZTO_HPP
#define CLIONGRAPHICSKIT_KIVALASZTO_HPP

#include "widgetbe2.hpp"
#include "elemek.hpp"

class Kivalaszto  : public Widget2{
protected:
    genv::canvas c;
    std::vector<Elemek*> e;
    std::vector<std::string>  _v;
    std::string _text;
    int le = 0;
    int max, _t;
    int _ty = _size_y/_t;
    int _font_size;

public:
    Kivalaszto(int x,int y, int sx, int sy,int fs, int t, std::vector<std::string> v);
    virtual void rajzol() override;
    void handle(genv::event ev) override;
    void returnvalue() override;
    void erase_text();
    std::string gettext();
    void refr(int x, int y, int sx, int sy, int fs, int t);
};


#endif //CLIONGRAPHICSKIT_KIVALASZTO_HPP