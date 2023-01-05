#include "RecordToFilesystem.h"

void CreateDefaultDirectories () {
	std::wstring exePath = GetExePath ();
	exePath.append (L"\\Datas");
	std::wstring newDir = exePath;
	const wchar_t* newDirectory = newDir.c_str ();
	_wmkdir (newDirectory);
}

void CreateNewDirectoryForRecord (FuB::DataBase* dataBase) {
	FuB::Data* dataAcessor = dataBase->GetData ();
	std::wstring exePath = GetExePath ();
	std::wstring newDir;
	const wchar_t* newDirectory;
	int stringSize;
	std::wstring ws_currDate = GetDatewithOutSpecCharacters (dataAcessor[dataBase->GetSize () - 1].GetHozzaAdva (stringSize));

	exePath.append (L"\\Datas\\");
	exePath.append (ws_currDate);
	newDir = exePath;
	newDirectory = newDir.c_str ();
	_wmkdir (newDirectory);

	System::String^ newDirPath = gcnew System::String (newDir.c_str ());
	dataAcessor[dataBase->GetSize () - 1].SetDirPath (newDirPath, newDirPath->Length);

}

void CopyImageToRecordDirectory (FuB::DataBase* dataBase, int idx) {
	FuB::Data* dataAcessor = dataBase->GetData ();
	std::wstring exePath = GetExePath ();
	std::wstring newDir;
	int stringSize;
	std::wstring ws_currDate = GetDatewithOutSpecCharacters (dataAcessor[idx].GetHozzaAdva (stringSize));
	std::wstring ws_filePathFrom (dataAcessor[idx].GetFilePathFrom (stringSize));

	exePath.append (L"\\Datas\\");
	exePath.append (ws_currDate);
	exePath.append (L"\\");
	exePath.append (FindName (ws_filePathFrom));
	exePath.append (FindFormat (ws_filePathFrom));

	const wchar_t* targetPath = exePath.c_str ();
	const wchar_t* sourcePath = ws_filePathFrom.c_str ();

	CopyImage (sourcePath, targetPath);

	System::String^ newFilePathTo = gcnew System::String (exePath.c_str ());
	dataAcessor[idx].SetFilePathTo (newFilePathTo, newFilePathTo->Length);
}


void SaveRecordToFilesystem (FuB::DataBase* dataBase, int idx) {
	int stringSize;
	int buffsize;
	FuB::Data* dataAcessor = dataBase->GetData ();
	std::wstring ws_dirPath = (dataAcessor[idx].GetDirPath (stringSize));
	std::wstring ws_currDate = GetDatewithOutSpecCharacters (dataAcessor[idx].GetHozzaAdva (stringSize));
	ws_dirPath.append (L"\\");
	ws_dirPath.append (ws_currDate);
	ws_dirPath.append (L".txt");

	std::ofstream wnewFile (ws_dirPath, std::ios::out | std::ios::binary);
	std::wstring wdataString (dataAcessor[idx].GetDataName (buffsize));
	wdataString.append (L"\r\n");
	wdataString.append (dataAcessor[idx].GetClientName (buffsize));
	wdataString.append (L"\r\n");
	wdataString.append (dataAcessor[idx].GetAdress(buffsize));
	wdataString.append (L"\r\n");
	wdataString.append (dataAcessor[idx].GetPhoneNumber (buffsize));
	wdataString.append (L"\r\n");
	wdataString.append (dataAcessor[idx].GetDate (buffsize));
	wdataString.append (L"\r\n");
	wdataString.append (dataAcessor[idx].GetHozzaAdva (buffsize));
	wdataString.append (L"\r\n");
	wdataString.append (dataAcessor[idx].GetFilePathFrom (buffsize));
	wdataString.append (L"\r\n");
	wdataString.append (dataAcessor[idx].GetFilePathTo (buffsize));
	wdataString.append (L"\r\n");
	wdataString.append (dataAcessor[idx].GetDirPath (buffsize));
	wdataString.append (L"\r\n");
	wdataString.append (dataAcessor[idx].GetNotes (buffsize));
	wdataString.append (L"\r\n");

	char* strc = (char *)wdataString.c_str ();
	wnewFile.write (strc, sizeof (wchar_t)*wdataString.size ());
	wnewFile.close ();
}

