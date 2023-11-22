#include "Polynom.h"
#include <sstream>
#include <cmath>

QString Polynom::solve()
{
    if(a == 0)
        return "Enter non-zero coefficient a\n";
    else if(b == 0)
        return "Enter non-zero coeficient b\n";

	number D = b * b - 4 * a * c;
	
    if(D < 0)
        return "There are no valid roots\n";
    else if(D == 0)
    {
        QString str;

        str += "D = ";
        str << D;
        str += "\nx = ";
        str << -b / (2 * a);
        str += "\n";

        return str;
    }

    QString str;
    str += "D = ";
    str << D;
    str += "\nx₁ = ";
    str << ((-b + sqrt(D)) / (2 * a));
    str += "\nx₂ = ";
    str << ((-b - sqrt(D)) / (2 * a));
    str += "\n";

    return str;
}

number Polynom::solve(number x)
{
	return a * x * x + b * x + c;
}

QString& operator<<(QString& out, Polynom &p)
{
    QString str;

    str << p.a;
    out += str;
    out += "X² + ";

    str = "";

    str << p.b;
    out += str;
    out += "X + ";

    str = "";

    str << p.c;
    out += str + " = 0";
	return out;
}
