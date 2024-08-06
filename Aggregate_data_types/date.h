#pragma once

class date{
    public:
        void getDate();
        void getDay();
        void getMonth();
        void setDate(int month, int day);
    private:
        int month;
        int day;
};