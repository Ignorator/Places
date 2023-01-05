#include "RecordFromFilesystem.h"


std::vector<std::wstring> GetDirList () {
	std::wstring exePath = GetExePath ();
	exePath.append (L"\\Datas\\");

	std::vector<std::wstring> r;
	for (auto& p : std::filesystem::recursive_directory_iterator (exePath))
		if (p.status ().type () == std::filesystem::file_type::directory)
			r.push_back (p.path ().wstring ());
	return r;
}

std::vector<std::wstring> GetOnlyFolderNames (std::vector<std::wstring> stringVector) {
	std::vector<std::wstring> r;
	for (int i = 0; i < stringVector.size (); i++) {
		int idx = FindLastSpecCharInString (stringVector[i]);
		wchar_t charsToAdd[100];
		int k = 0;
		for (int j = idx + 1; j < stringVector[i].size (); j++) {
			charsToAdd[k] = stringVector[i][j];
			k++;
		}
		charsToAdd[k] = '\0';
		std::wstring stringToAdd (charsToAdd);
		r.push_back (stringToAdd);
	}
	return r;
}

int FindLastSpecCharInString (std::wstring string) {
	int idx = 0;
	for (int i = 0; i < string.size (); i++) {
		if (string[i] == '\\')
			idx = i;
	}
	return idx;
}

void RemoveRecordFromFilesystem (FuB::DataBase* dataBase, int idx) {
	int stringSize;
	FuB::Data* dataAcessor = dataBase->GetData ();
	std::wstring ws_dirPath = (dataAcessor[idx].GetDirPath (stringSize));
	std::wstring ws_currDate = GetDatewithOutSpecCharacters (dataAcessor[idx].GetHozzaAdva (stringSize));
	ws_dirPath.append (L"\\");
	ws_dirPath.append (ws_currDate);
	ws_dirPath.append (L".txt");
	wchar_t recordToRemove[1000];
	for (int i = 0; i < ws_dirPath.size (); i++) {
		recordToRemove[i] = ws_dirPath[i];
	}
	recordToRemove[ws_dirPath.size ()] = '\0';
	_wremove (recordToRemove);  //remove the picture
}

void FillUpDataBaseFromRecords (FuB::DataBase* dataBase, std::vector<std::wstring> stringVector) {
	std::vector<std::wstring> recordList = GetOnlyFolderNames (stringVector);
	if (stringVector.size () > 0) {
		for (int j = 0; j < stringVector.size (); j++) {
			std::wstring oneFilePath = stringVector[j];
			oneFilePath.append (L"\\");
			oneFilePath.append (recordList[j]);
			oneFilePath.append (L".txt");
			std::wstring fromFile;
			wchar_t filePath[1000];
			for (int i = 0; i < oneFilePath.size (); i++) {
				filePath[i] = oneFilePath[i];
			}
			filePath[oneFilePath.size ()] = '\0';
			fromFile = readUnicodeFile (filePath);
			dataBase->AddData ();
			FuB::Data* dataAccessor = dataBase->GetData ();
			int size;
			int m = 0;
			int k = 0;
			while (fromFile[k] != '\r' && fromFile[k + 1] != '\n') {
				dataAccessor[j].GetDataName (size)[m] = fromFile[k];
				m++;
				k++;
			}
			dataAccessor[j].GetDataName (size)[m] = '\0';
			k += 2;
			m = 0;
			while (fromFile[k] != '\r' && fromFile[k + 1] != '\n') {
				dataAccessor[j].GetClientName (size)[m] = fromFile[k];
				m++;
				k++;
			}
			dataAccessor[j].GetClientName (size)[m] = '\0';
			k += 2;
			m = 0;
			while (fromFile[k] != '\r' && fromFile[k + 1] != '\n') {
				dataAccessor[j].GetAdress (size)[m] = fromFile[k];
				m++;
				k++;
			}
			dataAccessor[j].GetAdress (size)[m] = '\0';
			k += 2;
			m = 0;
			while (fromFile[k] != '\r' && fromFile[k + 1] != '\n') {
				dataAccessor[j].GetPhoneNumber (size)[m] = fromFile[k];
				m++;
				k++;
			}
			dataAccessor[j].GetPhoneNumber (size)[m] = '\0';
			k += 2;
			m = 0;
			while (fromFile[k] != '\r' && fromFile[k + 1] != '\n') {
				dataAccessor[j].GetDate (size)[m] = fromFile[k];
				m++;
				k++;
			}
			dataAccessor[j].GetDate (size)[m] = '\0';
			k += 2;
			m = 0;
			while (fromFile[k] != '\r' && fromFile[k + 1] != '\n') {
				dataAccessor[j].GetHozzaAdva (size)[m] = fromFile[k];
				m++;
				k++;
			}
			dataAccessor[j].GetHozzaAdva (size)[m] = '\0';
			k += 2;
			m = 0;
			while (fromFile[k] != '\r' && fromFile[k + 1] != '\n') {
				dataAccessor[j].GetFilePathFrom (size)[m] = fromFile[k];
				m++;
				k++;
			}
			dataAccessor[j].GetFilePathFrom (size)[m] = '\0';
			k += 2;
			m = 0;
			while (fromFile[k] != '\r' && fromFile[k + 1] != '\n') {
				dataAccessor[j].GetFilePathTo (size)[m] = fromFile[k];
				m++;
				k++;
			}
			dataAccessor[j].GetFilePathTo (size)[m] = '\0';
			k += 2;
			m = 0;
			while (fromFile[k] != '\r' && fromFile[k + 1] != '\n') {
				dataAccessor[j].GetDirPath (size)[m] = fromFile[k];
				m++;
				k++;
			}
			dataAccessor[j].GetDirPath (size)[m] = '\0';
			k += 2;
			m = 0;
			while (fromFile.size () > k) {
					dataAccessor[j].GetNotes (size)[m] = fromFile[k];
					m++;
					k++;
			}
			dataAccessor[j].GetNotes (size)[m] = '\0';
		}
	}
}


std::wstring readUnicodeFile (const wchar_t* filename)
{
	std::ifstream wif (filename);
	std::stringstream wss;
	wss << wif.rdbuf ();
	std::string  const &str = wss.str ();
	std::wstring wstr;
	wstr.resize (str.size () / sizeof (wchar_t));
	std::memcpy (&wstr[0], str.c_str (), str.size ()); // copy data into wstring
	return wstr;
}