std::wstring GetExePath () {
	TCHAR buffer[MAX_PATH];
	GetCurrentDirectory (MAX_PATH, buffer);
	CString str (buffer);
	bool isFirst = true;
	WCHAR result[MAX_PATH];
	for (int i = 0; i < str.GetLength (); i++) {
		result[i] = str[i];
	}
	result[str.GetLength ()] = '\0';
	return result;
}

std::wstring GetDatewithOutSpecCharacters (std::wstring date) {
	wchar_t m_currDate[1000];
	int j = 0;
	int numberOfSChar = 0;
	for (int i = 0; i < date.size(); i++) {
		if (date[i] == '.' || date[i] == ' ' || date[i] == ':') {
			numberOfSChar++;
			continue;
		}
		m_currDate[j] = date[i];
		j++;
	}
	m_currDate[date.size() - numberOfSChar] = '\0';
	return m_currDate;
}

void StringToWString (const std::string &s, std::wstring &ws)
{
	std::wstring wsTmp (s.begin (), s.end ());

	ws = wsTmp;
}

std::wstring FindName (std::wstring& searchIn) {
	wchar_t nameToAppend[100];
	int lastFoundIndex = 0;
	for (int i = 0; i < searchIn.length (); i++) {
		if (searchIn[i] == '\\')
			lastFoundIndex = i;
	}
	lastFoundIndex++;
	int j = 0;
	for (int i = lastFoundIndex; i < searchIn.length () - 4; i++, j++) {
		nameToAppend[j] = searchIn[i];
	}
	nameToAppend[j] = '\0';
	return nameToAppend;
}

std::wstring FindFormat (std::wstring& searchIn) {
	int lastFoundIndex = 0;
	std::wstring formatToAppend;
	for (int i = 0; i < searchIn.length (); i++) {
		if (searchIn[i] == '.')
			lastFoundIndex = i;
	}
	if (searchIn[lastFoundIndex + 1] == 'p' && searchIn[lastFoundIndex + 2] == 'n') {
		std::wstring fta (L".png");
		formatToAppend = fta;
	} else if (searchIn[lastFoundIndex + 1] == 'P' && searchIn[lastFoundIndex + 2] == 'N') {
		std::wstring fta (L".png");
		formatToAppend = fta;
	} else if (searchIn[lastFoundIndex + 1] == 'p' && searchIn[lastFoundIndex + 2] == 'd') {
		std::wstring fta (L".pdf");
		formatToAppend = fta;
	} else if (searchIn[lastFoundIndex + 1] == 'P' && searchIn[lastFoundIndex + 2] == 'D') {
		std::wstring fta (L".pdf");
		formatToAppend = fta;
	} else if (searchIn[lastFoundIndex + 1] == 'j' && searchIn[lastFoundIndex + 2] == 'p' && searchIn[lastFoundIndex + 3] == 'g') {
		std::wstring fta (L".jpg");
		formatToAppend = fta;
	} else if (searchIn[lastFoundIndex + 1] == 'J' && searchIn[lastFoundIndex + 2] == 'P' && searchIn[lastFoundIndex + 3] == 'G') {
		std::wstring fta (L".jpg");
		formatToAppend = fta;
	} else if (searchIn[lastFoundIndex + 1] == 'j' && searchIn[lastFoundIndex + 2] == 'p' && searchIn[lastFoundIndex + 3] == 'e') {
		std::wstring fta (L".jpeg");
		formatToAppend = fta;
	} else if (searchIn[lastFoundIndex + 1] == 'J' && searchIn[lastFoundIndex + 2] == 'P' && searchIn[lastFoundIndex + 3] == 'E') {
		std::wstring fta (L".jpeg");
		formatToAppend = fta;
	}

	return formatToAppend;
}

void CopyImage (const WCHAR* sourcePath, const WCHAR* targetPath) {
	CopyFile (sourcePath, targetPath, FALSE);
}