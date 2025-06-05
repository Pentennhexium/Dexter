#ifndef DEXTER_IDENTIFIER_H
#define DEXTER_IDENTIFIER_H

#include <iostream>
#include <string>

namespace dex {
    class Identifier {
    private:
        std::string space;
        std::string path;

        static std::string defaultSpace;

    public:
        Identifier();
        Identifier(std::string);
        Identifier(char[]);
        operator std::string() const;
        bool operator==(const Identifier&) const;

        static void setDefaultNamespace(std::string);

        friend std::ostream& operator<<(std::ostream&, const Identifier&);
    };
}

#endif
