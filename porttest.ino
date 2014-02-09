void receiveStr(char *str);

int port, val;

void setup()
{
  Serial.begin(115200);
  Serial.println("Started");
}

void loop()
{
  char str[0xff];
  
  Serial.print(">>> ");
  receiveStr(str);
  if(*str)
    port=atoi(str+1);
  switch(*str){
    case 'w':
      Serial.print("Writing HIGH to port ");
      Serial.println(port);
      pinMode(port, OUTPUT);
      digitalWrite(port, HIGH);
      break;
    case 'd':
      Serial.print("Writing LOW to port ");
      Serial.println(port);
      pinMode(port, OUTPUT);
      digitalWrite(port, LOW);
      break;
    case 'r':
      Serial.print("Reading from port ");
      Serial.println(port);
      pinMode(port, INPUT);
      val=digitalRead(port);
      Serial.println(val);
      break;
    default:
      Serial.println("Error: invalid command");
      break;
  }
}

void receiveStr(char *str)
{
  char c;
  while(1){
    if(Serial.available()){
      c=Serial.read();
      Serial.print(c);
      if(c=='\r')
        break;
      *str++=c;
    }
  }
  *str='\0';
  Serial.println("");
  return;
}
