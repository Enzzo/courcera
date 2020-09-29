#include "database.h"
#include "date.h"
#include "condition_parser.h"
#include "node.h"
#include "test_runner.h"

#include <iostream>
#include <stdexcept>

std::string ParseEvent(std::istream& is) {
    std::string event;
    is >> event;
    return event;
}

void TestAll();

int main() {
    TestAll();

    Database db;

    for (std::string line; getline(std::cin, line); ) {
        std::istringstream is(line);

        std::string command;
        is >> command;

        //Добавить событие к дате
        //Add 2017-07-08 Someone's birthday
        if (command == "Add") {            
            const auto date = ParseDate(is);
            const auto event = ParseEvent(is);
            db.Add(date, event);
        }

        //Вывести на экран список всех событий и дат
        //Print
        else if (command == "Print") {            
            db.Print(std::cout);
        }

        //Удалить дату (или список дат) или событие по условию
        //Del date == 2017-07-08
        //Del date > 2017-11-20
        //Del event != "holiday"
        else if (command == "Del") {
            
            auto condition = ParseCondition(is);
            auto predicate = [condition](const Date& date, const std::string& event) {
                return condition->Evaluate(date, event);
            };
            int count = db.RemoveIf(predicate);
            std::cout << "Removed " << count << " entries" << std::endl;
        }


        else if (command == "Find") {
            //Find event != "working day"
            auto condition = ParseCondition(is);
            auto predicate = [condition](const Date& date, const std::string& event) {
                return condition->Evaluate(date, event);
            };

            const auto entries = db.FindIf(predicate);
            for (const auto& entry : entries) {
                std::cout << entry << std::endl;
            }
            std::cout << "Found " << entries.size() << " entries" << std::endl;
        }

        //Last 2017-06-01
        //выводит эту, или ближайшую к ней, но не бОльшую
        //если значение ниже минимальной даты списка, то пишем "no entries"
        else if (command == "Last") {
            try {
                std::cout << db.Last(ParseDate(is)) << std::endl;
            }
            catch (std::invalid_argument&) {
                std::cout << "No entries" << std::endl;
            }
        }
        else if (command.empty()) {
            continue;
        }
        else {
            throw std::logic_error("Unknown command: " + command);
        }
    }

    return 0;
}

void TestParseEvent() {
    {
        std::istringstream is("event");
        AssertEqual(ParseEvent(is), "event", "Parse event without leading spaces");
    }
    {
        std::istringstream is("   sport event ");
        AssertEqual(ParseEvent(is), "sport event ", "Parse event with leading spaces");
    }
    {
        std::istringstream is("  first event  \n  second event");
        std::vector<std::string> events;
        events.push_back(ParseEvent(is));
        events.push_back(ParseEvent(is));
        AssertEqual(events, std::vector<std::string>{"first event  ", "second event"}, "Parse multiple events");
    }
}

void TestAll() {
    TestRunner tr;
    tr.RunTest(TestParseEvent, "TestParseEvent");
    tr.RunTest(TestParseCondition, "TestParseCondition");
}
