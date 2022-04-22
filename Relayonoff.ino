/*
 # Product: 16A Relay Module
 # SKU    : DFR0251
 # Description:
 #    This sample code is combined  with the figure above to test the relay module whether works normally.
 # Link:
 #    D     --  2       // Signal
 #    GND   --  GND
 #    VCC   --  VCC
 #    COM   --  13      // INPUT
 #    NO    --  LED     // OUTPUT
 #    LED - --  GND
*/


int Relay = 3;

void setup()
{
  pinMode(13, OUTPUT);         //Set Pin13 as output
  digitalWrite(13, HIGH);     //Set Pin13 High
  pinMode(Relay, OUTPUT);     //Set Pin3 as output
}
void loop()
{
          digitalWrite(Relay, HIGH);   //Turn off relay
          delay(2000);
          digitalWrite(Relay, LOW);    //Turn on relay
          delay(2000);
}
