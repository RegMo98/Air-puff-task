/* 
  Bonsai signal as input

  Using a binary signal receive from bonsai, turn on a external LED.
 
*/
// name the varaibles we are using:

//bonsai input:
const int detect = 22;
const int led = 13;
const int stim = 5;
const int opto = 50;

// variables will change:
int state;

// the setup function runs once when you press reset or power the board
void setup() {
  pinMode(detect, INPUT_PULLUP);
  pinMode(led, OUTPUT);
  pinMode(stim, OUTPUT);
  pinMode(opto, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  state= digitalRead(detect);
  Serial.println(state);
  // if state is activated state is high  turn on led and stim
  if (state == HIGH) {
    //maybe dinsert a delay for better positioning
    digitalWrite(opto, HIGH);
    delay(100); //delay with opto light ON waiting for airpuff
    digitalWrite(stim, LOW);
    digitalWrite(led,HIGH);
    //time of the TTL for opto
    delay(200);
    digitalWrite(stim,HIGH);
    digitalWrite(led,LOW);
    delay(700);
    digitalWrite(opto,LOW);
    
    //refractory period after a stim is delivered
    delay(5000);
  }
  else {
    digitalWrite(opto,LOW);
    digitalWrite(led,LOW);
    digitalWrite(stim,HIGH);
  }
}
