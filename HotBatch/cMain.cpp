
#include "Variables.h"
#define BUFSIZE MAX_PATH

void readEnvironment()
{
	char currPath[MAX_PATH];
	GetCurrentDirectoryA(MAX_PATH, currPath);
	s_global_CurrentPath = currPath;
	s_global_cfgFilePath = currPath + s_configfile;
}

void loadHotkeys()
{
	char hotkey01_buffer[100];
	LPCSTR hotkey_file_lpcstr = const_cast<char *>(s_global_cfgFilePath.c_str());

	i_global_hotkey01 = GetPrivateProfileIntA("HOTKEYS", "hotkey01", 0 , hotkey_file_lpcstr);
	i_global_hotkey02 = GetPrivateProfileIntA("HOTKEYS", "hotkey02", 0, hotkey_file_lpcstr);
	i_global_hotkey03 = GetPrivateProfileIntA("HOTKEYS", "hotkey03", 0, hotkey_file_lpcstr);
	i_global_hotkey04 = GetPrivateProfileIntA("HOTKEYS", "hotkey04", 0, hotkey_file_lpcstr);
	i_global_hotkey05 = GetPrivateProfileIntA("HOTKEYS", "hotkey05", 0, hotkey_file_lpcstr);
	i_global_hotkey06 = GetPrivateProfileIntA("HOTKEYS", "hotkey06", 0, hotkey_file_lpcstr);
	i_global_hotkey07 = GetPrivateProfileIntA("HOTKEYS", "hotkey07", 0, hotkey_file_lpcstr);
	i_global_hotkey08 = GetPrivateProfileIntA("HOTKEYS", "hotkey08", 0, hotkey_file_lpcstr);
	i_global_hotkey09 = GetPrivateProfileIntA("HOTKEYS", "hotkey09", 0, hotkey_file_lpcstr);

	if (bl_logging) { cout << "Following hotkeys are available : " << endl; }
	if (bl_logging) {
		cout << s_global_hotkey01 << endl << s_global_hotkey02 << endl << s_global_hotkey03 << endl <<
			s_global_hotkey04 << endl << s_global_hotkey05 << endl << s_global_hotkey06 << endl << s_global_hotkey07 << endl
			<< s_global_hotkey08 << endl << s_global_hotkey09 << endl;
	}
}

void mainThread()
{
	cout << "Launching main thread..." << endl;
	cout << "Awaiting input";

	while (true)
	{
		cout << ".";

		if (GetAsyncKeyState(i_global_hotkey01))
		{
			cout << "\nexecuting command!" << endl;
			const char * c = s_global_batch01.c_str();
			system(c);
		}

		if (GetAsyncKeyState(i_global_hotkey02))
		{
			cout << "\nexecuting command!" << endl;
			const char * c = s_global_batch02.c_str();
			system(c);
		}

		if (GetAsyncKeyState(i_global_hotkey03))
		{
			cout << "\nexecuting command!" << endl;
			const char * c = s_global_batch03.c_str();
			system(c);
		}

		if (GetAsyncKeyState(i_global_hotkey04))
		{
			cout << "\nexecuting command!" << endl;
			const char * c = s_global_batch04.c_str();
			system(c);
		}

		if (GetAsyncKeyState(i_global_hotkey05))
		{
			cout << "\nexecuting command!" << endl;
			const char * c = s_global_batch05.c_str();
			system(c);
		}

		if (GetAsyncKeyState(i_global_hotkey06))
		{
			cout << "\nexecuting command!" << endl;
			const char * c = s_global_batch06.c_str();
			system(c);
		}

		if (GetAsyncKeyState(i_global_hotkey07))
		{
			cout << "\nexecuting command!" << endl;
			const char * c = s_global_batch07.c_str();
			system(c);
		}

		if (GetAsyncKeyState(i_global_hotkey08))
		{
			cout << "\nexecuting command!" << endl;
			const char * c = s_global_batch08.c_str();
			system(c);
		}

		if (GetAsyncKeyState(i_global_hotkey09))
		{
			cout << "\nexecuting command!" << endl;
			const char * c = s_global_batch09.c_str();
			system(c);
		}

		//Free some memory
		Sleep(i_sleeptime);
	}
}

void loadScripts()
{

	string scriptFolder = "\\scripts\\";
	string scriptExtension = ".bat";

	string absoluteScriptFileName01 = s_global_CurrentPath + scriptFolder + "script01" + scriptExtension;
	s_global_batch01 = absoluteScriptFileName01.c_str();

	string absoluteScriptFileName02 = s_global_CurrentPath + scriptFolder + "script02" + scriptExtension;
	s_global_batch02 = absoluteScriptFileName02.c_str();

	string absoluteScriptFileName03 = s_global_CurrentPath + scriptFolder + "script03" + scriptExtension;
	s_global_batch03 = absoluteScriptFileName03.c_str();

	string absoluteScriptFileName04 = s_global_CurrentPath + scriptFolder + "script04" + scriptExtension;
	s_global_batch04 = absoluteScriptFileName04.c_str();

	string absoluteScriptFileName05 = s_global_CurrentPath + scriptFolder + "script05" + scriptExtension;
	s_global_batch05 = absoluteScriptFileName05.c_str();

	string absoluteScriptFileName06 = s_global_CurrentPath + scriptFolder + "script06" + scriptExtension;
	s_global_batch06 = absoluteScriptFileName06.c_str();

	string absoluteScriptFileName07 = s_global_CurrentPath + scriptFolder + "script07" + scriptExtension;
	s_global_batch07 = absoluteScriptFileName07.c_str();

	string absoluteScriptFileName08 = s_global_CurrentPath + scriptFolder + "script08" + scriptExtension;
	s_global_batch08 = absoluteScriptFileName08.c_str();

	string absoluteScriptFileName09 = s_global_CurrentPath + scriptFolder + "script09" + scriptExtension;
	s_global_batch09 = absoluteScriptFileName09.c_str();

}

void loadSettings()
{
	char logging_buffer[100];
	LPCSTR logging_lpc = const_cast<char *>(s_global_cfgFilePath.c_str());
	GetPrivateProfileStringA("SETTINGS", "logging", "f", logging_buffer, 100, logging_lpc);
	if (stricmp("true", logging_buffer) == 0) { bl_logging = true; };
	if (bl_logging) { cout << "logging is true !! " << endl; }

	char debugmode_buffer[100];
	LPCSTR debugmode_lpc = const_cast<char *>(s_global_cfgFilePath.c_str());
	GetPrivateProfileStringA("SETTINGS", "debugmode", "f", debugmode_buffer, 100, debugmode_lpc);
	if (stricmp("true", debugmode_buffer) == 0) { bl_debugmode = true; }

	LPCSTR sleep_lpc = const_cast<char *>(s_global_cfgFilePath.c_str());
	i_sleeptime = GetPrivateProfileIntA("SETTINGS", "sleeptime", 500, sleep_lpc);

}

void initialize()
{

	system("TITLE HotBatch - sandaasu");

	readEnvironment(); if (bl_logging) { cout << "loaded environmental variables .." << endl; }
	loadSettings(); if (bl_logging) { cout << "loaded settings .." << endl; }

	if (bl_logging) { cout << "Booting up.." << endl; }
	if (bl_logging) { cout << "Executing internal methods..." << endl; }

	
	loadHotkeys(); if (bl_logging) { cout << "loaded hotkeys .." << endl; }
	loadScripts(); if (bl_logging) { cout << "loaded scripts .." << endl; }
	mainThread(); if (bl_logging) { cout << "launched main thread .." << endl; }
}

void main()
{
	int err = GetLastError();
	initialize();
}