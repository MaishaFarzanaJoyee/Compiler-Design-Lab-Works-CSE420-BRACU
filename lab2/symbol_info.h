#include<bits/stdc++.h>
using namespace std;
//almost done
class symbol_info {
private:
    string name;
    string type;
    // Write necessary attributes to store what type of symbol it is (variable/ array/ function).
    string identifier_type;
    
    
    // Write necessary attributes to store the type/return type of the symbol (int/ float/ void/ ...).
    string return_type;
    // Write necessary attributes to store the parameters of a function.
    vector<string> param;
    
    // Write necessary attributes to store the array size if the symbol is an array.
    int array_size;


public:
    symbol_info(string name, string type) {
        this->name = name;
        this->type = type;
    }
    string get_name() {
        return name;
    }
    string get_type() {
        return type;
    }
    void set_name(string name) {
        this->name = name;
    }
    void set_type(string type) {
        this->type = type;
    }
    // Write necessary functions to set and get the attributes of the symbol_info class.

    string get_identifier_type() {
        return identifier_type;
    }

    void set_identifier_type(string identifier_type) {
        this->identifier_type = identifier_type;
    }

    string get_return_type() {
        return return_type;
    }

    void set_return_type(string return_type) {
        this->return_type = return_type;
    }
   
    int get_array_size() {
        return array_size;
    }

    void set_array_size(int array_size) {
        this->array_size = array_size;
    }

    vector<string> get_parameter() {
        return param;
    }
    
   void add_parameter(string parameter) {
    param.push_back(parameter);
   }

    void set_parameter_list(vector<string> list) {
        param = list;
    }

 
   
    ~symbol_info() {
        // Write necessary code to deallocate memory, if necessary (not needed in this case).
    }
};
