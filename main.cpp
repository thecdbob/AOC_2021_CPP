#include <iostream>
#include <vector>
#include <fstream>
#include <iostream>
#include <vector>

//modular file input function

std::vector<int> file_input(std::string input){
    // converts the textfile into a vector of ints
    int depth;
    std::string temp;
    std::vector<int> deptharray = {};
    std::ifstream input_file(input);

    while(input_file >> temp)
    {
        deptharray.push_back(std::stoi(temp));
    }
    input_file.close();
    return deptharray;
}

int part_01(std::vector<int> vector_p1){
    // go through the vector and compare previous entries to the current one, and return a count of increase
    int depth_count = 0;
    for(int i = 1; i < vector_p1.size(); i++)
    {
        if(vector_p1[i] > vector_p1[i-1])
            depth_count += 1;
    }
    return depth_count;
}

int part_02(std::vector<int> vector_p2){
    // same as first but in three items
    int depth_count_trois = 0;
        for(int i = 3; i < vector_p2.size(); i++)
        {
            if((vector_p2[i-2] + vector_p2[i-1] + vector_p2[i]) > (vector_p2[i-3] + vector_p2[i-2] + vector_p2[i-1]))
                depth_count_trois += 1;
        }
    return depth_count_trois;
}

// main function for calling functions
int main() {
    std:: string part_01_input = "day_01_part_01.txt";
    std::vector<int> input_p1 = file_input(part_01_input);
    int part_01_int = part_01(input_p1);
    int part_02_int = part_02(input_p1);
    std::cout << part_01_int << "\n";
    std::cout << part_02_int << "\n";
    return 0;
}