#pragma once
#include "database.h"

namespace FuB {
	class Sorts {
	public:
		Sorts::Sorts () {};
		Sorts::Sorts (FuB::DataBase* dataBase) : dataBase (dataBase) {};
	private: FuB::DataBase* dataBase;
	public:
		void Swap (FuB::Data* xp, FuB::Data* yp);

		void SortByAddedDateDown ();
		void SortByAddedDateUp ();
		void SortByDateDown ();
		void SortByDateUp ();
		void SortByDataNameDown ();
		void SortByDataNameUp ();
		void SortByNameDown ();
		void SortByNameUp ();
		void SortByAddressUp ();
		void SortByAddressDown ();
	};
}