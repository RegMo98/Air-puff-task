/* 
  Bonsai signal as input

  Using a binary signal receive from bonsai, turn on a external LED.
 
*/
// name the varaibles we are using:

//bonsai input:
const int detect = 22;
const int led = 13;
const int stim = 5;


// variables will change:
int state;

// the setup function runs once when you press reset or power the board
void setup() {
  pinMode(detect, INPUT_PULLUP);
  pinMode(led, OUTPUT);
  pinMode(stim, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  state= digitalRead(detect);
  Serial.println(state);
  // if state is activated state is high  turn on led ans stim
  if (state == HIGH) {
    //maybe insert a delay for better positioning
    digitalWrite(stim, LOW);
    digitalWrite(led,HIGH);
    //time of the TTL
    delay(200);
    digitalWrite(stim,HIGH);
    digitalWrite(led,LOW);
    //refractory period after a stim is delivered 10s
    delay(10000);
  }
  else {
    digitalWrite(stim,HIGH);
    digitalWrite(led,LOW);
  }
}
