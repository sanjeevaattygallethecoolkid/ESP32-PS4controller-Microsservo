#include <PS4Controller.h>
#include <ESP32Servo.h>

Servo myServo;

const int SERVO_PIN = 23;

// Replace this with the ESP32 Bluetooth MAC
// address that your controller was paired to.
const char* ESP32_MAC = "a2:fe:f2:9a:12:17";

void setup()
{
    Serial.begin(115200);

    myServo.setPeriodHertz(50);
    myServo.attach(SERVO_PIN, 500, 2400);
    myServo.write(90);

    PS4.begin(ESP32_MAC);

    Serial.println("Waiting for PS4 controller...");
}

void loop()
{
    if (PS4.isConnected())
    {
        // Left stick horizontal axis: -128 to 127
        int stickX = PS4.LStickX();

        // Ignore small movements around the centre
        if (abs(stickX) < 10)
        {
            stickX = 0;
        }

        int angle = map(stickX, -128, 127, 180, 0);

        myServo.write(angle);

        Serial.print("Stick X: ");
        Serial.print(stickX);
        Serial.print(" | Servo angle: ");
        Serial.println(angle);
    }
    else
    {
        myServo.write(90);
    }