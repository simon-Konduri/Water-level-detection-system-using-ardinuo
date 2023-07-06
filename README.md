# Water-level-detection-system-using-ardinuo
Title: Water Level Detection System with Arduino


The Water Level Detection System is an Arduino-based project that helps monitor and detect the water level in a tank or container. It utilizes various sensors and components to provide accurate measurements and visual feedback using LEDs.

**Components Used:

Arduino Uno board: The Arduino Uno acts as the brain of the system, controlling the sensors and the output devices.
DHT Sensor: The DHT sensor is used to measure the ambient temperature and humidity. It provides environmental data that can be useful for further analysis or monitoring.
LED: LEDs are used to indicate the water level. Different colors can be used to represent different water level states, such as green for normal, yellow for caution, and red for critical.
Ultrasonic Sensor (HC-SR04): The ultrasonic sensor is used to measure the distance from the sensor to the water surface. By calculating the difference between the maximum tank height and the measured distance, the system can determine the water level accurately.


**Functionality:

The Arduino board is connected to the DHT sensor and the ultrasonic sensor.
The ultrasonic sensor emits ultrasonic waves, which bounce back when they encounter the water surface, allowing the Arduino to calculate the distance to the water level.
The Arduino processes the distance data from the ultrasonic sensor and compares it with predefined thresholds to determine the water level status.
Based on the water level status, the Arduino controls the LED to display the corresponding color, indicating the water level condition.
Additionally, the DHT sensor measures temperature and humidity, which can be displayed or logged for further analysis.
