

const int hourPin = 8; //location of hour increment button on arduino.//
const int startButton = 12; //location of start button that starts the timer loop.//
const int lightPin = 13; //location of the pin that triggers the relay.//

int hours; //number of hours (later multiplied my milliseconds) the delay lasts.//

int buttonClick();  //protoyped function for increment counter.//
boolean debounce(boolean last); //prototyped function for the hour increment button debouncer.//

// the setup function runs once when you press reset or power the board
void setup() 
{
  pinMode(hourPin, INPUT);
  pinMode(startButton, INPUT);
  pinMode(lightPin, OUTPUT);
  Serial.begin(9600);

  hours = buttonClick();
  
  Serial.print("Hours entered: ");
  Serial.print(hours); 
}

// the loop function runs over and over again forever
void loop() 
{
  digitalWrite(lightPin, HIGH);  
  
  unsigned long onTime = (3600000 * hours);  //1 hr (in ms) for each button click//
  
  delay(onTime);             
  digitalWrite(lightPin, LOW); 
  
  unsigned long offTime = (86400000 - onTime);  //24 hr (in ms) - time lights are on//
  
  delay(offTime);            
}
