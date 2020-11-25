/*set top of stack pointer*/
asm(".word 0x2001C00");

/*jump tp blink function*/
asm(".word blink")

void blink(void){

/*enable GPIO G clock*/
*((unsigned int*)0x40023830)|=(1<<6);

/*SET GPIO PG13/PG14 OUTPUT*/
*((unsigned int*)0x40021800)|=((1<<28)|(1<<26));
*((unsigned int*)0x40021800)&=~((1<<29)|(1<<27));

/*SET GPIO PG13/PG14 OUTPUT MODE(push-pull)*/
*((unsigned int*)40021804)&=~((1<<13)|(1<<14));

/*SET GPIO PG13/PG14 OUTPUT(PULL DOWN)*/
*((unsigned int*)0x4002180c)|=((1<<29)|(1<<27));
*((unsigned int*)0x4002180c)&=~((1<<28)|(1<<26));

int i;

while(1){
        /*PG13 SET PG14 RESET*/
         *((unsigned int*)0x40021818)|=0x40002000;
         /*delay use*/
         for(i=0;i<10000;i++);
         /*PG13 RESET PG14 SET*/
         *((unsigned int*)0x40021818)|=0x20004000;
         /*delay use*/
         for(i=0;i<10000;i++);

}


}






}