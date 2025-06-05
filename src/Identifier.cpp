#include <stdexcept>
#include "Identifier.h"

using namespace dex;

std::string Identifier::defaultSpace;

Identifier::Identifier() {}

Identifier::Identifier(std::string str) {
    int colons = std::count(str.begin(), str.end(), ':');
    if (colons == 0) {
        if (defaultSpace.empty()) throw std::invalid_argument("Identifier '" + str + "' missing namespace and no default namespace is set.");
        str = defaultSpace + ':' + str;
        space = defaultSpace;
    } else if (colons != 1) throw std::invalid_argument("Identifier '" + str + "' contains multiple colons");
    else space = str.substr(0, str.find(':'));
    path = str.substr(str.find(':') + 1);
}

Identifier::Identifier(char str[]): Identifier(std::string(str)) {}

Identifier::operator std::string() const { return space + ':' + path; }


bool Identifier::operator==(const dex::Identifier& other ) const { return (space == other.space) && (path == other.path); }

void Identifier::setDefaultNamespace(std::string space) { defaultSpace = space; }

std::ostream& dex::operator<<(std::ostream& os, const Identifier& id) { return os << std::string(id); }
