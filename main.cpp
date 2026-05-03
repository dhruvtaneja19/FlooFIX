#include <iostream>
#include <sstream>
#include <unordered_map>
#include <string>
#include "storage.hpp"
#include "tokenizer.hpp"

int main(void){
    std::string raw_msg = "8=FIX.4.2|9=118|35=D|49=SENDER|56=TARGET|34=2|52=20240528-09:20:52|11=ORDERID|55=MSFT|54=1|38=1000|40=2|44=150.5|10=000|";

    fix_field_storage fixmsg_store(raw_msg);
    // print the FIX message in tags and values
    for (const auto &pair : fixmsg.store(raw_msg))
    {
        std::cout << "Tag: " << pair.first << ", Value: " << pair.second << "\n";
    }
    return 0;
}