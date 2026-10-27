# Pinout

| Signal | Sketch definition | Pin |
|---|---|---|
| Right input | `RIGHT` | A2 |
| Left input | `LEFT` | A3 |
| Ultrasonic trigger | `TRIGGER_PIN` | A4 |
| Ultrasonic echo | `ECHO_PIN` | A5 |
| Maximum ultrasonic range | `MAX_DISTANCE` | 200 cm |
| Motor speed constant | `maxSpeed` | 120 |
| Motor channel 1 | `Motor1` | M1 |
| Motor channel 2 | `Motor2` | M2 |
| Motor channel 3 | `Motor3` | M3 |
| Motor channel 4 | `Motor4` | M4 |

The `AFMotor` library maps motor objects to the motor shield channels, not directly to Arduino pins. Check the supplied circuit image and the exact shield revision before wiring.
