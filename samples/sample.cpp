#include "Polynom.h"
#include "PolynomBuilder.h"

#include "antlr4-runtime.h"
#include "PolynomLexer.h"
#include "PolynomParser.h"

#include <iostream>
#include <string>
#include <locale.h>

using namespace std;

int main()
{

    cout << "Write polynom:" << endl;

    string inputLine;
    getline(cin, inputLine);

    try
    {
        // --- ANTLR pipeline ---
        antlr4::ANTLRInputStream input(inputLine);
        PolynomLexer lexer(&input);
        antlr4::CommonTokenStream tokens(&lexer);
        PolynomParser parser(&tokens);

        // чтобы ошибки бросали исключение
        parser.removeErrorListeners();
        parser.addErrorListener(new antlr4::ConsoleErrorListener());

        auto tree = parser.polynom();

        PolynomBuilder builder;
        Polynom p = std::any_cast<Polynom>(builder.visit(tree));

        cout << "What i parsed:" << endl;
        cout << p << endl;

        // пример вычисления
        cout << "\nWrite x y z: ";
        double x, y, z;
        if (cin >> x >> y >> z)
        {
            cout << "Solve: " << p.value(x, y, z) << endl;
        }
    }
    catch (const std::exception& e)
    {
        cerr << "Error: " << e.what() << endl;
    }
    catch (...)
    {
        cerr << "IDK error lol" << endl;
    }

    return 0;
}

