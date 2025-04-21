#include "log.h"

// Constructor
Log::Log() {
    srand(static_cast<unsigned>(time(0)));
}
Log::~Log() {
    if (csv.is_open()) {
        csv.close();
    }
}

// Get CSV Stream
ofstream& Log::getCsv() {
    return csv;
}

// Open CSV File
void Log::openCsv() {
    if (!csv.is_open()) {
        csv.open("resultado.csv");
        csv << "Barco,operacion,iteraciones,daño,time\n";
    }
}

// Close CSV File
void Log::closeCsv() {
    if (csv.is_open()) {
        csv.close();
    }
}

// Register Insert Operation
void Log::register_insert(int& iterations, string name, double time) {
    //std::cout << name << "," << "insert," << iterations << ",0," << time << "\n";
    csv << name << "," << "insert," << iterations << ",0," << time << "\n";
    csv.flush(); 
}

// Register Remove Operation
void Log::register_remove(int& iterations, string name, double time) {
    csv << name << "," << "deletion," << iterations << ",0," << time << "\n";
    csv.flush(); 
}

// Register Search Operation
void Log::register_search(int& iterations, string name, double& damage, double time) {
    csv << name << "," << "search," << iterations << "," << damage << "," << time<< "\n";
    csv.flush(); 
}