#pragma once
#include <afxwin.h>
#include <string>
using namespace std;

class Client {
public:
    CString number;
    CString id;
    CString name;
    CString attendance;  // 오타 수정
    CString grade;

    Client() {}

    Client(CString num, const CString& strId, const CString& strName,
        const CString& strAttendance = _T(""), const CString& strGrade = _T(""))
        : number(num), id(strId), name(strName), attendance(strAttendance), grade(strGrade) {
    }
};


