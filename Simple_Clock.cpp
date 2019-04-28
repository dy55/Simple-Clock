#include<iostream>
#include<iomanip>
#include<ctime>

using namespace std;

class _clock {
private:
	int hour, min, sec;
public:
	void setTime(int);
	void clockRun(int);
	void clockRing(int, int, int);
};

void _clock::setTime(int utc_plus) {
	tm* gm;
	time_t t = time(NULL);
	gm = gmtime(&t);
	hour = gm->tm_hour + utc_plus;
	min = gm->tm_min;
	sec = gm->tm_sec;
}

void _clock::clockRun(int utc_plus) {
	setTime(utc_plus);
	while(1){
		clockRing(0, 0, 10);
		cout << "\r" << setw(2) << setfill('0') << hour << " : " << setw(2) << setfill('0') << min << " : " << setw(2) << setfill('0') << sec;
		if (++sec >= 60) {
			sec = 0;
			if (++min >= 60) {
				min = 0;
				if (++hour >= 24) {
					hour = 0;
				}
			}
		}
		_sleep(1000);
	}
}

void _clock::clockRing(int min_value, int sec_value, int times) {
	if (min == min_value && sec >= sec_value && sec <= sec_value + times - 1)
		cout << "\a";
}

int main() {
	_clock vir_clock;
	cout << "Current time" << endl << endl;
	vir_clock.clockRun(8);
}