int x;
void setup() 
{
  Serial.begin(9600);
  pinMode(LED_BUILTIN,OUTPUT);
  pinMode(A0,INPUT);
}

void loop() 
{
  x=analogRead(A0);
  Serial.println(x);
  if(x==1023)
  {
    digitalWrite(LED_BUILTIN,LOW);
  }
  else
  {
    digitalWrite(LED_BUILTIN,HIGH);    
  }

  delay(50);
}
