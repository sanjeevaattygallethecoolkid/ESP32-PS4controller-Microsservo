# ESP32-PS4controller-Microsservo
An ESP32 project using MAC addresses and Bluetooth. Without a joystick module, I used a PS4 controller to control a servo through its left analogue stick. Using ESP32Servo and PS4Controller lib, I mapped joystick inputs to servo angles. I plan to expand this project while learning more about embedded systems and hardware control.

Important... some issues I had & fixes
- When changing the MAC address of the controller use the sixaxispair tool, make sure the micro usb actually transfers data and doesn't just charge the ps4 controller. This is not an issue I had but because not all micro usb's transfer data I thought this could be a potential problem.
- My one and only issue was that my controller wouldn't connect, code was fine to I checked my baud rate was set at 115200 which it was. So I changed the version of my ESP32 to a later model (ESP32 by Espressif systems) to 2.0.17. After that I was able to move the servo through the controller's joystick. Still not exactly sure how that fixed it? could someone tell me lol

How It Works
- ESP32: Acts as the controller's Bluetooth connection target.
- PS4 Controller: Provides horizontal joystick input through the PS4Controller library.
- Servo Motor: Connected to GPIO 23 and controlled using the ESP32Servo library.
- Joystick Input: The left stick's horizontal axis ranges from -128 to 127 and is mapped to a servo angle between 180° and 0°.
- Deadzone: Small joystick movements near the centre are ignored to reduce unwanted movement.

Libraries Used
- PS4Controller
- ESP32Servo
