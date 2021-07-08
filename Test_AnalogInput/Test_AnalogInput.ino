const int analogIn = 0;
float inputValue = 0;
float voltage = 0;
const float conversion_factor=331.84;

void setup(){
  Serial.begin(115200);
}

void loop(){
  inputValue = analogRead(analogIn);
  Serial.println(inputValue);
  voltage = inputValue/conversion_factor;
  Serial.println(voltage);
  delay(500);
}
