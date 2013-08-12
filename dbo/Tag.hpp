#pragma once
/** DBO object that represents a tag on a transaction
 */

#include <Wt/Dbo/Dbo>
#include <Wt/WDate>
#include <Wt/WString>

#include <string>

#include <string>

namespace docucount {
namespace dbo {

struct Transaction;
struct Report;

struct Tag : public Wt::Dbo::Dbo<Cat> {
    Wt::WString name;
    Wt::Dbo::collection<Transaction> transactions;
    Wt::Dbo::collection<Report> reports;
    void persist(Action& a) {
        using Wt::Dbo::field;

        field(a, name, "name");
        Wt::Dbo::hasMany(a, transactions, dbo::ManyToMany, "transaction_tag");
        Wt::Dbo::hasMany(a, reports, dbo::ManyToMany, "report_tag");
    }
};

}
}

