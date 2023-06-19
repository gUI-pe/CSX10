#define LED1 13
#define LED2 12
#define LED3 11
#define PIEZO 2
#define BUT1 5
#define BUT2 4
#define BUT3 3


void setup()
{
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(PIEZO,OUTPUT);
  pinMode(BUT1, INPUT);
  pinMode(BUT2, INPUT);
  pinMode(BUT3, INPUT);
  
  Serial.begin(9600);
}

void loop()
{
	int sorteado = sorteio();
  
  	Serial.println(sorteado);
  
  	int clicou = 1;
  
  	while(clicou == 1)
    {
      if(digitalRead(BUT1) == HIGH)
    	{
     		if(sorteado == 1)
        	{
              piscaCerto(sorteado);
              delay(500);
          	  piscaCerto(sorteado);
              delay(500);
          	  piscaCerto(sorteado);
        	}
      		else
       	 	{
          		acendeCerto(sorteado);
        	}
        
        	clicou = 0;
    	}
  		else if(digitalRead(BUT2) == HIGH)
  		{
   			if(sorteado == 2)
      	  	{
      	    	piscaCerto(sorteado);
              	delay(500);
              	piscaCerto(sorteado);
              	delay(500);
              	piscaCerto(sorteado);
      	 	}
      		else
        	{
          	  	acendeCerto(sorteado);
        	} 	
          
          	clicou = 0;
 	 	}
  	 	else if(digitalRead(BUT3) == HIGH)
  	 	{
   			if(sorteado == 3)
     	   	{
        	  piscaCerto(sorteado);
              delay(500);
              piscaCerto(sorteado);
              delay(500);
              piscaCerto(sorteado);
     	  	}
       		else
        	{
          	  	acendeCerto(sorteado);
        	} 
          
          	clicou = 0;
  	 	}
      
    }
      
}

int sorteio()
{
  randomSeed(analogRead(0)); // inicializa a sequência randômica
  int led = random(1, 4); // sorteia um led entre 1 e 3
  Serial.println("led sorteado = ");
  Serial.println(led);
  return led;
}

void piscaCerto(int lucky)
{
 	if(lucky == 1)
    {
      	digitalWrite(LED1, HIGH); 
      	delay(500);
      	digitalWrite(LED1, LOW); 
    }
  	else if(lucky == 2)
    {
      	digitalWrite(LED2, HIGH);
      	delay(500);
      	digitalWrite(LED2, LOW);
    }
  	else
    {
      	digitalWrite(LED3, HIGH);
      	delay(500);
      	digitalWrite(LED3, LOW);
    }
}

void acendeCerto(int lucky)
{
 	if(lucky == 1)
    {
      	digitalWrite(LED1, HIGH);
      	delay(3000);
      	digitalWrite(LED1, LOW);
    }
  	else if(lucky == 2)
    {
      	digitalWrite(LED2, HIGH);
      	delay(3000);
      	digitalWrite(LED2, LOW);
    }
  	else
    {
      	digitalWrite(LED3, HIGH);
      	delay(3000);
      	digitalWrite(LED3, LOW);
    }
}

