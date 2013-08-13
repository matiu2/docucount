#pragma once
/** DBO object that represents a tag on a transaction
 */

#include <Wt/Dbo/Dbo>
#include <Wt/WDate>
#include <Wt/WString>

namespace docucount {
namespace model {

struct Transaction;
struct Report;

struct Tag : public Wt::Dbo::Dbo<Tag> {
    Wt::WString name;
    Wt::Dbo::collection<Transaction> transactions;
    Wt::Dbo::collection<Report> reports;
    void persist(Action& a) {
        using Wt::Dbo::field;
        using Wt::Dbo::ManyToMany;

        field(a, name, "name");
        Wt::Dbo::hasMany(a, transactions, ManyToMany, "transaction_tag");
        Wt::Dbo::hasMany(a, reports, ManyToMany, "report_tag");
    }
};

}
}

