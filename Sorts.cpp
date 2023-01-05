#include "Sorts.h"
#include <string>

namespace FuB {

	void Sorts::Swap (FuB::Data* xp, FuB::Data* yp)
	{
		FuB::Data temp;
		temp = *xp;
		*xp = *yp;
		*yp = temp;
	}

	void Sorts::SortByAddedDateDown () {
		if (dataBase->GetSize () > 1) {
			FuB::Data* dataAcessor = dataBase->GetData ();
			int i, j;
			for (i = 0; i < dataBase->GetSize () - 1; i++) {
				for (j = 0; j < dataBase->GetSize () - i - 1; j++) {
					//------------------------------------------------------------------------------------------------------------------------------------
					int buffsize;
					std::wstring leftStr = dataAcessor[j].GetHozzaAdva (buffsize);
					char m_LeftDate[1000];
					int m = 0;
					int numberOfSChar = 0;
					for (int n = 0; n < buffsize; n++) {
						if (leftStr[n] == '.' || leftStr[n] == ' ' || leftStr[n] == ':') {
							numberOfSChar++;
							continue;
						}
						m_LeftDate[m] = leftStr[n];
						m++;
					}
					m_LeftDate[buffsize - numberOfSChar] = '\0';
					//------------------------------------------------------------------------------------------------------------------------------------
					int buffsize2;
					std::wstring rightStr = dataAcessor[j + 1].GetHozzaAdva (buffsize2);
					char m_RightDate[1000];
					int m2 = 0;
					int numberOfSChar2 = 0;
					for (int n = 0; n < buffsize2; n++) {
						if (rightStr[n] == '.' || rightStr[n] == ' ' || rightStr[n] == ':') {
							numberOfSChar2++;
							continue;
						}
						m_RightDate[m2] = rightStr[n];
						m2++;
					}
					m_RightDate[buffsize2 - numberOfSChar2] = '\0';

					std::string leftString = m_LeftDate;
					std::string rightString = m_RightDate;
					double leftInt = atof (leftString.c_str ());
					double rightInt = atof (rightString.c_str ());
					if (leftInt < rightInt) {
						Swap (&dataAcessor[j], &dataAcessor[j + 1]);
					}
				}
			}
		}
	}

	void Sorts::SortByAddedDateUp () {
		if (dataBase->GetSize () > 1) {
			FuB::Data* dataAcessor = dataBase->GetData ();
			int i, j;
			for (i = 0; i < dataBase->GetSize () - 1; i++) {
				for (j = 0; j < dataBase->GetSize () - i - 1; j++) {
					//------------------------------------------------------------------------------------------------------------------------------------
					int buffsize;
					std::wstring leftStr = dataAcessor[j].GetHozzaAdva (buffsize);
					char m_LeftDate[1000];
					int m = 0;
					int numberOfSChar = 0;
					for (int n = 0; n < buffsize; n++) {
						if (leftStr[n] == '.' || leftStr[n] == ' ' || leftStr[n] == ':') {
							numberOfSChar++;
							continue;
						}
						m_LeftDate[m] = leftStr[n];
						m++;
					}
					m_LeftDate[buffsize - numberOfSChar] = '\0';
					//------------------------------------------------------------------------------------------------------------------------------------
					int buffsize2;
					std::wstring rightStr = dataAcessor[j + 1].GetHozzaAdva (buffsize2);
					char m_RightDate[1000];
					int m2 = 0;
					int numberOfSChar2 = 0;
					for (int n = 0; n < buffsize2; n++) {
						if (rightStr[n] == '.' || rightStr[n] == ' ' || rightStr[n] == ':') {
							numberOfSChar2++;
							continue;
						}
						m_RightDate[m2] = rightStr[n];
						m2++;
					}
					m_RightDate[buffsize2 - numberOfSChar2] = '\0';

					std::string leftString = m_LeftDate;
					std::string rightString = m_RightDate;
					double leftInt = atof (leftString.c_str ());
					double rightInt = atof (rightString.c_str ());
					if (leftInt > rightInt) {
						Swap (&dataAcessor[j], &dataAcessor[j + 1]);
					}
				}
			}
		}
	}



