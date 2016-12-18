/************************************************************
 apfellicht code                   
 V1.0.0                          
 (c) 2016 hofmann engineering    
                                 
apfellicht dimms a light in a sinus wave on pin 5. quick and
dirty solution in first version. button on 13 not used by now.

*************************************************************/  

int button = 0;
int oldbutton = 0;
int light = 0;
int inclight = 1;

int h[] = {128,131,134,137,141,144,147,150,153,156,159,162,165,168, 
           171,174,177,180,183,186,189,191,194,197,199,202,205,207, 
           209,212,214,217,219,221,223,225,227,229,231,233,235,236, 
           238,240,241,243,244,245,246,248,249,250,251,252,252,253, 
           254,254,255,255,255,255,255,255,255,255,255,255,255,255, 
           254,254,253,253,252,251,250,249,248,247,246,245,243,242, 
           240,239,237,236,234,232,230,228,226,224,222,220,218,215, 
           213,211,208,206,203,201,198,195,193,190,187,184,181,179, 
           176,173,170,167,164,161,158,155,152,148,145,142,139,136, 
           133,130,126,123,120,117,114,111,108,104,101,98,95,92,89, 
           86,83,80,77,75,72,69,66,63,61,58,55,53,50,48,45,43,41,38, 
           36,34,32,30,28,26,24,22,20,19,17,16,14,13,11,10,9,8,7,6, 
           5,4,3,3,2,2,1,1,1,1,1,1,1,1,1,1,1,1,2,2,3,4,4,5,6,7,8,10, 
           11,12,13,15,16,18,20,21,23,25,27,29,31,33,35,37,39,42,44, 
           47,49,51,54,57,59,62,65,67,70,73,76,79,82,85,88,91,94,97, 
           100,103,106,109,112,115,119,122,125,128};

/************************************
 function setup                  
   initializes everything
   (1) Serial connection
   (2) pin5 for OUTPUT and pin12 for INPUT
   (3) start on index 128, means 0
 parameter none                  
 return none                     
************************************/
void setup() {
  Serial.begin(115200);
  pinMode(5, OUTPUT);
  pinMode(12, INPUT);
  light = 128;
}
/************************************
 function loop                  
   loop function does
     (1) reads the button on 12
     (2) sets PWM on pin 5 to sin[light],
         whereas the value comes from
         the array, precomputed sin wave. 
     (3) range checks
 parameter none                  
 return none                     
************************************/
void loop() {
  button = digitalRead(12);
  if (button != oldbutton) {
    Serial.println(button);
    oldbutton = button;
  }
  analogWrite(5, h[light]);
  delay(10);
  if (++light >= 256) light = 0;
}
