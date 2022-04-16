#include "dll_import_mgr.h"

void dll_Import_Mgr::load(EXTRACT &fp1, EX_CERTAIN &fp2, PACK &fp3, LIST &fp4, READ& fp5)
{
    if (m_hDll == NULL) return;
    loadExtractFun(fp1);
    loadExCertainFun(fp2);
    loadPackFun(fp3);
    loadListFun(fp4);
    loadReadFun(fp5);
}

void dll_Import_Mgr::loadExtractFun(EXTRACT &fp)
{
    fp = EXTRACT(GetProcAddress(m_hDll, m_extract));
}

void dll_Import_Mgr::loadExCertainFun(EX_CERTAIN &fp)
{
    fp = EX_CERTAIN(GetProcAddress(m_hDll, m_ex_certain));
}

void dll_Import_Mgr::loadPackFun(PACK &fp)
{
    fp = PACK(GetProcAddress(m_hDll, m_pack));
}

void dll_Import_Mgr::loadListFun(LIST &fp)
{
    fp = LIST(GetProcAddress(m_hDll, m_list));
}

void dll_Import_Mgr::loadReadFun(READ &fp)
{
    fp = READ(GetProcAddress(m_hDll, m_read));
}

dll_Import_Mgr::dll_Import_Mgr()
{
    m_hDll = LoadLibrary(m_dllName);
}
