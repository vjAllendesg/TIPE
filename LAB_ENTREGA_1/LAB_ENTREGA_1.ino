// Constantes pines
const int pinBulb = 5 ;
const int pinFan = 6;
const int pinNTC = 0 ;


// Constantes NTC1
const float R1 = 100000.0;  // R divisor
const float Beta = 4267.0;   // Valor constante
const float Tk = 298.15;     // temperatura en k de 25°c
const float R25 = 100000.0;   // resistencia del ntc en 25°
const float Vs = 5.;         // fuente de volt

// Constantes Delay
const float tDelay1 = 100;
const float tDelay2 = 100;
const float tDelay3 = 100;

void setup() {
  
  
  pinMode(0, INPUT);

} 

void loop() {
  // put your main code here, to run repeatedly:
}




void Bulb(){
  int bulbPower = 0;
  if (Serial.available() > 0) {
    bulbPower = Serial.parseInt();  // Lee un número enviado
    bulbPower = constrain(bulbPower, 0, 255); // límite válido
    analogWrite(pinBulb, bulbPower);    // Modifica el PWM del LED
    Serial.println(bulbPower);
  }
}


void Fan(){
  int fanPower = 0;
  if (Serial.available() > 0) {
    fanPower = Serial.parseInt();  // Lee un número enviado
    fanPower = constrain(fanPower, 0, 255); // límite válido
    analogWrite(pinFan, fanPower);    // Modifica el PWM del LED
    Serial.println(fanPower);
  }
}

//Hola a todos


void Temperatura() {
  //TEMPERATURA NTC STEINHART
  int input = analogRead(pinNTC);
  float V0 = input * Vs / 1023.0;
  float R_NTC = (R1 * Vs - V0 * R1) / V0;
  float t = 1 / (1 / Tk + (1 / Beta) * (log(R_NTC / R25)));  //Temperatura en K Steinhart
  t = t - 273.15;
}


