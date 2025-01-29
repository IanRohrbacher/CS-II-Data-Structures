//
//
// File:        logentry.cpp  
//       
// Version:     1.0
// Date:        
// Author:      
//
// Description: Class implementation for a log entry.
//
//
 
#include "string.hpp"
#include "logentry.hpp"
#include <iostream>
#include <vector>
#include <map>



// Date
std::ostream& operator<<(std::ostream &out, const Date& rhs) {
    //std::cout << "Date called" << std::endl;
    out << rhs.month << "/" << rhs.day << "/" << rhs.year;
    
    return out;
}



// Time
std::ostream& operator<<(std::ostream &out, const Time& rhs) {
    //std::cout << "Date called" << std::endl;
    out << rhs.hour << ":" << rhs.minute << "." << rhs.second;
    
    return out;
}



// REQUIRES:
// ENSURES:
LogEntry::LogEntry(const String& line) {
    //Use split to create LogEntry
    std::vector<String> logEntryParts = line.split(' ');

    // for(int i = 0; i < logEntryParts.size(); i++) {
    //     std::cerr << "logEntryParts[]" << i << "]|" << logEntryParts[i] << "|\n";
    // }
    
    host = logEntryParts[0];
    date = Date(logEntryParts[3].substr(1,2), logEntryParts[3].substr(4,6), logEntryParts[3].substr(8,11));
    time = Time(logEntryParts[3].substr(13,14), logEntryParts[3].substr(16,17), logEntryParts[3].substr(19,20));
    request = (logEntryParts[5] + logEntryParts[6] + logEntryParts[7]);
    status = logEntryParts[8];
    number_of_bytes = (logEntryParts[9]) == '-' ? 0 : logEntryParts[9].substr(0, logEntryParts[9].length()).toInt();
}

std::ostream& operator<<(std::ostream &out, const LogEntry& rhs) {
    out << rhs.host << " " << rhs.date << " " << rhs.time << " " << rhs.request << " " << rhs.status << " " << rhs.number_of_bytes;
    return out;
}



// Free
// REQUIRES:
// ENSURES:
std::vector<LogEntry> parse(std::istream& in) {
    std::vector<LogEntry> result;
    std::vector<String> LogEntryList;
    while(!in.eof()) {
        String tempString;
        char tempChar;
        //getline(in, temp);
        in.get(tempChar);
        while(tempChar != ' ' && tempChar != '\n') {
            //std::cerr << "tempChar|" << tempChar << "|\n";
            tempString += String(tempChar);
            in.get(tempChar);
        }
        //std::cerr << "tempString|" << tempString << "|\n";
        LogEntryList.push_back(tempString); 
    }

    int i = 0;
    while(LogEntryList[i] != "") {
        String tempStr = LogEntryList[i] + " " + LogEntryList[i+1] + " " + LogEntryList[i+2] + " " + LogEntryList[i+3] + " " + LogEntryList[i+4] + " " + LogEntryList[i+5] + " " + LogEntryList[i+6] + " " + LogEntryList[i+7] + " " + LogEntryList[i+8] + " " + LogEntryList[i+9];
        LogEntry temp(tempStr);
        result.push_back(temp);
        i+=10;
    }
    
    return result;
}

// REQUIRES:
// ENSURES:
void output_all(std::ostream& out, const std::vector<LogEntry>& rhs) {
    out << "All Output:\n";
    for(int i = 0; i < int(rhs.size()); i++) {
        out << rhs[i] << '\n';
    }
}

// REQUIRES:
// ENSURES:
void by_host(std::ostream& out, const std::vector<LogEntry>& rhs) {
    out << "All Host:\n";
    for(int i = 0; i < int(rhs.size()); i++) {
        out << rhs[i].getHost() << '\n';
    }
}

// REQUIRES:
// ENSURES:
int byte_count(const std::vector<LogEntry>& rhs) {
    int temp = 0;
    for(int i = 0; i < int(rhs.size()); i++) {
        temp += rhs[i].getNumber_of_bytes();
    }
    return temp;
}

void uniqueIP(std::ostream& out, const std::vector<LogEntry>& rhs) {
    std::map<String, int> ip;

    for(int i = 0; i < int(rhs.size()); i++) { 
        ip[rhs[i].getHost()] = i;
    }

    std::map<String, int>::iterator looper = ip.begin();

    out << "The unique IPs are:\n";
    while (looper != ip.end()) {
        out << looper->first << "\n";
        looper++;
    }
    out << "There are " << ip.size() << " unique IPs out of " << rhs.size() << " IPs\n";
}
/*
Write a short description of how you solved the problem

I used the fact std::map cant have two of the same Key values to loop through all of the LogEntrys.
After, I used a iterator to loop though the map to print all the Keys to see what ips where unique.

*/
