//
// Created by Pranav on 11-04-2023.
//

#ifndef DUPLEX_hpp
#define CPP_PROJECT_DUPLEX_H

#include <iostream>
#include <math.h>

using namespace std;

class duplex{
    friend duplex operator+(double x, const duplex &v);
    friend duplex operator+(const duplex &u, double x);
    friend duplex operator+(const duplex &u, const duplex &v);

    friend duplex operator-(double x, const duplex &v);
    friend duplex operator-(const duplex &u, double x);
    friend duplex operator-(const duplex &u, const duplex &v);


    friend duplex operator*(double x, const duplex &v);
    friend duplex operator*(const duplex &u, double x);
    friend duplex operator*(const duplex &u, const duplex &v);

    friend duplex operator/(const duplex &u, const duplex &v);
    friend duplex operator/(const duplex &u, const double &v);
    friend duplex operator/(const double &u, const duplex &v);

    friend double prim(const duplex &z);
    friend double dual(const duplex &z);

    friend double mod(const duplex &z);
    friend duplex conj(const duplex &z);

    friend duplex sin(const duplex &z);
    friend duplex cos(const duplex &z);
    friend duplex tan(const duplex &z);

    friend duplex deg2rad(const duplex &z);
    friend double deg2rad(const double &z);
    friend duplex rad2deg(const duplex &z);
    friend double rad2deg(const double &z);

    friend duplex rpm2radpersec(const duplex &z);
    friend double rpm2radpersec(const double &z);
    friend duplex radpersec2rpm(const duplex &z);
    friend double radpersec2rpm(const double &z);

    friend duplex pow(const duplex &z, double y);
    friend duplex sqrt(const duplex &z);

    friend duplex atan(const duplex &z);
    friend duplex aten2(const duplex &s, const duplex &c);

    friend ostream &operator<<(ostream &os, const duplex &z);
    friend istream &operator>>(istream &is, duplex &z);

public:
    double &prim(void);
    double &dual(void);

    duplex(void) {}
    duplex(double p, double d);
    duplex(const duplex &z);

    duplex &operator=(double x);
    duplex &operator=(const duplex &z);

    duplex &operator+=(double x);
    duplex &operator+=(const duplex &z);

    duplex operator-() const;

    double pr, du;
//private:
//    double pr, du;
};

