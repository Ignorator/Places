#pragma once
#include <fstream>
#include <iostream>

namespace FuB {
	class Data {
		wchar_t* dataName;
		wchar_t* clientName;
		wchar_t* address;
		wchar_t* phoneNumber;
		wchar_t* date;
		wchar_t* hozzaAdva;
		wchar_t* filePathFrom;
		wchar_t* filePathTo;
		wchar_t* dirPath;
		wchar_t* notes;
		int secondaryIndex;
	public:
		Data ();
		~Data ();
		Data (const Data &oldData);
		Data& operator = (Data& other) {
			for (int i = 0; i < 1000; i++) {
				this->dataName[i] = other.dataName[i];
				this->clientName[i] = other.clientName[i];
				this->address[i] = other.address[i];
				this->phoneNumber[i] = other.phoneNumber[i];
				this->date[i] = other.date[i];
				this->hozzaAdva[i] = other.hozzaAdva[i];
				this->filePathFrom[i] = other.filePathFrom[i];
				this->filePathTo[i] = other.filePathTo[i];
				this->dirPath[i] = other.dirPath[i];
			}
			for (int i = 0; i < 10000; i++) {
				this->notes[i] = other.notes[i];
			}
			this->secondaryIndex = other.secondaryIndex;
			return *this;
		}
		void SetDataName (System::String^ dataName, int size);
		void SetClientName (System::String^ clientName, int size);
		void SetAddress (System::String^ address, int size);
		void SetPhoneNumber (System::String^ phoneNumber, int size);
		void SetDate (System::String^ date, int size);
		void SetHozzaAdva (System::String^ hozzaAdva, int size);
		void SetFilePathFrom (System::String^ filePathFrom, int size);
		void SetFilePathTo (System::String^ filePathTo, int size);
		void SetDirPath (System::String^ filePathTo, int size);
		void SetNotes (System::String^ notes, int size);
		void SetSecondaryIndex (int index);

		wchar_t* GetDataName (int& size);
		wchar_t* GetClientName (int& size);
		wchar_t* GetAdress (int& size);
		wchar_t* GetPhoneNumber (int& size);
		wchar_t* GetDate (int& size);
		wchar_t* GetHozzaAdva (int& size);
		wchar_t* GetFilePathFrom (int& size);
		wchar_t* GetFilePathTo (int& size);
		wchar_t* GetDirPath (int& size);
		wchar_t* GetNotes (int& size);
		int GetSecondaryIndex ();
	};


	class DataBase {
		Data* data;
		int size;
		int selectedIndex;

		bool multipleSelected;
		int multinum;
		int* multipleSelect;

		void SortMultipleSelect ();
	public:
		DataBase ();
		~DataBase ();
		void AddData ();
		void DeleteData (int index);
		void SetSelectedIndex (int index);
		void SetMultipleSelected (bool ms);
		void AddToMultipleSelect (int newItem);
		Data* GetData();
		int GetMultiNum ();
		int GetSelectedIndex ();
		int GetSize ();
		int* GetMultipleSelect ();
		bool IsMultipleselected ();
	};
}
