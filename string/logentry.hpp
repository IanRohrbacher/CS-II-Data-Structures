//
// File:        logentry.hpp
//
// Version:     1.0
// Date:
// Author:
//
// Description: Class definition for a log entry.
//
//
//
 
#ifndef CS_LOGENTRY_H_
#define CS_LOGENTRY_H_

#include "string.hpp"
#include <iostream>
#include <vector>



class Date {
    public:
        Date() {day = ""; month = ""; year = "";};
        Date(String d, String m, String y) {day = d; month = m; year = y;};

    private:
        String  day, month, year;
        
        friend std::ostream& operator<<(std::ostream &, const Date&); 
};



class Time {
    public:
        Time() {hour = ""; minute = ""; second = "";};
        Time(String h, String m, String s) {hour = h; minute = m; second = s;};
    
    private:
        String  hour, minute, second;
        
        friend std::ostream& operator<<(std::ostream &, const Time&); 
};


// A single log entry
class LogEntry {
    public:
        LogEntry() {host = ""; date = Date("", "", ""); time = Time("", "", ""); request = ""; status = ""; number_of_bytes = 0;};
        LogEntry(const String&);

        String getHost() const {return host;};
        int getNumber_of_bytes() const {return number_of_bytes;};
        
        friend std::ostream& operator<<(std::ostream&, const LogEntry&);

    private:
        String  host;
        Date    date;
        Time    time;
        String  request;
        String  status;
        int     number_of_bytes;
};
//
// Free functions
//
std::vector<LogEntry>   parse       (std::istream&);
void                    output_all  (std::ostream&, const std::vector<LogEntry>&);
void                    by_host     (std::ostream&, const std::vector<LogEntry>&);
int                     byte_count  (const std::vector<LogEntry>&);
void uniqueIP(std::ostream&, const std::vector<LogEntry>&);

#endif
