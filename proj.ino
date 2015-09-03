int red = 11;
int green = 10;
int blue = 9;
int i=0;
int j=0;
int width=3;
int initDelay = 5000;
void setup() {
 
 DDRD = B11111111;
 pinMode(red,OUTPUT);
 pinMode(green,OUTPUT);
 pinMode(blue,OUTPUT);
 
}
void loop() {
  
  // put your main code here, to run repeatedly:on 
  // prints the date on July 8th
   delay(initDelay);
   initDelay = 0;

    cse();
    drawLine(B11111111,0,0,0,25);
    date();
    drawLine(B11111111,0,0,0,25);

} 
void date(){ //whole width 114
  setDigit('8');
     drawLine(B01101100, 0,0,0,5);
    setDigit('0');
      drawLine(B01101100, 0,0,0,2);
      drawLine(B01101100, 0,255,0,2);
      drawLine(B01101100, 0,0,0,2);
   setDigit('7');
      drawLine(B01101100, 0,0,0,5);
   setDigit('0');
      drawLine(B01101100, 0,0,0,2);
      drawLine(B01101100, 0,255,0,2);
      drawLine(B01101100, 0,0,0,2);
   setDigit('5');
     drawLine(B01101100, 0,0,0,5);
    setDigit('1');
     drawLine(B01101100, 0,0,0,5);
    setDigit('0');
     drawLine(B01101100, 0,0,0,5);
    setDigit('2');
     drawLine(B01101100, 0,0,0,5);
}
// this function chooses the number to be displayed.
void setDigit(char digit){
   switch(digit){  
    case '0':
      zero();
      break;
     case '1':
      one();
      break;
     case '2':
      two();
      break;
     case '3':
      three();
      break;
     case '4':
      four();
      break;
     case '5':
      five();
      break;
     case '6':
      six();
      break;
     case '7':
      seven();
      break; 
     case '8':
      eight();
      break;
     case '9':
      nine();
      break; 
   } 
  
}
// a function chain of number fro 0 to 9 that will give the pattern to the bulbs.
void zero(){
   drawLine(B01111110,200,200,200,width);
   drawLine(B10000001,200,200,200,width);
   drawLine(B01111110,200,200,200,width);

}
void one(){
   drawLine(B00000011,200,200,200,width);
   drawLine(B11111111,200,200,20,width);
   drawLine(B01100011,200,200,200,width);

}
void two(){
   drawLine(B11110011,200,200,200,width);
   drawLine(B11111111,200,200,200,width);
   drawLine(B11001111,200,200,200,width);

}
void three(){
   drawLine(B11111111,0,0,200,width);
   drawLine(B11011011,0,0,200,width);
   drawLine(B11011011,0,0,200,width);

}
void four(){
   drawLine(B11111111,200,200,200,width);
   drawLine(B00011000,200,200,200,width);
   drawLine(B11111000,200,200,200,width);

}
void five(){
   drawLine(B11011111,200,200,200,width);
   drawLine(B11011011,200,200,200,width);
   drawLine(B11111011,200,200,200,width);

}
void six(){
   drawLine(B10011111,200,200,200,width);
   drawLine(B10011001,200,200,200,width);
   drawLine(B11111111,200,200,200,width);
   
}
void seven(){
 drawLine(B11111111,200,200,200,width);
 drawLine(B11000000,200,200,200,width);
 drawLine(B11000000,200,200,200,width);

}
void eight(){
 drawLine(B11111111,200,200,200,width);
 drawLine(B10011001,200,200,200,width);
 drawLine(B11111111,200,200,200,width);

}
void nine(){
 drawLine(B11111111,200,200,200,width);
 drawLine(B11001000,200,200,200,width);
 drawLine(B11111000,200,200,200,width);

}

// this function will display "cse" on the LED
void cse(){
  // put your main code here, to run repeatedly:
   drawLine(B11111111,255,0,0,5);
   drawLine(B11000011,255,0,0,5);
   drawLine(B11000011,255,0,0,5);
//   drawLine(B11000011,0,0,255,5);
//   drawLine(B11111111,255,255,255,1);
   
   drawLine(B11011111,0,0,0,10);
   
   drawLine(B11011111,255,0,0,5);
   drawLine(B11011011,255,0,0,5);
   drawLine(B11111011,255,0,0,5);
   
   drawLine(B11011111,0,0,0,10);
   
   drawLine(B11111111,255,0,0,5);
   drawLine(B11011011,255,0,0,5);
   drawLine(B11011011,255,0,0,5);

   drawLine(B11011111,0,0,0,10);
  
}

// drawing a line of LED bulbs consist of 8 LEDs.
//function takes char pattern, RGB values and the width of the bulb that to be displayed
void drawLine(unsigned char pattern,int R,int G,int B,int lineWidth){
  // loop to draw the bulb with respect to the width.
  for(i=0;i<lineWidth;i++){
   // loop to on / off the 8 bulbs with delay of execution time 
   for( j=0;j<8;j++){
     // assinging RGB values to the bulb with the pattern.
     bulb(j,R*bitRead(pattern,j),G*bitRead(pattern,j),B*bitRead(pattern,j));
     // here the bitRead functiongives the value of the relevent bulb that to be displayed or not
   }
  }
  
}
void bulbColor(int r,int g,int b){
   // this function assigns RGB values to the bulbs using analogWrite funtions
   analogWrite(green,255-g);
   analogWrite(blue,255-b);
   analogWrite(red,255-r);
}
void bulb(int num,int r,int g,int b){ 
  // getting the bulb with rgb values
  bulbColor(0,0,0); 
  PORTD = 1 << num;
  bulbColor(r,g,b);  
}

