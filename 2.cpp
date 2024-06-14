#include <iostream>
#include <ctime>

using namespace std;

int main() {
    // تاریخ تولد را وارد کنید
    int year, month, day;
    cout << "Enter your birth year: ";
    cin >> year;
    cout << "Enter your birth month: ";
    cin >> month;
    cout << "Enter your birth day: ";
    cin >> day;

    // محاسبه تاریخ حال
    time_t now = time(0);
    tm* current_time = localtime(&now);
    int current_year = current_time->tm_year + 1900;
    int current_month = current_time->tm_mon + 1;
    int current_day = current_time->tm_mday;

    // محاسبه سن
    int age = current_year - year;
    if (current_month < month || (current_month == month && current_day < day)) {
        age--;
    }

    // محاسبه تعداد روزها، ساعت‌ها، دقایق و ثانیه‌ها
    int total_days = age * 365 + (age / 4); // برای سال‌های کبیسه
    int total_hours = total_days * 24;
    int total_minutes = total_hours * 60;
    int total_seconds = total_minutes * 60;

    cout << "You have lived for " << age << " years." << endl;
    cout << "You have lived for " << total_days << " days, " << total_hours << " hours, " << total_minutes << " minutes, and " << total_seconds << " seconds." << endl;

    return 0;
}
