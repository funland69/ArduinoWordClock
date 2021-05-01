/*
RTC Funktionen zur Steuerung der RTC DS1308
 */
void TimeRead(){
  Wire.beginTransmission(RTC_ADDRESS);
  Wire.write(0x00);               // Pointer auf Sekunden
  Wire.endTransmission();
  Wire.requestFrom(RTC_ADDRESS, 3);
  ss= bcdToDec(Wire.read());
  mm= bcdToDec(Wire.read());
  hh= bcdToDec(Wire.read());

}

void HourRead(){
  Wire.beginTransmission(RTC_ADDRESS);
  Wire.write(0x02);               // Pointer auf Sekunden
  Wire.endTransmission();
  Wire.requestFrom(RTC_ADDRESS, 1);
  hh= bcdToDec(Wire.read());
  //Serial.println("Stundenlesen");
}

void MinuteRead(){
  Wire.beginTransmission(RTC_ADDRESS);
  Wire.write(0x01);               // Pointer auf Sekunden
  Wire.endTransmission();
  Wire.requestFrom(RTC_ADDRESS, 1);
  mm= bcdToDec(Wire.read());
  //Serial.println("Minutenlesen");
}

void SecondRead(){
  Wire.beginTransmission(RTC_ADDRESS);
  Wire.write(0x00);               // Pointer auf Sekunden
  Wire.endTransmission();
  Wire.requestFrom(RTC_ADDRESS, 1);
  ss=bcdToDec(Wire.read() & 0x7f);
  //Serial.println("Sekundenlesen");
}

void RTC_Set(){
  Wire.beginTransmission(RTC_ADDRESS);
  Wire.write(0x00);
  Wire.write(decToBcd(ss));    // 0 to bit 7 starts the clock
  Wire.write(decToBcd(mm));
  Wire.write(decToBcd(hh));      // If you want 12 hour am/pm you need to set
  Wire.endTransmission();
}

void RTC_Start(){
  Wire.beginTransmission(RTC_ADDRESS);
  Wire.write(0x00);
  Wire.write(decToBcd(ss));    // 0 to bit 7 starts the clock
  Wire.endTransmission();
}

byte decToBcd(byte val)
{
  return ((val/10)<<4)+(val%10);
}

// Convert binary coded decimal to normal decimal numbers
byte bcdToDec(byte val)
{
  return ((val>>4)*10)+val%16;
}


void SaveByte(byte x,byte y){                       // Funktion SaveByte("Position","Daten") Daten in Byte Format
  Wire.begin();                                     // Start I2C Kommunikation
  Wire.beginTransmission(RTC_ADDRESS);              // Beginn Kommunikation auf  Adresse 0x68 
  Wire.write(x+7);                                // Speicher Register Adresse+0x07   
  Wire.write(y);                                     // zu Speicherndes Byte
  Wire.endTransmission();  
}

byte ReadByte(byte x){                             // Funktion ReadByte ("Position") Daten in Byte Format
  byte z;
  Wire.beginTransmission(RTC_ADDRESS);
  Wire.write(x+7);
  Wire.endTransmission();
  Wire.requestFrom(RTC_ADDRESS, 1);
  z=Wire.read();
  return z;
}



