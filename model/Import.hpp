#pragma once
/** DBO object that represents a collection of transactions that were imported
 */

#include <Wt/Dbo/Dbo>
#include <Wt/WDate>
#include <Wt/WString>

namespace docucount {
namespace model {

struct Transaction;

struct Import : public Wt::Dbo::Dbo<Import> {
    Wt::WString name;
    Wt::WDate date;     /// Date imported
    Wt::WString regex;  /// The value of the regex applied to 'data' to perform the import
    Wt::WString data;   /// The original csv or other data imported
    Wt::Dbo::collection<Transaction> transactions;
    void persist(Action& a) {
        using Wt::Dbo::field;

        field(a, name, "name");
        field(a, date, "date");
        field(a, regex, "regex");
        field(a, data, "data");
        Wt::Dbo::hasMany(a, transactions, "transactions");
    }
};

}
}

