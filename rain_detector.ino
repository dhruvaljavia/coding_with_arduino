void setup() 
{
  Serial.begin(9600);
}

void loop()
{
  int x = analogRead(A0);

  if(x<=1023 && x>=800)
  Serial.println("No rain");
  else if(x<=800 && x>=500)
  Serial.println("Light rain");
  else if(x<=500 && x>=300)
  Serial.println("Heavy rain");
  else
  Serial.println("Very heavy rain");
  Serial.println(x);
  
  delay(500); 
}
