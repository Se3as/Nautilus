#pragma once

#include <fstream>
#include <string>
#include <ctime>
#include <iostream>

using namespace std;
class Log {
    private:
        ofstream csv;
    public:
        Log();
        ~Log();
        ofstream& getCsv();

        // Open CSV file
        void openCsv();

        // Log registration methods
        void register_insert(int& iterations, string name, double time);
        void register_remove(int& iterations, string name, double time);
        void register_search(int& iterations, string name, double& damage, double time);

        // Close CSV file
        void closeCsv();
};


