#include <iostream>
#include <fstream>
class Adress{
public:
    std::string city;
    std::string street;
    int number_house;
    int number_flat;

};

class Read{

    int cicle = 0;
public:
    void work_to_files(std::string file_in, std::string file_out) {
        std::ifstream in;
        std::ofstream out;
        out.open(file_out);
        in.open(file_in);
        in >> cicle;
        Adress* adress = new Adress[cicle];
        for (int i = 0; i < cicle; i++) {
            in >> adress[i].city;
            in >> adress[i].street;
            in >> adress[i].number_house;
            in >> adress[i].number_flat;
        }

        std::string change;
        int number_change;
        for(int k = 0; k < cicle - 1; k++) {
            for (int i = 0; i < cicle - 1; i++) {
                if (adress[i].city > adress[i + 1].city) {

                    change = adress[i].city;
                    adress[i].city = adress[i + 1].city;
                    adress[i + 1].city = change;

                    change = adress[i].street;
                    adress[i].street = adress[i + 1].street;
                    adress[i + 1].street = change;

                    number_change = adress[i].number_house;
                    adress[i].number_house = adress[i + 1].number_house;
                    adress[i + 1].number_house = number_change;

                    number_change = adress[i].number_flat;
                    adress[i].number_flat = adress[i + 1].number_flat;
                    adress[i + 1].number_flat = number_change;
                }

            }
        }

        out  << cicle << "\n";
        for(int i = 0; i <cicle; i++){
            out << adress[i].city << ", ";
            out << adress[i].street << ", ";
            out << adress[i].number_house << ", ";
            out << adress[i].number_flat << "\n";
        }
        out.close();
        in.close();
        delete[] adress;
    }

};
int main() {

    Read read;
    read.work_to_files("in.txt", "out.txt");

    return 0;
}
