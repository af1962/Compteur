#include <SoftwareSerial.h>

SoftwareSerial Serial(4,3); // RX ,TX
int compteur=0;
int capteur = 1; // bouton en broche 2
int etatBp; // L'état du bouton
int memoire = HIGH; // La mémoire de l'état du bouton

String str="";
int increment = 0;


void setup() {
 Serial.begin(9600);
 Serial.setTimeout(100);
 pinMode(capteur,INPUT);
}

void loop() {
  str=Serial.readString();
  etatBp = digitalRead(capteur);
  if((etatBp != memoire) && (etatBp == HIGH))
    {
       compteur++;    
    Serial.print("cpt.val=");
    Serial.print(compteur);  
    Serial.write(0xFF);
    Serial.write(0xFF);
    Serial.write(0xFF);   
  }
   memoire = etatBp;  
    delay(100);
  

// Raz en appuyant sur l'écran
  if(str=="raz"){
    compteur=0;
    Serial.print("cpt.val=");
    Serial.print(compteur);  
    Serial.write(0xFF);
    Serial.write(0xFF);
    Serial.write(0xFF);
  }
    

}
