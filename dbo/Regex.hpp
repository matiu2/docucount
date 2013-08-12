#pragma once
/** DBO object that represents a regex used to find records
 */

#include <Wt/Dbo/Dbo>
#include <Wt/WDate>
#include <Wt/WString>

#include <string>

#include <string>

namespace docucount {
namespace dbo {

struct Regex : public Wt::Dbo::Dbo<Cat> {
    Wt::WString name;
    Wt::WString regex;
    void persist(Action& a) {
        using Wt::Dbo::field;

        field(a, name, "name");
        field(a, value, "value");
    }
};

}
}

