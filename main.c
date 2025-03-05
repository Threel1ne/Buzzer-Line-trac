/*======================================================================*/
/*  VER      : LINE Coding V10        			                        */
/*  Compile  :  WinAVR-20100110   /   AVRSTUDIO                         */
/*  Line Coding : Create imagination									*/
/*	Thai Edition : ND's.ROBOTICS (³°¡Ã ´ÕÍØ´Á¨Ñ¹·Ãì)						*/
/*======================================================================*/
char l;
//#define ENTRY_SET 1  //Entry mode enabled
#define S8INIT	 43   // à»Ô´à¤Ã×èÍ§áÅéÇ¡´»ØèÁ START ¤éÒ§äÇéà¾×èÍà¢éÒÊÙèâËÁ´·´ÊÍºà«ÍÃìâÇ ¤èÒàÃÔèÁµé¹   UP DOWN SERVO
#define S7INIT	 180  // à»Ô´à¤Ã×èÍ§áÅéÇ¡´»ØèÁ START ¤éÒ§äÇéà¾×èÍà¢éÒÊÙèâËÁ´·´ÊÍºà«ÍÃìâÇ ¤èÒàÃÔèÁµé¹   LEFT SERVO  
#define S6INIT	 1    // à»Ô´à¤Ã×èÍ§áÅéÇ¡´»ØèÁ START ¤éÒ§äÇéà¾×èÍà¢éÒÊÙèâËÁ´·´ÊÍºà«ÍÃìâÇ ¤èÒàÃÔèÁµé¹   RIGHT SERVO

//////**************** ¡ÒÃµÑé§¤èÒÁØÁ¢Í§à«ÍÃìâÇÁÍàµÍÃì (á¡éä¢ÁØÁãËéµÃ§¡ÑºËØè¹Â¹µì»ÃÐ¡Íº) ********
#define su 			sservo6(140,5); 	//	Â¡µÕ
#define sd			sservo6(43,5); 		//	ÇÒ§
#define sud 		sservo6(140,20);    //	Â¡µÕªéÒæ
#define sdd			sservo6(43,20);     //	ÇÒ§ªéÒæ

#define so0			sservo7(170,0); sservo8(4,0);  // à»Ô´¡ÇéÒ§ÊØ´ / servo open 0 
#define so1			sservo7(110,0); sservo8(56,0);  // à»Ô´»¡µÔ / servo open 1 
#define so2			sservo7(100,0); sservo8(66,0);  // à»Ô´á¤ºÊØ´ / servo open 2 

#define sc0			sservo7(64,0); sservo8(104,0);  //¤ÕººÅçÍ¡àÅç¡ / servo close 0  / small block
#define sc1			sservo7(74,0); sservo8(90,0);  //¤ÕººÅçÍ¡ãË­è / servo close 1  / big block
#define scl			sservo7(85,0); sservo8(135,0);  //¤ÕººÅçÍ¡àÅç¡äÇé·Ò§«éÒÂ / servo close left  / small block
#define scr			sservo7(35,0); sservo8(88,0);  //¤ÕººÅçÍ¡àÅç¡äÇé·Ò§¢ÇÒ / servo close rignt /  small block

#define bfol		sservo7(170,5); sservo8(135,4);    // ¤ÕººÅçÍ¡ãË­èäÇé·Ò§«éÒÂ
#define bfor		sservo7(35,4); sservo8(4,5);  // ¤ÕººÅçÍ¡ãË­èäÇé·Ò§¢ÇÒ
#define sfol		sservo7(170,0); sservo8(125,0); for(l=0 ; l<=8 ; l++){delay(30); sservo8(135,0);delay(30); sservo8(145,0);};// ¤ÕººÅçÍ¡àÅç¡äÇé·Ò§«éÒÂ
#define sfor		sservo7(45,0); sservo8(4,0); for(l=0 ; l<=8 ; l++) {delay(30); sservo7(35,0);delay(30); sservo7(25,0);}// ¤ÕººÅçÍ¡àÅç¡äÇé·Ò§¢ÇÒ


#define td1  delay(100);	// ËÂØ´ 0.1 ÇÔ¹Ò·Õ
#define td2  delay(200);	// ËÂØ´ 0.2 ÇÔ¹Ò·Õ






#include "lib/in_out.c"

