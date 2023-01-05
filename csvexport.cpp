#include "csvexport.h"

void CsvExportOneRecord (FuB::DataBase* dataBase, System::String^ path) {

	int buffsize;
	int idx = dataBase->GetSelectedIndex ();
	FuB::Data* dataAcessor = dataBase->GetData ();

	wchar_t w_path[1000];
	for (int i = 0; i < path->Length; i++) {
		w_path[i] = path[i];
	}
	w_path[path->Length] = '\0';
	std::wstring ws_dirPath(w_path);
	std::wofstream wnewFile;
	wnewFile.imbue (std::locale (std::locale::empty (), new std::codecvt_utf8<wchar_t, 0x10ffff, std::generate_header>));
	wnewFile.open(ws_dirPath, std::ios::out | std::ios::app);
	std::wstring wdataString;

	wdataString.append (L"Elnevezés");
	wdataString.append (L";");
	wdataString.append (L"Név");
	wdataString.append (L";");
	wdataString.append (L"Cím");
	wdataString.append (L";");
	wdataString.append (L"Telefonszám");
	wdataString.append (L";");
	wdataString.append (L"Dátum");
	wdataString.append (L";");
	wdataString.append (L"Hozzáadva");
	wdataString.append (L";");
	wdataString.append (L"Megjegyzések");
	wdataString.append (L"\n");

	wdataString.append (dataAcessor[idx].GetDataName (buffsize));
	wdataString.append (L";");
	wdataString.append (dataAcessor[idx].GetClientName (buffsize));
	wdataString.append (L";");
	wdataString.append (dataAcessor[idx].GetAdress (buffsize));
	wdataString.append (L";");
	wdataString.append (dataAcessor[idx].GetPhoneNumber (buffsize));
	wdataString.append (L";");
	wdataString.append (dataAcessor[idx].GetDate (buffsize));
	wdataString.append (L";");
	wdataString.append (dataAcessor[idx].GetHozzaAdva (buffsize));
 	wdataString.append (L";");

	std::wstring notesbuffer(dataAcessor[idx].GetNotes (buffsize));
	wchar_t* noteswithoutnewlines = new wchar_t[notesbuffer.size ()+1];
	int j = 0;
	int newline = 0;
	for (int i = 0; i < notesbuffer.size (); i++) {
		if (notesbuffer[i] == '\r') {
			noteswithoutnewlines[j] = ' ';
			j++;
			i++;
			newline++;
			continue;
		}
		noteswithoutnewlines[j] = notesbuffer[i];
		j++;
	}
	noteswithoutnewlines[notesbuffer.size () - newline] = '\0';

	std::wstring notes (noteswithoutnewlines);
 	wdataString.append (notes);
	wdataString.append (L"\n");

	wchar_t* strc = new wchar_t[wdataString.size () + 1];
	for (int i = 0; i < wdataString.size (); i++) {
		strc[i] = wdataString[i];
	}
	strc[wdataString.size ()] = '\0';
	wnewFile.write (strc, sizeof (char)*wdataString.size ());
	wnewFile.close ();
	delete[] strc;
	delete[] noteswithoutnewlines;
}

void CsvExportMultipleRecord (FuB::DataBase* dataBase, System::String^ path) {

	int buffsize;
	FuB::Data* dataAcessor = dataBase->GetData ();

	wchar_t w_path[1000];
	for (int i = 0; i < path->Length; i++) {
		w_path[i] = path[i];
	}
	w_path[path->Length] = '\0';
	std::wstring ws_dirPath (w_path);
	std::wofstream wnewFile;
	wnewFile.imbue (std::locale (std::locale::empty (), new std::codecvt_utf8<wchar_t, 0x10ffff, std::generate_header>));
	wnewFile.open (ws_dirPath, std::ios::out | std::ios::app);
	std::wstring wdataString;

	wdataString.append (L"Elnevezés");
	wdataString.append (L";");
	wdataString.append (L"Név");
	wdataString.append (L";");
	wdataString.append (L"Cím");
	wdataString.append (L";");
	wdataString.append (L"Telefonszám");
	wdataString.append (L";");
	wdataString.append (L"Dátum");
	wdataString.append (L";");
	wdataString.append (L"Hozzáadva");
	wdataString.append (L";");
	wdataString.append (L"Megjegyzések");
	wdataString.append (L"\n");

	int idx;
	for (int recordnum = 0; recordnum < dataBase->GetMultiNum (); recordnum++) {
		idx = dataBase->GetMultipleSelect ()[recordnum];

		wdataString.append (dataAcessor[idx].GetDataName (buffsize));
		wdataString.append (L";");
		wdataString.append (dataAcessor[idx].GetClientName (buffsize));
		wdataString.append (L";");
		wdataString.append (dataAcessor[idx].GetAdress (buffsize));
		wdataString.append (L";");
		wdataString.append (dataAcessor[idx].GetPhoneNumber (buffsize));
		wdataString.append (L";");
		wdataString.append (dataAcessor[idx].GetDate (buffsize));
		wdataString.append (L";");
		wdataString.append (dataAcessor[idx].GetHozzaAdva (buffsize));
		wdataString.append (L";");

		std::wstring notesbuffer (dataAcessor[idx].GetNotes (buffsize));
		wchar_t* noteswithoutnewlines = new wchar_t[notesbuffer.size () + 1];
		int j = 0;
		int newline = 0;
		for (int i = 0; i < notesbuffer.size (); i++) {
			if (notesbuffer[i] == '\r') {
				noteswithoutnewlines[j] = ' ';
				j++;
				i++;
				newline++;
				continue;
			}
			noteswithoutnewlines[j] = notesbuffer[i];
			j++;
		}
		noteswithoutnewlines[notesbuffer.size () - newline] = '\0';
		std::wstring notes (noteswithoutnewlines);
		wdataString.append (notes);
		wdataString.append (L"\n");
		delete[] noteswithoutnewlines;
	}

	wchar_t* strc = new wchar_t[wdataString.size () + 1];
	for (int i = 0; i < wdataString.size (); i++) {
		strc[i] = wdataString[i];
	}
	strc[wdataString.size ()] = '\0';

	wnewFile.write (strc, sizeof (char)*wdataString.size ());
	wnewFile.close ();
	delete[] strc;
}