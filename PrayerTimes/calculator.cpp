#include "calculator.h"
#include <cmath>

Calculator::Calculator(void)
{

}
PrayerTime Calculator::PrayerTimes(double latitude, double longitude, float altitude, int dayOfYear, float timeZone, int mazhab, float dawnTwilightAngle, float nightTwilightAngle) {
    PrayerTime result;

    int J = dayOfYear;               // Day of year
    float H = altitude;              // The height above sea level in meters (the altitude above sea level)
    double D = 0;                    // Solar Declination (Degrees)
    double T = 0;                    // Equation of Time (Minutes)
    float Gd = dawnTwilightAngle;    // Dawn’s Twilight Angle (15°-19°)
    float Gn = nightTwilightAngle;   // Night’s Twilight Angle (15°-19°)
    double B = latitude;             // Latitude (Degrees)
    double L = longitude;            // Longitude (Degrees)
    float TZ = timeZone;             // Time Zone (Hours)
    float R = 0;                     // Reference Longitude (Degrees)
    int Sh = 1;                      // Sh=1 (Shafii) - Sh=2 (Hanafi)

    double PI = 3.1415926535897931;
    double beta =  2 * PI * J / 365; // year angle

    D = (180 / PI) * (0.006918 - (0.399912 * cos(beta)) + (0.070257 * sin(beta)) - (0.006758 * cos(2 * beta)) + (0.000907 * sin(2 * beta)) - (0.002697 * cos(3 * beta)) + (0.001480 * sin(3 * beta)));
    T = 229.18 * (0.000075 + (0.001868 * cos(beta)) - (0.032077 * sin(beta)) - (0.014615 * cos(2 * beta)) - (0.040849 * sin(2 * beta)));
    R = 15 * TZ;
    double Z = 12 + ((R - L) / 15) - (T / 60);
    double U = (180 / (15 * PI)) * acos((sin((-0.8333 - 0.0347 * (H / fabs(H)) * sqrt(fabs(H))) * (PI / 180)) - sin(D * (PI / 180)) * sin(B * (PI / 180))) / (cos(D * (PI / 180)) * cos(B * (PI / 180))));
    double Vd = (180 / (15 * PI)) * acos((-1 * sin(Gd * (PI / 180)) - sin(D * (PI / 180)) * sin(B * (PI / 180))) / (cos(D * (PI / 180)) * cos(B * (PI / 180))));

    double Vn;
    if (Gn > 20) {
        Vn = U + (Gn / 60);
    } else {
        Vn = (180 / (15 * PI)) * acos((-1 * sin(Gn * (PI / 180)) - sin(D * (PI / 180)) * sin(B * (PI / 180))) / (cos(D * (PI / 180)) * cos(B * (PI / 180))));
    }
    double W = (180 / (15 * PI)) * acos((sin(atan(1 / (Sh + tan(fabs(B - D) * PI / 180)))) - sin(D * PI / 180) * sin(B * PI / 180)) / (cos(D * PI / 180) * cos(B * PI / 180)));

    result.Fajr = Z - Vd;
    result.Sunrise = Z - U;
    result.Noon = Z;
    result.Afternoon = Z + W;
    result.Sunset = Z + U;
    result.Dusk = Z + Vn;
    return result;
}

float Calculator::QiblaAngle(double latitude, double longitude) {
    double PI = 3.1415926535897931;
    double B = PI / 180;
    double Klat = 21.423333;
    double Klon = -39.75;
    double sinA = sin((longitude - Klon) * B);
    double cosFdTanFm = cos(latitude * B) * tan(Klat * B);
    double sinFdCosA = sin(latitude * B) * cos((longitude - Klon) * B);
    double cal = sinA / (cosFdTanFm - sinFdCosA);
    double result = atan(cal) / B;
    return result;
}
