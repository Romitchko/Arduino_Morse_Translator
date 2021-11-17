/*
 TP de Mr Labasse Sylvain
 Faire clignoter la led en morse via une traduction depuis
 une chaine de caractères
 Par Romain BAUDET
 */
 

#include <stdio.h> 
#include <string.h> 
#include <ctype.h> 

static const struct
{
   const char letter, *morse;
} Code[] =
{
   { 'A', ".- "   },{ 'B', "-... " },{ 'C', "-.-. " },{ 'D', "-.. "  },
   { 'E', ". "    },{ 'F', "..-. " },{ 'G', "--. "  },{ 'H', ".... " },
   { 'I', ".. "   },{ 'J', ".--- " },{ 'K', ".-.- " },{ 'L', ".-.. " },
   { 'M', "-- "   },{ 'N', "-. "   },{ 'O', "--- "  },{ 'P', ".--. " },
   { 'Q', "--.- " },{ 'R', ".-. "  },{ 'S', "... "  },{ 'T', "- "    },
   { 'U', "..- "  },{ 'V', "...- " },{ 'W', ".-- "  },{ 'X', "-..- " },
   { 'Y', "-.-- " },{ 'Z', "--.. " },{ ' ', "       "    },
};


int led = 13; 	//définit la led à utiliser ici 13
int morse_unit = 100;

void dot() {
  digitalWrite(led, HIGH);   // Allume la led
  delay(1*morse_unit);               // Délai de une seconde
  digitalWrite(led, LOW);    // Eteint la Led
  delay(1*morse_unit);               // Délai de une seconde
}

void dash() {
  digitalWrite(led, HIGH);   // Allume la led
  delay(3*morse_unit);               // Délai de une seconde
  digitalWrite(led, LOW);    // Eteint la Led
  delay(1*morse_unit);               // Délai de une seconde
}

void space() {
  delay(1*morse_unit);		// délais pour un espace correspondant à 1* unité de morse = 100
}

void encode_letter(const char *c)
{
   size_t i;
   i = 0;
   while(c[i] != '\0')
     {
       Serial.println(c[i]); 
        if(c[i] == '.')
          {
            dot();
          }  
        if(c[i] == '-')
          {
            dash();
          } 
        if(c[i] == ' ')
          {
            space();
          } 
        i++;
     }
}

void encode_string(const char *s)
{
   size_t i, j;
   for ( i = 0; s[i]; ++i )
   {
      for ( j = 0; j < sizeof Code / sizeof *Code; ++j )
      {
         if ( toupper(s[i]) == Code[j].letter )
         {
            Serial.println(Code[j].letter); 
            Serial.println(Code[j].morse); 
            encode_letter(Code[j].morse);
            break;
         }
      }
   }
}


void setup() {                
  // 
  Serial.begin(9600);
  pinMode(led, OUTPUT);     
}

// Retourne la chaine de caractères en mode loop infini
void loop() {
  const char text[] = "Bonjour Sylvain"; //entrer un texte
  encode_string(text);
  delay(2000);
}
