#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <cmath>

namespace Core {
    class Calculator;
}


typedef struct prayerTime
{
    float Fajr;
    float Sunrise;
    float Noon;
    float Afternoon;
    float Sunset;
    float Dusk;
    prayerTime() : Fajr(0), Sunrise(0), Noon(0), Afternoon(0), Sunset(0), Dusk(0) {}
} PrayerTime;

class Calculator {
    public :
        Calculator(void);
        PrayerTime PrayerTimes(double latitude, double longitude, float altitude, int dayOfYear, float timeZone, int mazhab,  float dawnTwilightAngle, float nightTwilightAngle);
        float QiblaAngle(double latitude, double longitude);
};


#endif // CALCULATOR_H
