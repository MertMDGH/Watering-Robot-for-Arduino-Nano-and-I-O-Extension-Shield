#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <Servo.h>
//it is important to include all of those
Servo myServo
void setup() {
  myServo.attach(YOUR_PIN); //The Servo that opens the water flow
}
int main() {
    int last_day = -1;

    while (1) {
        time_t now = time(NULL);
        struct tm *t = localtime(&now);

        if (t->tm_hour ==  YOUR HOUR && t->tm_min == YOUR MINUTE && t->tm_mday != last_day) {
            //Water flows
            myServo.write(90);
            delay(YOUR_WATER_FLOW_TIME);
            myServo.write(0);
            //Water flows
            last_day = t->tm_mday;
        }

        sleep(60);
    }
}
