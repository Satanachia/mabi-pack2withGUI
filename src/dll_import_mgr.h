#ifndef DLL_IMPORT_MGR_H
#define DLL_IMPORT_MGR_H

#include <windows.h>
#include <QDebug>
#include <QString>
#include <string>

typedef void(*EXTRACT)(const char*, const char*);
typedef void(*EX_CERTAIN)(const char*, const char*, const char*);
typedef void(*PACK)(const char*, const char*);
typedef const char*(*LIST)(const char*);
typedef const char*(*READ)(const char*, const char*);

class dll_Import_Mgr
{
public:
    dll_Import_Mgr();
    void load(EXTRACT&, EX_CERTAIN&, PACK&, LIST&, READ&);
    void loadExtractFun(EXTRACT&);
    void loadExCertainFun(EX_CERTAIN&);
    void loadPackFun(PACK&);
    void loadListFun(LIST&);
    void loadReadFun(READ&);
private:
    LPCWSTR m_dllName = L"mabipack.dll";
    LPCSTR m_extract = "extractfile";
    LPCSTR m_ex_certain = "certainfile";
    LPCSTR m_pack = "packfile";
    LPCSTR m_list = "listfile";
    LPCSTR m_read = "readfile";
    HMODULE m_hDll;
};

#endif // DLL_IMPORT_MGR_H
