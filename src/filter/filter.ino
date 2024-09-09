
void setup() {
	Serial.begin(9600);
}

void loop() {
	int sensorValue = analogRead(A0);
	float filteredValue =0;
	for (int i = 0; i < 100; i++) {
		filteredValue += analogRead(A0);
		delayMicroseconds(100);
	}
	filteredValue /= 100;

	//Serial.print(sensorValue);
	//Serial.print(",");
	Serial.println(filteredValue);
	delay(100);
}