	void Sorts::SortByDateDown () {
		if (dataBase->GetSize () > 1) {
			FuB::Data* dataAcessor = dataBase->GetData ();
			int i, j;
			for (i = 0; i < dataBase->GetSize () - 1; i++) {
				for (j = 0; j < dataBase->GetSize () - i - 1; j++) {
					//------------------------------------------------------------------------------------------------------------------------------------
					int buffsize;
					std::wstring leftStr = dataAcessor[j].GetDate (buffsize);
					char m_LeftDate[1000];
					int m = 0;
					int numberOfSChar = 0;
					for (int n = 0; n < buffsize; n++) {
						if (leftStr[n] == '.' || leftStr[n] == ' ' || leftStr[n] == ':') {
							numberOfSChar++;
							continue;
						}
						m_LeftDate[m] = leftStr[n];
						m++;
					}
					m_LeftDate[buffsize - numberOfSChar] = '\0';
					//------------------------------------------------------------------------------------------------------------------------------------
					int buffsize2;
					std::wstring rightStr = dataAcessor[j + 1].GetDate (buffsize2);
					char m_RightDate[1000];
					int m2 = 0;
					int numberOfSChar2 = 0;
					for (int n = 0; n < buffsize2; n++) {
						if (rightStr[n] == '.' || rightStr[n] == ' ' || rightStr[n] == ':') {
							numberOfSChar2++;
							continue;
						}
						m_RightDate[m2] = rightStr[n];
						m2++;
					}
					m_RightDate[buffsize2 - numberOfSChar2] = '\0';

					std::string leftString = m_LeftDate;
					std::string rightString = m_RightDate;
					double leftInt = atof (leftString.c_str ());
					double rightInt = atof (rightString.c_str ());
					if (leftInt < rightInt) {
						Swap (&dataAcessor[j], &dataAcessor[j + 1]);
					}
				}
			}
		}
	}


	void Sorts::SortByDateUp () {
		if (dataBase->GetSize () > 1) {
			FuB::Data* dataAcessor = dataBase->GetData ();
			int i, j;
			for (i = 0; i < dataBase->GetSize () - 1; i++) {
				for (j = 0; j < dataBase->GetSize () - i - 1; j++) {
					//------------------------------------------------------------------------------------------------------------------------------------
					int buffsize;
					std::wstring leftStr = dataAcessor[j].GetDate (buffsize);
					char m_LeftDate[1000];
					int m = 0;
					int numberOfSChar = 0;
					for (int n = 0; n < buffsize; n++) {
						if (leftStr[n] == '.' || leftStr[n] == ' ' || leftStr[n] == ':') {
							numberOfSChar++;
							continue;
						}
						m_LeftDate[m] = leftStr[n];
						m++;
					}
					m_LeftDate[buffsize - numberOfSChar] = '\0';
					//------------------------------------------------------------------------------------------------------------------------------------
					int buffsize2;
					std::wstring rightStr = dataAcessor[j + 1].GetDate (buffsize2);
					char m_RightDate[1000];
					int m2 = 0;
					int numberOfSChar2 = 0;
					for (int n = 0; n < buffsize2; n++) {
						if (rightStr[n] == '.' || rightStr[n] == ' ' || rightStr[n] == ':') {
							numberOfSChar2++;
							continue;
						}
						m_RightDate[m2] = rightStr[n];
						m2++;
					}
					m_RightDate[buffsize2 - numberOfSChar2] = '\0';

					std::string leftString = m_LeftDate;
					std::string rightString = m_RightDate;
					double leftInt = atof (leftString.c_str ());
					double rightInt = atof (rightString.c_str ());
					if (leftInt < rightInt) {
						Swap (&dataAcessor[j], &dataAcessor[j + 1]);
					}
				}
			}
		}
	}


