const int buttonPin = 2;
const int ledPin = 12;

const unsigned long debounceDelay = 50; 

int buttonState = LOW;           
int lastButtonState = LOW;       
unsigned long lastDebounceTime = 0;  

enum LedState {
  OFF = LOW,
  ON = HIGH
};

void setup() {
  pinMode(ledPin, OUTPUT);        
  pinMode(buttonPin, INPUT);      
  digitalWrite(ledPin, OFF);     
}

void loop() {
  int reading = digitalRead(buttonPin);  

  // Check if the button state has changed
  if (reading != lastButtonState) {
    lastDebounceTime = millis();  // Reset debounce timer
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    // If the button state has changed
    if (reading != buttonState) {
      buttonState = reading;

      // Only toggle LED if the button is pressed
      if (buttonState == HIGH) {
        toggleLed(); 
      }
    }
  }

  lastButtonState = reading;  // Update the last button state
}

void toggleLed() {
  int currentState = digitalRead(ledPin);
  digitalWrite(ledPin, currentState == ON ? OFF : ON);
}
