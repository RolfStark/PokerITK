#ifndef CLIONGRAPHICSKIT_BUTTON_HPP
#define CLIONGRAPHICSKIT_BUTTON_HPP

#include "widgetbe2.hpp"

class Button : public Widget2 {
public:
    Button(int x, int y, int sx, int sy,int i,std::string text);
    void rajzol() override;
    void handle(genv::event ev) override;
    void returnvalue() override;
    int returnint();
    bool is_clicked();
    void erase_clicked();
private:
    int r, g, b, _i;
    std::string _text;
    bool clicked = false;
};


#endif