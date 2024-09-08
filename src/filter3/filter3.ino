float sensorValue;
float filteredValue;
float sensitivity = 0.1;

void setup() {
	Serial.begin(9600);
	sensroValue = analogRead(A0);
	filteredValue = sensorValue;
}

void loop() {
	sensorValue = analogRead(A0);
	filteredValue = filteredValue * ( 1 - sensitivity ) + sensorValue * sensitivity;

	delay(10);
	Serial.print(sensorValue);
	Serial.print(",");
	Serial.print(filteredValue);

	float cm = 10650.08 * pow(filteredValue, -0.935) - 10;

	Serial.print(",");
	Serial.println(cm);
}
