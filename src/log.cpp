#include "log.h"
#include <ctime>

// Constructor
Log::Log() {
    srand(static_cast<unsigned>(time(0)));
}

// Singleton Instance
Log& Log::getInstance() {
    static Log instance;
    return instance;
}

// Get CSV Stream
std::ofstream& Log::getCsv() {
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
void Log::register_insert(int iterations, std::string name, double time) {
    csv << name << "," << "insert," << iterations << ",0," << time << "\n";
}

// Register Remove Operation
void Log::register_remove(int iterations, std::string name, double time) {
    csv << name << "," << "deletion," << iterations << ",0," << time << "\n";
}

// Register Search Operation
void Log::register_search(int iterations, std::string name, double damage, double time) {
    csv << name << "," << "search," << iterations << "," << damage << "," << time << "\n";
}