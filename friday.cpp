/*
ID: ichangs1
PROG: friday
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream fout ("friday.out");
    ifstream fin ("friday.in");
    int years, startyr, endyr, tracker, currentday;
    fin >> years;
    startyr = 1900;
    endyr = startyr + years - 1;
    tracker = 2; //tracker % 7 == 0 - Saturday... tracker % 7 == 6 - Friday
    int regmonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int leapmonth[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; //if current year % 4 == 0 && current year % 100 != 0, we use this
    int days[7] = {0}; //Former error lay in here: you MUST intialize it this way to fill the array with all zeros...
    for(int i = startyr; i <= endyr; i++){
        if((i % 4 != 0) || (i % 100 == 0 && i % 400 != 0))  {
            for(int j = 0; j < 12; j++){
                for(int currentday = 1; currentday <= regmonth[j]; currentday++){
                    if(currentday == 13){
                        days[tracker % 7]++;
                    }
                    tracker++;
                }
            }
        }
        else{
            for(int j = 0; j < 12; j++){
                for(int currentday = 1; currentday <= leapmonth[j]; currentday++){
                    if(currentday == 13)
                        days[tracker % 7]++;
                    tracker++;
                }
            }
        }
    }
    for(int i = 0; i < 6; i++){
        fout << days[i] << " ";
    }
    fout << days[6] << endl;
    return 0;
}
