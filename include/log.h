#ifndef LOG_H
#define LOG_H

#include <fstream>
#include <string>

class Log {
    private:
        std::ofstream csv;

        // Private constructor to enforce singleton
        Log();

        // Deleted copy constructor and assignment operator
        Log(const Log&) = delete;
        Log& operator=(const Log&) = delete;

    public:
        // Access the singleton instance
        static Log& getInstance();

        // CSV access (optional)
        std::ofstream& getCsv();

        // Open CSV file
        void openCsv();

        // Log registration methods
        void register_insert(int iterations, std::string name, double time);
        void register_remove(int iterations, std::string name, double time);
        void register_search(int iterations, std::string name, double damage, double time);

        // Close CSV file
        void closeCsv();
};

#endif // LOG_H
