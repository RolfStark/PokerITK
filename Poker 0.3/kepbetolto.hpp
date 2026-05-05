#ifndef CLIONGRAPHICSKIT_KEPBETOLTO_HPP
#define CLIONGRAPHICSKIT_KEPBETOLTO_HPP

#include "widgetbe2.hpp"
#include <fstream>

class Kepbetolto : public Widget2{
protected:
    int r,g,b;
    std::vector<int> rgb;
    std::vector<std::vector<int>> cell;
    std::ifstream _file;
    std::string _string_file;
    std::vector<std::vector<std::vector<int>>> _vk;
    genv :: canvas c;
public:
    Kepbetolto(int x,int y,int sx,int sy, std::string sf);
    void rajzol() override;
    void handle(genv::event ev) override;
    void returnvalue() override;
};


#endif //CLIONGRAPHICSKIT_KEPBETOLTO_HPP