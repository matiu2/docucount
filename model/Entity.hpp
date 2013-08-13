#pragma once
/** Models an Entity, either a person or a company or something like that*/

#include <Wt/Dbo/Dbo>

namespace docucount {
namespace model {

struct Account;

struct Entity : public Wt::Dbo::Dbo<Entity> {
    Wt::WString name;
    Wt::Dbo::collection<Account> accounts;
    void persist(Action& a) {
        namespace dbo = Wt::Dbo;
        field(a, name, "name");
        dbo::hasMany(a, tags, dbo::ManyToMany, "transaction_tag");
    }
};

}
}
