#include "database.h"
#include "string.h"
#include <string>
#include <filesystem>
#include "RecordFromFilesystem.h"

namespace FuB {

	Data::Data () {
		dataName = new wchar_t[1000];
		dataName[0] = '\0';
		clientName = new wchar_t[1000];
		clientName[0] = '\0';
		address = new wchar_t[1000];
		address[0] = '\0';
		phoneNumber = new wchar_t[1000];
		phoneNumber[0] = '\0';
		date = new wchar_t[1000];
		date[0] = '\0';
		hozzaAdva = new wchar_t[1000];
		hozzaAdva[0] = '\0';
		filePathFrom = new wchar_t[1000];
		filePathFrom[0] = '\0';
		filePathTo = new wchar_t[1000];
		filePathTo[0] = '\0';
		dirPath = new wchar_t[1000];
		dirPath[0] = '\0';
		notes = new wchar_t[10000];
		notes[0] = '\0';
		secondaryIndex = -1;
	}

	Data::~Data () {
		delete[] dataName;
		delete[] clientName;
		delete[] address;
		delete[] phoneNumber;
		delete[] date;
		delete[] hozzaAdva;
		delete[] filePathFrom;
		delete[] filePathTo;
		delete[] dirPath;
		delete[] notes;
	}

	Data::Data (const Data &oldData) {
		for (int i = 0; i < 1000; i++) {
			this->dataName[i] = oldData.dataName[i];
			this->clientName[i] = oldData.clientName[i];
			this->address[i] = oldData.address[i];
			this->phoneNumber[i] = oldData.phoneNumber[i];
			this->date[i] = oldData.date[i];
			this->hozzaAdva[i] = oldData.hozzaAdva[i];
			this->filePathFrom[i] = oldData.filePathFrom[i];
			this->filePathTo[i] = oldData.filePathTo[i];
			this->dirPath[i] = oldData.dirPath[i];
		}
		for (int i = 0; i < 10000; i++) {
			this->notes[i] = oldData.notes[i];
		}
		this->secondaryIndex = oldData.secondaryIndex;
	}

	void Data::SetDataName (System::String^ dataName, int size) {
		if (size < 1000) {
			for (int i = 0; i < size; i++) {
				this->dataName[i] = dataName[i];
			}
			this->dataName[size] = '\0';
		}
		else {
			return;
		}
	}

	void Data::SetClientName (System::String^ clientName, int size) {
		if (size < 1000) {
			for (int i = 0; i < size; i++) {
				this->clientName[i] = clientName[i];
			}
			this->clientName[size] = '\0';
		}
		else {
			return;
		}
	}

	void Data::SetAddress (System::String^ address, int size) {
		if (size < 1000) {
			for (int i = 0; i < size; i++) {
				this->address[i] = address[i];
			}
			this->address[size] = '\0';
		}
		else {
			return;
		}
	}

	void Data::SetPhoneNumber (System::String^ phoneNumber, int size) {
		if (size < 1000) {
			for (int i = 0; i < size; i++) {
				this->phoneNumber[i] = phoneNumber[i];
			}
			this->phoneNumber[size] = '\0';
		}
		else {
			return;
		}
	}
	void Data::SetDate (System::String^ date, int size) {
		if (size < 1000) {
			for (int i = 0; i < size; i++) {
				this->date[i] = date[i];
			}
			this->date[size] = '\0';
		}
		else {
			return;
		}
	}

	void Data::SetHozzaAdva (System::String^ hozzaAdva, int size) {
		if (size < 1000) {
			for (int i = 0; i < size; i++) {
				this->hozzaAdva[i] = hozzaAdva[i];
			}
			this->hozzaAdva[size] = '\0';
		}
		else {
			return;
		}
	}

	void Data::SetFilePathFrom (System::String^ filePathFrom, int size) {
		if (size < 1000) {
			for (int i = 0; i < size; i++) {
				this->filePathFrom[i] = filePathFrom[i];
			}
			this->filePathFrom[size] = '\0';
		}
		else {
			return;
		}
	}

	void Data::SetFilePathTo (System::String^ filePathTo, int size) {
		if (size < 1000) {
			for (int i = 0; i < size; i++) {
				this->filePathTo[i] = filePathTo[i];
			}
			this->filePathTo[size] = '\0';
		}
		else {
			return;
		}
	}

	void Data::SetDirPath (System::String^ dirPath, int size) {
		if (size < 1000) {
			for (int i = 0; i < size; i++) {
				this->dirPath[i] = dirPath[i];
			}
			this->dirPath[size] = '\0';
		}
		else {
			return;
		}
	}

	void Data::SetNotes (System::String^ notes, int size) {
		if (size < 10000) {
			for (int i = 0; i < size; i++) {
				this->notes[i] = notes[i];
			}
			this->notes[size] = '\0';
		}
		else {
			return;
		}
	}

	void Data::SetSecondaryIndex (int index) {
		secondaryIndex = index;
	}


	wchar_t* Data::GetDataName (int& size) {
		if (dataName != nullptr) {
			int i = 0;
			while (dataName[i] != '\0') {
				i++;
			}
			size = i;
			return dataName;
		}
		else {
			size = 0;
			return nullptr;
		}
	}

	wchar_t* Data::GetClientName (int& size) {
		if (clientName != nullptr) {
			int i = 0;
			while (clientName[i] != '\0') {
				i++;
			}
			size = i;
			return clientName;
		}
		else {
			size = 0;
			return nullptr;
		}
	}