	void Sorts::SortByDataNameDown () {
		if (dataBase->GetSize () > 1) {
			FuB::Data* dataAcessor = dataBase->GetData ();
			int i, j, size;
			for (i = 0; i < dataBase->GetSize () - 1; i++) {
				for (j = 0; j < dataBase->GetSize () - i - 1; j++) {
					std::wstring leftStr = dataAcessor[j].GetDataName (size);
					std::wstring rightStr = dataAcessor[j + 1].GetDataName (size);
					if (leftStr < rightStr) {
						Swap (&dataAcessor[j], &dataAcessor[j + 1]);
					}
				}
			}
		}
	}


	void Sorts::SortByDataNameUp () {
			if (dataBase->GetSize () > 1) {
				FuB::Data* dataAcessor = dataBase->GetData ();
				int i, j, size;
				for (i = 0; i < dataBase->GetSize () - 1; i++) {
					for (j = 0; j < dataBase->GetSize () - i - 1; j++) {
						std::wstring leftStr = dataAcessor[j].GetDataName (size);
						std::wstring rightStr = dataAcessor[j + 1].GetDataName (size);
						if (leftStr > rightStr) {
							Swap (&dataAcessor[j], &dataAcessor[j + 1]);
						}
					}
				}
			}
		}


	void Sorts::SortByNameDown () {
		if (dataBase->GetSize () > 1) {
			FuB::Data* dataAcessor = dataBase->GetData ();
			int i, j, size;
			for (i = 0; i < dataBase->GetSize () - 1; i++) {
				for (j = 0; j < dataBase->GetSize () - i - 1; j++) {
					std::wstring leftStr = dataAcessor[j].GetClientName (size);
					std::wstring rightStr = dataAcessor[j + 1].GetClientName (size);
					if (leftStr < rightStr) {
						Swap (&dataAcessor[j], &dataAcessor[j + 1]);
					}
				}
			}
		}
	}


	void Sorts::SortByNameUp () {
		if (dataBase->GetSize () > 1) {
			FuB::Data* dataAcessor = dataBase->GetData ();
			int i, j, size;
			for (i = 0; i < dataBase->GetSize () - 1; i++) {
				for (j = 0; j < dataBase->GetSize () - i - 1; j++) {
					std::wstring leftStr = dataAcessor[j].GetClientName (size);
					std::wstring rightStr = dataAcessor[j + 1].GetClientName (size);
					if (leftStr > rightStr) {
						Swap (&dataAcessor[j], &dataAcessor[j + 1]);
					}
				}
			}
		}
	}


	void Sorts::SortByAddressUp () {
		if (dataBase->GetSize () > 1) {
			FuB::Data* dataAcessor = dataBase->GetData ();
			int i, j, size;
			for (i = 0; i < dataBase->GetSize () - 1; i++) {
				for (j = 0; j < dataBase->GetSize () - i - 1; j++) {
					std::wstring leftStr = dataAcessor[j].GetAdress (size);
					std::wstring rightStr = dataAcessor[j + 1].GetAdress (size);
					if (leftStr > rightStr) {
						Swap (&dataAcessor[j], &dataAcessor[j + 1]);
					}
				}
			}
		}
	}


	void Sorts::SortByAddressDown () {
		if (dataBase->GetSize () > 1) {
			FuB::Data* dataAcessor = dataBase->GetData ();
			int i, j, size;
			for (i = 0; i < dataBase->GetSize () - 1; i++) {
				for (j = 0; j < dataBase->GetSize () - i - 1; j++) {
					std::wstring leftStr = dataAcessor[j].GetAdress (size);
					std::wstring rightStr = dataAcessor[j + 1].GetAdress (size);
					if (leftStr < rightStr) {
						Swap (&dataAcessor[j], &dataAcessor[j + 1]);
					}
				}
			}
		}
	}
}