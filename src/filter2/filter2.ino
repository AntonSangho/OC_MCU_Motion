#define num 20
float sensorValues[num];

void setup() {
	Serial.begin(9600);
}

void loop() {
	for (int i = 0; i < num -1; i++) {
		sensorValues[i] = sensorValues[i + 1];
	}
	sensorValues[num - 1] = analogRead(A0);
	float filteredValue;
	for (int i = 0; i < num; i++) {
		filteredValue += sensorValues[i];
	}
	filteredValue /= num;
	delay(100);
	Serial.print(sensorValues[num - 1]);
	Serial.print(",");
	Serial.println(filteredValue);
}
