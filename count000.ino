#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "0DwXymzDGTDY88-lSFxW1bljoQiSXdWx";

char ssid[] = "Camwifi";
char pass[] = "eeeeeeee";

int count = 0;
int sensor = 1;

WidgetLCD lcd(V0);

void setup()
{
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass, "blynk.iot-cm.com", 8080);

  pinMode(D0, INPUT);
  
  lcd.clear();
  lcd.print(4, 0, "621320104");
  lcd.print(1, 1, "APICHAI BUTDEE");
  delay(2000);
  lcd.clear();
  lcd.print(4, 0, "READY");
}

void loop()
{
  Blynk.run();
  sensor = digitalRead(D0);
  if(sensor == 0){
    count = count + 1;
    lcd.clear();
    lcd.print(1, 0, "Counting...");
    lcd.print(1, 1, "Count : ");
    lcd.print(9, 1, count);
    delay(500);
  }
  
}