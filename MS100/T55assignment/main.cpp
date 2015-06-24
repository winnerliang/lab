#include <iostream>
#include <string.h>

using namespace std;

class CMyString
{
public:
      CMyString(char* pData = NULL);
      CMyString(const CMyString& str);
      ~CMyString(void);
      char * GetChar() const
      {
        return m_pData;
      }
      void SetChar(char *str)
      {
        m_pData = str;
      }
      CMyString& operator = (const CMyString& str);
      void display()
      {
        cout<<m_pData<<endl;
      }

private:
      char* m_pData;
};

CMyString::~CMyString()
{
    delete [] m_pData;
}

CMyString::CMyString(char* pData)
{
    this->m_pData = new char [strlen(pData)+1];
    strcpy(this->m_pData, pData);
}

CMyString::CMyString(const CMyString& str)
{
    char * temp = str.GetChar();
    this->m_pData = new char [strlen( temp )+1];
    strcpy(this->m_pData, temp );
}
CMyString & CMyString :: operator = ( const CMyString & str )
{
    if( &str != this )
    {
        CMyString temp(str);
        char * ptemp = temp.GetChar();
        temp.SetChar(this->m_pData);
        this->m_pData = ptemp;
    }
    return *this;
}

int main()
{
    CMyString ms("you"), mf("me");

    ms.display();
    ms = mf;

    ms.display();
    return 0;
}
