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

#define MAX_CWD_LENS 128
#define MAX_BUFFER_SIZE 64
#define MAX_TOK_BUFSIZE 64
#define TOKEN_DELIMETERS " \t\r\n\a"
#include "Command.h"
#include "Analyse.h"
using namespace std;
int cd(char **args);
int size_of_command();

/* Mảng các câu lệnh command được hỗ trợ */
const char *command[] = {
    "cd"//,     
    // "cls",    
    // "echo",  
    // "exit", 
    // "help", 
    // "del",
    // "dir",
    // "mkdir", 
    // "date",
    // "time",
    // "pc",
    // "calc",
    // "run"
};

/* Mảng các lệnh command*/
int (*activate_command[])(char **) = {  
    /**
     * đây là một mảng ,mỗi phần tử của mảng là một con trỏ đến hàm mang tham số char**
     * 
     */

  &cd /*,
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
  */ 
}; 

/**
 * Chạy lệnh với lệnh là arg[0] như cd, dir, exit, help
 **/
int execute(char ** args){
    /**
     * Chạy lệnh với lệnh là arg[0] như cd, dir, exit, help
     **/
    if (args[0] == NULL){
        return 0;
    }
    for(int i=0; i < size_of_command() ; i++){
        if(strcmp(args[0],command[i]) == 0){ /* Kiểm tra xem người dùng nhập lệnh nào trong tập lệnh */
            return (*activate_command[i])(args);
        }
    }
    return 0;
}

/**
 * Trả về số câu lệnh trong tập các lệnh 
 **/
int size_of_command(){
    /**
     * Trả về số câu lệnh trong tập các lệnh 
     **/
    return sizeof(command) / sizeof(char *);
}

