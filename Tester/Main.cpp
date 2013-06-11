#include "Technique/Code/MssqlDriver.h"
#include "Technique/Code/MssqlScanner.h"
#include "Technique/Code/SqlDeclaration.h"
#include "Technique/Code/SqlProcedure.h"
#include "Technique/Code/SqlVariable.h"

using namespace SyteLine::Technique::Code;

//CSqlParameter GetLastParameter(CMssqlDriver& oDriver)
//{
//    auto stlParameters = oDriver.Parameters();
//    size_t nLastLine = 0;
//    mstring sLastName = "";
//
//    for(auto parameter = stlParameters.begin(); parameter != stlParameters.end(); parameter++)
//    {
//        if(parameter->second.Lines() > nLastLine)
//        {
//            nLastLine = parameter->second.Lines();
//            sLastName = parameter->first;
//        }
//    }
//
//    return move(CSqlParameter(stlParameters[sLastName]));
//}
//
//void Output(const CSqlParameter& oLastParameter, mstring sInputFileFullName, mstring sOutputFileFullName)
//{
//    ifstream stlInputFileStream(sInputFileFullName);
//    ofstream stlOuptuFileStream(sOutputFileFullName, ios::trunc);
//    char csBuffer[2048] = {0};
//    size_t nReadLine = 1;
//    mstring sInserted = "   , @UserId   TokenType   =   NULL";
//
//    while(stlInputFileStream.getline(csBuffer,2048))
//    {
//        if(nReadLine == oLastParameter.Lines()+1)
//        {
//            stlOuptuFileStream.write(sInserted.c_str(), sInserted.length());
//            stlOuptuFileStream.write("\n", strlen("\n"));
//        }
//
//        stlOuptuFileStream.write(csBuffer, strlen(csBuffer));
//        stlOuptuFileStream.write("\n", strlen("\n"));
//
//        memset(csBuffer, 0, sizeof(csBuffer));
//        nReadLine++;
//    }
//
//    stlInputFileStream.close();
//    stlOuptuFileStream.close();
//}

void main()
{
    mstring sInputFileFullName("D:\\Rpt_1099FormPrintingSp.sp");
    //mstring sOutputFileFullName("D:\\Rpt_1099FormPrintingSp.output.sql");
    ifstream stlInputFileStream(sInputFileFullName);
    CMssqlDriver oDriver;
    CMssqlScanner oScanner(&stlInputFileStream);

    oScanner.Flex(oDriver);
    CSqlDeclaration dcl = oDriver.Declaration();
    vector<CSqlProcedure> sp = oDriver.Procedures();
    CSqlVariable v = oDriver.QueryParameter("@ExOptszSiteGroup");
   

    //auto m = oDriver.QuoteParameters();

    stlInputFileStream.close();

    //auto oLastParameter = GetLastParameter(oDriver);

   // Output(oLastParameter, sInputFileFullName, sOutputFileFullName);

}