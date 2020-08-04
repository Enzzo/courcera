#include <iostream>
#include <exception>
#include <string>

std::string AskTimeServer() {
    /* ƒл€ тестировани€ повставл€йте сюда код, реализующий различное поведение этой функии:
       * нормальный возврат строкового значени€
       * выброс исключени€ system_error
       * выброс другого исключени€ с сообщением.
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
        /* –еализуйте этот метод:
            * если AskTimeServer() вернула значение, запишите его в last_fetched_time и верните
            * если AskTimeServer() бросила исключение system_error, верните текущее значение
            пол€ last_fetched_time
            * если AskTimeServer() бросила другое исключение, пробросьте его дальше.
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
    // ћен€€ реализацию функции AskTimeServer, убедитесь, что это код работает корректно
    TimeServer ts;
    try {
        std::cout << ts.GetCurrentTime() << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Exception got: " << e.what() << std::endl;
    }
    return 0;
}
