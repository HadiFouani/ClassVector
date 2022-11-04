#include <iostream>
#include <cmath>
using namespace std;
int pgcd(int a, int b)
{
    int r = a % b;
    while (r != 0)
    {
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}
class Rational
{
public:
    Rational(int num, int denom = 1) : num(num), denom(denom)
    {
        int div = abs(pgcd(this->num, this->denom));
        this->num /= div;
        this->denom /= div;
    }
    Rational &operator+=(const Rational &r)
    {
        num = num * r.denom + r.num * denom;
        denom = denom * r.denom;
        return *this;
    }
    Rational &operator-=(const Rational &r)
    {
        num = num * r.denom - r.num * denom;
        denom = denom * r.denom;
        return *this;
    }
    // Rational operator+(const Rational &r) const
    // {
    //     return Rational(num * r.denom + r.num * denom, denom * r.denom);
    // }
    Rational operator-() const
    {
        Rational r = *this;
        r.num = -num;
        return r;
    }
    // const Rational operator-(const Rational &r) const
    // {
    //     return *this + (-r);
    // }

    bool operator==(const Rational &r) const
    {
        return (num / denom == r.num / r.denom);
    }
    bool operator!=(const Rational &r) const
    {
        return !operator==(r);
    }

    Rational operator*(const Rational &r) const
    {
        return Rational(num * r.num, denom * r.denom);
    }
    Rational &operator*=(const Rational &r)
    {
        num *= r.num;
        denom *= r.denom;
        return *this;
    }
    Rational operator/(const Rational &r) const
    {
        return Rational(num * r.denom, denom * r.num);
    }
    Rational &operator/=(const Rational &r)
    {
        num *= r.denom;
        denom *= r.num;
        return *this;
    }
    bool operator<=(const Rational &r) const
    {
        return (num / denom <= r.num / r.denom);
    }
    bool operator<(const Rational &r) const
    {
        return (num / denom < r.num / r.denom);
    }
    bool operator>=(const Rational &r) const
    {
        return (num / denom >= r.num / r.denom);
    }
    bool operator>(const Rational &r) const
    {
        return (num / denom > r.num / r.denom);
    }
    double getNum() const { return num; }
    double getDenom() const { return denom; }

private:
    int num;
    int denom;
};
const Rational operator+(Rational r1, const Rational &r2)
{
    r1 += r2;
    return r1;
}
const Rational operator-(Rational r1, const Rational &r2)
{
    r1 -= r2;
    return r1;
}
ostream &operator<<(ostream &os, const Rational &r)
{
    os << r.getNum() << "/" << r.getDenom();
    return os;
}
int main()
{
    Rational r1(2, 3);
    Rational r2(2, 3);
    Rational r3 = r1 + r2;
    Rational r4 = -r1;
    Rational r5 = r1 * r2;
    Rational r6 = r3 - r2;
    r1 += r2;
    cout << r1 << endl;
    r1 -= r2;
    cout << r1 << endl;
    r1 *= r2;
    cout << r1 << endl;
    r1 /= r2;
    cout << r1 << endl;
    cout << (r1 == r2) << "   " << (r1 != r2) << endl;
    cout << r3 << endl;
    cout << r4 << endl;
    cout << r5 << endl;
    cout << r6 << endl;
    return 0;
}