# Working Principle

The sketch repeatedly measures ultrasonic distance and reads two digital inputs. It then applies a set of conditional rules to control four motors.

1. **Read distance:** `NewPing` measures the echo time and returns a distance in centimetres.
2. **Read directional inputs:** `RIGHT` (A2) and `LEFT` (A3) are read using `digitalRead()`.
3. **Move forward:** when the distance is above 3 cm and below 15 cm, or both inputs are HIGH.
4. **Turn left:** when right is LOW and left is HIGH. The left-turn routine briefly reverses motors M1/M2 while driving M3/M4 forward.
5. **Turn right:** when right is HIGH and left is LOW. The right-turn routine drives M1/M2 forward and reverses M3/M4.
6. **Stop:** when distance is above 15 cm or at most 3 cm, the motors are set to `RELEASE`.

The program prints distance and input states to Serial Monitor at 9600 baud. Sensor polarity and physical placement determine whether the logic matches the intended tracking behavior.
