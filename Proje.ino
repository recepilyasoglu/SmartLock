
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <Blynk.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>

Servo smartLock;

char auth[] = "your blynk password";

char ssid[] = "your telephone name";
char pass[] = "your telephone password";


void setup() {
 
  Serial.begin(9600);
  
  Blynk.begin("your blynk password", "your telephone name", "your telephone password");

  smartLock.attach(1);


}

BLYNK_WRITE(V2)
{
  int pinValue = param.asInt();// pin V1'den bir değişkene gelen değer atama
  Serial.print("Kapı Durumu: ");
  Serial.println("Açıldı");
     
 
  Blynk.virtualWrite(V0, "Kapı Durumu");
        
  Blynk.email("useraccount@gmail.com",String("Kapınızın Kilidi Açıldı"));
  Blynk.virtualWrite(V1, "Açık");    
                
      servo();

}

BLYNK_WRITE(V3)
{
    int pinValue2 = param.asInt(); //pin V2'den bir değişkene gelen değer atama
    Serial.print("Kapı Durumu: ");
    Serial.println("Kilitli");

    Blynk.virtualWrite(V0, "Kapı Durumu");
    Blynk.email("useraccount@gmail.com",String("Kapınızın Kilidi Kapatıldı"));
    Blynk.virtualWrite(V1, "Kilitli");

    smartLock.write(180);
    
  
  
}

void loop()
{
  Blynk.run();  // Commented out for a short time.
}

void servo()
{
  smartLock.write(70);
}
