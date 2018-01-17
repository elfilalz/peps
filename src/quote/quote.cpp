#include <iostream>
#include <sstream>
#include <curl/curl.h>
#include <boost/algorithm/string.hpp>

#include "quote.hpp"
#include "curl_utils.hpp"

Quote::Quote(std::string symbol) {
    this->symbol = symbol;
}

Quote::~Quote() {}

std::string Quote::getHistoricalCsv(int period1, int period2, const char *interval) {
    std::string url = "https://finance.yahoo.com/quote/"
            + this->symbol
            + "/?p="
            + this->symbol;

    std::string *crumb = new std::string;
    std::string *cookie = new std::string;

    // Get the Crumb and Cookie from Yahoo Finance
    getCrumbCookie(url, crumb, cookie);

    // Download the historical prices Csv
    std::string csv = downloadCsv(
                this->symbol, period1, period2, interval, crumb, cookie);

    // Free memory
    delete crumb;
    delete cookie;

    // Return the csv
    return csv;

}

void Quote::getHistoricalSpots(int period1, int period2, const char *interval) {
    // Download the historical prices Csv
    std::string csv = this->getHistoricalCsv(period1, period2, interval);

    std::istringstream csvStream(csv);
    std::string line;

    // Remove the header line
    std::getline(csvStream, line);

    while (std::getline(csvStream, line)) {
        std::vector<std::string> data;
        boost::split(data, line, boost::is_any_of(","));

        Spot spot = Spot(
                data[0],                // date
                std::stod(data[1]),     // open
                std::stod(data[2]),     // high
                std::stod(data[3]),     // low
                std::stod(data[4])      // close
                );

        this->spots.push_back(spot);
    }
}

void Quote::printSpots() {
    for (std::vector<Spot>::iterator it = this->spots.begin();
         it != this->spots.end();
         ++it) {
         std::cout << std::endl << it->toString();
    }
    std::cout << std::endl;
}