	wchar_t* Data::GetAdress (int& size) {
		if (address != nullptr) {
			int i = 0;
			while (address[i] != '\0') {
				i++;
			}
			size = i;
			return address;
		}
		else {
			size = 0;
			return nullptr;
		}
	}

	wchar_t* Data::GetPhoneNumber (int& size) {
		if (phoneNumber != nullptr) {
			int i = 0;
			while (phoneNumber[i] != '\0') {
				i++;
			}
			size = i;
			return phoneNumber;
		}
		else {
			size = 0;
			return nullptr;
		}
	}

	wchar_t* Data::GetDate (int& size) {
		if (date != nullptr) {
			int i = 0;
			while (date[i] != '\0') {
				i++;
			}
			size = i;
			return date;
		}
		else {
			size = 0;
			return nullptr;
		}
	}

	wchar_t* Data::GetHozzaAdva (int& size) {
		if (hozzaAdva != nullptr) {
			int i = 0;
			while (hozzaAdva[i] != '\0') {
				i++;
			}
			size = i;
			return hozzaAdva;
		}
		else {
			size = 0;
			return nullptr;
		}
	}

	wchar_t* Data::GetFilePathFrom (int& size) {
		if (filePathFrom != nullptr) {
			int i = 0;
			while (filePathFrom[i] != '\0') {
				i++;
			}
			size = i;
			return filePathFrom;
		}
		else {
			size = 0;
			return nullptr;
		}
	}

	wchar_t* Data::GetFilePathTo (int& size) {
		if (filePathTo != nullptr) {
			int i = 0;
			while (filePathTo[i] != '\0') {
				i++;
			}
			size = i;
			return filePathTo;
		}
		else {
			size = 0;
			return nullptr;
		}
	}

	int Data::GetSecondaryIndex () {
		return secondaryIndex;
	}

	wchar_t* Data::GetDirPath (int& size) {
		if (dirPath != nullptr) {
			int i = 0;
			while (dirPath[i] != '\0') {
				i++;
			}
			size = i;
			return dirPath;
		}
		else {
			size = 0;
			return nullptr;
		}
	}

	wchar_t* Data::GetNotes (int& size) {
		if (notes != nullptr) {
			int i = 0;
			while (notes[i] != '\0') {
				i++;
			}
			size = i;
			return notes;
		}
		else {
			size = 0;
			return nullptr;
		}
	}

	DataBase::DataBase () {
		multipleSelected = false;
		multinum = 0;
		size = 0;
		selectedIndex = -1;
	}

	DataBase::~DataBase () {
		delete[] data;
	}

	void DataBase::AddData () {
		if (size > 0) {
			Data* tmpData = new Data[size+1];
			for (int i = 0; i < size; i++) {
				tmpData[i] = this->data[i];
			}
			delete[] this->data;
			this->data = tmpData;
			size++;
		}else if(size == 0)	{
			this->data = new Data[1];
			size = 1;
			selectedIndex = -1;
		}
	}

	void DataBase::DeleteData (int index) {
		if (size < 2) {
			int buffsize;
			_wremove (data[index].GetFilePathTo (buffsize));  //remove the picture
			RemoveRecordFromFilesystem (this, (index)); //remove the record
			_wrmdir(data[index].GetDirPath(buffsize));		 //remove the directory
			delete[] data;
			data = new Data[1];
			size = 0;
			selectedIndex = -1;
			return;
		}
		Data * tmpData = new Data[size];
		for (int i = 0; i < index; i++) {
			tmpData[i] = data[i];
		}
		for (int i = index + 1; i < size; i++) {
			tmpData[i - 1] = data[i];

		}
		int buffsize;
		_wremove (data[index].GetFilePathTo (buffsize));
		RemoveRecordFromFilesystem (this, (index)); //remove the record
		_wrmdir (data[index].GetDirPath (buffsize));
		delete[] data;
		data = tmpData;
		selectedIndex = -1;
		size--;
	}

	void DataBase::AddToMultipleSelect (int newItem) {
		for (int i = 0; i < multinum; i++) {
			if (multipleSelect[i] == newItem)
				return;
		}
		int* tmp = new int[multinum+1];
		for (int i = 0; i < multinum; i++) {
			tmp[i] = multipleSelect[i];
		}
		tmp[multinum] = newItem;
		if(multinum >1)
			delete[] multipleSelect;
		multipleSelect = tmp;
		multinum++;
		SetMultipleSelected (true);
		SortMultipleSelect ();
	}

	void Swap (int *xp, int *yp)
	{
		int temp = *xp;
		*xp = *yp;
		*yp = temp;
	}

	void DataBase::SortMultipleSelect () {
		if (multinum != 1) {
			int i, j;
			for (i = 0; i < multinum - 1; i++) {
				for (j = 0; j < multinum - i - 1; j++) {
					if (multipleSelect[j] > multipleSelect[j + 1])
					Swap (&multipleSelect[j], &multipleSelect[j + 1]);
				}
			}
		}
	}

	void DataBase::SetSelectedIndex (int index) {
		selectedIndex = index;
	}

	void DataBase::SetMultipleSelected (bool ms) {
		if (!ms) {
			if(multinum>0)
				delete[] multipleSelect;
			multinum = 0;
		}
		multipleSelected = ms;
	}

	int DataBase::GetMultiNum () {
		return multinum;
	}

	int DataBase::GetSelectedIndex () {
		return selectedIndex;
	}
	int DataBase::GetSize () {
		return size;
	}

	Data* DataBase::GetData () {
		return this->data;
	}

	bool DataBase::IsMultipleselected () {
		return multipleSelected;
	}

	int* DataBase::GetMultipleSelect () {
		return multipleSelect;
	}
}