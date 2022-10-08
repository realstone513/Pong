#pragma once
#include <map>
#include "../3rd/Singleton.h"
#include "DataTable.h"

using namespace std;

class DataTableManager : public Singleton<DataTableManager>
{
private:
	map<DataTable::Types, DataTable*> tables;

	DataTableManager(const DataTableManager& ref);
	DataTableManager& operator=(const DataTableManager& ref);

public:
	DataTableManager();
	~DataTableManager();

	void Init();
	void Release();

	template <typename T>
	T* Get(DataTable::Types type);
};

template<typename T>
inline T* DataTableManager::Get(DataTable::Types type)
{
	auto find = tables.find(type);
	if (find == tables.end())
		return nullptr;
	return dynamic_cast<T*>(find->second);
}
#define DATATABLE_MGR (DataTableManager::GetInstance())