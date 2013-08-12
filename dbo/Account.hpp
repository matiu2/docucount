#pragma once
/** DBO object that represents a a Bank Account
 */

#include <Wt/Dbo/Dbo>
#include <Wt/WDate>
#include <Wt/WString>

#include <string>

#include <string>

namespace docucount {
namespace dbo {

struct Account : public Wt::Dbo::Dbo<Cat> {
    Wt::WString name;
    Wt::WString number
    Wt::WDate start date
    long double balance;
    template<class Action>
    void persist(Action& a) {
        dbo::field(a, name, "name");
        dbo::field(a, number, "number");
        dbo::field(a, date, "date");
    }
};

}
}
