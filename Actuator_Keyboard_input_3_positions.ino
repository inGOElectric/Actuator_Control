//delay(4164); Time required for full extraction!
//8 = IN1; 9 = IN2
//Extending:  digitalWrite(8,LOW); digitalWrite(9,HIGH);
//Contracting:  digitalWrite(8,HIGH); digitalWrite(9,LOW);
//0.8V to 4.2V maps to 0 to 50mm

//Throttle Voltage monitoring
int analogInput = A2; //throttle input
float Vout = 0.00;
float Vin = 0.00;
float R1 = 420.00;
float R2 = 270.00;
int val = 0;
int pos;
float caseposition=0;
int timel;

void setup() {
  pinMode(analogInput, INPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  Serial.begin(9600);
  Serial.println("Enter values 3 = 36mm; 4 = 42mm, 5 = 50mm;");
}
void contract() {
  digitalWrite(8,HIGH); 
  digitalWrite(9,LOW);
}
void extend() {
  digitalWrite(8,LOW); 
  digitalWrite(9,HIGH);
}

void nopower() {
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
}
void loop() {

  val = analogRead(analogInput); // reads the analog input
  Vout = (val * 4.95) / 1024.00;
  Vin = Vout / (R2/(R1+R2));
  pos = map(Vin, 3.36, 4.25, 38, 50);
  //Serial.print(pos); Serial.println(" mm");
  if (Serial.available() > 0) {
    int iB = Serial.read();
    switch (iB) {
      case 51:
        caseposition = 38;
        Serial.println("Changing position to 38mm");
        if(pos>30) {
          timel = ((pos - caseposition)/12)*1000;
          Serial.println(timel);
          contract();
          delay(timel);
          nopower();
          delay(1000);
         }
        else {
          timel = -((pos - caseposition)/12)*1000;
          Serial.println(timel);
          extend(); 
          delay(timel);
          nopower();
          delay(1000);
         }
        break;
      case 52:
        caseposition = 43;
        Serial.println("Changing position to 42mm");
        if(pos>40) {
          timel = ((pos - caseposition)/12)*1000;
          Serial.println(timel);
          contract();
          delay(timel);
          nopower();
          delay(1000);
         }
        else {
          timel = -((pos - caseposition)/12)*1000;
          Serial.println(timel);
          extend(); 
          delay(timel);
          nopower();
          delay(1000);
         }
        break;
      case 53:
        caseposition = 50;
        Serial.println("Changing position to 50mm");
        if(pos>50) {
          timel = ((pos - caseposition)/12)*1000;
          Serial.println(timel);
          contract();
          delay(timel);
          nopower();
          delay(1000);
         }
        else {
          timel = -((pos - caseposition)/12)*1000;
          Serial.println(timel);
          extend(); 
         }
        break;
    }
  }
}
