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
        Adress adress[cicle];
        for (int i = 0; i < cicle; i++) {
            in >> adress[i].city;
            in >> adress[i].street;
            in >> adress[i].number_house;
            in >> adress[i].number_flat;
        }

        Adress adress1[cicle];
        std::copy_n(adress, cicle, adress1);
        int rise[cicle];
        int count = 0;
        for(int k = 0; k < cicle; k++) {
            rise[k] = k;
            for (int i = 0; i < cicle; i++) {
                if (adress1[rise[k]].city > adress1[i].city) {
                    rise[k] = i;
                    i = 0;
                    count++;
                }else if(i == cicle - 1 && count == 0){
                    rise[k] = k;
                }
            }
            adress1[rise[k]].city = "аааааа";
            count = 0;
        }

        out  << cicle << "\n";
        for(int i = 0; i <cicle; i++){
            out << adress[rise[i]].city << ", ";
            out << adress[rise[i]].street << ", ";
            out << adress[rise[i]].number_house << ", ";
            out << adress[rise[i]].number_flat << "\n";
        }
        out.close();
        in.close();
    }

};
int main() {

    Read read;
    read.work_to_files("in.txt", "out.txt");

    return 0;
}
