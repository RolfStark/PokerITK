#include "graphics.hpp"
#include "jatekmester.hpp"
#include "kepbetolto.hpp"
#include <vector>
#include <iostream>

using namespace std;
using namespace genv;

class Myapp : public Jatekmester {
public:
    Myapp() {
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
        cout << _kozos[1].id << endl;

    }

};

int main()
{
    srand(time(0));
    event ev;
    Myapp app;
    app.alap();

    return 0;
}
