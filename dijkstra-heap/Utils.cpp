#include "Utils.h"

double Utils::log_x(double number, double base) {
    return log(number) / log(base);
}

// Get current date/time, format is YYYY-MM-DD.HH:mm:ss
std::string Utils::currentDateTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    // Visit http://en.cppreference.com/w/cpp/chrono/c/strftime
    // for more information about date/time format
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

    return buf;
}

