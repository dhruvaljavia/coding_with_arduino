int x,nw,ctr,count,i,num,a;
int symbl[5];
void setup()
{
  Serial.begin(9600);
  pinMode(A0,INPUT);
  nw=1023;
  for(a=0;a<5;++a)
  symbl[a]=0;
}

void loop() 
{
  ctr=count=0;
  x=analogRead(A0);
  nw=x;
  if(nw!=1023)
  {
    decode();
    num = 10000*symbl[0] + 1000*symbl[1] + 100*symbl[2] + 10*symbl[3] + 1*symbl[4];
    //Converting symbl into letters or numbers..///////////////////////////////////////////////////////
    switch(num)
    {
      case 12000:
      Serial.print("A ");
      break;

      case 21110:
      Serial.print("B ");
      break;

      case 21210:
      Serial.print("C ");
      break;

      case 21100:
      Serial.print("D ");
      break;

      case 10000:
      Serial.print("E ");
      break;

      case 11210:
      Serial.print("F ");
      break;

      case 22100:
      Serial.print("G ");
      break;

      case 11110:
      Serial.print("H ");
      break;

      case 11000:
      Serial.print("I ");
      break;

      case 12220:
      Serial.print("J ");
      break;

      case 21200:
      Serial.print("K ");
      break;

      case 12110:
      Serial.print("L ");
      break;

      case 22000:
      Serial.print("M ");
      break;

      case 21000:
      Serial.print("N ");
      break;

      case 22200:
      Serial.print("O ");
      break;

      case 12210:
      Serial.print("P ");
      break;

      case 22120:
      Serial.print("Q ");
      break;

      case 12100:
      Serial.print("R ");
      break;

      case 11100:
      Serial.print("S ");
      break;

      case 20000:
      Serial.print("T ");
      break;

      case 11200:
      Serial.print("U ");
      break;

      case 11120:
      Serial.print("V ");
      break;

      case 12200:
      Serial.print("W ");
      break;

      case 21120:
      Serial.print("X ");
      break;

      case 21220:
      Serial.print("Y ");
      break;

      case 22110:
      Serial.print("Z ");
      break;

      case 12222:
      Serial.print("1 ");
      break;

      case 11222:
      Serial.print("2 ");
      break;

      case 11122:
      Serial.print("3 ");
      break;

      case 11112:
      Serial.print("4 ");
      break;

      case 11111:
      Serial.print("5 ");
      break;

      case 21111:
      Serial.print("6 ");
      break;

      case 22111:
      Serial.print("7 ");
      break;

      case 22211:
      Serial.print("8 ");
      break;

      case 22221:
      Serial.print("9 ");
      break;

      case 22222:
      Serial.print("0 ");
      break;
   }
  //conversion ends/////////////////////////////////////////////////////////////////////////////////////
  for(a=0;a<5;++a)
  symbl[a]=0;
  }
  delay(1);
}

void decode()
{
  i=0;
   a:
    {
      ++ctr;
      x=analogRead(A0);
      if(x!=1023)
      goto a;
    }
    delay(2);
    nw=x;
    if(ctr<1000)
    symbl[i]=1;
    else
    symbl[i]=2;
    ++i;
    ctr=0;
    Serial.print("_ ");
    b:
    {
      ++count;
      x=analogRead(A0);
      if(x!=1023)
      {
       nw=x;
       count=0;
      }

      if(count==0)
      goto a;
      else if(count>0 && count<10000)
      goto b;
    }
}
