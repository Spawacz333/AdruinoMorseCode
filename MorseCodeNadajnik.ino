//zmienne
String aM[25] = {
  //A       B       C     D         E
  "1200", "2111", "2121", "2110", "1000",
  //F      G       H      I         J
  "1121", "2210", "1111", "1100", "1222", 
  //K      L       M      N         O
  "2120", "1211", "2200", "2100", "2220",
  //P       Q     R       S        T
  "1221", "2212", "1210", "1110", "2000",
  //U       W        X      Y        Z
  "1120", "1220", "2112", "2122", "2211"
};

char alfabet[25] = {
  "abcdefghijklmnopqrstuwxyz"
};

char message[100];
String msgGet;

int aM_Delay = 300;

int ledPin = 13;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
}

void loop() {
  delay(2500);

  for(int x=0; x<100; x++)
    message[x] = '0';

bool waiting = true;

  while(waiting)
  {
    if(Serial.available() > 0)
    {
      msgGet = Serial.readString();
    
      if(msgGet.length() > 99)
      continue;
      
      for(int i=0; i < msgGet.length(); i++)
      message[i] = msgGet.charAt(i);
    
      msgGet = '0';
      waiting = false;
    }
  }

    for(int m=0; m < 100; m++)
    {
       for(int i=0; i<=25; i++)
       {
         if(message[m] == alfabet[i])
         { 
           for(int x=0; x < 4; x++)
           {
             if('2' == aM[i].charAt(x))
             {
               digitalWrite(ledPin, HIGH);
               delay(aM_Delay * 3);
               digitalWrite(ledPin, LOW);
               delay(aM_Delay);
             }
             else if('1' == aM[i].charAt(x))
             {
               digitalWrite(ledPin, HIGH);
               delay(aM_Delay);
               digitalWrite(ledPin, LOW);
               delay(aM_Delay);
             }
             else if('0' == aM[i].charAt(x))
             {
               delay(aM_Delay);
               break;
             }
           }
         }
         }
       }
}
