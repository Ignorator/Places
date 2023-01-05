#include "ListViewDrawer.h"

void ReDrawListView (FuB::DataBase* dataBase, System::Windows::Forms::ListView^  listView){
	listView->Items->Clear ();
	FuB::Data* dataAcessor = dataBase->GetData ();
	int size;
	for (int i = 0; i < dataBase->GetSize (); i++) {
		std::wstring m_dataName (dataAcessor[i].GetDataName (size));
		std::wstring m_clientName (dataAcessor[i].GetClientName (size));
		std::wstring m_address (dataAcessor[i].GetAdress (size));
		std::wstring m_phonenumber (dataAcessor[i].GetPhoneNumber (size));
		std::wstring m_date (dataAcessor[i].GetDate (size));
		std::wstring m_hozzaadva (dataAcessor[i].GetHozzaAdva (size));
		std::wstring m_jegyzetek (dataAcessor[i].GetNotes (size));

		System::String^ s_dataName = gcnew System::String (m_dataName.c_str ());
		System::String^ s_clientName = gcnew System::String (m_clientName.c_str ());
		System::String^ s_address = gcnew System::String (m_address.c_str ());
		System::String^ s_phonenumber = gcnew System::String (m_phonenumber.c_str ());
		System::String^ s_date = gcnew System::String (m_date.c_str ());
		System::String^ s_hozzaadva = gcnew System::String (m_hozzaadva.c_str ());
		System::String^ s_jegyzetek = gcnew System::String (m_jegyzetek.c_str ());

		System::Windows::Forms::ListViewItem^  listViewItem = (gcnew System::Windows::Forms::ListViewItem (gcnew cli::array< System::String^  > (7) {
				s_dataName,
				s_address,
				s_clientName,
				s_phonenumber,
				s_date,
				s_hozzaadva,
				s_jegyzetek,
		}, -1));
		listView->Items->Add (listViewItem);
	}
}