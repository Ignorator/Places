#pragma once
#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include "RecordFromFilesystem.h"

void CsvExportOneRecord (FuB::DataBase* dataBase, System::String^ path);
void CsvExportMultipleRecord (FuB::DataBase* dataBase, System::String^ path);