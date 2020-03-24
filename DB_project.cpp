//============================================================================
// Name        : DB_project.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <map>
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <time.h>
#include <set>
#include <stdlib.h>
#include <ctype.h>
#include <fstream>
#include <iomanip>
using namespace std;

struct Date {
	int year;
	int month;
	int day;
};

bool operator==(const Date& date1,const Date& date2) {
	if ((date1.year == date2.year && date1.month == date2.month) &&
			date1.day == date2.day) {
		return true;
	} else {
		return false;
	}
}

bool operator<(const Date& date1, const Date& date2) {
	if (date1.year < date2.year) {
		return true;
	} else if (date1.year == date2.year && date1.month < date2.month) {
		return true;
	} else if ((date1.year == date2.year && date1.month == date2.month) &&
			date1.day < date2.day) {
		return true;
	} else {
		return false;
	}
}

bool CheckSep(istream& stream) {
	if (stream.peek() != ':') {
		cout << "Wrong separator: " << char(stream.peek()) << endl;
		throw runtime_error("sorry");
		return false;
	} else {
		stream.ignore(1);
	return true;
	}
}
bool CheckYear(istream& stream, Date& date) {
	int year;
	stream >> year;
	if (year < 0) {
		cout << "year value should be more than or equal to zero" << endl;

		return false;
	}  date.year = year;
	return true;
}

bool CheckMonth(istream& stream, Date& date) {
	int month;
	stream >> month;
	if (month < 1 || month > 12) {
		cout << "Month value is invalid: " << to_string(month) << endl;

		return false;
	} else {
		date.month = month;
		return true;
	}
}
bool CheckDay(istream& stream, Date& date) {
	int day;
	stream >> day;
	if (day < 1 || day > 31) {
		cout << "Day value is invalid: " << to_string(day);

		return false;
	} date.day = day;
	return true;
}

istream& operator>>(istream& stream, Date& date) {


			CheckYear(stream, date);

			CheckSep(stream);

	    	CheckMonth(stream, date);

			CheckSep(stream);

			CheckDay(stream, date);




	    return stream;


}


ostream& operator<<(ostream& stream,const Date date) {
	stream << setfill('0');
	stream << setw(4) << date.year << ":" << setw(2) << date.month << ":"
			<< setw(2) << date.day;
	return stream;
}


class Database {
public:
	Database(Date& date, string& event) {
		data[date].insert(event);
	}
	Database() {}

	map<Date, set<string>> GetData() {
		return data;
	}
    void Add(Date& date, string& event) {
    	data[date].insert(event);
    }
    void Find(Date& date) {
    	for (auto& i : data[date]) {
    		cout << i << endl;
    	}
    }
    void DelEvent(Date& date, string& event) {
    	if (data[date].count(event) == 1) {
    		if (data[date].size() > 1) {
    		data[date].erase(event);
    		cout << "Deleted one event" << endl;
    	  } else if (data[date].size() == 1) {
    		  data.erase(date);
    	  }
    	} else if (data.count(date) == 0) {
    		cout << "Date has not been found" << endl;
    	}

    	else if (data[date].count(event) == 0) {
    		cout << "Event not found" << endl;
    	}
    }
    void DelEvents(Date& date) {
    	int length = data[date].size();
    	if (length == 0) {
    		cout << "Nothing has been found of planned on that date" << endl;
    	}
    	else {
    	data.erase(date);
    	cout << "Deleted " << length << " events" << endl;
    }
  }
    void Print() {
    	for (auto& item : data) {
    		cout << item.first << " ";
    		for (auto& event : item.second) {
    			cout << event << " ";
    		}cout << endl;
    	}
    }


private:
	map<Date, set<string>> data;
};

int main() {
	string line;
	Database DB;
    while (getline(cin, line)) {
    	istringstream command;
    	string request;
    	command.str(line);
    	command >> request;
    	if (request == "Add") {
    		try {
    		Date date;
    		string event;
    		command >> date;
    		command >> event;

    		DB.Add(date, event);
    	  } catch (exception& ex) {
    		  cout << "Exception has happened: " << ex.what() << endl;
    	  }
    	} else if (request == "Find") {
    		try {
    		Date date;
    		command >> date;

    		DB.Find(date);
    	  } catch (exception& ex) {
    		  cout << "Exception has happened: " << ex.what() << endl;
    	  }
    	} else if (request == "Print") {
         try {
    		DB.Print();
         } catch (exception& ex) {
        	 cout << "Exception has happened: " << ex.what() << endl;
         }
    	} else if (request == "Del") {
    		try {
    		Date date;
    		string event;
    		command >> date;
    		command >> event;

    		if (event == "") {

    			DB.DelEvents(date);

    		} else {

    				DB.DelEvent(date, event);

    		}
    	  } catch (exception& ex ) {
  			cout << "Exception has happened: " << ex.what() << endl;
  		}
    	}

    }
	return 0;
}
