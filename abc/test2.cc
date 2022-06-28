#include <windows.h>

#include <stdio.h>

#define BUFFER_SIZE 200

 

int main(void)

{

TCHAR infoBuf[BUFFER_SIZE];

LPCWSTR lpPathName = L"C:\\Program Files\\Microsoft sql server";

// Get the current working directory

if(!GetCurrentDirectory(BUFFER_SIZE, infoBuf))

printf("GetCurrentDirectory() failed!\n");

printf("Your current directory is: %S\n", infoBuf);

printf("Changing directory...\n");

// Set to current working directory

if(!SetCurrentDirectory(lpPathName))

printf("SetCurrentDirectory() failed!\n");

 

// Do some verification...

if(!GetCurrentDirectory(BUFFER_SIZE, infoBuf))

printf("GetCurrentDirectory() failed!\n");

printf("Your current directory is: %S\n", infoBuf);

 

// Get and display the Windows directory.

if(!GetWindowsDirectory(infoBuf, BUFFER_SIZE))

printf("GetWindowsDirectory() failed!\n");

printf("Your Windows directory is: %S\n", infoBuf);

 

// Get and display the system directory.

if(!GetSystemDirectory(infoBuf, BUFFER_SIZE))

printf("GetSystemDirectory() failed!\n");

printf("Your system directory is: %S\n", infoBuf);

return 0;

}