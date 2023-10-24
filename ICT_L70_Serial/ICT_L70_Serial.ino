/*
  SerialPassthrough sketch

  

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/SerialPassthrough
  https://www.youtube.com/watch?v=M2E2yWcKJfc&t=463s #billacceptor-
  https://www.youtube.com/watch?v=M2E2yWcKJfc
  https://kriss-sport.com/dl-files/thirdParty/bv20_operations_manual.pdf
  https://www.youtube.com/watch?v=gegpO70tos8

  PIN 2 rx
  PIN 3 TX
  PIN 5 GND

  PIN 15 rx3
  PIN 14 tx3
  //USE IC TTL MAX 232
*/
#define NoteAcceptor Serial3

int credit = 0;
int pushButton = 4;
int pushButton2 = 5;
const int ledPin = 13;    // the number of the LED pin
int incomingByte = 0;   
byte noteInEscrow = 0;
//byte channelValues[] = [5, 10, 20];

const byte numBytes = 32;
byte receivedBytes[numBytes];
byte numReceived = 0;

void setup() {
  Serial.begin(9600);
  //Serial1.begin(300, SERIAL_8N2);
  pinMode(15, INPUT_PULLUP); //PULL UP SERIAL RX PIN
  //pinMode(15, INPUT); //PULL DOWN SERIAL RX PIN
  pinMode(pushButton, INPUT_PULLUP); 
  pinMode(pushButton2, INPUT_PULLUP); 
  // NoteAcceptor.begin(300, SERIAL_8N2);
  NoteAcceptor.begin(9600, SERIAL_8E1);
  pinMode(ledPin, OUTPUT);
  //NoteAcceptor.write(170);//enable escrow
  //NoteAcceptor.write(171);//Disable escrow
  //NoteAcceptor.write(62);//enable all channel
  //NoteAcceptor.write(185);//Disable all channel
  // NoteAcceptor.write(0x3E);
  //NoteAcceptor.write(0x3E);
}

void loop() {
  if (Serial.available()) {        // If anything comes in Serial (USB),
  byte byteln2 = Serial.read();
  if (byteln2 == 185){
    //Serial.println(byteln);//give back
  } 
  
  if (byteln2 ==  89){
    digitalWrite(ledPin, HIGH);
    delay(1000);
    digitalWrite(ledPin, LOW);
  }
  if (byteln2 == 'Y'){
    NoteAcceptor.write(02);
    digitalWrite(ledPin, HIGH);
    delay(5000);
    digitalWrite(ledPin, LOW);
    
  }
  if (byteln2 == 'E'){//enable Test
   NoteAcceptor.write(62);
    digitalWrite(ledPin, HIGH);
    delay(5000);
    digitalWrite(ledPin, LOW);
   
  }
   if (byteln2 == 'D'){//Disable Test
   NoteAcceptor.write(94);
    digitalWrite(ledPin, HIGH);
    delay(5000);
    digitalWrite(ledPin, LOW);
    
  }
  
    //NoteAcceptor.write(Serial.read());  // read it and send it out Serial1 (pins 0 & 1)
    //Serial.print("I received x: ");
    
    //Serial.println( Serial.read());
    //Serial.println("**byteIn2**");

    // if (Serial.available() > 0) {
      // read the incoming byte:
      //incomingByte = Serial.read();

      // say what you got:
    //  Serial.print("I received: ");
      //Serial.println(incomingByte, DEC);
   // }
  }
  /*
    // if (byteInx == 255){
    //   digitalWrite(ledPin, HIGH);
    //   delay(5000);
    //   digitalWrite(ledPin, LOW);
    // }
  }*/
  int buttonState = digitalRead(pushButton);
  int buttonState2 = digitalRead(pushButton2);
  // if (buttonState){
  // Serial.println(buttonState);
  // delay(5000);
  // }
  if (buttonState2){//manual Test
  Serial.println(4);
  delay(5000);
  }
  delay(1);
  if (NoteAcceptor.available()) {       // If anything comes in Serial1 (pins 0 & 1)
    
    //Serial.write(Serial1.read());  // read it and send it out Serial (USB)
    byte byteIn = NoteAcceptor.read();
    //incomingByte = NoteAcceptor.read();
    //Serial.println("**in**");
    Serial.println(byteIn);
    Serial.println("**byteIn**");
    if (byteIn == 128){
      //Serial.println("**Suckes**");
      NoteAcceptor.write(02); //enable cash acceptor
    }

    //NoteAcceptor.write(02);
    //Serial.println(byteIn,HEX);
    //Serial.println("**Byte Hex**");
    /*44h 68D 20K
    45H 69D 50K */
    switch (byteIn) {
      case 70:
        // statements
        Serial.println("**100K**");
        break;
      case 69:
        // statements
         Serial.println("**50K**");
        break;
      case 68:
        // statements
         Serial.println("**20K**");
        break;
      case 67:
        // statements
         Serial.println("**10K**");
        break;
      case 66:
        // statements
         Serial.println("**5K**");
        break;
      default:
        // statements
        break;
    }

    
  }
}