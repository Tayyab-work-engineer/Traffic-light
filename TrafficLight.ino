// C++ code

unsigned long startMillis;  //some global variables available anywhere in the program
unsigned long currentMillis;
const unsigned long periodRed = 2000;  //the value is a number of milliseconds

int button_press = 0;

void setup()
{
  pinMode(10, OUTPUT);
  digitalWrite(10, LOW);
  pinMode(9, OUTPUT);
  digitalWrite(9, LOW);
  pinMode(8, OUTPUT);
  digitalWrite(8, HIGH);
  
  pinMode(3, INPUT_PULLUP);
  
  
  startMillis = millis();
  
  
}

void loop(){
  currentMillis = millis();  //get the current "time" (actually the number of milliseconds since the program started)
  if(digitalRead(3) == LOW){
    button_press = 1;
  }
  if (currentMillis - startMillis >= periodRed){
    if(button_press == 1){
      
    	digitalWrite(10,HIGH);
    	digitalWrite(9, HIGH);
    	digitalWrite(8, LOW);
      
      	delay(1000);
        startMillis = millis(); //update
      	button_press = 0;

    }
  }
  else{
    
    digitalWrite(10,LOW);
    digitalWrite(9, LOW);
    digitalWrite(8, HIGH);
  }
  
}