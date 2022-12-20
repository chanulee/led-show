// Code to send and receive data from openFrameworks
int ledPins[] = {11,10,9,6,5};
const int FLEX_PIN = A2; // Pin connected to voltage divider output
const int X_PIN = A0;
const int Y_PIN = A1;

char msg;
int msgInt;
int b;
int t;
int anglePlus = 160;

int xValue = 0 ;
int yValue = 0 ;

const float VCC = 4.98;
const float R_DIV = 47500.0;

const float STRAIGHT_RESISTANCE = 37300.0; // resistance when straight
const float BEND_RESISTANCE = 90000.0;

void setup() {
  // Start the serial communication
  for (int i = 0; i<5; i++){    
    pinMode(ledPins[i], OUTPUT);
  }
    pinMode(FLEX_PIN, INPUT);
  pinMode(X_PIN, INPUT);
  pinMode(Y_PIN, INPUT);
  Serial.begin(9600);
}

void loop() {


  
  if (Serial.available()>0) { //when serial works
    //read from oF
    msg=Serial.read();
    msgInt = msg -'0'-1;

    switch (msgInt) {
      case 0:
          for(int n=0; n<5;n++){
              for (int i = 0; i<=250; i++) {
              analogWrite (ledPins[n], i);
              delay(1);
            }
          }
          for(int n=0; n<5;n++){
            for (int i = 250; i>=0; i--) {
              analogWrite (ledPins[n], i);
              delay(1);
            }
          }
        break;    
      case 1: 
      yValue = 0;
      while(yValue<800){ 
          xValue = analogRead(X_PIN) ;  
          yValue = analogRead(Y_PIN) ; 
                  if(xValue<240){
              for (int i = 0; i<5; i++) {
              analogWrite (ledPins[i], 0);
            }
          analogWrite (ledPins[4], 255);
        }
        if((xValue >= 240) && (xValue < 440)){
          for (int i = 0; i<5; i++) {
              analogWrite (ledPins[i], 0);
            }
          analogWrite (ledPins[3], 255);
        }
       if((xValue >= 440) && (xValue < 640)){
          for (int i = 0; i<5; i++) {
              analogWrite (ledPins[i], 0);
          }
          analogWrite (ledPins[2], 255);
        }
               if((xValue >= 640) && (xValue < 800)){
          for (int i = 0; i<5; i++) {
              analogWrite (ledPins[i], 0);
          }
          analogWrite (ledPins[1], 255);
        }
        if(xValue >= 800){
          for (int i = 0; i<5; i++) {
              analogWrite (ledPins[i], 0);
          }
          analogWrite (ledPins[0], 255);
        }
      }
                for (int i = 0; i<5; i++) {
              analogWrite (ledPins[i], 0);
          }
      break; 

      case 2:
              for (int i = 0; i<=250; i++) {
              analogWrite (ledPins[2], i);
              delay(1);
              }
              for (int i = 0; i<=250; i++) {
                analogWrite (ledPins[1], i);
                analogWrite (ledPins[3], i);
                delay(1);
              }
              for (int i = 250; i>=0; i--) {
                analogWrite (ledPins[2], i);
                delay(1);
              }
              for (int i = 0; i<=250; i++) {
                analogWrite (ledPins[0], i);
                analogWrite (ledPins[4], i);
                delay(1);
              }
              for (int i = 250; i>=0; i--) {
                analogWrite (ledPins[1], i);
                analogWrite (ledPins[3], i);
                delay(1);
              }
              for (int i = 250; i>=0; i--) {
                analogWrite (ledPins[0], i);
                analogWrite (ledPins[4], i);
                delay(1);
              }
        break;
      case 3:
        while(anglePlus>150){
            int flexADC = analogRead(FLEX_PIN);
  
  float flexV = flexADC * VCC / 1023.0;
  int flexR = R_DIV * (VCC / flexV - 1.0);
  float angle = map(flexR, STRAIGHT_RESISTANCE, BEND_RESISTANCE,
                   0, 180.0);  // bend angle
  int anglePlus = -angle-50;
          analogWrite(ledPins[3], anglePlus);
        }
                        for (int i = 0; i<5; i++) {
              analogWrite (ledPins[i], 0);
          }
        break;
       case 4:
        analogWrite(ledPins[4], 255);
        break;
        
      default:
        break;
    }
  }
    delay(10);
}
