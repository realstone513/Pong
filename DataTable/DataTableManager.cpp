#include "DataTableManager.h"
#include "StringTable.h"

DataTableManager::DataTableManager(const DataTableManager& ref)
{
}

DataTableManager& DataTableManager::operator=(const DataTableManager& ref)
{
    return *this;
}

DataTableManager::DataTableManager()
{
    Init();
}

DataTableManager::~DataTableManager()
{
    Release();
}

void DataTableManager::Init()
{
    DataTable* table = new StringTable();
    table->Load();
    tables.insert({ DataTable::Types::String, table });

    table->Load();
}

void DataTableManager::Release()
{
    for (auto pair : tables)
    {
        delete pair.second;
    }
    tables.clear();
}
