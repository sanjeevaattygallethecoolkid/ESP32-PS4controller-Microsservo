# ESP32-PS4controller-Microsservo
An ESP32 project using MAC addresses and Bluetooth. Without a joystick module, I used a PS4 controller to control a servo through its left analogue stick. Using ESP32Servo and PS4Controller lib, I mapped joystick inputs to servo angles. I plan to expand this project while learning more about embedded systems and hardware control.

How It Works
- ESP32: Acts as the controller's Bluetooth connection target.
- PS4 Controller: Provides horizontal joystick input through the PS4Controller library.
- Servo Motor: Connected to GPIO 23 and controlled using the ESP32Servo library.
- Joystick Input: The left stick's horizontal axis ranges from -128 to 127 and is mapped to a servo angle between 180° and 0°.
- Deadzone: Small joystick movements near the centre are ignored to reduce unwanted movement.


Libraries Used
- PS4Controller
- ESP32Servo
