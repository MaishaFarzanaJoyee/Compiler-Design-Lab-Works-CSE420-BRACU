#include "symbol_info.h"

class scope_table
{
private:
    int bucket_count;
    int unique_id;
    scope_table *parent_scope = NULL;
    vector<list<symbol_info *>> table;

    int hash_function(string name)
{
    int s = 0;
    for (char c : name)
    {
        s+= int(c); 
    }
    return s % bucket_count;
}


public:
    scope_table();

    
    scope_table(int bucket_count, int unique_id, scope_table *parent_scope);
    scope_table *get_parent_scope();
    int get_unique_id();
    symbol_info *lookup_in_scope(symbol_info* symbol);
    bool insert_in_scope(symbol_info* symbol);
    bool delete_from_scope(symbol_info* symbol);
    void print_scope_table(ofstream& outlog);
   
    ~scope_table();
   

    // you can add more methods if you need
};                         

scope_table::scope_table() {
    bucket_count = 0;
    unique_id = 0;
    parent_scope = NULL;
}

scope_table::scope_table(int bucket_count, int unique_id, scope_table *parent_scope) {
    this->bucket_count = bucket_count;
    this->unique_id = unique_id;
    this->parent_scope = parent_scope;
    table.resize(bucket_count);
}

scope_table* scope_table::get_parent_scope() {
    return parent_scope;
}

int scope_table::get_unique_id() {
    return unique_id;
}

symbol_info* scope_table::lookup_in_scope(symbol_info* symbol) {
    int index = hash_function(symbol->get_name());
    for (auto& sym : table[index]) {
        if (sym->get_name() == symbol->get_name()) {
            return sym;
        }
    }
    return nullptr;
}

bool scope_table::insert_in_scope(symbol_info* symbol) {
    int index = hash_function(symbol->get_name());
    for (auto& sym : table[index]) {
        if (sym->get_name() == symbol->get_name()) {
            return false; // exists
        }
    }
    table[index].push_back(symbol);
    return true;
}

bool scope_table::delete_from_scope(symbol_info* symbol) {
    int index = hash_function(symbol->get_name());
    auto& cell = table[index];
    for (auto it = cell.begin(); it != cell.end(); ++it) {
        if ((*it)->get_name() == symbol->get_name()) {
            cell.erase(it);
            return true; // deleted
        }
    }
    return false; 
}



// complete the methods of scope_table class
void scope_table::print_scope_table(ofstream& outlog)
{
    outlog << "ScopeTable # "+ to_string(unique_id) << endl;

    //iterate through the current scope table and print the symbols and all relevant information
    for (int i = 0; i < bucket_count; i++) {
        if (!table[i].empty()) {
            outlog << i << " --> ";
            for (auto& sym : table[i]) {
                outlog << "< " << sym->get_name() << " : " << sym->get_type();
                string id_type = sym->get_identifier_type();
                if (!id_type.empty()) {
                    outlog << " , " << id_type;
                }
                string ret_type = sym->get_return_type();
                if (!ret_type.empty()) {
                    outlog << " , " << ret_type;
                }
                int arr_size = sym->get_array_size();
                if (arr_size > 0) {
                    outlog << " , " << arr_size;
                }
                vector<string> params = sym->get_parameter();
                if (!params.empty()) {
                    outlog << " , (";
                    for (size_t j = 0; j < params.size(); j++) {
                        outlog << params[j];
                        if (j < params.size() - 1) {
                            outlog << ", ";
                        }
                    }
                    outlog << ")";
                }
                outlog << " > ";
            }
            outlog << endl;
        }
    }
    
}
scope_table::~scope_table()
{
    for (int i = 0; i < bucket_count; i++)
    {
        for (symbol_info *sym : table[i])
        {
            delete sym;
        }
    }
}