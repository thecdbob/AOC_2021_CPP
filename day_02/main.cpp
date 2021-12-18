#include <iostream>
#include <vector>
#include <fstream>
#include <iostream>
#include <vector>
#include <regex>

const std::string part_02_input = "input_day_02.txt";

// file i/o function that outputs a vector of strings
std::vector<std::string> file_input(std::string input){
    // converts the textfile into a vector of ints
    std::string temp;
    std::vector<std::string> deptharray = {};
    std::ifstream input_file(input);

    while(getline(input_file, temp))
    {
        deptharray.push_back((temp));
    }
    input_file.close();
    return deptharray;
}

int part_01(std::vector<std::string> input_p1){
    int x = 0;
    int y = 0;
    std::regex forward("forward");
    std::regex up("up");
    std::regex down("down");
    std::string temp_string;
    for(int i=0; i < input_p1.size(); i++) {
        temp_string = input_p1[i];
        if (std::regex_search(temp_string, forward)){
            x += std::stoi(&temp_string.back());
            //std::cout << "f" << std::endl;
        }
        else if (std::regex_search(temp_string, up)){
            y -= std::stoi(&input_p1[i].back());
            //std::cout << "u" << std::endl;
        }
        else if (std::regex_search(temp_string, down)) {
            y += std::stoi(&input_p1[i].back());
            //std::cout << "d" << std::endl;
        }
    }
    //std::cout << x << " x + y " << y << "\n";
    int mult_results = x*y;
    return mult_results;
}

int part_02(std::vector<std::string> input_p2){
    int x = 0;
    int y = 0;
    int aim = 0;
    std::regex forward("forward");
    std::regex up("up");
    std::regex down("down");
    std::string temp_string;
    for(int i=0; i < input_p2.size(); i++) {
        temp_string = input_p2[i];
        if (std::regex_search(temp_string, forward)){
            int x_value = std::stoi(&temp_string.back());
            x += x_value;
            y += (aim * x_value);
        }
        else if (std::regex_search(temp_string, up)){
            aim -= std::stoi(&input_p2[i].back());
        }
        else if (std::regex_search(temp_string, down)) {
            aim += std::stoi(&input_p2[i].back());
        }
    }
    int mult_results = x*y;
    return mult_results;
}

int main() {
    std::vector<std::string> string_file_input_day_02 = file_input(part_02_input);
    int part_01_int = part_01(string_file_input_day_02);
    std::cout << part_01_int << "\n";
    int part_02_int = part_02(string_file_input_day_02);
    std::cout << part_02_int << "\n";
    return 0;
}
