#include "OpenImage.h"

void ShowPicture (FuB::DataBase* dataBase) {
	if (!dataBase->IsMultipleselected () && dataBase->GetSelectedIndex () != -1) {
		//open file
		int size;
		FuB::Data* dataAcessor = dataBase->GetData ();
		std::wstring filePathTo = dataAcessor[dataBase->GetSelectedIndex ()].GetFilePathTo (size);
		if (filePathTo.length () > 1)
			ShellExecute (0, 0, dataAcessor[dataBase->GetSelectedIndex ()].GetFilePathTo (size), 0, 0, SW_SHOW);
	}
}