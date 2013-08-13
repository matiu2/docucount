#pragma once
/** DBO object that represents a a Bank Account transaction
 */

#include <Wt/Dbo/Dbo>
#include <Wt/WDate>
#include <Wt/WString>

namespace docucount {
namespace model {

struct Account;
struct Tag;
struct Import;

struct Transaction : public Wt::Dbo::Dbo<Transaction> {
private:
public:
    Wt::Dbo::ptr<Account> account;    /// The account that this transaction occured on. Transfers will have two transactions, one for each account
    Wt::WString description;          /// The description as given by the bank data we imported
    Wt::WDate date;                   /// The date of the transaction
    long double amount;               /// The amount of the transaction
    Wt::Dbo::collection<Tag> tags;    /// All the tags attached to this transaction
    Wt::Dbo::ptr<Import> import;      /// The import process that imported this transaction
    void persist(Action& a) {
        using Wt::Dbo::field;
        namespace dbo = Wt::Dbo;

        dbo::belongsTo(a, account, "account");
        field(a, description, "description");
        field(a, date, "date");
        field(a, _amount, "amount");
        dbo::hasMany(a, tags, dbo::ManyToMany, "transaction_tag");
        dbo::belongsTo(a, import, "import");
    }
};

}
}
