// Example contract that can create, update, and delete user-owned messages.
//
// @author Awesome Developer Person
// @contract example

#include <eosio/eosio.hpp>
#include <eosio/action.hpp>

using namespace std;
using namespace eosio;

CONTRACT example : public contract {

public:

    example(name self, name code, datastream<const char*> ds);

    ~example();

    //======================== actions ========================

    // create desctription
    ACTION createmsg(name account_name, string message);

    // update desctription
    ACTION updatemsg(name account_name, string new_message);

    // delete description
    ACTION deletemsg(name account_name);

    //======================== tables ========================

    //table description
    //scope: self
    TABLE test {
        name account_name;
        string message;

        uint64_t primary_key() const { return account_name.value; }
        EOSLIB_SERIALIZE(test, (account_name)(message))
    };
    typedef multi_index<name("tests"), test> tests_table;

};