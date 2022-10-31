#include <iostream>
using namespace std;
class Vector
{
public:
    Vector(double x = 0, double y = 0)
        : x(x), y(y) {}
    const Vector operator+(const Vector &rhs) const
    {
        return Vector(x + rhs.x, y + rhs.y);
    }
    Vector &operator+=(const Vector &rhs)
    {
        x += rhs.x;
        y += rhs.y;
        return *this;
    }
    void display()
    {
        cout << "V(" << x << " , " << y << ")" << endl;
    }

private:
    double x;
    double y;
};
int main()
{
    Vector v(1, 5);
    Vector v1(2, 6);
    Vector v2(5, 18);
    Vector v3 = v + v1;
    (v1 += v2) += v3;
    v1.display();
    return 0;
}