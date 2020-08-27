/*ASCII ENCODE/DECODE */
#include <iostream>
#include <vector>
#include <iterator>
#include <string>

#define drop;  std::cout << std::endl;

class Module
{
private:
    std::string txt;
    std::string int_tx;
    std::vector<char> _char; //split char container
    std::vector<std::string> _int; //split int container


    std::vector<unsigned int> ENCODE()
    {
        std::vector<unsigned int> temp; //temp container
        std::vector<char>::iterator itr = _char.begin();
        for(itr; itr!= _char.end(); ++itr)
            temp.push_back(int(*itr)); //conv char to dec eqv

        std::cout<< "[ENCODED CONTAINER: ] ";
        drop;
        for(it : temp)
            std::cout<< it << "| ";
        return temp; //return vector
    }

    std::vector<char> DECODE()
    {
        int temp_val;
        std::vector<char>temp;
        std::vector<std::string>::iterator itr = _int.begin();
        for(itr; itr!= _int.end(); ++itr)
        {
            int temp_int = std::stoi(*itr);
            temp.push_back(char(temp_int));
        }
        return temp;
    }

public:
    Module() { /*default */ }
    Module(std::string tx) : txt(tx)
    {
        /*split txt -> char */
        for(unsigned int i=0; i < txt.size(); i++)
        {
            _char.push_back(txt[i]);
        }
    }

    Module(std::string int_txt, char k) : int_tx(int_txt)
    {
        std::string temp,t1,t2,t3;
        for(unsigned int i=0; i < int_tx.size(); i++)
        {
            t1 = int_tx[i];
            t2 = int_tx[i+=1];
            t3 = int_tx[i+=1];
            temp = std::string(t1) + std::string(t2) + std::string(t3) ;
            _int.push_back(temp);

        }

        std::cout << "[processing...]" << std::endl;
        system("PAUSE");
    }


    std::string app_int(int x)
{
    std::string val = std::to_string(x);
    val =  std::string("0") + val;
    return val;

}

    void get_encode()
    {
        std::vector<unsigned int> rec;
        ENCODE().swap(rec); //encoded value stored in rec
        drop;
        drop;
        std::cout << "[IDEAL ASCII ENCODE: ] " <<std::endl;
        for(auto it : rec)
        {
            if(std::to_string(it).length() != 3)
            {
                std::cout<< app_int(it);
            }
            else
            {
               std::cout<< it;
            }
        }
    }

    void get_decode()
    {
        std::vector<char> ret;
        DECODE().swap(ret);

        std::cout<< "[IDEAL ASCII DECODE: ]" <<std::endl;
        for(auto it : ret)
        {
            std::cout<< it;
        }
    }
};

int main()
{
    try{
    //Module obj; //def
    std::string text;
    std::string ascii_int;
    int idx;

    do{
    std::cout << "[ENCODE: ] 1. \n" << "[DECODE: ] 2. \n" << "[EXIT] 0. " <<std::endl;
    std::cin >> idx;
    system("CLS");

    switch(idx)
    {
    case 1:
        {
        std::cin.ignore();
        std::cout<< "PASTE TEXT" << std::endl;

        std::getline(std::cin, text);
        Module obj1(text);

        obj1.get_encode();
        drop;
        system("PAUSE");
        system("CLS");
        break;
        }
    case 2:
        {
        std::cout << "[Drop ASCII code: ] "<< std::endl;
        std::cin.ignore();
        std::getline(std::cin, ascii_int);
        Module obj2(ascii_int, 'd');
        drop;
        obj2.get_decode();
        drop;
        system("PAUSE");
        system("CLS");
        break;
        }

    default:
        throw(99);
        break;
    }

    drop;
    }while(idx != 0);

    }
    catch(int trap)
    {
        if(trap == 99)
        {
            std::cout << "enter ideal values" << std::endl;

        }
    }
}
