# Hardware Components

The following list is based on the firmware and supplied circuit/media. Verify the physical bill of materials before treating this as final.

| Component | Purpose | Notes |
|---|---|---|
| Arduino-compatible board | Runs the control sketch | Exact board model not specified in the supplied code |
| Motor Shield V1-compatible driver | Drives four DC motors | Sketch uses `AFMotor`; verify shield compatibility |
| Four DC motors | Robot locomotion | Voltage/current ratings depend on the actual motors |
| Ultrasonic sensor | Measures distance ahead | Trigger A4, echo A5 |
| Two digital sensing inputs | Directional decision input | Connected to A2 and A3; exact sensor models need confirmation |
| Robot chassis and wheels | Mechanical platform | Match motor mounting and wheel size |
| Battery and wiring | Powers logic and motors | Size for motor stall current; use suitable grounding and protection |

## Power and Safety

Do not power motors directly from Arduino GPIO pins. Confirm the motor driver's current rating and the battery voltage against the motor specifications. Keep motor power and logic wiring correctly grounded as required by the driver.
