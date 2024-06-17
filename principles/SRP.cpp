class ReportGenerator {
public:
    std::string generateReport() {
        // Генерація звіту
        return "Report";
    }
};

class ReportPrinter {
public:
    void printReport(const std::string& report) {
        // Друк звіту
        std::cout << report << std::endl;
    }
};
//Принцип єдиної відповідальності (SRP) говорить, що клас або модуль повинен мати лише одну причину для зміни, тобто одну відповідальність.