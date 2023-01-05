#pragma once
#include "database.h"
#include <filesystem>
#include "windows.h"
#include "string.h"
#include <string>
#include <atlstr.h>
#include <fstream>

void CreateDefaultDirectories ();
void CreateNewDirectoryForRecord (FuB::DataBase* dataBase);
void CopyImageToRecordDirectory (FuB::DataBase* dataBase, int idx);
void SaveRecordToFilesystem (FuB::DataBase* dataBase, int idx);
std::wstring GetExePath ();
std::wstring GetDatewithOutSpecCharacters (std::wstring date);
void StringToWString (const std::string &s, std::wstring &ws);
std::wstring FindName (std::wstring& searchIn);
std::wstring FindFormat (std::wstring& searchIn);
void CopyImage (const WCHAR* sourcePath, const WCHAR* targetPath);