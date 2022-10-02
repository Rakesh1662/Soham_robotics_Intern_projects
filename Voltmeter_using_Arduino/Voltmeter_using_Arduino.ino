
#include<LiquidCrystal_I2C.h>
//LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C address 0x27, 16 column and 2 rows
//open the backlight

int analogInput = 1;
float Vout = 0.00;
float Vin = 0.00;
float R1 = 10000.00; // resistance of R1 (100K)
float R2 = 100000.00; // resistance of R2 (10K)
int val = 0;
void setup() {
  lcd.begin();                       //initializes the LCD and specifies the dimensions
  lcd.print(" Soham Academy  ");
  lcd.setCursor(0, 1);
  lcd.print("ArduinoVoltmeter");
  delay(5000);
  lcd.clear();
  lcd.print("Arduino Projects");
  lcd.setCursor(0, 1);
  delay(500);
  lcd.clear();
  pinMode(analogInput, INPUT); //assigning the input port
  Serial.begin(9600); //BaudRate
}
void loop() {
  val = analogRead(analogInput);//reads the analog input
  Vout = (val * 5.00) / 1024.00; // formula for calculating voltage out i.e. V+, here 5.00
  Vin = Vout / (R2 / (R1 + R2)); // formula for calculating voltage in i.e. GND
  if (Vin < 0.09) //condition
  {
    Vin = 0.00; //statement to quash undesired reading !
  }
  Serial.print("\t Voltage source = ");
  Serial.println(Vin);
  lcd.print("Voltage Source= ");
  lcd.setCursor(0,1);  
  lcd.print(Vin);
  delay(1000);//for maintaining the speed of the output in serial moniter
  lcd.clear();

} 