//////////////////////// Program setting section ////////////////////////
void setup(void){
	motorset(0);         // µÑé§¤èÒÁÍàµÍÃì motor type   0 - ¸ÃÃÁ´Ò , 1 - coreless motor
//	absh(17,13,10,7,5,2);  // red
//	turnabsh(15,10,8,5,3);  // red
	absh(20,17,14,10,7,3);  // blue
	turnabsh(20,12,7,4,2);  // blue
	motorstop(255,255);     // ¤ÇÒÁáÃ§¡ÒÃËÂØ´¢Í§ÁÍàµÍÃìàÁ×èÍËÂØ´ 255 à»ç¹¡ÒÃËÂØ´·Ñ¹·Õ ÂÔè§¤èÒ¹éÍÂ ÂÔè§¹ØèÁ¹ÇÅ
	ffmotor(0,0);         // ¤èÒ¡ÒÃá¡éä¢¤ÇÒÁàºÕèÂ§àº¹¢Í§ÁÍàµÍÃìàªÔ§àÊé¹ ÂÔè§µÑÇàÅ¢ÁÒ¡ ¤ÇÒÁàÃçÇÂÔè§ªéÒÅ§ (0~255) 
	bbmotor(0,0);         // ¤èÒ¡ÒÃá¡éä¢¤ÇÒÁàºÕèÂ§àº¹¢Í§ÁÍàµÍÃìËÁØ¹¡ÅÑº ÂÔè§µÑÇàÅ¢ÁÒ¡ ¤ÇÒÁàÃçÇÂÔè§ªéÒÅ§ (0~255) 
	dec_absh(20,15,10,7,3,1);
	decffmotor(0,0);         // ¤èÒ¡ÒÃá¡éä¢¤ÇÒÁàºÕèÂ§àº¹¢Í§ÁÍàµÍÃìàªÔ§àÊé¹ ÂÔè§µÑÇàÅ¢ÁÒ¡ ¤ÇÒÁàÃçÇÂÔè§ªéÒÅ§ (0~255)
	decbbmotor(0,0);         // ¤èÒ¡ÒÃá¡éä¢¤ÇÒÁàºÕèÂ§àº¹¢Í§ÁÍàµÍÃìàªÔ§àÊé¹ ÂÔè§µÑÇàÅ¢ÁÒ¡ ¤ÇÒÁàÃçÇÂÔè§ªéÒÅ§ (0~255)
	start(ON);            // µÑé§¤èÒàÊÕÂ§¢éÒÁ·Ò§áÂ¡ã¹¤ÓÊÑè§ line (ON, OFF)

	crosstime(500);
	
	
	



}
//////////////////////// ÊÔé¹ÊØ´ÊèÇ¹¡ÒÃµÑé§¤èÒâ»Ãá¡ÃÁ //////////////////////


////////////////////////// à¢ÕÂ¹â»Ãá¡ÃÁ·Õè¹Õè!!! ////////////////////
void loop(void){
//	remote_play(0);
buzzer(5,50,500);
	restart(2);   // »éÍ§¡Ñ¹¡ÒÃ´Óà¹Ô¹¡ÒÃ«éÓ ËÒ¡µéÍ§¡ÒÃÃÑ¹à¾ÕÂ§¤ÃÑé§à´ÕÂÇÍÂèÒÅºÍÍ¡
}
///////////////////// ¨ºÊèÇ¹¡ÒÃà¢ÕÂ¹â»Ãá¡ÃÁ //////////////////////// 

