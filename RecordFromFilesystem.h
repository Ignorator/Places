#pragma once
#include "database.h"
#include <filesystem>
#include "windows.h"
#include "string.h"
#include <string>
#include <atlstr.h>
#include <fstream>
#include "RecordToFilesystem.h"
#include <sstream> 

std::vector<std::wstring> GetDirList ();
std::vector<std::wstring> GetOnlyFolderNames (std::vector<std::wstring> stringVector);
int FindLastSpecCharInString (std::wstring string);
void RemoveRecordFromFilesystem (FuB::DataBase* dataBase, int idx);
void FillUpDataBaseFromRecords (FuB::DataBase* dataBase, std::vector<std::wstring> stringVector);
std::wstring readUnicodeFile (const wchar_t* filename);