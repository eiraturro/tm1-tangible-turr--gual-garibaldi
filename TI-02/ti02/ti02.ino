const int BUTTON_PIN = 2;
const int LED_PIN = 10;
// LED I BUTTON
int lastState = HIGH;  // Recordem l'estat anterior del botó (no premut)
bool on = false;       // El LED comença apagat (false = apagat)


void setup() {

  // POTENCIOMETRE/SERIAL
  Serial.begin(9600);  // inicialitzar serial

  // LED I BUTTON
  pinMode(BUTTON_PIN, INPUT_PULLUP);  // Configurem el botó com a entrada
  pinMode(LED_PIN, OUTPUT);           // Configurem el LED com a sortida
}


void loop() {

  // POTENCIOMETRE/SERIAL
  int raw = analogRead(A0);               // Llegim el potenciometre
  int level = map(raw, 0, 1023, 0, 255);  // Convertim el valor a brillantor
  level = constrain(level, 50, 255);       // Limitem el valor entre 0 i 255
  Serial.println(raw);                    // Mostrem el valor al Serial Monitor

  // LED I BUTTON
  int state = digitalRead(BUTTON_PIN);  // Llegim l'estat actual del botó

  if (lastState == HIGH && state == LOW) {  // Detectem quan premem el botó
    on = !on;                               // Canviem l'estat: encès passa a apagat i a l'inrevés
    delay(30);                              // Esperem 30 mil·lisegons per evitar errors de lectura
  }
  lastState = state;
  // CONTROL DE LA BRILLANTOR
  if (on) {
    analogWrite(LED_PIN, level);  // LED encès amb brillantor regulable
  } 
  else {
    analogWrite(LED_PIN, 0);  // LED apagat
  }
}
