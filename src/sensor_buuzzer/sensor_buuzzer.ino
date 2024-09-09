const int buzzerPin = 12; // Define the pin for the buzzer

void setup() {
    Serial.begin(9600);
    pinMode(buzzerPin, OUTPUT); // Set the buzzer pin as an output
}

void loop() {
    int sensorValue = analogRead(A0);
    float filteredValue = 0;
    for (int i = 0; i < 100; i++) {
        filteredValue += analogRead(A0);
        delayMicroseconds(100);
    }
    filteredValue /= 100;

    //Serial.print(sensorValue);
    //Serial.print(",");
    Serial.println(filteredValue);

    if (filteredValue > 100) {
    	tone(buzzerPin, 1000); // Turn the buzzer on
    } else {
	noTone(buzzerPin); // Turn the buzzer off
    }

    delay(100);
}
