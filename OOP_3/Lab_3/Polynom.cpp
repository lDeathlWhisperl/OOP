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

QString sign(number num)
{
    auto abs { [](number num) {return num < 0 ? num * -1 : num;} };
    QString str;

    if(num == -1)
        return " - ";
    else if(num == 1)
        return " + ";

    if(num < 0)
    {
        str += " - ";
        str << abs(num);
        return str;
    }

    str += " + ";
    str << num;
    return str;
}


QString& operator<<(QString& out, Polynom &p)
{
    auto abs { [](number num) {return num < 0 ? num * -1 : num;} };
    QString temp;
    temp << p.a;

    out += ((abs(p.a) == 1) ? (p.a < 0 ? "-" : "") : temp);
    out += "x²";
    out += sign(p.b);
    out += "x";

    temp = "";
    temp << abs(p.c);

    out += ((p.c == 0) ? "" : ((p.c < 0) ? (" - " + temp) : (" + " + temp)));
    out += " = 0";
	return out;
}
