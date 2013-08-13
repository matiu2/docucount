#pragma once
/** DBO object that represents a a Bank Account
 */

#include <Wt/Dbo/Dbo>
#include <Wt/WDate>
#include <Wt/WString>


namespace docucount {
namespace model {

struct Entity;

struct Account : public Wt::Dbo::Dbo<Account> {
    Wt::WString name;             /// Name of the account
    Wt::WString number;           /// Account number as supplied by the bank
    Wt::WDate startDate;         /// The date of the starting balance
    long double startBalance;     /// The starting balance of the account
    long double balance;          /// The current balance in this account
    Wt::Dbo::ptr<Entitiy> entity; /// The person/company that owns this account
    template<class Action>
    void persist(Action& a) {
        using Wt::Dbo::field;
        field(a, name, "name");
        field(a, number, "number");
        field(a, startDate, "start_date");
        field(a, startBalance, "start_balance");
        field(a, balance, "balance");
        dbo::belongsTo(a, entity, "entity");
    }
};

}
}
