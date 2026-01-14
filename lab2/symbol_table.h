#include "scope_table.h"
#include <iostream>

class symbol_table
{
private:
    scope_table *current_scope= NULL;
    int bucket_count=10;
    int current_scope_id=0;

public:
    symbol_table(int bucket_count)
    {
        this->bucket_count = bucket_count;
       
    }
    ~symbol_table()
    {
        while (current_scope != NULL)
        {
            scope_table *temp = current_scope;
            current_scope = current_scope->get_parent_scope();
            delete temp;
        }
    }        

    void enter_scope(ofstream& outlog)
    {
        current_scope_id += 1;
        outlog<<"New ScopeTable with id "<<current_scope_id<<" created"<<endl;
        scope_table *new_scope = new scope_table(bucket_count, current_scope_id, current_scope);
        current_scope = new_scope;
    }

    void exit_scope()
    {
        if (current_scope == NULL)
            return;
        scope_table *temp = current_scope;
        current_scope = current_scope->get_parent_scope();
        delete temp;
    }

    bool insert(symbol_info* symbol)
    {
        if (current_scope != NULL)
        {
            return current_scope->insert_in_scope(symbol);
        }
        return false;
    }

   symbol_info* lookup(symbol_info* symbol)
{
    scope_table *temp = current_scope;

    while (temp != NULL)
    {
        symbol_info* result = temp->lookup_in_scope(symbol);
        if (result != NULL)
        {
            return result;  
        }
        temp = temp->get_parent_scope();  
    }
    return NULL;  
}


    void print_current_scope(ofstream& outlog)
    {
        if (current_scope != NULL)
        {
            current_scope->print_scope_table(outlog);
        }
        else
        {
            outlog << "No current scope to print." << endl;
        }
    }


    void print_all_scopes(ofstream& outlog)
    {
        outlog<<"################################"<<endl<<endl;
        scope_table *temp = current_scope;
        while (temp != NULL)
        {
            temp->print_scope_table(outlog);
            temp = temp->get_parent_scope();
        }
        outlog<<"################################"<<endl<<endl;
    }       

    // you can add more methods if you need 
};



// complete the methods of symbol_table class



// void symbol_table::print_all_scopes(ofstream& outlog)
// {
//     outlog<<"################################"<<endl<<endl;
//     scope_table *temp = current_scope;
//     while (temp != NULL)
//     {
//         temp->print_scope_table(outlog);
//         temp = temp->get_parent_scope();
//     }
//     outlog<<"################################"<<endl<<endl;
// }