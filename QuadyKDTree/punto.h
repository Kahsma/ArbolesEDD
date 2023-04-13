#ifndef _punto_H_
#define _punto_H_
#include <iostream>
struct punto {
    int x;
    int y;
    punto& operator = (const punto &p) {
        x = p.x;
        y = p.y;
        return *this;
    }
    bool operator == (const punto &p) const {
        return (x == p.x && y == p.y);
    }
    friend std::ostream& operator << (std::ostream &o, const punto &p)
    { o << "(" << p.x << "," << p.y << ")";
     return o;
    }
};
#endif