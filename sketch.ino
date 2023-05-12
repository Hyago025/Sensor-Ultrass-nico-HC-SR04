#define echo 4
#define trig 5

unsigned long tempo;
double distancia;
int Buzzer = 7;
int LedVerde = 10;
int LedAmarelo = 9;
int LedVermelho = 8;
   
void setup() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(LedVerde,OUTPUT);
  pinMode(LedAmarelo,OUTPUT); 
  pinMode(LedVermelho,OUTPUT);
  pinMode(Buzzer,OUTPUT);
  Serial.begin(9600);
  digitalWrite(trig, LOW);
}

void loop () {
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);  
  tempo = pulseIn(echo, HIGH);  
  distancia = tempo/58;  
  Serial.println(distancia);

if (distancia <=100) { 
    digitalWrite(LedVermelho ,HIGH);
    digitalWrite(LedAmarelo ,LOW);
    digitalWrite(LedVerde ,LOW);
    tone(7,329,100);
  	delay(distancia*10);
}
  if (distancia >100 and distancia <200) { 
    digitalWrite(LedAmarelo ,HIGH);
    digitalWrite(LedVermelho ,LOW);
    digitalWrite(LedVerde ,LOW);
    noTone(Buzzer); 
}
   if (distancia >=200) { 
    digitalWrite(LedVerde ,HIGH);
    digitalWrite(LedVermelho ,LOW);
    digitalWrite(LedAmarelo ,LOW);
    noTone(Buzzer);  
 } 
}
