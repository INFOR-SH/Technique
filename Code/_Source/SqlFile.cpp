#include "../SqlFile.h"
#include "../SqlProcedure.h"

using namespace SyteLine::Technique::Code;

CSqlFile::CSqlFile()
{
}

CSqlFile::CSqlFile(const CSqlFile& oThat)
    :m_oDeclaration(oThat.m_oDeclaration)
    ,m_stlProcedures(oThat.m_stlProcedures)
{
}

CSqlFile::CSqlFile(const CSqlFile&& oThat)
{
    *this = move(oThat);
}

CSqlFile::~CSqlFile()
{
}
void CSqlFile::Declaration(const CSqlDeclaration& oDeclaration)
{
    m_oDeclaration = oDeclaration;
}

void CSqlFile::AddProcedure(const CSqlProcedure& oProcedure)
{
    m_stlProcedures.push_back(oProcedure);
}

CSqlDeclaration CSqlFile::Declaration() const
{
    return m_oDeclaration;
}

vector<CSqlProcedure> CSqlFile::Procedures() const
{
    return m_stlProcedures;
}

CSqlDeclaration& CSqlFile::QuoteDeclaration()
{
    return m_oDeclaration;
}

vector<CSqlProcedure>& CSqlFile::QuoteProcedures()
{
    return m_stlProcedures;
}

const CSqlFile& CSqlFile::operator=(const CSqlFile& oRValue)
{
    m_oDeclaration = oRValue.m_oDeclaration;
    m_stlProcedures = oRValue.m_stlProcedures;

    return *this;
}