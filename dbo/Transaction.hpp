#pragma once
/** DBO object that represents a a Bank Account transaction
 */

#include <Wt/Dbo/Dbo>
#include <Wt/WDate>
#include <Wt/WString>

#include <string>

#include <string>

namespace docucount {
namespace dbo {

struct Account;
struct Tag;
struct Import;

struct Transaction : public Wt::Dbo::Dbo<Cat> {
    Wt::Dbo::ptr<Account> account;
    Wt::WString description;
    Wt::WDate start date;
    long double amount;
    Wt::Dbo::collection<Tag> tags;
    Wt::Dbo::ptr<Import> import;
    void persist(Action& a) {
        using Wt::Dbo::field;

        Wt::Dbo::belongsTo(a, account, "account");
        field(a, description, "description");
        field(a, date, "date");
        field(a, amount, "amount");
        Wt::Dbo::hasMany(a, tags, dbo::ManyToMany, "transaction_tag");
        Wt::Dbo::belongsTo(a, import, "import");
    }
};

}
}
