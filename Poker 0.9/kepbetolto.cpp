#include "kepbetolto.hpp"
#include "graphics.hpp"

#include <iostream>


using namespace std;
using namespace genv;

Kepbetolto::Kepbetolto(int x, int y, int sx, int sy, string sf) :
    Widget2(x,y,sx,sy), _string_file(sf)
{
    _file.open("kartyakepek/" + sf + ".bmp.kep");
    _file >> _size_x;
    _file >> _size_y;
    for (int i = 0; i < _size_y;i++) {
        for (int j = 0; j < _size_x; j++) {
            _file >> r >> g >> b;
            rgb.push_back(r);
            rgb.push_back(g);
            rgb.push_back(b);
            cell.push_back(rgb);
            rgb.clear();
        }
        _vk.push_back(cell);
        cell.clear();
    }
    _file.close();
}

void Kepbetolto::rajzol()
{
    c.open(_size_x, _size_y);
    for (int i = 0; i < _vk.size();i++) {
        for (int j = 0; j < _vk[0].size();j++) {
            c << move_to(j,i);
            c << color(_vk[i][j][0],_vk[i][j][1],_vk[i][j][2]);
            c << dot;
        }
    }
    gout << stamp(c, _x ,_y);
}

void Kepbetolto::handle(event ev)
{
}

void Kepbetolto::returnvalue()
{
}