int main(void)
{
    init_port();
    init_usart();
    init_message();
    init_timer();
    init_int();
    init_adc();  
	
	line_coding_init();
	
    while(1){  
		uart_data_check(); 
		
		#ifdef ENTRY_SET
		if(command_flag==ON)
			command_chk();
			memory_line_play();
		#else
			loop();
		#endif
	}
}
/////////////////////   Radio control //////////////////////
void remote_play(unsigned char ver){
	char spd = 8;//12;
	remot_ver = ver;
	remot_set(remot_ver);  // ¡ÒÃµÑé§¤èÒµÒÁÃÕâÁ·¤Í¹â·ÃÅ
	while(1){

		if(remot_ver == 0){  // µÑÇ¤Çº¤ØÁ¡ÒÃà¢éÒÃËÑÊ   bit mode
			uart_remot_data_check(0); // ¡ÒÃÇÔà¤ÃÒÐËì¢éÍÁÙÅ¡ÒÃÃÑºáººÍ¹Ø¡ÃÁà»ç¹ÊÑ­­Ò³¤Çº¤ØÁÃÐÂÐä¡Å
			
			
				
			if(remot_read_data & REMOT_R1){  // while holding R1
				if(remot_read_data & REMOT_L_UP){
					if(spd <= 18)
						spd+=2;
					buzzer(1,50,100);
				}
				else if(remot_read_data & REMOT_L_DN){
					if(spd >= 4)
						spd-=2;
					buzzer(1,50,100);
				}
				else if(remot_read_data & REMOT_L_LEFT){
					motor(0,-15,40);
					delay(50);
					motor(-15,-15,20);
					delay(50);
					motor(-15,0,30);
					delay(50);
					motor(15,15,50);
					delay(55);
				}
				else if(remot_read_data & REMOT_L_RIGHT){
					motor(-15,0,40);
					delay(50);
					motor(-15,-15,20);
					delay(50);
					motor(0,-15,40);
					delay(50);
					motor(15,15,45);
					delay(55);
				}
				else if(remot_read_data & REMOT_R_LEFT){
					if(remot_read_data & REMOT_R1){
						motor(-20,20,500);
					}
				}
				else if(remot_read_data & REMOT_R_RIGHT){
					if(remot_read_data & REMOT_R1){
						motor(20,-20,500);
					}
				}
			}
			else{
				if(remot_read_data & REMOT_L_UP){
					if(remot_read_data & REMOT_R_LEFT)
						wheel(0,spd);
					else if(remot_read_data & REMOT_R_RIGHT)
						wheel(spd,0);
					else
						wheel(spd,spd);
				}
				else if(remot_read_data & REMOT_L_DN){
					if(remot_read_data & REMOT_R_LEFT)
						wheel(0,-spd);
					else if(remot_read_data & REMOT_R_RIGHT)
						wheel(-spd,0);
					else
						wheel(-spd,-spd);
				}
				else if(remot_read_data & REMOT_L_LEFT){
					wheel(-spd,spd);
				}
				else if(remot_read_data & REMOT_L_RIGHT)
					wheel(spd,-spd);
				else if(remot_read_data & REMOT_R_LEFT){
					decwheel(-5,5);
				}
				else if(remot_read_data & REMOT_R_RIGHT){
					decwheel(5,-5);
				}
				else{
					wheel(0,0);
				}

				if(remot_read_data & REMOT_R_UP){
					sservo6(60,0);
					delay(500);
					sservo6(165,2);
				}
				else if(remot_read_data & REMOT_R_DN){

				}
		
				
				else if(remot_read_data & REMOT_L2){
				}
			
				
				else if(remot_read_data & REMOT_R1){
				}
				else if(remot_read_data & REMOT_R2){
				}	
				else if(remot_read_data & REMOT_SELECT){
				}
				else if(remot_read_data & REMOT_START){
				}
			}
		//	delay(1);	
			
		}
		else if(remot_ver == 1){  // PS2 Remote Controller RF
			ReadGamepad();				// ps2 gamepad received signal analysis
			remot_read_data = PS2data;
			if(remot_read_data & REMOT_PR_L_UP){
				if(remot_read_data & REMOT_PR_R_LEFT)
					wheel(0,spd);
				else if(remot_read_data & REMOT_PR_R_RIGHT)
					wheel(spd,0);
				else
					wheel(spd,spd);
			}
			else if(remot_read_data & REMOT_PR_L_DN){
				if(remot_read_data & REMOT_PR_R_LEFT)
					wheel(0,-spd);
				else if(remot_read_data & REMOT_PR_R_RIGHT)
					wheel(-spd,0);
				else
					wheel(-spd,-spd);
			}
			else if(remot_read_data & REMOT_PR_L_LEFT)
				wheel(-spd,spd);
			else if(remot_read_data & REMOT_PR_L_RIGHT)
				wheel(spd,-spd);
			else{
				wheel(0,0);
			}	
			if(remot_read_data & REMOT_PR_L1){
				if(remot_read_data & REMOT_PR_R_UP){
					if(spd <= 18)
						spd+=2;
				}
				else if(remot_read_data & REMOT_PR_R_DN){
					if(spd >= 4)
						spd-=2;
				}
				buzzer(1,50,10);
			}
			else if(remot_read_data & REMOT_PR_R_UP){

			}
			else if(remot_read_data & REMOT_PR_R_DN){

			}
			else if(remot_read_data & REMOT_PR_R_LEFT){

			}
			else if(remot_read_data & REMOT_PR_R_RIGHT){
				
			}
		
				
			else if(remot_read_data & REMOT_PR_L2){
			}
			
				
			else if(remot_read_data & REMOT_PR_R1){
			}
			else if(remot_read_data & REMOT_PR_R2){
			}	
			else if(remot_read_data & REMOT_PR_SELECT){
			}
			else if(remot_read_data & REMOT_PR_START){
			}		
			delay(10);

		}
	}
}
