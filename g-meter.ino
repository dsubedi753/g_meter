const int iro =7;
bool insignal = 0;
bool count = 0;
bool trigger = 0;

unsigned long prev =0;
unsigned long now = 0;
unsigned long dur = 0;
float frequency= 0;
float period = 0;

void setup()
{
  pinMode(iro,INPUT);
  Serial.begin(9600);
}
void loop()
{
  insignal = digitalRead(iro);
  if (insignal == LOW)       //IR module sends low when obstacle is present
  {
    if (trigger == 0)        // positive triggered
     {
        if (count==0)           // directional triggered
        {
          now = micros();
          period = (float)duration(now) / (float)1000000;
          frequency = (float)1 / (float)period;
          Serial.print("Frequency:   ");
          Serial.println(frequency,3);
          Serial.println();         //extra line
          count =1;
        }
        else
        {
          count=0;
        }
        trigger = 1;
     }
  }
  else
  {
     trigger = 0;
  }
  delay(5);
}

unsigned long duration(unsigned long now)
{
  
  dur = now-prev;
  prev = now;
  return dur;
}

