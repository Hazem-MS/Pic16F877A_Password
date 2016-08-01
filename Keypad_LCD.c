int Kp,K,M,count,i,sum,x,b,a;
int Key_Read(void)
{
    Kp = 20;
    portb.F4 = 1;portb.F5 = 0;portb.F6 = 0;
    if(portb.F0 == 1)Kp = 1;
    if(portb.F1 == 1)Kp = 4;
    if(portb.F2 == 1)Kp = 7;
    if(portb.F3 == 1)Kp = 10;
    //////////////////////////////////////
    portb.F4 = 0;portb.F5 = 1;portb.F6 = 0;
    if(portb.F0 == 1)Kp = 2;
    if(portb.F1 == 1)Kp = 5;
    if(portb.F2 == 1)Kp = 8;
    if(portb.F3 == 1)Kp = 0;
    //////////////////////////////////////
    portb.F4 = 0;portb.F5 = 0;portb.F6 = 1;
    if(portb.F0 == 1)Kp = 3;
    if(portb.F1 == 1)Kp = 6;
    if(portb.F2 == 1)Kp = 9;
    if(portb.F3 == 1)Kp = 11;
    //////////////////////////////////////
    return Kp;
}
void main()
{
     b=1;
     trisb = 0b00001111;
     trisc = 0b10000000;
     portc = 0;
     ///////////// Store The Password(12345) //////////
     Eeprom_Write(0x00,1);
     Eeprom_Write(0x01,2);
     Eeprom_Write(0x02,3);
     Eeprom_Write(0x03,4);
     Eeprom_Write(0x04,5);
     //////////////////////////////////////////
     Lcd_Init(&portd);
S:   Lcd_Cmd(Lcd_Clear);
     Lcd_Out_Cp("Ent Pass:");
     while(1)
     {          delay_ms(300);
                sum = 0;
                for(count = 0;count <= 4;count++)
                {
                          do{
                                    K = Key_Read();
                            }
                while(k == 20);
     ////// Store the number Entered By the user /////////
     
                        Eeprom_Write(count + 5,K);
                        
     ////////////////////////////////////////////////////
                            if(K < 10)M = K + 0x30;
                            else M = K + 0x37;
                            if(K == 11){
                                 Lcd_Cmd(Lcd_Clear);
                                 goto S;
                                 }
                            Lcd_Out_Cp("*");
                            delay_ms(700);

                do{
                                    K = Key_Read();
                            }
                while(k==20);
               // Lcd_Out_Cp("*");
                if(k==10)

                {
    ////////////// Detection Process /////////////////////
                
                for(i = 0;i <= 4;i++)
                {
                  if(sum==0) sum = sum + (Eeprom_Read(i) - Eeprom_Read(i + 5));
                }

                if(sum == 0){ b=1;
                              Lcd_Out(2,1,"OPEN");

                              portc=1;

                              //do
                              //{
                              for(x=1000 ; x>2; x--)
                              {
                              delay_ms(10);
                              PORTC=PORTC<<1;
                              if (PORTc.F4) PORTC=1;
                              

                              }
                              delay_ms(5000);
                              for(x=1000; x>2; x--)
                              {
                              delay_ms(10);
                              PORTC=PORTC>>1;
                              if (PORTC==0) PORTc=8;
                               }
                               for(a=0;a<5;a++)
                               { Eeprom_Write(a+5,19);
                                }
                               goto S;

                            }
                else {
                        Lcd_Out(2,1,"ERORR");
                        b++;
                         delay_ms(500);
                       if(b==4){
                              while(1){delay_ms(500); Lcd_Out(2,1,"LOCKED"); }}
                        
                      } }   }
     }
                       
}