//////////////////////////////////////////
////////// Danh sách câu lệnh //////////// 
//////////////////////////////////////////
/*
int help(char **args){
    if (args[1] == NULL) {
	printf("Type \"help [command]\" for more information about a specific command.\n");
	printf("Suppoted commands:\n cd\n date\n time\n dir\n cls\n echo\n del\n mkdir\n pc\n exit\n ");
	printf("Usage:\n\t <command> [option]\n\tEXAMPLE: help cd\n");
	printf("%-30s%s\n%-30s%s", " cd",
	        "Change the current directory. You must write the new directory after this command.",
		" ", "EXAMPLES: \"cd C:/\"\n\n");
	printf("%-30s%s\n%-30s%s", " date",
		"Show the today's date.",
		" ", "EXAMPLES: \"date\"\n\n");
	printf("%-30s%s\n%-30s%s", " time",
		"Show the current time.",
		" ", "EXAMPLES: \"time\"\n\n");
	printf("%-30s%s\n%-30s%s", " dir",
		"Show all files and folders in the current directory.",
		" ", "EXAMPLES: \"dir\"\n\n");
        printf("%-30s%s\n%-30s%s", " cls",
		"Clear the console screen.",
            	" ", "EXAMPLES: \"cls\"\n\n");
        printf("%-30s%s\n%-30s%s", " echo",
		"Print a message on the screen.",
            	" ", "EXAMPLES: \"echo [message]\"\n\n");
        printf("%-30s%s\n%-30s%s", " del",
		"Delete a file or folder in the current directory.",
            	" ", "EXAMPLES: \"del [Folder/Filename]\"\n\n");
        printf("%-30s%s\n%-30s%s", " mkdir",
		"Make a new directory.",
            	" ", "EXAMPLES: \"mkdir[Foldername]\"\n\n");
	printf("%-30s%s\n%-30s%s", " run",
		"Run .bat file only.",
            	" ", "EXAMPLES: \"run [filename.bat]\"\n\n");
        printf("%-30s%s\n%-30s%s\n%-30s%s", " pc",
            	"Process.", " ",
            	"You must enter the options in the 2nd argument, such as fg, bg, all, find, kill, killid, suspend, resume",
            	" ", "EXAMPLES: \"pc bg\"\n\n");
	printf("%-30s%s", " exit", "Exit this tiny shell :((((\n");
    }
    else if(!strcmp(args[1],"cd")) {
        cout << "Change the current directory." << endl;
        cout << "       cd           : Show the current directory" << endl;
        cout << "       cd ..        : Show the parent directory of the current directory" << endl;
        cout << "       cd [path]    : Change the current directory to [path]" << endl;
        cout << "EXAMPLE: cd C:\\Users\\Admin\\ => change current directory to C:\\User\\Admin" << endl;
    }
    else if(!strcmp(args[1],"date")) {
        cout << "Display the current date to screen." << endl;
        cout << "This command does not support any options." << endl;
    }
    else if(!strcmp(args[1],"time")){
        cout << "Diplay the current time to screen." << endl;
        cout << "This command does not support any options." << endl;
    }
    else if(!strcmp(args[1],"dir")){
        cout << "Display the list of files and folder in the directory to the screen." << endl;
        cout << "       dir         : Show the files and folders in the current directory" << endl;
        cout << "       dir [path]  : Show the files and folders in the [path]" << endl;
        cout << "EXAMPLE: \"dir\", \"dir C:\\Users\\Admin\"" << endl;
    }
    else if(!strcmp(args[1],"cls")){
        cout << "Clear all line displaying on the console screen." << endl;
        cout << "This command does not support any options." << endl;
    }
    else if(!strcmp(args[1],"echo")){
        cout << "Print the message on the screen." << endl;
        cout << "This command does not support any options." << endl;
        cout << "EXAMPLE: \"echo Hello World\"" << endl;
        cout << "       => \"Hello World\"" << endl;
    }
    else if(!strcmp(args[1],"del")){
        cout << "Delete file or folder in the current directory." << endl;
        cout << "Recommend: Folder/File name contains no space." << endl;
        cout << "       del [Folder/Filename] : Delete folder/file (Folder/Filename) in the current dirrectory" << endl;
        cout << "EXAMPLE: \"del ABC\"" << endl; 
    }
    else if(!strcmp(args[1],"mkdir")){
        cout << "Make a new directory in the current directory." << endl;
        cout << "Recommend: Foldername contains no space." << endl;
        cout << "       mkdir [Foldername] : Make folder [Foldername] in the current directory" << endl;
        cout << "EXAMPLE: \"mkdir ABC\"" << endl;
    }
    else if (!strcmp(args[1], "run")){
        cout << "Run .bat file only with commands which our shell supports" << endl;
        cout << "       run [Filename.bat] : Run .bat file with commands which our shell supports " << endl;
        cout << "EXAMPLE: \"run command.bat\"" << endl;
    }
    else if(!strcmp(args[1],"pc")){
        cout << "Supported options:" << endl;
        cout << "        all     Show list of all running processes" << endl;
	cout << "        find    Get pid of specific program(s) by name" << endl;
	cout << "        suspend Suspend a program by process id" << endl;
	cout << "        resume  Resume a program by process id" << endl;
	cout << "        kill    Terminate all program by name" << endl;
        cout << "        killid  Terminate a program by process id" << endl;
        cout << "        bg      Run a program in background mode by path to program" << endl;
	cout << "        fg      Run a program in foregound mode by path to program" << endl;
        cout << "EXAMPLE: \"pc fg C:\\Users\\Admin\\ABC\"" << endl;
    }
    else if(!strcmp(args[1],"exit")){
        cout << "Exit the TinyShell." << endl;
        cout << "This command does not support any options." << endl; 
    }
    return 0;
}
*/
/**
 * Chuyển directory hiện tại sang directory mới
 * Câu lệnh: cd [path] 
 * cd : trả về đường dẫn directory hiện tại 
 * cd .. :trả về đường dẫn directory cha
 * cd [path]: chuyển current working directory sang directory mới
 * 
 **/
int cd(char **args){
    /**
     * Chuyển directory hiện tại sang directory mới
     * Câu lệnh: cd [path] 
     * cd : trả về đường dẫn directory hiện tại 
     * cd .. :trả về đường dẫn directory cha
     * cd [path]: chuyển current working directory sang directory mới
     * 
     **/
    if(args[1] == NULL){ /* Nếu chỉ gõ lệnh cd */
        system("cd"); /* Dùng luôn lệnh cd có sẵn của Windows (Chơi bẩn nhưng kệ) */
        cout << endl;
        return EXIT_SUCCESS;
    }
    /* Nếu cd [path] */
    else {
        char* path = combinePath(args,1); /* Chuẩn hóa path */
        TCHAR* temp = GetWC(path);
        if(SetCurrentDirectory(temp) == FALSE){ /* Tìm đường dẫn nếu có */
        // cout << args[1] << endl;
        fprintf(stdout,"Not able to set current working directory\n");
        }
    }
    return 0;
}
