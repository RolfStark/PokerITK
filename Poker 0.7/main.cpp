#include "graphics.hpp"
#include "jatekmester.hpp"
#include "kepbetolto.hpp"
#include <vector>
#include <iostream>

using namespace std;

class Myapp : public Jatekmester {
public:
    Myapp()
    {
    }
    void refr() {
        int ra;
        int j = 0;
        for (int i = 0; i < 2; i++) {
            ra = rand() % (51 - j);
            _w.push_back(new Kepbetolto(225 + i * 100,350,0,0,_k[ra].id));
            _tied.push_back(_k[ra]);
            _k.erase(_k.begin()+ ra);
            j++;
        }
        for (int i = 0; i < 5; i++) {
            ra = rand() % (51 - j);
            _w.push_back(new Kepbetolto(75 + i * 100,200,0,0,_k[ra].id));
            _kozos.push_back(_k[ra]);
            _k.erase(_k.begin()+ ra);
            j++;
        }
        for (int i = 0; i < 2; i++) {
            ra = rand() % (51 - j);
            _w.push_back(new Kepbetolto(225 + i * 100,50,0,0,_k[ra].id));
            _ove.push_back(_k[ra]);
            _k.erase(_k.begin()+ ra);
            j++;
        }
    }

};

int main()
{
    srand(time(0));
    Myapp app;
    while (!app.is_over()) {
            app.refr();
            app.alap();

    }


    return 0;
}
