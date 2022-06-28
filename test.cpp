
#define UNICODE
#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <windows.h>
#include <time.h>
#include <sys/types.h>
#include <psapi.h>
#include <tlhelp32.h>
#include "test.h"


using namespace std;
#define BUFFER_SIZE 200
char* command[15];
 int printPrompt(char *cur_directory){
    /**
     * In ra màn hình console đường dẫn 
     * (VD: C:\Users\Admin\.....> $ *phần tiếp này là lệnh*)
     **/
    if(GetCurrentDirectory(300,(LPWSTR)cur_directory) == 0){
        cout << "Reading of current working directory failed.\n";
        return -1;
    }
    cout << cur_directory << "> $";   
    return 1;
}
int size_of_command(){
    /**
     * Trả về số câu lệnh trong tập các lệnh 
     **/
    return sizeof(command) / sizeof(char *);
}
int (*activate_command[])(char **) = { 
  &cd,
  &cls,
  &echo,
  &exit,
  &help,
  &del,
  &dir,
  &mk_dir,
  &date,
  &time_cmd,
  &pc,
  &calc,
  &runbat	  
}; 
int main(void)

{

// TCHAR infoBuf[BUFFER_SIZE]  ;
// GetCurrentDirectory(300,infoBuf);
// printf("%S", infoBuf);

return 0;

}