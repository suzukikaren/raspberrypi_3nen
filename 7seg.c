#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>


void led_light(int fd,char* str){
  fd = open(str, O_WRONLY);
     if (fd < 0) {
       printf("GPIO value open error.\n");
       exit(1);
      }
     write(fd,"1",2);
//3秒待つ                                                                       
   usleep(3 * 1000 * 1000);
}

void led_dark(int fd){
//GPIO21に0を出力する(LED OFF)                                                  
     write(fd,"0",2);
     close(fd);
}

void led_used(int fd,char *led){

//GPIO21の使用終了を指定する                                                    
  fd = open("/sys/class/gpio/unexport", O_WRONLY);
    if (fd < 0){
      printf("GPIO unexport open error.\n");
      exit(1);
     }
  write(fd,led,3);
  close(fd);
}


int main(int argc ,char **argv){

  int fd[7]={0,0,0,0,0,0,0};
  int *j;
  *j= 5;
  char led[8][7] = {"5","6","7","8","9","10","11"};
  char str[8][50]={"/sys/class/gpio/gpio5/value",
             "/sys/class/gpio/gpio6/value",
             "/sys/class/gpio/gpio7/value",
             "/sys/class/gpio/gpio8/value",
             "/sys/class/gpio/gpio9/value",
             "/sys/class/gpio/gpio10/value",
             "/sys/class/gpio/gpio11/value"};
  int i =0;
 for(i=0; i < 7 ; i++){
  //GPIO21の使用開始を指定する                                                  
  fd[i] = open("/sys/class/gpio/export", O_WRONLY);
  if (fd[i] < 0) {
    printf("GPIO export open error.\n");
    exit(1);
  }

  write(fd[i],j,3);
  close(fd[i]);
  *j++;
  }
  /*                                                                            
  fd[1] = open("/sys/class/gpio/export", O_WRONLY);                             
  if (fd[1] < 0) {                                                              
    printf("GPIO export open error.\n");                                        
    exit(1);                                                                    
  }                                                                             
                                                                                
  write(fd[1],"6",3);                                                           
  close(fd[1]);                  
                                                                               
  */

  //0.1秒待つ(次のオープンでエラーになった場合があったため)                     
  usleep(100000);

  /*                                                                            
  //GPIO21を出力に指定する                                                      
  char str[]="/sys/class/gpio/gpio";                                            
  char str2[]="/direction";                                                     
  char str3[35]="\0”;           

  char *num;                                                                    
  for(int i=0;i<7;i++){                                                         
    itoa(i,num,10);                                                             
    strcat(str3,str,num);                                                       
    strcat(str3,str3,str2);                                                     
  */

  fd[0] = open("/sys/class/gpio/gpio5/direction", O_WRONLY);
  if (fd[0] < 0) {
    printf("GPIO direction open error.\n");
    exit(1);
  }
  write(fd[0],"out",4);
  close(fd[0]);

  fd[1] = open("/sys/class/gpio/gpio6/direction", O_WRONLY);
  if (fd[1] < 0) {
    printf("GPIO direction open error.\n");
    exit(1);
  }
  write(fd[1],"out",4);
  close(fd[1]);


  fd[2] = open("/sys/class/gpio/gpio7/direction", O_WRONLY);
  if (fd[2] < 0) {
    printf("GPIO direction open error.\n");
    exit(1);
  }
  write(fd[2],"out",4);
  close(fd[2]);

  fd[3] = open("/sys/class/gpio/gpio8/direction", O_WRONLY);
 if (fd[3] < 0) {
    printf("GPIO direction open error.\n");
    exit(1);
  }
  write(fd[3],"out",4);
  close(fd[3]);

  fd[4] = open("/sys/class/gpio/gpio9/direction", O_WRONLY);
  if (fd[4] < 0) {
    printf("GPIO direction open error.\n");
    exit(1);

  }
  write(fd[4],"out",4);
  close(fd[4]);

  fd[5] = open("/sys/class/gpio/gpio10/direction", O_WRONLY);
  if (fd[5] < 0) {
    printf("GPIO direction open error.\n");
    exit(1);
  }
  write(fd[5],"out",4);
  close(fd[5]);


  fd[6] = open("/sys/class/gpio/gpio11/direction", O_WRONLY);
  if (fd[6] < 0) {
    printf("GPIO direction open error.\n");
    exit(1);
  }
  write(fd[6],"out",4);
  close(fd[6]);


  led_light(fd[0], str[0]);//5番pinを出力   
 led_dark(fd[0]);         //5pinに0を代入                                      
  //GPIO21に0を出力する(LED OFF)                                                

  led_used(fd[0],led[0]);
  led_used(fd[1],led[1]);
  led_used(fd[2],led[2]);
  led_used(fd[3],led[3]);
  led_used(fd[4],led[4]);
  led_used(fd[5],led[5]);
  led_used(fd[6],led[6]);

  return 0;

}
