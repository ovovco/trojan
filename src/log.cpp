#include "log.h"
#include <cstdio>
#include <string>
#include <sstream>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/date_time/posix_time/posix_time_io.hpp>
using namespace std;
using namespace boost::posix_time;

void Log::log(const string &message) {
    fprintf(stderr, "%s\n", message.c_str());
}

void Log::log_with_date_time(const string &message) {
    time_facet *facet = new time_facet("[%Y-%m-%d %H:%M:%S] ");
    ostringstream stream;
    stream.imbue(locale(stream.getloc(), facet));
    stream << second_clock::local_time();
    Log::log(stream.str() + message);
}