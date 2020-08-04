#include <iostream>
#include <exception>
#include <string>

std::string AskTimeServer() {
    /* ��� ������������ ������������ ���� ���, ����������� ��������� ��������� ���� ������:
       * ���������� ������� ���������� ��������
       * ������ ���������� system_error
       * ������ ������� ���������� � ����������.
    */
    std::string time = "01:00:00";
    //time = "1";
    if (time == "0") {
        throw std::system_error(std::error_code());
    }
    if (time == "1") {
        throw std::exception();
    }
    return time;
}

class TimeServer {
public:
    std::string GetCurrentTime() {
        /* ���������� ���� �����:
            * ���� AskTimeServer() ������� ��������, �������� ��� � last_fetched_time � �������
            * ���� AskTimeServer() ������� ���������� system_error, ������� ������� ��������
            ���� last_fetched_time
            * ���� AskTimeServer() ������� ������ ����������, ���������� ��� ������.
        */
        try {
            last_fetched_time = AskTimeServer();
        }
        catch (std::system_error&) {
            return last_fetched_time;
        }
        return last_fetched_time;
    }

private:
    std::string last_fetched_time = "00:00:00";
};

int main() {
    // ����� ���������� ������� AskTimeServer, ���������, ��� ��� ��� �������� ���������
    TimeServer ts;
    try {
        std::cout << ts.GetCurrentTime() << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Exception got: " << e.what() << std::endl;
    }
    return 0;
}