// friend functions:
    inline duplex operator+(double x, const duplex &v)
    // Addition of a real and a duplex.
    {
        return duplex(x + v.pr, v.du);
    }
    inline duplex operator+(const duplex &u, double x)
    // Addition of a duplex end a real.
    {
        return duplex(u.pr + x, u.du);
    }
    inline duplex operator+(const duplex &u, const duplex &v)
    // Addition of a duplex and a duplex.
    {
        return duplex(u.pr + v.pr, u.du + v.du);
    }
    inline duplex operator-(double x, const duplex &v)
    // subtraction of a duplex from a real.
    {
        return duplex(x- v.pr,-v.du);
    }
    inline duplex operator-(const duplex &u, double x)
    // subtraction of a real from a duplex.
    {
        return duplex(u.pr - x, u.du);
    }
    inline duplex operator-(const duplex &u, const duplex &v)
    // subtraction of a duplex from a duplex.
    {
        return duplex(u.pr - v.pr, u.du - v.du);
    }
    inline duplex operator*(double x, const duplex &v)
    // Multiplication of a real and a duplex.
    {
        return duplex(x * v.pr, x * v.du);
    }
    inline duplex operator*(const duplex &u, double x)
    // Multiplication of a duplex and e real.
    {
        return duplex(u.pr * x, u.du * x);
    }
    inline duplex operator*(const duplex &u, const duplex &v)
    // Multiplication of a duplex end a duplex.
    {
    return duplex(u.pr * v.pr, u.pr * v.du + u.du * v.pr);
    }
    inline duplex operator/(const duplex &u, const duplex &v)
    // Division of a duplex by a duplex.
    {
        return duplex(u.pr/v.pr,(u.du * v.pr - u.pr * v.du) / ( v.pr * v.pr ) );
    }

    inline duplex operator/(const duplex &u, const double &v)
    // Division of a duplex by a double.
    {
        return duplex(u.pr/v, u.du/v);
    }

    inline duplex operator/(const double &u, const duplex &v)
    // Division of a double by a duplex.
    {
        return duplex(u / v.pr, -u * v.du / (v.pr * v.pr));
    }

    inline double prim(const duplex &z)
    // Return the primary part of a duplex.
    {
        return z.pr;
    }
    inline double dual(const duplex &z)
    // Return the dual part of a duplex.
    {
        return z.du;
    }
    inline duplex sin(const duplex &z)
    // Sine function for duplex argument.
    {
        return duplex(sin(z.pr), z.du * cos(z.pr));
    }
    inline duplex cos(const duplex &z)
    // Cosine function for duplex argument.
    {
        return duplex(cos(z.pr), -z.du * sin(z.pr));
    }
    inline duplex tan(const duplex &z)
    // Tangent function for duplex argument.
    {
        return duplex( tan(z.pr), z.du/( cos(z.pr)*cos(z.pr) ) );
    }

    inline duplex atan2(const duplex &s, const duplex &c)
    // Double-argument tangent function for duplex arguments.
    {
        double pi=4.*atan(1.);
        if (c.pr > 0 && s.pr > 0)
            return duplex( atan( s/c ) );
        if (c.pr < 0 )
            return duplex( atan( s/c ) + pi );
        else
            return duplex( atan( s/c ) + 2*pi );
    }

    inline duplex deg2rad(const duplex &z)
    // Convert primary portion of duplex angle from degrees to radians.
    {
        return duplex(z.pr*atan(1.)/45.,z.du);
    }
    inline double deg2rad(const double &z)
    // Convert primary angle from degrees to radians.
    {
        return double(z*atan(1.)/45.);
    }
    inline duplex rad2deg(const duplex &z)
    // Convert primary portion of duplex angle from radians to degrees.
    {
        double zdeg = z.pr * 45. / atan(1.); // convert angle to degrees
        while (zdeg < 0.) {
            zdeg = zdeg + 360.; // adjust angle to positive
        }
        while (zdeg > 360.) {
            // adjust angle to < 360 deg
            zdeg = zdeg - 360.;
        }
        return duplex(zdeg, z.du);
    }

    inline double rad2deg(const double &z)
    // Convert primary angle from radians to degrees.
    {
        double zdeg = z * 45. / atan(1.);
        while (zdeg < 0.) {
            zdeg = zdeg + 360.;
        }
        while (zdeg > 360.) {
            zdeg = zdeg - 360.;
        }
        return zdeg;
    }

    inline duplex pow(const duplex &z, double y)
    // Duplex number raised to a power.
    {
        return duplex(pow(z.pr, y), y * z.du * pow(z.pr, y - 1.));
    }
    inline duplex sqrt(const duplex &z)
    // Square root of a duplex argument.
    {
        return duplex(sqrt(z.pr), 0.5 * z.du / sqrt(z.pr));
    }

    inline duplex atan(const duplex &z)
    // Arctangent of a duplex argument.
    {
        return duplex(atan(z.pr), z.du / (1. + z.pr * z.pr));
    }
    // member functions end operators:
    inline double &duplex::prim(void)
    // primary component of a duplex number
    {
        return pr;
    }
    inline double &duplex::dual(void)
    // dual component of a duplex number
    {
        return du;
    }
    inline duplex::duplex(double p, double d)
    // constructor
    {
        pr = p;
        du = d;
    }
    inline duplex::duplex(const duplex &z)
    // copy constructor
    {
        pr = z.pr;
        du = z.du;
    }

    inline duplex &duplex::operator=(double x)
    // overload assignment operator
    {
        pr = x;
        du = 0.0;
        return *this;
    }

    inline duplex &duplex::operator=(const duplex &z)
    // overload assignment operator
    {
        pr = z.pr;
        du = z.du;
        return *this;
    }

    inline duplex &duplex::operator+=(double x) // overload increment operator
    {
        pr += x;
        return *this;
    }
    inline duplex &duplex::operator+=(const duplex &z)
    // overload increment operator
    {
        pr += z.pr;
        du += z.du;
        return *this;
    }
    inline duplex duplex::operator-() const
    // negative of a duplex nuri>er (unary •i~)
    {
        return duplex ( -pr, -du );
    }
    ostream &operator<<(ostream &os, const duplex &z)
    // output stream insertion operator
    {
        os << '(' << z.pr << ',' << z.du << ')';
        return os;
    }
    istream &operator>>(istream &is, duplex &z)
    // input stream extraction operator
    {
        is >> z.pr >> z.du;
        return is ;
    }

#endif //DUPLEX_hpp
