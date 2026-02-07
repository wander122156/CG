#include <iostream>

void naiveDrawLine(int x1,int x2,int y1,int y2)
{

    float m = (y2 - y1) / (x2 - x1);

    for (int x = x1; x <= x2; x++) {
        // Assuming that the round function finds
        // closest integer to a given float.
        int y =  (m*x + c);

        std::cout << x << " " << y << std::endl;
    }
}

int main() {

}
