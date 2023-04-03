#include <string>
#include <iostream>

using namespace std;
enum Color{
    #define DEFINE_COLOR(color, opposite) eColor##color,
    #include "color.h"
    #undef DEFINE_COLOR
    NOT_A_COLOR,
};

std::string ColorToString(Color c) {
    switch (c)
    {
    #define DEFINE_COLOR(color, opposite) case eColor##color: return string("eColor") + #color;
    #include "color.h"
    #undef DEFINE_COLOR
    default:
        return "<unknown>";
    }
}

Color GetOppositeColor(Color c) {
    switch (c)
    {
    #define DEFINE_COLOR(color, opposite) case eColor##color: return eColor##opposite;
    #include "color.h"
    #undef DEFINE_COLOR
    default:
        return NOT_A_COLOR;
    }
}

Color StringToColor(std::string s) {
    #define DEFINE_COLOR(color, opposite) if(string("eColor") + #color == s) return eColor##color;
    #include "color.h"
    #undef DEFINE_COLOR
    return NOT_A_COLOR;
}

int main() {
    Color c = eColorRed;
    cout << ColorToString(c) << endl;
    cout << ColorToString(GetOppositeColor(c)) << endl;
    cout << ColorToString(StringToColor("eColorRed")) << endl;

}